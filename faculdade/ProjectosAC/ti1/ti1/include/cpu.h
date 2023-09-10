//
// Created by Hervé Paulino on 19/03/2022.
//

#ifndef CAOSS_INSTRUCTIONS_H
#define CAOSS_INSTRUCTIONS_H

// 8 registos --> 3 bits
// 32 instruções --> 5 bits
// tamanho --> 1 bits -- 0 w, 1 b

// 2 tipos
// mem  00 inst(1) address(10) reg
// load store
// alu  01 inst(4) t(1) reg1 reg2 reg3
// add, sub, and, or, neg, shl, sha, shr
// int  10 address 14

// format:

typedef enum {
    BYTE = 1,
    WORD = 2,
} op_size;

typedef enum {
    MEMORY=0,
    LOAD_IMMEDIATE=1,
    ALU=2,
    INT=3
} instruction_type;

typedef enum {
    ADD=0,
    SUB=1,
    AND=2,
    OR=3,
    NEG=4, // Two's complement
    NOT=5, // One's complement
    SAR=6, // arithmetic shift
    SAL=7 // arithmetic shift
} alu_opcode;

typedef enum {
    LOAD_MEM=0,
    STORE_MEM=1,
} ls_opcode;



void cpu_run();
void show_registers();

#endif //CAOSS_INSTRUCTIONS_H
