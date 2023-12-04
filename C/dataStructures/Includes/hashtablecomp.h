#ifndef HASHTABLECOMP_H
#define HASHTABLECOMP_H
#define STARTSIZE 7
#define GROWFACTOR 2
#define MIN_LOAD_FACTOR 0.75
typedef struct hashtablecomp{

DListWComp **spine;
u_int64_t currSize,currSpineSize,sizeOfElem;
comparator*comp;
}hashtablecomp;

/*

static:
pre: mem is sizeOfElem in size in bytes
u_int64_t hashCode(void* mem);

void grow(hashtable* table)


double getLoadFactor(hashtable* table);

int isFull(hashtable* table);


void rehash(hashtable* table);





*/


hashtablecomp* initHashTableComp(u_int64_t sizeofElem,comparator*comp);
//pre: mem is sizeOfElem in bytes in size
void addToHTComp(hashtablecomp** table,void* mem);

void removeFromHTComp(hashtablecomp* table,void * mem);

void* getHTElemComp(hashtablecomp* table,void* mem);

void destroyHashTableComp(hashtablecomp* table);

void printHashTableComp(hashtablecomp* table);




#endif

