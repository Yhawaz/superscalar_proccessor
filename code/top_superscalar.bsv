import RVUtil::*;
import BRAM::*;
import pipelined::*;
import FIFO::*;
import MemTypes::*;
import CacheInterface::*;
import superscaler::*;

module mktop_superscalar(Empty);
    // Instantiate the dual ported memory
    BRAM_Configure cfg = defaultValue();
    cfg.loadFormat = tagged Hex "mem.vmh";
    BRAM2PortBE#(Bit#(30), Word, 4) bram <- mkBRAM2ServerBE(cfg);


    SuperscalarCacheInterface superCache <- mkSuperscalarCacheInterface();

    SSRVIfc rv_core <- mksuperscalar;

    FIFO#(SuperCacheReq) ireq <- mkFIFO;
    FIFO#(Mem) dreq <- mkFIFO;
    FIFO#(Mem) mmioreq <- mkFIFO;
    let debug = False;
    Reg#(Bit#(32)) cycle_count <- mkReg(0);

    rule tic;
	    cycle_count <= cycle_count + 1;
    endrule

    rule requestI;
        let req <- rv_core.getIReq;
        if (debug) $display("Get IReq", fshow(req));
        // $display(req);
        // ireq.enq(Mem{byte_en: req.word_byte,  addr: req.addr, data : req.data });
        ireq.enq(req);

        superCache.sendReqInstr(req);

            // bram.portB.request.put(BRAMRequestBE{
            //         writeen: req.byte_en,
            //         responseOnWrite: True,
            //         address: truncate(req.addr >> 2),
            //         datain: req.data});
    endrule

    rule responseI;
        let x <- superCache.getRespInstr();
        // let x <- bram.portB.response.get();
        let superReq = ireq.first();
        let req = Mem{byte_en: superReq.word_byte, addr: superReq.addr, data: superReq.data};
        ireq.deq();
        if (debug) $display("Get IResp ", fshow(req), fshow(x));
        req.data = x.ins1;
        rv_core.getIResp(req);
        if(isValid(x.ins2))begin
            let parsedAddr = parseAddress(req.addr);
            parsedAddr.offset =parsedAddr.offset + superReq.fetchTwo;
            req.addr = {parsedAddr.tag, parsedAddr.index, parsedAddr.offset, 2'b00};
            req.data = fromMaybe(?, x.ins2);
            rv_core.getIResp2(req);
        end
    endrule

    rule requestD;
        let req <- rv_core.getDReq;
        dreq.enq(req);
        if (debug) $display("Get DReq", fshow(req));
        // $display("DATA ",fshow(CacheReq{word_byte: req.byte_en, addr: req.addr, data: req.data}));
        superCache.sendReqData(CacheReq{word_byte: req.byte_en, addr: req.addr, data: req.data});

        // bram.portA.request.put(BRAMRequestBE{
        //   writeen: req.byte_en,
        //   responseOnWrite: True,
        //   address: truncate(req.addr >> 2),
        //   datain: req.data});
    endrule

    rule responseD;
        // let x <- bram.portA.response.get();
        let x <- superCache.getRespData();

        let req = dreq.first();
        dreq.deq();
        if (debug) $display("Get IResp ", fshow(req), fshow(x));
        req.data = x;
            rv_core.getDResp(req);
    endrule
  
    rule requestMMIO;
        let req <- rv_core.getMMIOReq;
        if (debug) $display("Get MMIOReq", fshow(req));
        if (req.byte_en == 'hf) begin
            if (req.addr == 'hf000_fff4) begin
                // Write integer to STDERR
                        $fwrite(stderr, "%0d", req.data);
                        $fflush(stderr);
            end
        end
        if (req.addr ==  'hf000_fff0) begin
                // Writing to STDERR
                $fwrite(stderr, "%c", req.data[7:0]);
                $fflush(stderr);
        end else
            if (req.addr == 'hf000_fff8) begin
                $display("RAN CYCLES", cycle_count);

            // Exiting Simulation
                if (req.data == 0) begin
                        $fdisplay(stderr, "  [0;32mPASS[0m");
                end
                else
                    begin
                        $fdisplay(stderr, "  [0;31mFAIL[0m (%0d)", req.data);
                    end
                $fflush(stderr);
                $finish;
            end

        mmioreq.enq(req);
    endrule

    rule responseMMIO;
        let req = mmioreq.first();
        mmioreq.deq();
        if (debug) $display("Put MMIOResp", fshow(req));
        rv_core.getMMIOResp(req);
    endrule
    
endmodule
