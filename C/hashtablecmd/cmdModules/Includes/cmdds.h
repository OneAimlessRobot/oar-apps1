#ifndef CMDDS_H
#define CMDDS_H




void addElem(int64_t argc,int* toExit, void** argv);

void printElems(int64_t argc,int* toExit, void** argv);


void remElem(int64_t argc,int* toExit, void** argv);


void sairds(int64_t argc,int* toExit, void** argv);

void showallds(int64_t argc,int* toExit, void** argv);

void destroyds(int64_t argc,int* toExit, void** argv);

extern cmdstruct dscmds[];
#endif
