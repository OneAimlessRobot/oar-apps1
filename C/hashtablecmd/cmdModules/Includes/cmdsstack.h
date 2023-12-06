#ifndef CMDSSTACK_H
#define CMDSSTACK_H

void addElemStack(int64_t argc,int* toExit, void** argv);

void printElemsStack(int64_t argc,int* toExit, void** argv);


void remElemStack(int64_t argc,int* toExit, void** argv);


void sairStack(int64_t argc,int* toExit, void** argv);

void showallStack(int64_t argc,int* toExit, void** argv);

void destroyStack(int64_t argc,int* toExit, void** argv);

extern cmdstruct stackcmds[];

#endif
