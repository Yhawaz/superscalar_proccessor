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

typedef struct { Bit#(4) byte_en; Bit#(32) addr; Bit#(32) data; } Mem deriving (Eq, FShow, Bits);

typedef Bit#(32) Word;

typedef Bit#(5) RIndex;
interface RVIfc;
    method ActionValue#(Mem) getIReq();
    method Action getIResp(Mem a);
    method ActionValue#(Mem) getDReq();
    method Action getDResp(Mem a);
    method ActionValue#(Mem) getMMIOReq();
    method Action getMMIOResp(Mem a);
endinterface


interface Scoreboard;
    method Action insert(RIndex dst);
    method Bool search1(RIndex src);
    method Bool search2(RIndex src);
    method Action remove1(RIndex dst);
    method Action remove2(RIndex dst);
    method Action remove3(RIndex dst);
    method Action remove4(RIndex dst);
    method Bool search3(RIndex src);
    method Bool search4(RIndex src);
    method Action insert1(RIndex dst);
endinterface

interface BypassRegisterFile;
    // method ActionValue#(Word) show(Word pc);
    method Word rv1(RIndex src);
    method Word rv2(RIndex src);
    method Word rv3(RIndex src);
    method Word rv4(RIndex src);
    method Action set(RIndex src, Word val);
    method Action set1(RIndex src, Word val);
endinterface

typedef struct { Bool isUnsigned; Bit#(2) size; Bit#(2) offset; Bool mmio; } MemBusiness deriving (Eq, FShow, Bits);

function Bool isMMIO(Bit#(32) addr);
    Bool x = case (addr) 
        32'hf000fff0: True;
        32'hf000fff4: True;
        32'hf000fff8: True;
        default: False;
    endcase;
    return x;
endfunction

typedef struct { Bit#(32) pc;
                 Bit#(32) ppc;
                 Bit#(1) epoch; 
                 KonataId k_id; // <- This is a unique identifier per instructions, for logging purposes
             } F2D deriving (Eq, FShow, Bits);

typedef struct { 
    DecodedInst dInst;
    Bit#(32) pc;
    Bit#(32) ppc;
    Bit#(1) epoch;
    Bit#(32) rv1; 
    Bit#(32) rv2; 
    KonataId k_id; // <- This is a unique identifier per instructions, for logging purposes
    } D2E deriving (Eq, FShow, Bits);

typedef struct { 
    MemBusiness mem_business;
    Word addr;
    Bit#(32) data;
    DecodedInst dInst;
    KonataId k_id; // <- This is a unique identifier per instructions, for logging purposes
    Word pc;
} E2W deriving (Eq, FShow, Bits);


(* synthesize *)
module mkScoreboard(Scoreboard);
    
    Vector#(32, Ehr#(6, Bit#(3))) buff <- replicateM(mkEhr(0));    
    // rule show_sb;
    //     $write("scoreboard: " );
    //     for (Integer i = 0; i < 32; i = i + 1)begin
    //         $write(" %2d: %1d", i, buff[i][0]);
    //     end
    //     $write("\n");
    // endrule

    method Action remove1(RIndex dst);
        buff[dst][0]  <= buff[dst][0] - 1;
    endmethod

    method Action remove2(RIndex dst);
        buff[dst][1]  <= buff[dst][1] - 1;
    endmethod

    method Action remove3(RIndex dst);
        buff[dst][2]  <= buff[dst][2] - 1;
    endmethod

    method Action remove4(RIndex dst);
        buff[dst][3]  <= buff[dst][3] - 1;
    endmethod

    method Bool search1(RIndex src);
        return buff[src][4] != 0 && src != 0;
    endmethod
    method Bool search2(RIndex src);
        return buff[src][4] != 0 && src != 0;
    endmethod
    method Action insert(RIndex dst);
        buff[dst][4] <= buff[dst][4] + 1;
    endmethod
    //for superscalar
    method Bool search3(RIndex src);
        return buff[src][5]!=0 && src!=0;
    endmethod
    //i made another one that way i can use this to check if instr 2 is dependent on instr 1
    method Bool search4(RIndex src);
        return buff[src][5]!=0 && src!=0;
    endmethod
    method Action insert1(RIndex dst);
        buff[dst][5] <= buff[dst][5]+1;
    endmethod

endmodule

(* synthesize *)
module mkBRF(BypassRegisterFile); 
    Vector#(32, Ehr#(3, Bit#(32))) rf <- replicateM(mkEhr(0));
    // Vector#(32, Reg#(Bit#(32))) rf <- replicateM(mkReg(0));

    // method ActionValue#(Word) show(Word pc); 
    //     // $display("pc is 0x%x and sp: 0x%x ", pc, rf[2][1]);
    //     $display("hi");
    //     return rf[2][1];
    // endmethod
    // String to_show 
    // rule print;
    //     $display("sp: 0x%x",rf[2][1]);
    // endrule

    // endmethod 

    method Action set(RIndex src, Word val);
         rf[src][0] <= (src == 0)? 0 : val;
    endmethod

    method Action set1(RIndex src, Word val);
        rf[src][1] <= (src==0)? 0 : val ;
    endmethod   
    method Word rv1(RIndex src) = rf[src][2];
    method Word rv2(RIndex src) = rf[src][2];
    method Word rv3(RIndex src) = rf[src][2];
    method Word rv4(RIndex src) = rf[src][2];




    // method Action set(RIndex src, Word val);
    //      rf[src] <= (src == 0)? 0 : val;
    // endmethod

    // method Word rv1(RIndex src) = rf[src];
    // method Word rv2(RIndex src) = rf[src];
endmodule

(* synthesize *)
module mkpipelined(RVIfc);
    // Interface with memory and devices
    FIFO#(Mem) toImem <- mkBypassFIFO;
    FIFO#(Mem) fromImem <- mkBypassFIFO;
    FIFO#(Mem) toDmem <- mkBypassFIFO;
    FIFO#(Mem) fromDmem <- mkBypassFIFO;
    FIFO#(Mem) toMMIO <- mkBypassFIFO;
    FIFO#(Mem) fromMMIO <- mkBypassFIFO;

    // CacheInterface cache <- mkCacheInterface;


	// Code to support Konata visualization
    String dumpFile = "output.log" ;
    let lfh <- mkReg(InvalidFile);
	Reg#(KonataId) fresh_id <- mkReg(0);
	Reg#(KonataId) commit_id <- mkReg(0);

	FIFO#(KonataId) retired <- mkFIFO;
	FIFO#(KonataId) squashed <- mkFIFO;

    

    
    Reg#(Bool) starting <- mkReg(True);

    // MY REGS
    Reg#(Word) pc <- mkReg(0);
    Ehr#(2, Bit#(1)) globalEpoch <- mkEhr(0);

    Ehr#(2, Bit#(32)) redirectPc <- mkEhr(0);
    Ehr#(2, Bool) mispredicted <- mkEhr(False);

    Ehr#(3, Maybe#(Word)) dataE <- mkEhr(Invalid);
    Ehr#(3, Maybe#(Word)) dataW<- mkEhr(Invalid);
    Ehr#(3, Bit#(5)) dstE <- mkEhr(0);
    Ehr#(3, Bit#(5)) dstW <- mkEhr(0);

    FIFO#(F2D) f2d <- mkFIFO;
    FIFO#(D2E) d2e <-  mkFIFO;
    FIFO#(E2W) e2w <-  mkFIFO;
   
    Reg#(Bit#(32)) cycles <- mkReg(0);

    Scoreboard sb <- mkScoreboard;
    BypassRegisterFile rf <- mkBRF;

    rule tick;
        cycles <= cycles + 1;
    endrule

    rule reset_ehr;
        dataW[2] <= Invalid;
        dataE[2] <= Invalid;
        dstE[2] <= 0;
        dstW[2] <= 0;
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
        if(mispredicted[1] == True) begin
            // $display("misprediction");
            pc_fetched = redirectPc[1];
        end else begin
            pc_fetched = pc;
        end

        let req = Mem {byte_en : 0,
            addr : pc_fetched,
            data : 0}; 

        // You should put the pc that you fetch in pc_fetched
        // Below is the code to support Konata's visualization
		let iid <- fetch1Konata(lfh, fresh_id, 0);
        labelKonataLeft(lfh, iid, $format("F 0x%x at cycle %5d  ", pc_fetched, cycles));

        toImem.enq(req);
        f2d.enq(F2D{pc : pc_fetched , ppc : pc_fetched + 4, epoch: globalEpoch[1], k_id : iid});

        mispredicted[1] <= False;
        pc <= pc_fetched + 4;
        // This will likely end with something like:
        // f2d.enq(F2D{ ..... k_id: iid});
        // iid is the unique identifier used by konata, that we will pass around everywhere for each instruction
    endrule

    rule decode if (!starting );// TODO
        let from_fetch = f2d.first();

        let resp = fromImem.first();
        // $display("decode in cycle %d", cycles); 
        let instr = resp.data;
        let decodedInst = decodeInst(instr);

        let rs1_idx = getInstFields(instr).rs1;
        let rs2_idx = getInstFields(instr).rs2;
        let rd_idx = getInstFields(instr).rd;

        if (!(sb.search1(rs1_idx) || (sb.search2(rs2_idx) )))begin
            let rs1 = rf.rv1(rs1_idx);
            let rs2 = rf.rv2(rs2_idx);
            // let b = 32'b0;
            // if (from_fetch.pc == 32'h10a8 || from_fetch.pc == 32'h10d4) b = rf.show(from_fetch.pc);
            // if (rs1 == 32'h20) $display("pc: 0x%x", pc);

            if (decodedInst.valid_rd) sb.insert(rd_idx);

            f2d.deq();
            fromImem.deq();
            d2e.enq(D2E { 
                dInst: decodedInst,
                pc: from_fetch.pc,
                ppc: from_fetch.ppc,
                epoch: from_fetch.epoch, 
                rv1:  rs1,
                rv2: rs2, 
                k_id: from_fetch.k_id// <- This is a unique identifier per instructions, for logging purposes
                });
        end else begin
        /*
            Bool stall = False;
            
            let rs1 = rf.rv1(rs1_idx);
            let rs2 = rf.rv2(rs2_idx);

            // if(dstW[1] !=0 &&((rs1_idx == dstW[1]) || (rs2_idx == dstW[1]))) stall = True;
            if(rs1_idx == dstW[1] && dstW[1] != 0)begin
                if(isValid(dataW[1])) begin
                    rs1 = fromMaybe(?, dataW[1]);
                end else stall = True;
            end 

            if(rs2_idx == dstW[1] && dstW[1] != 0)begin
                if(isValid(dataW[1])) begin
                    rs2 = fromMaybe(?, dataW[1]);
                end else stall = True;
            end 

            if(rs1_idx == dstE[1] && dstE[1] != 0)begin
                if(isValid(dataE[1])) begin
                    rs1 = fromMaybe(?, dataE[1]);
                end else stall = True;
            end 

            if(rs2_idx == dstE[1] && dstE[1] != 0)begin
                if(isValid(dataE[1])) begin
                    rs2 = fromMaybe(?, dataE[1]);
                end else stall = True;
            end 

            if(!stall)begin

                if (decodedInst.valid_rd) sb.insert(rd_idx);

                f2d.deq();
                fromImem.deq();
                d2e.enq(D2E { 
                    dInst: decodedInst,
                    pc: from_fetch.pc,
                    ppc: from_fetch.ppc,
                    epoch: from_fetch.epoch, 
                    rv1:  rs1,
                    rv2: rs2, 
                    k_id: from_fetch.k_id// <- This is a unique identifier per instructions, for logging purposes
                    });
            end
*/
        end

        // To add a decode event in Konata you will likely do something like:
        decodeKonata(lfh, from_fetch.k_id);
        labelKonataLeft(lfh,from_fetch.k_id, $format("D pc: 0x%x at cycle %5d ", from_fetch.pc, cycles));
    endrule

    rule set_dstE if(!starting); 
        let from_decode = d2e.first();
        if(from_decode.dInst.valid_rd) dstE[0] <= getInstFields(from_decode.dInst.inst).rd; 
    endrule
    rule execute if (!starting );
        let from_decode = d2e.first();
        d2e.deq();

        // $display("execute in cycle %d", cycles); 
		executeKonata(lfh, from_decode.k_id);

        if (from_decode.epoch != globalEpoch[0])begin
            squashed.enq(from_decode.k_id);
            labelKonataLeft(lfh,from_decode.k_id, $format("E (NOP) at pc: 0x%x at cycle %5d ", from_decode.pc, cycles));

            if (from_decode.dInst.valid_rd) sb.remove2(getInstFields(from_decode.dInst.inst).rd);

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
                labelKonataLeft(lfh,from_decode.k_id, $format("E (MEM) at pc: 0x%x at cycle %5d ", from_decode.pc, cycles));
                    toDmem.enq(req);
                end
            end

            // if it's a branch instruction idk 
            else if (isControlInst(from_decode.dInst)) begin
                labelKonataLeft(lfh,from_decode.k_id, $format("E (CTRL) at pc: 0x%x at cycle %5d ", from_decode.pc, cycles));
                data = from_decode.pc + 4;
                
            /// else
            end else begin 
                labelKonataLeft(lfh,from_decode.k_id, $format("E (ALU) at pc: 0x%x at cycle %5d ", from_decode.pc, cycles));
            end

            let controlResult = execControl32(from_decode.dInst.inst, from_decode.rv1, from_decode.rv2, imm, from_decode.pc);
            let nextPc = controlResult.nextPC;

            if (controlResult.nextPC != from_decode.ppc && controlResult.taken)begin
                mispredicted[0] <= True;
                redirectPc[0] <= controlResult.nextPC;
                globalEpoch[0] <= ~globalEpoch[0];
            end else mispredicted[0] <= False;


            if(from_decode.dInst.valid_rd && !isMemoryInst(from_decode.dInst)) dataE[0] <= Valid(data); 

            e2w.enq(E2W{ 
                    mem_business: MemBusiness { isUnsigned : unpack(isUnsigned), size : size, offset : offset, mmio: mmio},
                    addr : addr,
                    data: data,
                    dInst: from_decode.dInst,
                    k_id : from_decode.k_id,// <- This is a unique identifier per instructions, for logging purposes
                    pc : from_decode.pc
                });

            // if (isMemoryInst(from_decode.dInst) 
            //         && fields.rs2 == 5'd1 
            //         && from_decode.pc != 32'h10cc) 
            //         $display("Execute pc: 0x%x, data: 0x%x, addr: 0x%x", from_decode.pc, data, addr);
   
        end
        // Similarly, to register an execute event for an instruction:
    		// executeKonata(lfh, k_id);
    	// where k_id is the unique konata identifier that has been passed around that came from the fetch stage


    	// Execute is also the place where we advise you to kill mispredicted instructions
    	// (instead of Decode + Execute like in the class)
    	// When you kill (or squash) an instruction, you should register an event for Konata:
    	

        // This will allow Konata to display those instructions in grey
    endrule

    rule set_dstW if(!starting); 
        let from_execute = e2w.first();
        let fields = getInstFields(from_execute.dInst.inst);
		if (from_execute.dInst.valid_rd) dstW[0] <= fields.rd;
    endrule
    rule writeback if (!starting );
        let from_execute = e2w.first();
        e2w.deq();

        // $display("writeback in cycle %d", cycles);

		writebackKonata(lfh, from_execute.k_id);
        labelKonataLeft(lfh,from_execute.k_id, $format(" W at cycle %5d", cycles));
        retired.enq(from_execute.k_id);

        let data = from_execute.data;
        let fields = getInstFields(from_execute.dInst.inst);
        if (isMemoryInst(from_execute.dInst)) begin // (* // write_val *)
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
            dataW[0] <= Valid(data);
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

    rule administrative_konata_commit;
		    retired.deq();
		    let f = retired.first();
		    commitKonata(lfh, f, commit_id);
	endrule
		
	rule administrative_konata_flush;
		    squashed.deq();
		    let f = squashed.first();
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
		
    method ActionValue#(Mem) getIReq();
		toImem.deq();
		return toImem.first();
    endmethod
    method Action getIResp(Mem a);
    	fromImem.enq(a);
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
