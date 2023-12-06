#ifndef CMDSHASHTABLE_H
#define CMDSHASHTABLE_H

void addElemHashTable(int64_t argc,int* toExit, void** argv);

void printElemsHashTable(int64_t argc,int* toExit, void** argv);


void remElemHashTable(int64_t argc,int* toExit, void** argv);


void sairHashTable(int64_t argc,int* toExit, void** argv);

void showallHashTable(int64_t argc,int* toExit, void** argv);

void destroyHashTable(int64_t argc,int* toExit, void** argv);

extern cmdstruct hashtablecmds[];

#endif
