import FIFO::*;
import SpecialFIFOs::*;
import RegFile::*;
import RVUtil::*;
import Vector::*;
import KonataHelper::*;
import Printf::*;
import Ehr::*;
import CacheInterface :: *;
import MemTypes :: *;
import SuperFIFO::*;
import pipelined::*; 

interface AddrPred;
    method Word nap(Word pc);
    method Action update(Word pc, Word nextPC, Bool taken);
endinterface

module mkBtb(AddrPred);
    RegFile#(BtbIndex, Word) ppcArr <- mkRegFileFull;
    RegFile#(BtbIndex, BtbTag) entryPcArr <- mkRegFileFull;
    Vector#(128, Reg#(Bool)) validArr <- replicateM(mkReg(False));

    function BtbIndex getIndex(Word pc) = truncate(pc>>2);
    function BtbTag getTag(Word pc) = truncateLSB(pc); 

    method Word nap(Word pc);
        BtbIndex index = getIndex(pc);
        BtbTag tag = getTag(pc);
        if(validArr[index] && tag == entryPcArr.sub(index))
            return ppcArr.sub(index);
        else
            return (pc + 4);
    endmethod

    method Action update(Word pc, Word nextPC, Bool taken);
        BtbIndex index = getIndex(pc);
        BtbTag tag = getTag(pc);
        if(taken) begin
            entryPcArr.upd(index, tag);
            ppcArr.upd(index, nextPC);
            validArr[index] <= True;
        end else begin
            validArr[index] <= False;
        end
    endmethod
endmodule


function Bool notLineBoundary(Word addr); 
    let pa = parseAddress(addr);
    return pa.offset != 4'hf;
endfunction

interface SSRVIfc;
    method ActionValue#(SuperCacheReq) getIReq();
    method Action getIResp(Mem a);
    method Action getIResp2(Mem a);
    method ActionValue#(Mem) getDReq();
    method Action getDResp(Mem a);
    method ActionValue#(Mem) getMMIOReq();
    method Action getMMIOResp(Mem a);
endinterface

(* synthesize *)
module mksuperscalar(SSRVIfc);
    // Interface with memory and devices
    FIFO#(SuperCacheReq) toImem <- mkBypassFIFO;
    SuperFIFO#(Mem) fromImem <- mkBypassSuperFIFO;
    FIFO#(Mem) toDmem <- mkBypassFIFO;
    FIFO#(Mem) fromDmem <- mkBypassFIFO;
    FIFO#(Mem) toMMIO <- mkBypassFIFO;
    FIFO#(Mem) fromMMIO <- mkBypassFIFO;

    // CacheInterface cache <- mkCacheInterface;


	// Code to support Konata visualization
    String dumpFile = "output.log" ;
    let lfh <- mkReg(InvalidFile);
    Reg#(KonataId) fresh_id<- mkReg(0);
	Ehr#(2,KonataId) commit_id <- mkEhr(0);

	FIFO#(KonataId) retired1 <- mkFIFO;
	FIFO#(KonataId) squashed1 <- mkFIFO;

	FIFO#(KonataId) retired2 <- mkFIFO;
	FIFO#(KonataId) squashed2 <- mkFIFO;

    Reg#(Bool) starting <- mkReg(True);

    // MY REGS
    Reg#(Word) pc <- mkReg(0);
    Ehr#(3, Bit#(1)) globalEpoch <- mkEhr(0);

    AddrPred btb <- mkBtb;

    Ehr#(3, Bit#(32)) redirectPc <- mkEhr(0);
    Ehr#(3, Bool) mispredicted <- mkEhr(False);

    SuperFIFO#(F2D) f2d <- mkSuperFIFO;
    SuperFIFO#(D2E) d2e <-  mkSuperFIFO;
    SuperFIFO#(E2W) e2w <-  mkSuperFIFO;
    
    Reg#(Bit#(32)) cycles <- mkReg(0);

    Scoreboard sb <- mkScoreboard;
    BypassRegisterFile rf <- mkBRF;

    Ehr#(2, Bool) decode_1_done <- mkEhr(False); 
    Ehr#(2, Bool) execute_1_done <- mkEhr(False); 
    Ehr#(2, Bool) execute_1_squashed <- mkEhr(False); 
    Ehr#(2, Bool) writeback_1_done<- mkEhr(False); 

    Ehr#(2,Bool) exec_1_alu<-mkEhr(False);
    Ehr#(2,Bool) is_mem_inst<-mkEhr(False);
    Ehr#(2,Bool) double_retired<-mkEhr(False);
    Ehr#(2,Bool) double_squashed<-mkEhr(False);

    rule tick;
        cycles <= cycles + 1;
        decode_1_done[1] <= False;
        execute_1_done[1] <= False;
        execute_1_squashed[1] <= False;
        writeback_1_done[1] <= False;
        double_squashed[1] <= False;
        // $display("NEW CYCLE");
    endrule
   
   Bit#(32) maxCycles = 1000;
//    rule timeout if (cycles > maxCycles);
//         $display("Restricted to %0d cycles", maxCycles);
//        $finish(1);
//    endrule

	rule do_tic_logging;
        
        if (starting) begin
            let f <- $fopen(dumpFile, "w") ;
            lfh <= f;
            $fwrite(f, "Kanata\t0004\nC=\t1\n");
            starting <= False;
        end
		konataTic(lfh);
	endrule
		
    rule fetch if (!starting );
        Bit#(32) pc_fetched = 0;

        // redirect
        if(mispredicted[2] == True) begin
            // $display("misprediction");
            pc_fetched = redirectPc[2];
            mispredicted[2] <= False;
        end else begin
            pc_fetched = pc;
        end

        let req = SuperCacheReq{word_byte: 0,
            addr : pc_fetched,
            data : 0,
            fetchTwo : 0}; 
        // let req1 = Mem{byte_en:0,
        //     addr : pc_fetched+4,
        //     data:0};

        // You should put the pc that you fetch in pc_fetched
        // Below is the code to support Konata's visualization

        Bit#(32) nap_pc = btb.nap(pc_fetched);

        let parsedPC = parseAddress(pc_fetched);
        let parsedPPC = parseAddress(nap_pc);

        // $display("Fetching ", fshow(pc_fetched), " ", fshow(nap_pc));

        if (parsedPC.tag == parsedPPC.tag && parsedPC.index == parsedPPC.index) begin
            let iid <- nfetchKonata(lfh, fresh_id, 0, 2);
            let nap_nap_pc = btb.nap(nap_pc);

            req.fetchTwo = parsedPPC.offset - parsedPC.offset;
            toImem.enq(req); //TODO with the SuperCache32

            f2d.enq1(F2D{pc : pc_fetched , ppc : nap_pc, epoch: globalEpoch[2], k_id : iid});
            labelKonataLeft(lfh, iid, $format("F 0x%x at cycle %5d  ", pc_fetched, cycles));

            f2d.enq2(F2D{pc : nap_pc , ppc : nap_nap_pc, epoch: globalEpoch[2], k_id : iid + 1});
            labelKonataLeft(lfh, iid + 1 , $format("F 0x%x at cycle %5d  ", nap_pc, cycles));

            pc <= nap_nap_pc;
        end else begin

            let iid <- fetch1Konata(lfh, fresh_id, 0);
            pc <= nap_pc;

            f2d.enq1(F2D{pc : pc_fetched , ppc : nap_pc, epoch: globalEpoch[2], k_id : iid});
            labelKonataLeft(lfh, iid, $format("F 0x%x at cycle %5d  ", pc_fetched, cycles));
            toImem.enq(req);
        end
        // This will likely end with something like:
        // f2d.enq(F2D{ ..... k_id: iid});
        // iid is the unique identifier used by konata, that we will pass around everywhere for each instruction
    endrule


    rule decode_2 if (!starting && decode_1_done[1] && f2d.deqReadyN(2) && d2e.enqReadyN(2));// TODO
        //$display("decode 2 is firing");
        //instruction 2
        let from_fetch = f2d.first2();
        let resp = fromImem.first2();

        if(from_fetch.pc != resp.addr)begin
            // $display("we fucked up in decode 2");
            // $display("from_fetch1: ", fshow(f2d.first1()));
            // $display("from_fetch2: ", fshow(from_fetch));
            // $display("response1: ", fshow(fromImem.first1()));
            // $display("response2: ", fshow(resp));
        end else begin
        // $display("decode in cycle %d", cycles); 
            let instr = resp.data;
            let decodedInst = decodeInst(instr);
            let rs1_idx = getInstFields(instr).rs1;
            let rs2_idx = getInstFields(instr).rs2;
            let rd_idx = getInstFields(instr).rd;

            if (!(sb.search3(rs1_idx) || (sb.search4(rs2_idx)))) begin
                let rs1=rf.rv3(rs1_idx);
                let rs2=rf.rv4(rs2_idx);
                if (decodedInst.valid_rd) sb.insert1(rd_idx);
                f2d.deq2();
                fromImem.deq2();
                d2e.enq2(D2E { 
                    dInst: decodedInst,
                    pc: from_fetch.pc,
                    ppc: from_fetch.ppc,
                    epoch: from_fetch.epoch, 
                    rv1:  rs1,
                    rv2: rs2, 
                    k_id: from_fetch.k_id// <- This is a unique identifier per instructions, for logging purposes
                    }); 
            end
            // To add a decode event in Konata you will likely do something like:
            decodeKonata(lfh, from_fetch.k_id);
            labelKonataLeft(lfh,from_fetch.k_id, $format("D pc: 0x%x at cycle %5d ", from_fetch.pc, cycles));
        end
    endrule

    rule decode_1 if (!starting );// TODO
    //instruction 1
        let from_fetch = f2d.first1();
        let resp = fromImem.first1();

        if(from_fetch.pc != resp.addr)begin
        // $display("we fucked up in decode 1");
        // $display("from_fetch: ", fshow(from_fetch));
        // $display("response: ", fshow(resp));
        // $finish;
        end
        // $display("decode in cycle %d", cycles); 
        let instr = resp.data;
        let decodedInst = decodeInst(instr);
        let rs1_idx = getInstFields(instr).rs1;
        let rs2_idx = getInstFields(instr).rs2;
        let rd_idx = getInstFields(instr).rd;

        if (!(sb.search1(rs1_idx) || (sb.search2(rs2_idx)))) begin
            let rs1=rf.rv1(rs1_idx);
            let rs2=rf.rv2(rs2_idx);
            if (decodedInst.valid_rd) sb.insert(rd_idx);
            f2d.deq1();
            fromImem.deq1();
            d2e.enq1(D2E { 
                dInst: decodedInst,
                pc: from_fetch.pc,
                ppc: from_fetch.ppc,
                epoch: from_fetch.epoch, 
                rv1:  rs1,
                rv2: rs2, 
                k_id: from_fetch.k_id// <- This is a unique identifier per instructions, for logging purposes
                }); 

            decode_1_done[0] <= True;
        end
        // To add a decode event in Konata you will likely do something like:
        decodeKonata(lfh, from_fetch.k_id);
        labelKonataLeft(lfh,from_fetch.k_id, $format("D pc: 0x%x at cycle %5d ", from_fetch.pc, cycles));
    endrule


    rule execute2 if(!starting && execute_1_done[1] );
        //$display("execute 2");
        let from_decode=d2e.first2();
        
        //squashing
        if(from_decode.epoch!=globalEpoch[1])begin
            	
		    executeKonata(lfh, from_decode.k_id);

            squashed2.enq(from_decode.k_id);

            labelKonataLeft(lfh,from_decode.k_id, $format("E (NOP) at pc: 0x%x at cycle %5d ", from_decode.pc, cycles));
            d2e.deq2();
            if (from_decode.dInst.valid_rd) sb.remove4(getInstFields(from_decode.dInst.inst).rd);
        end else if (isAlu(from_decode.dInst) && exec_1_alu[1]) begin
		    executeKonata(lfh, from_decode.k_id);
            d2e.deq2();
            let fields =getInstFields(from_decode.dInst.inst); 
            let imm = getImmediate(from_decode.dInst);
            Bool mmio = False;

            // basically execute
            let data = execALU32(from_decode.dInst.inst, from_decode.rv1, from_decode.rv2, imm, from_decode.pc);

            let isUnsigned = 0;

            // needed for loads and stores apparently
            let funct3 = getInstFields(from_decode.dInst.inst).funct3;
            let size = funct3[1:0];
            let addr = from_decode.rv1 + imm;
            Bit#(2) offset = addr[1:0];
            
            labelKonataLeft(lfh,from_decode.k_id, $format("E (ALU) at pc: 0x%x at cycle %5d , inst: 0x%x", from_decode.pc, cycles, from_decode.dInst.inst));
            let nextPc = from_decode.pc + 4;



                e2w.enq2(E2W{ 
                        mem_business: MemBusiness { isUnsigned : unpack(isUnsigned), size : size, offset : offset, mmio: mmio},
                        addr : addr,
                        data: data,
                        dInst: from_decode.dInst,
                        k_id : from_decode.k_id,// <- This is a unique identifier per instructions, for logging purposes
                        pc : from_decode.pc
                    });
        

        end
        exec_1_alu[1] <= False;
    endrule


    rule execute1 if (!starting );
        let from_decode = d2e.first1();
        d2e.deq1();
        execute_1_done[0] <= True;
        // $display("current pc: 0x%x     current inst: 0x%x", from_decode.pc, from_decode.dInst.inst);

        // $display("execute in cycle %d", cycles); 
		executeKonata(lfh, from_decode.k_id);

        if (from_decode.epoch != globalEpoch[0])begin
            squashed1.enq(from_decode.k_id);
            labelKonataLeft(lfh,from_decode.k_id, $format("E (NOP) at pc: 0x%x at cycle %5d ", from_decode.pc, cycles));

            if (from_decode.dInst.valid_rd) sb.remove3(getInstFields(from_decode.dInst.inst).rd);

        end else begin

            let fields =getInstFields(from_decode.dInst.inst); 
            let imm = getImmediate(from_decode.dInst);
            Bool mmio = False;

            // basically execute
            let data = execALU32(from_decode.dInst.inst, from_decode.rv1, from_decode.rv2, imm, from_decode.pc);

            let isUnsigned = 0;

            // needed for loads and stores apparently
            let funct3 = getInstFields(from_decode.dInst.inst).funct3;
            let size = funct3[1:0];
            let addr = from_decode.rv1 + imm;
            Bit#(2) offset = addr[1:0];

            // if LOAD or STORE
            if (isMemoryInst(from_decode.dInst)) begin
                // Technical details for load byte/halfword/word
                let shift_amount = {offset, 3'b0};
                let byte_en = 0;
                case (size) matches
                2'b00: byte_en = 4'b0001 << offset;
                2'b01: byte_en = 4'b0011 << offset;
                2'b10: byte_en = 4'b1111 << offset;
                endcase
                data = from_decode.rv2 << shift_amount;
                addr = {addr[31:2], 2'b0};
                isUnsigned = funct3[2];
                let type_mem = (from_decode.dInst.inst[5] == 1) ? byte_en : 0;
                let req = Mem {byte_en : type_mem,
                        addr : addr,
                        data : data};
                if (isMMIO(addr)) begin 
                    // if (debug) $display("[Execute] MMIO", fshow(req));
                    toMMIO.enq(req);
                labelKonataLeft(lfh,from_decode.k_id, $format("E (MMIO) at pc: 0x%x at cycle %5d ", from_decode.pc, cycles));
                    mmio = True;
                end else begin 
                labelKonataLeft(lfh,from_decode.k_id, $format("E (MEM) at pc: 0x%x at cycle %5d, addr: 0x%x", from_decode.pc, cycles, req.addr));
                    toDmem.enq(req);
                end
            end

            // if it's a branch instruction idk 
            else if (isControlInst(from_decode.dInst)) begin
                labelKonataLeft(lfh,from_decode.k_id, $format("E (CTRL) at pc: 0x%x at cycle %5d ", from_decode.pc, cycles));
                data = from_decode.pc + 4;

            /// else
            end else begin 
                labelKonataLeft(lfh,from_decode.k_id, $format("E (ALU) at pc: 0x%x at cycle %5d , inst: 0x%x", from_decode.pc, cycles, from_decode.dInst.inst));
            end
            
            if(isAlu(from_decode.dInst)) begin
                exec_1_alu[0]<=True;
                //$display("we have a alu");
            end
            let controlResult = execControl32(from_decode.dInst.inst, from_decode.rv1, from_decode.rv2, imm, from_decode.pc);
            let nextPc = controlResult.nextPC;

            if (controlResult.nextPC != from_decode.ppc)begin
                mispredicted[0] <= True;
                redirectPc[0] <= controlResult.nextPC;
                globalEpoch[0] <= ~globalEpoch[0];
            end else mispredicted[0] <= False;
            
            // $display("ControlResult ", fshow(from_decode), " ", fshow(nextPc), " ", fshow(controlResult.taken));
            btb.update(from_decode.pc, controlResult.nextPC, controlResult.taken);

            e2w.enq1(E2W{ 
                    mem_business: MemBusiness { isUnsigned : unpack(isUnsigned), size : size, offset : offset, mmio: mmio},
                    addr : addr,
                    data: data,
                    dInst: from_decode.dInst,
                    k_id : from_decode.k_id,// <- This is a unique identifier per instructions, for logging purposes
                    pc : from_decode.pc
                });
        end
        // Similarly, to register an execute event for an instruction:
    		// executeKonata(lfh, k_id);
    	// where k_id is the unique konata identifier that has been passed around that came from the fetch stage


    	// Execute is also the place where we advise you to kill mispredicted instructions
    	// (instead of Decode + Execute like in the class)
    	// When you kill (or squash) an instruction, you should register an event for Konata:
    	

        // This will allow Konata to display those instructions in grey
    endrule
    

    rule writeback2 if(!starting && writeback_1_done[1]);
        //$display("writeback2 working");

        let from_execute = e2w.first2();
        is_mem_inst[1]<=False;

        let data = from_execute.data;
        let fields = getInstFields(from_execute.dInst.inst);

        // if(isMemoryInst(from_execute.dInst) && !is_mem_inst[1])begin

        //     writebackKonata(lfh, from_execute.k_id);
        //     labelKonataLeft(lfh,from_execute.k_id, $format(" W at cycle %5d", cycles));
        //     retired.enq2(from_execute.k_id);
        //     e2w.deq2();
        //     let resp = ?;
        //     let mem_business  = from_execute.mem_business;
		//     if (mem_business.mmio) begin 
        //         resp = fromMMIO.first();
		//         fromMMIO.deq();
		//     end else begin 
        //         resp = fromDmem.first();
		//         fromDmem.deq();
		//     end
        //     let mem_data = resp.data;
        //     mem_data = mem_data >> {mem_business.offset ,3'b0};
        //     case ({pack(mem_business.isUnsigned), mem_business.size}) matches
        //         3'b000 : data = signExtend(mem_data[7:0]);
        //         3'b001 : data = signExtend(mem_data[15:0]);
        //         3'b100 : data = zeroExtend(mem_data[7:0]);
        //         3'b101 : data = zeroExtend(mem_data[15:0]);
        //         3'b010 : data = mem_data;
        //     endcase 

        //     if (!from_execute.dInst.legal) begin
        //         $display("panic");
        //         $finish;
        //     end
        //     if (from_execute.dInst.valid_rd) begin
        //         let rd_idx = fields.rd;

        //         rf.set1(rd_idx, data);
        //         sb.remove2(rd_idx);
        //     end 
        // end
        // else if (!isMemoryInst(from_execute.dInst)) begin
        if (!isMemoryInst(from_execute.dInst)) begin
            writebackKonata(lfh, from_execute.k_id);
            labelKonataLeft(lfh,from_execute.k_id, $format(" W at cycle %5d", cycles));
            retired2.enq(from_execute.k_id);
            e2w.deq2(); 
            if (!from_execute.dInst.legal) begin
                $display("panic");
                $finish;
            end
            if (from_execute.dInst.valid_rd) begin
                let rd_idx = fields.rd;

                rf.set1(rd_idx, data);
                sb.remove2(rd_idx);
            end 
        end
    endrule


    rule writeback1 if (!starting );
        let from_execute = e2w.first1();
        e2w.deq1();
        writeback_1_done[0] <= True;

        // $display("writeback in cycle %d", cycles);

		writebackKonata(lfh, from_execute.k_id);
        labelKonataLeft(lfh,from_execute.k_id, $format(" W at cycle %5d", cycles));
        retired1.enq(from_execute.k_id);

        let data = from_execute.data;
        let fields = getInstFields(from_execute.dInst.inst);
        if (isMemoryInst(from_execute.dInst) ) begin // (* // write_val *)
            is_mem_inst[0]<=True;
            let resp = ?;
            let mem_business  = from_execute.mem_business;
		    if (mem_business.mmio) begin 
                resp = fromMMIO.first();
		        fromMMIO.deq();
		    end else begin 
                resp = fromDmem.first();
		        fromDmem.deq();
		    end
            let mem_data = resp.data;
            mem_data = mem_data >> {mem_business.offset ,3'b0};
            case ({pack(mem_business.isUnsigned), mem_business.size}) matches
	     	3'b000 : data = signExtend(mem_data[7:0]);
	     	3'b001 : data = signExtend(mem_data[15:0]);
	     	3'b100 : data = zeroExtend(mem_data[7:0]);
	     	3'b101 : data = zeroExtend(mem_data[15:0]);
	     	3'b010 : data = mem_data;
             endcase
		end
        if (!from_execute.dInst.legal) begin
			// if (debug) $display("[Writeback] Illegal Inst, Drop and fault: ", fshow(from_execute.dInst));
			// pc <= 0;	// Fault
            $display("panic");
            $finish;
	    end
		if (from_execute.dInst.valid_rd) begin
            let rd_idx = fields.rd;

            rf.set(rd_idx, data);
            sb.remove1(rd_idx);
            // if (isMemoryInst(from_execute.dInst)
            //         && rd_idx == 5'd1 
            //         && from_execute.pc != 32'h10cc)
            //         $display("Writeback pc: 0x%x, data: 0x%x, addr: 0x%x", from_execute.pc, data, from_execute.addr);
		end 


        // Similarly, to register an execute event for an instruction:
	   		// writebackKonata(lfh,k_id);


	   	// In writeback is also the moment where an instruction retires (there are no more stages)
	   	// Konata requires us to register the event as well using the following: 
		// retired.enq(k_id);
	endrule
		

	// ADMINISTRATION:

    rule administrative_konata_commit1;
        retired1.deq();
        let f = retired1.first();
        commitKonata(lfh, f, commit_id[1]);
	endrule

    
    rule administrative_konata_commit2;
        retired2.deq();
        let f = retired2.first();
        commitKonata(lfh, f, commit_id[0]);
	endrule

	rule administrative_konata_flush1;
        squashed1.deq();
        let f = squashed1.first();
        squashKonata(lfh, f);
	endrule

	rule administrative_konata_flush2;
        squashed2.deq();
        let f = squashed2.first();
        squashKonata(lfh, f);
    endrule


//   rule getIReq;
//     let req = toImem.first();
//     toImem.deq();
//     cache.sendReqInstr(CacheReq{word_byte : req.byte_en, addr : req.addr, data : req.data});
//   endrule

//   rule getIResp;
//     let resp <- cache.getRespInstr();
//     fromImem.enq(Mem{byte_en : ?, addr : ?, data : resp});
//   endrule


//   rule getDreq;
//     let req = toDmem.first();
//     toDmem.deq();
//     cache.sendReqData(CacheReq{word_byte : req.byte_en, addr : req.addr, data : req.data});
//   endrule

//   rule getDResp;
//     let resp <- cache.getRespData();
//     fromDmem.enq(Mem{byte_en : ?, addr : ?, data : resp});
//   endrule
		
    method ActionValue#(SuperCacheReq) getIReq();
		toImem.deq();
		return toImem.first();
    endmethod
    method Action getIResp(Mem a);
    	fromImem.enq1(a);
    endmethod
    method Action getIResp2(Mem a);
    	fromImem.enq2(a);
    endmethod
    method ActionValue#(Mem) getDReq();
		toDmem.deq();
		return toDmem.first();
    endmethod
    method Action getDResp(Mem a);
		fromDmem.enq(a);
    endmethod
    method ActionValue#(Mem) getMMIOReq();
		toMMIO.deq();
		return toMMIO.first();
    endmethod
    method Action getMMIOResp(Mem a);
		fromMMIO.enq(a);
    endmethod
endmodule
