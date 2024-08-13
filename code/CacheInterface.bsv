// SINGLE CORE CACHE INTERFACE WITH NO PPP
import MainMem::*;
import MemTypes::*;
import Cache32::*;
import Cache512::*;
import FIFOF::*;
import FIFO::*;
import SpecialFIFOs ::*;


interface CacheInterface;
    method Action sendReqData(CacheReq req);
    method ActionValue#(Word) getRespData();
    method Action sendReqInstr(CacheReq req);
    method ActionValue#(Word) getRespInstr();
endinterface


module mkCacheInterface(CacheInterface);
    let verbose = True;
    MainMem mainMem <- mkMainMem(); 
    Cache512 cacheL2 <- mkCache;
    Cache32 cacheI <- mkInstCache;
    Cache32 cacheD <- mkCache32;

    // You need to add rules and/or state elements.
    FIFOF#(MainMemReq) instReq <- mkFIFOF;
    FIFOF#(MainMemReq) dataReq <- mkFIFOF;
    FIFO#(Bool)   isInstReq <- mkFIFO;

    // ideally these rules happens first:
    rule getInstMiss;
        let mem_req <- cacheI.getToMem();
        instReq.enq(mem_req); 
    endrule

    rule getDataMiss; 
        let mem_req <- cacheD.getToMem();
        dataReq.enq(mem_req);
    endrule

    // and then these follow afterwards
    rule processL1Misses; 
        if(instReq.notEmpty())begin
            // read the instruction request
            let req = instReq.first();
            instReq.deq(); 

            // send it to the L2 cache
            // $display("current request", fshow(req));
            cacheL2.putFromProc(req);

            // update the InstReq queue to reflect that we are now handling an Instruction request
            // $display("L1 inst miss");
            isInstReq.enq(True);
        end else if(dataReq.notEmpty())begin
            // read the data request
            let req = dataReq.first();
            dataReq.deq();

            // send it to the L2 cache
            cacheL2.putFromProc(req);

            // update the InstReq so we know we are not handling an Instruction request (ie handling a data request)
            isInstReq.enq(False);
        end
    endrule

    rule processL2Response;
        // need to use arrow cuz get to proc is an action value
        // $display("sending a response to an L1 cache");
        let resp <- cacheL2.getToProc();
         
        if(isInstReq.first())begin
            cacheI.putFromMem(resp);
        end else begin
            cacheD.putFromMem(resp);
        end

        isInstReq.deq();
    endrule


    rule reqFromL2ToMem;
        // $display("sending a main mem request");

        let req <- cacheL2.getToMem();
        mainMem.put(req);
    endrule

    rule respFromMemtoL2;
        // $display("got a mainmem response");
        let resp <- mainMem.get();
        cacheL2.putFromMem(resp);
    endrule
    


    method Action sendReqData(CacheReq req);
        cacheD.putFromProc(req);
    endmethod

    method ActionValue#(Word) getRespData() ;
        let resp <- cacheD.getToProc();
        return resp;
    endmethod


    method Action sendReqInstr(CacheReq req);
        cacheI.putFromProc(req);
    endmethod

    method ActionValue#(Word) getRespInstr();
        let resp <- cacheI.getToProc();
        return resp;
    endmethod
endmodule

interface SuperscalarCacheInterface;
    method Action sendReqData(CacheReq req);
    method ActionValue#(Word) getRespData();
    method Action sendReqInstr(SuperCacheReq req);
    method ActionValue#(OneOrTwoWords) getRespInstr();
endinterface


module mkSuperscalarCacheInterface(SuperscalarCacheInterface);
    let verbose = True;
    MainMem mainMem <- mkMainMem(); 
    Cache512 cacheL2 <- mkCache;
    SuperscalarInstCache32 cacheI <- mkSuperscalarInstCache32;
    Cache32 cacheD <- mkCache32;

    // You need to add rules and/or state elements.
    FIFOF#(MainMemReq) instReq <- mkFIFOF;
    FIFOF#(MainMemReq) dataReq <- mkFIFOF;
    FIFO#(Bool)   isInstReq <- mkFIFO;

    // ideally these rules happens first:
    rule getInstMiss;
        let mem_req <- cacheI.getToMem();
        instReq.enq(mem_req); 
    endrule

    rule getDataMiss; 
        let mem_req <- cacheD.getToMem();
        dataReq.enq(mem_req);
    endrule

    // and then these follow afterwards
    rule processL1Misses; 
        if(instReq.notEmpty())begin
            // read the instruction request
            let req = instReq.first();
            instReq.deq(); 

            // send it to the L2 cache
            // $display("current request", fshow(req));
            cacheL2.putFromProc(req);

            // update the InstReq queue to reflect that we are now handling an Instruction request
            // $display("L1 inst miss");
            isInstReq.enq(True);
        end else if(dataReq.notEmpty())begin
            // read the data request
            let req = dataReq.first();
            dataReq.deq();

            // send it to the L2 cache
            cacheL2.putFromProc(req);

            // update the InstReq so we know we are not handling an Instruction request (ie handling a data request)
            isInstReq.enq(False);
        end
    endrule

    rule processL2Response;
        // need to use arrow cuz get to proc is an action value
        // $display("sending a response to an L1 cache");
        let resp <- cacheL2.getToProc();
         
        if(isInstReq.first())begin
            cacheI.putFromMem(resp);
        end else begin
            cacheD.putFromMem(resp);
        end

        isInstReq.deq();
    endrule


    rule reqFromL2ToMem;
        // $display("sending a main mem request");

        let req <- cacheL2.getToMem();
        mainMem.put(req);
    endrule

    rule respFromMemtoL2;
        // $display("got a mainmem response");
        let resp <- mainMem.get();
        cacheL2.putFromMem(resp);
    endrule
    


    method Action sendReqData(CacheReq req);
        cacheD.putFromProc(req);
    endmethod

    method ActionValue#(Word) getRespData() ;
        let resp <- cacheD.getToProc();
        return resp;
    endmethod


    method Action sendReqInstr(SuperCacheReq req);
        cacheI.putFromProc(req);
    endmethod

    method ActionValue#(OneOrTwoWords) getRespInstr();
        let resp <- cacheI.getToProc();
        return resp;
    endmethod
endmodule
