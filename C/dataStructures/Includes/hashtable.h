#ifndef HASHTABLE_H
#define HASHTABLE_H
#define STARTSIZE 7
#define GROWFACTOR 2
#define MIN_LOAD_FACTOR 0.75
typedef struct hashtable{

DListW **spine;
u_int64_t currSize,currSpineSize,sizeOfElem;

}hashtable;

/*

static:
pre: mem is sizeOfElem in size in bytes
u_int64_t hashCode(void* mem);

void grow(hashtable* table)


double getLoadFactor(hashtable* table);

int isFull(hashtable* table);


void rehash(hashtable* table);





*/


hashtable* initHashTable(u_int64_t sizeofElem);
//pre: mem is sizeOfElem in bytes in size
void addToHT(hashtable** table,void* mem);

void removeFromHT(hashtable* table,void * mem);

void* getHTElem(hashtable* table,void* mem);

void destroyHashTable(hashtable* table);

void printHashTable(hashtable* table);




#endif

