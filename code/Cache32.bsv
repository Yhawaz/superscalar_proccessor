// SINGLE CORE ASSOIATED CACHE -- stores words

import BRAM::*;
import FIFO::*;
import FIFOF::*;
import SpecialFIFOs::*;
import MemTypes::*;
import Ehr::*;
import Vector :: * ;

// The types live in MemTypes.bsv

// Notice the asymmetry in this interface, as mentioned in lecture.
// The processor thinks in 32 bits, but the other side thinks in 512 bits.
interface Cache32;
    method Action putFromProc(CacheReq e);
    method ActionValue#(Word) getToProc();
    method ActionValue#(MainMemReq) getToMem();
    method Action putFromMem(MainMemResp e);
endinterface


(* synthesize *)
module mkCache32(Cache32);
    BRAM_Configure cfg = defaultValue;
    cfg.loadFormat = tagged Binary "zero.vmh";  // zero out for you

    // Did you make sure to define your data types in MemTypes.bsv? It will help you debug if you use types.

    // Hint 1: one way is to have one BRAM for each of data, state, and tag.
    // Hint 2: The index into all of your BRAMs should be the same.
    // Hint 3: Define additional types and structs as necessary.
    
    // Rename these to meaningful names if you're keeping them.
    // the second argument is the type being held, and the first argument is the address type (3rd would be byte enable specifics)
    // BRAM1Port#(PLACEHOLDER, PLACEHOLDER) example_bram1 <- mkBRAM1Server(cfg);
    BRAM1PortBE#(LineIndex, Bit#(512), 64) dataArray <- mkBRAM1ServerBE(cfg);  // also a placeholder
    BRAM1Port#(LineIndex, LineTag) tagArray <- mkBRAM1Server(cfg);  // also a placeholder
    BRAM1Port#(LineIndex, LineState) statusArray <- mkBRAM1Server(cfg);  // also a placeholder

    // You may instead find it useful to use the CacheArrayUnit abstraction presented
    // in lecture. In that case, most of your logic would be in that module, which you 
    // can instantiate within this one.

    // Hint: Refer back to the slides for implementation details.
    // Hint: You may find it helpful to outline the necessary states and rules you'll need for your cache
    // Hint: Don't forget about $display
    // Hint: If you want to add in a store buffer, do it after getting it working without one.

    FIFO#(CacheReq) curReq <- mkFIFO;
    FIFO#(Word) toProc <- mkBypassFIFO;

    FIFO#(MainMemReq) toMem <- mkBypassFIFO;
    FIFO#(MainMemResp) fromMem <- mkBypassFIFO;

    Reg#(CacheState) curState <- mkReg(Ready);


    
    rule ready if (curState == Ready);
        let r = curReq.first();
        let pa = parseAddress(r.addr);

        let ind = pa.index;
        dataArray.portA.request.put(BRAMRequestBE{writeen: 64'b0, // 0 for read
                            responseOnWrite: False,
                            address: ind,  
                            datain: ?}); 

        statusArray.portA.request.put(BRAMRequest{write: False, // False for read
                            responseOnWrite: False,
                            address: ind,  
                            datain: ?}); 

        tagArray.portA.request.put(BRAMRequest{write: False, // False for read
                            responseOnWrite: False,
                            address: ind,  
                            datain: ?}); 

        curState <= Lookup;
    endrule

    rule lookup if (curState == Lookup);
        let r = curReq.first();
        let pa = parseAddress(r.addr);
        let ind = pa.index;

        let lineData <- dataArray.portA.response.get();
        let statusData <- statusArray.portA.response.get();
        let tagData <- tagArray.portA.response.get();
        // if (r.word_byte  != 0) $display("write request with req: ", fshow(r));
        // $display("32 cache current status: ", fshow(statusData));

        // hit
        if( statusData != NotValid && tagData == pa.tag)begin
            if(r.word_byte != 0)begin

                // make a vector the same size in bits as the writeen 
                Vector#(16, Bit#(4)) writeen_v = unpack(0);
                Vector#(16, Word) line_v = unpack(0);

                line_v[pa.offset] = r.data;
                writeen_v[pa.offset] = r.word_byte;

                // send the writeen bits back to bits, from vector
                Bit#(64) one_hot = pack(writeen_v);
                Bit#(512) data_bits = pack(line_v);

                dataArray.portA.request.put(BRAMRequestBE{writeen: one_hot, // 0 for read
                                                    responseOnWrite: False,
                                                    address: ind,  
                                                    datain: data_bits});  

                statusArray.portA.request.put(BRAMRequest{write : True, 
                                                    responseOnWrite : False, 
                                                    address : ind, 
                                                    datain : Dirty});


                toProc.enq(0);
            end else begin
                Vector#(16, Word) line_v = unpack(lineData);
                toProc.enq(line_v[pa.offset]);
            end

            curReq.deq(); // don't need to handle this request anymore
            curState <= Ready;
        end else if( statusData != Dirty) begin
            let mem_req = MainMemReq{write : 1'b0, addr : {pa.tag, pa.index}, data : ?};
            
            toMem.enq(mem_req);
            curState <= Allocate;
        end else begin
            let mem_req = MainMemReq{write : 1'b1, addr : {tagData, pa.index}, data : lineData};
            // $display("writeback");
            toMem.enq(mem_req);
            curState <= Writeback;
        end
    endrule

    rule writeback if(curState == Writeback);
        let r = curReq.first();
        let pa = parseAddress(r.addr);

        fromMem.deq();
        let mem_req = MainMemReq{write : 1'b0, addr : {pa.tag, pa.index}, data : ?};
                
        toMem.enq(mem_req);
        curState <= Allocate;
    endrule

    rule allocate if (curState == Allocate);
        let r = curReq.first();
        let pa = parseAddress(r.addr);
        let ind = pa.index;

        Bit#(512) mem_line = fromMem.first(); 

        Bit#(64) writeen_in = signExtend(1'b1);

        if(r.word_byte != 0)begin
            toProc.enq(0);
            Bit#(512) new_data = line_modify(mem_line, r.data, r.word_byte, pa.offset);


            dataArray.portA.request.put(BRAMRequestBE{writeen: writeen_in, // 0 for read
                                                responseOnWrite: False,
                                                address: ind,  
                                                datain: new_data});  

            statusArray.portA.request.put(BRAMRequest{write : True, 
                                                responseOnWrite : False, 
                                                address : ind, 
                                                datain : Dirty});

            tagArray.portA.request.put(BRAMRequest{write : True, 
                                                responseOnWrite : False, 
                                                address : ind, 
                                                datain : pa.tag});
        end else begin
            Vector#(16, Word) line_v = unpack(mem_line);
            toProc.enq(line_v[pa.offset]);
            dataArray.portA.request.put(BRAMRequestBE{writeen: writeen_in, // 0 for read
                                                responseOnWrite: False,
                                                address: ind,  
                                                datain: mem_line});  

            statusArray.portA.request.put(BRAMRequest{write : True, 
                                                responseOnWrite : False, 
                                                address : ind, 
                                                datain : Clean});

            tagArray.portA.request.put(BRAMRequest{write : True, 
                                                responseOnWrite : False, 
                                                address : ind, 
                                                datain : pa.tag});
        end

        curState <= Ready;
        curReq.deq();
        fromMem.deq();
    endrule


    method Action putFromProc(CacheReq e);
        curReq.enq(e);
    endmethod
        
    method ActionValue#(Word) getToProc();
        let ret = toProc.first();
        toProc.deq();
        return ret;
    endmethod
        
    method ActionValue#(MainMemReq) getToMem();
        let ret = toMem.first();
        toMem.deq();
        return ret;
    endmethod
        
    method Action putFromMem(MainMemResp e);
        fromMem.enq(e);
    endmethod

endmodule

// (* synthesize *)
module mkInstCache(Cache32);
    BRAM_Configure cfg = defaultValue;
    cfg.loadFormat = tagged Binary "zero.vmh";  // zero out for you

    // BRAM1Port#(PLACEHOLDER, PLACEHOLDER) example_bram1 <- mkBRAM1Server(cfg);
    BRAM1PortBE#(LineIndex, Bit#(512), 64) dataArray <- mkBRAM1ServerBE(cfg);  // also a placeholder
    BRAM1Port#(LineIndex, LineTag) tagArray <- mkBRAM1Server(cfg);  // also a placeholder
    BRAM1Port#(LineIndex, LineState) statusArray <- mkBRAM1Server(cfg);  // also a placeholder


    FIFO#(CacheReq) fromProc <- mkBypassFIFO;
    FIFO#(Word) toProc <- mkBypassFIFO;

    FIFO#(MainMemReq) toMem <- mkBypassFIFO;
    FIFO#(MainMemResp) fromMem <- mkBypassFIFO;

    Ehr#(2, CacheState) curState <- mkEhr(Ready);
    Ehr#(3, Bool) isHit <- mkEhr(False);

    Reg#(CacheReq) curReq <- mkRegU;
    Reg#(Word) cycles <- mkReg(0);
    rule cycle_count;
        cycles <= cycles + 1;
    endrule

    rule reset_isHit;
        isHit[2] <= False;
    endrule
    
    rule ready if (curState[0] == Ready);
        let r = fromProc.first();
        fromProc.deq();

        let pa = parseAddress(r.addr);

        let ind = pa.index;
        dataArray.portA.request.put(BRAMRequestBE{writeen: 64'b0, // 0 for read
                            responseOnWrite: False,
                            address: ind,  
                            datain: ?}); 

        statusArray.portA.request.put(BRAMRequest{write: False, // False for read
                            responseOnWrite: False,
                            address: ind,  
                            datain: ?}); 

        tagArray.portA.request.put(BRAMRequest{write: False, // False for read
                            responseOnWrite: False,
                            address: ind,  
                            datain: ?}); 

        curState[0] <= Lookup;
        curReq <= r;
    endrule

    rule override if (isHit[1]);
        
        if(curState[1] == Ready)begin // means we had a hit
            let new_r = fromProc.first();
            fromProc.deq();

            let new_pa = parseAddress(new_r.addr);

            let new_ind = new_pa.index;
            dataArray.portA.request.put(BRAMRequestBE{writeen: 64'b0, // 0 for read
                                responseOnWrite: False,
                                address: new_ind,  
                                datain: ?}); 

            statusArray.portA.request.put(BRAMRequest{write: False, // False for read
                                responseOnWrite: False,
                                address: new_ind,  
                                datain: ?}); 

            tagArray.portA.request.put(BRAMRequest{write: False, // False for read
                                responseOnWrite: False,
                                address: new_ind,  
                                datain: ?}); 

            curReq <= new_r;

            // // still gotta handle da loads

            // //fancy 
            curState[1] <= Lookup;
        end 
    endrule

    rule lookup if (curState[0] == Lookup);
        let r = curReq;
        let pa = parseAddress(r.addr);
        let ind = pa.index;

        let lineData <- dataArray.portA.response.get();
        let statusData <- statusArray.portA.response.get();
        let tagData <- tagArray.portA.response.get();
        // if (r.word_byte  != 0) $display("write request with req: ", fshow(r));
        // $display("32 cache current status: ", fshow(statusData));

        // hit
        if( statusData != NotValid && tagData == pa.tag)begin
            isHit[0] <= True;
            Vector#(16, Word) line_v = unpack(lineData);
            toProc.enq(line_v[pa.offset]);
   

            // lame
            curState[0] <= Ready;

        end else begin
            let mem_req = MainMemReq{write : 1'b0, addr : {pa.tag, pa.index}, data : ?};
            
            isHit[0] <= False;
            toMem.enq(mem_req);
            curState[0] <= Allocate;
        end
    endrule


    rule allocate if (curState[0] == Allocate);
        let r = curReq;
        let pa = parseAddress(r.addr);
        let ind = pa.index;

        Bit#(512) mem_line = fromMem.first(); 

        Bit#(64) writeen_in = signExtend(1'b1);

            Vector#(16, Word) line_v = unpack(mem_line);
            toProc.enq(line_v[pa.offset]);
            dataArray.portA.request.put(BRAMRequestBE{writeen: writeen_in, // 0 for read
                                                responseOnWrite: False,
                                                address: ind,  
                                                datain: mem_line});  

            statusArray.portA.request.put(BRAMRequest{write : True, 
                                                responseOnWrite : False, 
                                                address : ind, 
                                                datain : Clean});

            tagArray.portA.request.put(BRAMRequest{write : True, 
                                                responseOnWrite : False, 
                                                address : ind, 
                                                datain : pa.tag});

        curState[0] <= Ready;
        fromMem.deq();
    endrule


    method Action putFromProc(CacheReq e);
        fromProc.enq(e);
    endmethod
        
    method ActionValue#(Word) getToProc();

        let ret = toProc.first();
        toProc.deq();
        return ret;
    endmethod
        
    method ActionValue#(MainMemReq) getToMem();
        let ret = toMem.first();
        toMem.deq();
        return ret;
    endmethod
        
    method Action putFromMem(MainMemResp e);
        fromMem.enq(e);
    endmethod

endmodule



interface SuperscalarInstCache32;
    method Action putFromProc(SuperCacheReq e);
    method ActionValue#(OneOrTwoWords) getToProc();
    method ActionValue#(MainMemReq) getToMem();
    method Action putFromMem(MainMemResp e);
endinterface

module mkSuperscalarInstCache32(SuperscalarInstCache32);
    BRAM_Configure cfg = defaultValue;
    cfg.loadFormat = tagged Binary "zero.vmh";  // zero out for you

    // BRAM1Port#(PLACEHOLDER, PLACEHOLDER) example_bram1 <- mkBRAM1Server(cfg);
    BRAM1PortBE#(LineIndex, Bit#(512), 64) dataArray <- mkBRAM1ServerBE(cfg);  // also a placeholder
    BRAM1Port#(LineIndex, LineTag) tagArray <- mkBRAM1Server(cfg);  // also a placeholder
    BRAM1Port#(LineIndex, LineState) statusArray <- mkBRAM1Server(cfg);  // also a placeholder


    FIFO#(SuperCacheReq) fromProc <- mkBypassFIFO;
    FIFO#(OneOrTwoWords) toProc <- mkBypassFIFO;

    FIFO#(MainMemReq) toMem <- mkBypassFIFO;
    FIFO#(MainMemResp) fromMem <- mkBypassFIFO;

    Ehr#(2, CacheState) curState <- mkEhr(Ready);
    Ehr#(3, Bool) isHit <- mkEhr(False);

    Reg#(SuperCacheReq) curReq <- mkRegU;
    Reg#(Word) cycles <- mkReg(0);
    rule cycle_count;
        cycles <= cycles + 1;
    endrule

    rule reset_isHit;
        isHit[2] <= False;
    endrule
    
    rule ready if (curState[0] == Ready);
        let r = fromProc.first();
        fromProc.deq();

        let pa = parseAddress(r.addr);

        let ind = pa.index;
        dataArray.portA.request.put(BRAMRequestBE{writeen: 64'b0, // 0 for read
                            responseOnWrite: False,
                            address: ind,  
                            datain: ?}); 

        statusArray.portA.request.put(BRAMRequest{write: False, // False for read
                            responseOnWrite: False,
                            address: ind,  
                            datain: ?}); 

        tagArray.portA.request.put(BRAMRequest{write: False, // False for read
                            responseOnWrite: False,
                            address: ind,  
                            datain: ?}); 

        curState[0] <= Lookup;
        curReq <= r;
    endrule

    rule override if (isHit[1]);
        
        if(curState[1] == Ready)begin // means we had a hit
            let new_r = fromProc.first();
            fromProc.deq();

            let new_pa = parseAddress(new_r.addr);

            let new_ind = new_pa.index;
            dataArray.portA.request.put(BRAMRequestBE{writeen: 64'b0, // 0 for read
                                responseOnWrite: False,
                                address: new_ind,  
                                datain: ?}); 

            statusArray.portA.request.put(BRAMRequest{write: False, // False for read
                                responseOnWrite: False,
                                address: new_ind,  
                                datain: ?}); 

            tagArray.portA.request.put(BRAMRequest{write: False, // False for read
                                responseOnWrite: False,
                                address: new_ind,  
                                datain: ?}); 

            curReq <= new_r;

            // // still gotta handle da loads

            // //fancy 
            curState[1] <= Lookup;
        end 
    endrule

    rule lookup if (curState[0] == Lookup);
        let r = curReq;
        let pa = parseAddress(r.addr);
        let ind = pa.index;

        let lineData <- dataArray.portA.response.get();
        let statusData <- statusArray.portA.response.get();
        let tagData <- tagArray.portA.response.get();
        // if (r.word_byte  != 0) $display("write request with req: ", fshow(r));
        // $display("32 cache current status: ", fshow(statusData));

        // hit
        if( statusData != NotValid && tagData == pa.tag)begin
            isHit[0] <= True;
            Vector#(16, Word) line_v = unpack(lineData);

            OneOrTwoWords ret;
            ret.ins1 = line_v[pa.offset];
            let next = pa.offset + r.fetchTwo;

            if (r.fetchTwo != 0) begin
                ret.ins2 = Valid(line_v[next]);
            end else begin
                ret.ins2 = Invalid;
            end

            toProc.enq(ret);
   

            // lame
            curState[0] <= Ready;

        end else begin
            let mem_req = MainMemReq{write : 1'b0, addr : {pa.tag, pa.index}, data : ?};
            
            isHit[0] <= False;
            toMem.enq(mem_req);
            curState[0] <= Allocate;
        end
    endrule


    rule allocate if (curState[0] == Allocate);
        let r = curReq;
        let pa = parseAddress(r.addr);
        let ind = pa.index;

        Bit#(512) mem_line = fromMem.first(); 

        Bit#(64) writeen_in = signExtend(1'b1);

        Vector#(16, Word) line_v = unpack(mem_line);
       
        OneOrTwoWords ret;
        ret.ins1 = line_v[pa.offset];
        let next = pa.offset + r.fetchTwo;

        if (r.fetchTwo != 0) begin
            ret.ins2 = Valid(line_v[next]);
        end else begin
            ret.ins2 = Invalid;
        end

        toProc.enq(ret);

        dataArray.portA.request.put(BRAMRequestBE{writeen: writeen_in, // 0 for read
                                            responseOnWrite: False,
                                            address: ind,  
                                            datain: mem_line});  

        statusArray.portA.request.put(BRAMRequest{write : True, 
                                            responseOnWrite : False, 
                                            address : ind, 
                                            datain : Clean});

        tagArray.portA.request.put(BRAMRequest{write : True, 
                                            responseOnWrite : False, 
                                            address : ind, 
                                            datain : pa.tag});

        curState[0] <= Ready;
        fromMem.deq();
    endrule


    method Action putFromProc(SuperCacheReq e);
        fromProc.enq(e);
    endmethod
        
    method ActionValue#(OneOrTwoWords) getToProc();

        let ret = toProc.first();
        toProc.deq();
        return ret;
    endmethod
        
    method ActionValue#(MainMemReq) getToMem();
        let ret = toMem.first();
        toMem.deq();
        return ret;
    endmethod
        
    method Action putFromMem(MainMemResp e);
        fromMem.enq(e);
    endmethod 

endmodule
