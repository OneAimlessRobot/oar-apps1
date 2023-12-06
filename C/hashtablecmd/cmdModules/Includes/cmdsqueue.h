#ifndef CMDSQUEUE_H
#define CMDSQUEUE_H

void addElemQueue(int64_t argc,int* toExit, void** argv);

void printElemsQueue(int64_t argc,int* toExit, void** argv);


void remElemQueue(int64_t argc,int* toExit, void** argv);


void sairQueue(int64_t argc,int* toExit, void** argv);

void showallQueue(int64_t argc,int* toExit, void** argv);

void destroyQueue(int64_t argc,int* toExit, void** argv);

extern cmdstruct queuecmds[];

#endif
