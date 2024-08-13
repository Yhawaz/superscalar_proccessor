import BRAM::*;
import FIFO::*;
import FIFOF::*;
import SpecialFIFOs::*;
import MemTypes::*;
import Ehr::*;

// Note that this interface *is* symmetric. 
interface Cache512;
    method Action putFromProc(MainMemReq e);
    method ActionValue#(MainMemResp) getToProc();
    method ActionValue#(MainMemReq) getToMem();
    method Action putFromMem(MainMemResp e);
endinterface

// delete when you're done with it
// typedef Bit#(1) PLACEHOLDER;

(* synthesize *)
module mkCache(Cache512);
    BRAM_Configure cfg = defaultValue;
    cfg.loadFormat = tagged Binary "zero512.vmh";  // zero out for you

    // Rename this to a meaningful name if you're keeping it, or adding more.
    BRAM1Port#(LineIndexL2, Bit#(512)) dataArray <- mkBRAM1Server(cfg);  // also a placeholder
    BRAM1Port#(LineIndexL2, LineTagL2) tagArray <- mkBRAM1Server(cfg);  // also a placeholder
    BRAM1Port#(LineIndexL2, LineState) statusArray <- mkBRAM1Server(cfg);  // also a placeholder

    // You may instead find it useful to use the CacheArrayUnit abstraction presented
    // in lecture. In that case, most of your logic would be in that module, which you 
    // can instantiate within this one.

    // Hint: Refer back to the slides for implementation details.
    // Hint: You may find it helpful to outline the necessary states and rules you'll need for your cache
    // Hint: Don't forget about $display
    // Hint: If you want to add in a store buffer, do it after getting it working without one.

    FIFO#(MainMemReq) fromProc <- mkBypassFIFO;
    FIFO#(MainMemResp) toProc <- mkBypassFIFO;

    FIFO#(MainMemReq) toMem <- mkBypassFIFO;
    FIFO#(MainMemResp) fromMem <- mkBypassFIFO;

    Reg#(CacheState) curState <- mkReg(Ready);
    Reg#(MainMemReq) curReq <-  mkRegU;

    // rule disp; 
    //     $display("L2 state: ", curState);
    // endrule
    
    rule ready if (curState == Ready);
        let r = fromProc.first();
        fromProc.deq();

        let pa = parseAddressL2(r.addr);

        let ind = pa.index;
        dataArray.portA.request.put(BRAMRequest{write: False, // 0 for read
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
        curReq <= r;
    endrule

    rule lookup if (curState == Lookup);
        let r = curReq;
        let pa = parseAddressL2(r.addr);
        let ind = pa.index;

        let lineData <- dataArray.portA.response.get();
        let statusData <- statusArray.portA.response.get();
        let tagData <- tagArray.portA.response.get();

        // hit
        if( statusData != NotValid && tagData == pa.tag)begin
            if(r.write != 0)begin

                dataArray.portA.request.put(BRAMRequest{write: True, // 0 for read
                                                    responseOnWrite: False,
                                                    address: ind,  
                                                    datain: r.data});  

                statusArray.portA.request.put(BRAMRequest{write : True, 
                                                    responseOnWrite : False, 
                                                    address : ind, 
                                                    datain : Dirty});
                toProc.enq(0);
            end else begin
                toProc.enq(lineData);
            end

            curState <= Ready;
        end else if( statusData != Dirty) begin
            let mem_req = MainMemReq{write : 1'b0, addr : {pa.tag, pa.index}, data : ?};
            
            toMem.enq(mem_req);
            curState <= Allocate;
        end else begin
            let mem_req = MainMemReq{write : 1'b1, addr : {tagData, pa.index}, data : lineData};

            toMem.enq(mem_req);
            curState <= Writeback;
        end
    endrule

    rule writeback if(curState == Writeback);
        let r = curReq;
        let pa = parseAddressL2(r.addr);

        fromMem.deq();

        let mem_req = MainMemReq{write : 1'b0, addr : {pa.tag, pa.index}, data : ?};
                
        toMem.enq(mem_req);
        curState <= Allocate;
    endrule

    rule allocate if (curState == Allocate);
        let r = curReq;
        let pa = parseAddressL2(r.addr);
        let ind = pa.index;

        Bit#(512) mem_line = fromMem.first(); 

        Bit#(64) writeen_in = signExtend(1'b1);

        if(r.write != 0)begin
            // $display("doing a write");
            toProc.enq(0);
            dataArray.portA.request.put(BRAMRequest{write: True, // 0 for read
                                                responseOnWrite: False,
                                                address: ind,  
                                                datain: r.data});  

            statusArray.portA.request.put(BRAMRequest{write : True, 
                                                responseOnWrite : False, 
                                                address : ind, 
                                                datain : Dirty});

            tagArray.portA.request.put(BRAMRequest{write : True, 
                                                responseOnWrite : False, 
                                                address : ind, 
                                                datain : pa.tag});
        end else begin
            // $display("doing a read");
            toProc.enq(mem_line);
            dataArray.portA.request.put(BRAMRequest{write: True, // 0 for read
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
        fromMem.deq();
    endrule


    method Action putFromProc(MainMemReq e);
        fromProc.enq(e);
    endmethod
        
    method ActionValue#(MainMemResp) getToProc();
        // $display("sending to L1");
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
