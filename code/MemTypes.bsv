import Vector :: * ;
// Types used in L1 interface
typedef struct { Bit#(1) write; Bit#(26) addr; Bit#(512) data; } MainMemReq deriving (Eq, FShow, Bits, Bounded);
typedef struct { Bit#(4) word_byte; Bit#(32) addr; Bit#(32) data; } CacheReq deriving (Eq, FShow, Bits, Bounded);
typedef struct { Bit#(4) word_byte; Bit#(32) addr; Bit#(32) data; WordOffset fetchTwo;} SuperCacheReq deriving (Eq, FShow, Bits, Bounded);
typedef Bit#(512) MainMemResp;
typedef Bit#(32) Word;

// (Curiosity Question: CacheReq address doesn't actually need to be 32 bits. Why?)

// Helper types for implementation (L1 cache):
typedef enum {
    NotValid= 2'b0,
    Clean = 2'b01,
    Dirty= 2'b10
} LineState deriving (Eq, Bits, FShow);


typedef enum {
    Ready,
    Lookup, 
    Writeback, 
    Allocate
}CacheState deriving (Eq, Bits, FShow);

// You should also define a type for LineTag, LineIndex. Calculate the appropriate number of bits for your design.
typedef Bit#(19) LineTag;
typedef Bit#(7) LineIndex;
typedef Bit#(4) WordOffset;
// You may also want to define a type for WordOffset, since multiple Words can live in a line.

// You can translate between Vector#(16, Word) and Bit#(512) using the pack/unpack builtin functions.
// typedef Vector#(16, Word) LineData;

// Optional: You may find it helpful to make a function to parse an address into its parts.
// e.g.,
typedef struct {
        LineTag tag;
        LineIndex index;
        WordOffset offset;
    } ParsedAddress deriving (Bits, Eq);
    
// typedef Bit#(1) ParsedAddress;  // placeholder

function ParsedAddress parseAddress(Bit#(32) address);
    return ParsedAddress{tag : address[31:13], index : address[12:6], offset : address[5:2]};
endfunction

// and define whatever other types you may find helpful.
function Bit#(512) line_modify(Bit#(512) line, Word in, Bit#(4) word_byte, Bit#(4) offset);
    Vector#(16, Word) line_v = unpack(line);
    Word w = line_v[offset];

    if(word_byte[3] == 1'b1) w[31:24] = in[31:24];
    if(word_byte[2] == 1'b1) w[23:16] = in[23:16];
    if(word_byte[1] == 1'b1) w[15:8] = in[15:8];
    if(word_byte[0] == 1'b1) w[7:0] = in[7:0];

    line_v[offset] = w;

    return pack(line_v);

endfunction

// Helper types for implementation (L2 cache):

typedef Bit#(18) LineTagL2;
typedef Bit#(8) LineIndexL2;

typedef struct {
        LineTagL2 tag;
        LineIndexL2 index;
    } ParsedAddressL2 deriving (Bits, Eq);

function ParsedAddressL2 parseAddressL2(Bit#(26) address);
    return ParsedAddressL2{tag : address[25:8], index : address[7:0]};
endfunction

typedef struct{
    Word ins1; 
    Maybe#(Word) ins2;
} OneOrTwoWords deriving(Bits, Eq, FShow);

// Helper types for BTB:

typedef Bit#(7) BtbIndex;
typedef Bit#(23) BtbTag;
