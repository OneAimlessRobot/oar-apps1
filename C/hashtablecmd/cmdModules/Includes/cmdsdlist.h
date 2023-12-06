#ifndef CMDSDLIST_H
#define CMDSDLIST_H

void addElemDList(int64_t argc,int* toExit, void** argv);

void printElemsDList(int64_t argc,int* toExit, void** argv);


void remElemDList(int64_t argc,int* toExit, void** argv);


void sairDList(int64_t argc,int* toExit, void** argv);

void showallDList(int64_t argc,int* toExit, void** argv);

void destroyDListW(int64_t argc,int* toExit, void** argv);

extern cmdstruct dlistcmds[];

#endif
