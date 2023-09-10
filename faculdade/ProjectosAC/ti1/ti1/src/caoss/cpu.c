//
// Created by Hervé Paulino on 19/03/2022.
//

#include "types.h"
#include "memory.h"
#include "cpu.h"
#include "alu.h"
#include "os.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

// Registers
caoss_word registers[NREGISTERS];
caoss_address pc = 0;
caoss_instruction ir;


/**
 * Uses read_code to load instruction at code[pc] to ir (the instruction register)
 */
//=========================================Ja PASSEI POR AQUI.=============================
void fetch() {
    read_code(pc,&ir);
}

//=========================================Ja PASSEI POR AQUI.=============================
void memory_operation(ls_opcode instruction_type, caoss_address adress,byte regId) {
    // TODO: decode the instruction. Put in variable opcode the identifier of the instruction in register ir.
    ls_opcode opcode = instruction_type; //TODO
    caoss_word address = adress;  // TODO
    byte reg = regId;  // TODO

#ifdef DEBUG
    print_load_store(ir, opcode, address, reg);
#endif

    switch (opcode) {
        case LOAD_MEM:
            read_data(address, &registers[reg]);
            break;

        case STORE_MEM:
            write_data(registers[reg], address);
            break;
    }
}

//=========================================Ja PASSEI POR AQUI.=============================
void load_immediate_operation(caoss_word valueVar, byte regId) {

    caoss_word value = valueVar; // TODO
    if (value & 0x0400) // extend the signal to 16 bytes, to support negative numbers
        value = value | 0xF800;
    byte reg = regId; // TODO

#ifdef DEBUG
    print_load_immediate(ir, value, reg);
#endif

    registers[reg] = value;
}


//=========================================JaPASSEI POR AQUI.=============================

void alu_operation(alu_opcode opId,op_size sizeId,byte regId1, byte regId2, byte regIdOut) {

    // TODO: decode the instruction. Put in variable opcode the identifier of the instruction in register ir.
    alu_opcode opcode =  opId; // TODO
    op_size size =  sizeId; // TODO
    byte reg_in_1 = regId1; // TODO
    byte reg_out =  regIdOut; // TODO

    if (is_binary_operation(opcode)) {
            // Binary operation
            byte reg_in_2 =  regId2; // TODO

#ifdef DEBUG
        print_alu_instruction(ir, opcode, size, reg_in_1, reg_in_2, reg_out);
#endif

            size = size+1; // convert bit value (0/1) to actual size in bytes (1/2)

            switch (opcode) {
                case ADD:
                    add(size, reg_in_1, reg_in_2, reg_out);
                    break;
                case SUB:
                    sub(size, reg_in_1, reg_in_2, reg_out);
                    break;
                case AND:
                    and(size, reg_in_1, reg_in_2, reg_out);
                    break;
                case OR:
                    or(size, reg_in_1, reg_in_2, reg_out);
                    break;
                case SAR:
                    sar(size, reg_in_1, reg_in_2, reg_out);
                    break;
                case SAL:
                    sal(size, reg_in_1, reg_in_2, reg_out);
                    break;

                default:
                    error("Unknown opcode\n");
            }
        }
        else {
            // unary operation

#ifdef DEBUG
        print_alu_instruction(ir, opcode, size, reg_in_1, 0, reg_out);
#endif
            size = size+1; // convert bit value (0/1) to actual size in bytes (1/2)
            switch (opcode) {
                case NEG:
                    neg(size, reg_in_1, reg_out);
                    break;
                case NOT:
                    not(size, reg_in_1, reg_out);
                    break;

                default:
                    error("Unknown opcode\n");
            }
    }

}


void interrupt_operation() {

    caoss_word int_number = (byte) (ir & 0X3FFF); // 0011 1111 1111 1111

#ifdef DEBUG
    print_interrupt(ir, int_number);
#endif

    switch (int_number) {
        case 0:
            syscall(registers[0]);
            break;

        default:
            fprintf(stderr, "%s: invalid interrupt %d\n", CAOSS_ERROR, int_number);
            exit(1);
    }
}
//ssssss

/**
 * Decode the instruction in ir and call the respective function to carry out the operation's execution
 */
void decode_and_execute() {

#ifdef DEBUG
    printf ("Decoding instruction 0x%x at address %d\n", ir, pc);
#endif

instruction_type inst_type= (ir&0xc000)>>14;//1100 0000 0000 0000;

    switch (inst_type) {
        case MEMORY:{
        ls_opcode code=(ir&0x2000)>>13; //0010 0000 0000 0000;
        caoss_address address= (ir&0x1ff8)>>3; //0001 1111 1111 1000;
        byte reg= ir&0x0007; //0000 0000 0000 0111;
            memory_operation(code,address,reg);
            }
            break;

        case LOAD_IMMEDIATE:{
        caoss_word value= (ir&0x3ff8)>>3;//0011 1111 1111 1000
        byte regId=ir&0x0007;//0000 0000 0000 0111 
            load_immediate_operation(value,regId);
            }
            break;

        case ALU:{
        alu_opcode opType= (ir&0x3c00)>>10;//0011 1100 0000 0000
            op_size size=(ir&0x0200)>>9;//0000 0010 0000 0000
            byte regId1=(ir&0x01c0)>>6;//0000 0001 1100 0000 
            byte regId2=(ir&0x0038)>>3;//0000 0000 0011 1000
            byte regId=ir&0x0007;//0000 0000 0000 0111 
            alu_operation(opType,size,regId1,regId2,regId);
            }
            break;

        case INT:{
            interrupt_operation();
            }
            break;

        default:
            error("instruction type not known.");
            exit(1);
    }
}

void cpu_run() {

    while (1) {
#ifdef DEBUG
        show_memory();
        show_registers();
#endif
        fetch();
        decode_and_execute();
        pc+=2;
        
    }
}



void show_registers() {

    unsigned size = sizeof(caoss_word)*9 - 1; // extra spaces for separating bytes
    unsigned char intNum[size+1];
    intNum[size] = 0;

    printf("Registers:\n");
    printf ("\tpc [%5u] \t [%s]\n", pc, int2bin(pc, intNum, size, WORD));
    printf ("\tir [%5u] \t [%s]\n\n", ir, int2bin(ir, intNum, size, WORD));
    for (int i = 0; i<NREGISTERS; i++) {
        printf ("\tr%d [%5d] [%5d] [%s]\n", (i+1), registers[i], (short) registers[i], int2bin(registers[i], intNum, size, WORD));
    }
}
