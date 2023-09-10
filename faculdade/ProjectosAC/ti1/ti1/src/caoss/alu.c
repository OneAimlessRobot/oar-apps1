#include "alu.h"

int mascara=0x00ff; //0000 0000 1111 1111
//Esta bem.
void add(op_size size, byte register_in1, byte register_in2, byte register_out) {

    if (size == BYTE) {
    registers[register_out]&=0xff00; //1111 1111 0000 0000
    
    
    // 1100 1110 1110 1110                                 
    // 1111 1111 0000 0000
    // 1100 1110 0000 0000                 //1111 1101 1101 1011
    					                                          

    registers[register_out] |= (registers[register_in1] + registers[register_in2])&mascara;
    }
    else {
        registers[register_out] = registers[register_in1] + registers[register_in2];
    }
}
//Está bem.
void sub(op_size size, byte register_in1, byte register_in2, byte register_out) {
    if (size == BYTE) {
    
    registers[register_out]&=0xff00;

    registers[register_out] |= (registers[register_in1] - registers[register_in2])&mascara;
    }
    else {
    
    registers[register_out] = registers[register_in1] - registers[register_in2];

    }
}
// esta bem
void and(op_size size, byte register_in1, byte register_in2, byte register_out) {
    if (size == BYTE) {

    
    registers[register_out]&=0xff00;
    
    // 1100 1110 1110 1110                                 
    // 1111 1111 0000 0000
    // 1100 1110 0000 0000                 //1111 1101 1101 1011
    					

    registers[register_out] |= (registers[register_in1] & registers[register_in2])&mascara;
    }
    else {
    registers[register_out] = registers[register_in1] & registers[register_in2];

    }
}
//Esta bem.
void or(op_size size, byte register_in1, byte register_in2, byte register_out) {
    if (size == BYTE) {
    
    registers[register_out]&=0xff00;

    registers[register_out] |= (registers[register_in1] | registers[register_in2])&mascara;

    }
    else {
    registers[register_out] = registers[register_in1] | registers[register_in2];

    }
}
//esta bem.
void sal(op_size size, byte register_in1, byte register_in2, byte register_out) {
    if (size == BYTE) {
    
    registers[register_out]&=0xff00;

    registers[register_out] |= (registers[register_in1] << registers[register_in2])&mascara;
    }
    else {
    registers[register_out] = registers[register_in1] << registers[register_in2];

    }
}

void sar(op_size size, byte register_in1, byte register_in2, byte register_out) {
    if (size == BYTE) {
    registers[register_out]&=0xff00;

    registers[register_out] |= (registers[register_in1] >> registers[register_in2])&mascara;

    }
    else {
    //Cusquei de um colega. Manuel Pinto
    registers[register_out] = (short) registers[register_in1] >> (short)registers[register_in2];

    }
}
//esta bem.
void neg(op_size size, byte register_in, byte register_out) {
    if (size == BYTE) {
    registers[register_out]&=0xff00;
    
    registers[register_out] |= (-registers[register_in])&mascara;
    

    }
    else {
    registers[register_out] = -registers[register_in];

    }
}
//esta bem.
void not(op_size size, byte register_in, byte register_out) {
    if (size == BYTE) {
    registers[register_out]&=0xff00;
    
    registers[register_out] |= (~registers[register_in])&mascara;

    }
    else {
    registers[register_out] = ~registers[register_in];

    }
}
