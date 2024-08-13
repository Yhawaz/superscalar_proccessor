.section ".text.init"
    .globl _start
    .globl exit
    .globl main
    .globl print_char
    .globl load_arg
_start:
    // initialize global pointer
    // la gp, _gp
    li gp, 0
    li  x1, 0
    li  x2, 0
    li  x3, 0
    li  x4, 0
    li  x5, 0
    li  x6, 0
    li  x7, 0
    li  x8, 0
    li  x9, 0
    li  x10,0
    li  x11,0
    li  x12,0
    li  x13,0
    li  x14,0
    li  x15,0
    li  x16,0
    li  x17,0
    li  x18,0
    li  x19,0
    li  x20,0
    li  x21,0
    li  x22,0
    li  x23,0
    li  x24,0
    li  x25,0
    li  x26,0
    li  x27,0
    li  x28,0
    li  x29,0
    li  x30,0
  li  x31,0
    // initialize stack pointer
    // hard-code sp to the top of memory (assuming 64 KB)
    li sp, 0x80000

    call main
    # li x10, 0
    j exit

print_char:
    andi t0, a0, 0xff
    li t1, 0xf000fff0
    sw t0, 0(t1)
    ret

load_arg:
    li t0, 0x40003000
    lw a0, 0(t0)
    ret

exit:
    li t0, 0xf000fff8; 
    sw a0, 0(t0)

exit_loop:
    beq x0, x0, exit_loop
