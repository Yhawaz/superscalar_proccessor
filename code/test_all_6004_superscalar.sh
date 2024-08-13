#!/bin/bash

echo testing add
./run_6004_superscalar.sh fullasmtests/add

echo testing addi
./run_6004_superscalar.sh fullasmtests/addi

echo testing and
./run_6004_superscalar.sh fullasmtests/and

echo testing andi
./run_6004_superscalar.sh fullasmtests/andi

echo testing auipc
./run_6004_superscalar.sh fullasmtests/auipc

echo testing beq
./run_6004_superscalar.sh fullasmtests/beq

echo testing bge
./run_6004_superscalar.sh fullasmtests/bge

echo testing bgeu
./run_6004_superscalar.sh fullasmtests/bgeu

echo testing blt
./run_6004_superscalar.sh fullasmtests/blt

echo testing bltu
./run_6004_superscalar.sh fullasmtests/bltu

echo testing bne
./run_6004_superscalar.sh fullasmtests/bne

echo testing bpred_bht
./run_6004_superscalar.sh fullasmtests/bpred_bht

echo testing bpred_j_noloop
./run_6004_superscalar.sh fullasmtests/bpred_j_noloop

echo testing bpred_j
./run_6004_superscalar.sh fullasmtests/bpred_j

echo testing bpred_ras
./run_6004_superscalar.sh fullasmtests/bpred_ras

echo testing cache
./run_6004_superscalar.sh fullasmtests/cache

echo testing j
./run_6004_superscalar.sh fullasmtests/j

echo testing jal
./run_6004_superscalar.sh fullasmtests/jal

echo testing jalr
./run_6004_superscalar.sh fullasmtests/jalr

echo testing lui
./run_6004_superscalar.sh fullasmtests/lui

echo testing lw
./run_6004_superscalar.sh fullasmtests/lw

echo testing or
./run_6004_superscalar.sh fullasmtests/or

echo testing ori
./run_6004_superscalar.sh fullasmtests/ori

echo testing simple
./run_6004_superscalar.sh fullasmtests/simple

echo testing sll
./run_6004_superscalar.sh fullasmtests/sll

echo testing slli
./run_6004_superscalar.sh fullasmtests/slli

echo testing slt
./run_6004_superscalar.sh fullasmtests/slt

echo testing slti
./run_6004_superscalar.sh fullasmtests/slti

echo testing sra
./run_6004_superscalar.sh fullasmtests/sra

echo testing srai
./run_6004_superscalar.sh fullasmtests/srai

echo testing srl
./run_6004_superscalar.sh fullasmtests/srl

echo testing srli
./run_6004_superscalar.sh fullasmtests/srli

echo testing sub
./run_6004_superscalar.sh fullasmtests/sub

echo testing sw
./run_6004_superscalar.sh fullasmtests/sw

echo testing xor
./run_6004_superscalar.sh fullasmtests/xor

echo testing xori
./run_6004_superscalar.sh fullasmtests/xori

