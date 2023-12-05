#ifndef CMDFUNCEXMPL_H
#define CMDFUNCEXMPL_H


extern cmdstruct commands[];



void addNums(int64_t argc,int* toExit, void** argv);

void multNums(int64_t argc,int* toExit, void** argv);

void myname(int64_t argc,int* toExit, void** argv);

void myiq(int64_t argc,int* toExit, void** argv);

void sair(int64_t argc,int* toExit, void** argv);

void showall(int64_t argc,int* toExit, void** argv);

void showRandomQuote(int64_t argc,int* toExit, void** argv);

void factorial(int64_t argc,int* toExit, void** argv);

void sumarr(int64_t argc,int* toExit, void** argv);
#endif
