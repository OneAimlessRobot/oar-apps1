#ifndef CMDFUNCEXMPL_H
#define CMDFUNCEXMPL_H


extern cmdstruct commands[];



void addNums(u_int64_t argc,int* toExit, void** argv);

void multNums(u_int64_t argc,int* toExit, void** argv);

void myname(u_int64_t argc,int* toExit, void** argv);

void myiq(u_int64_t argc,int* toExit, void** argv);

void sair(u_int64_t argc,int* toExit, void** argv);

void showall(u_int64_t argc,int* toExit, void** argv);


#endif
