#include "../Includes/preprocessor.h"
#include "../Includes/nodes.h"
#include "../Includes/doublelist.h"
#include "../Includes/hashtable.h"


static u_int64_t hashCode(hashtable* table,char* mem){

u_int64_t hash= 5381;

	u_int64_t count=0;

for(;count<table->sizeOfElem;count++){

hash= ((hash << 5) + hash) +mem[count];
}
return hash;

}

static u_int64_t getTablePosForElem(hashtable * table, void* mem){


	return hashCode(table,(char*)mem)%table->currSpineSize;


}

static  double getLoadFactor(hashtable* table){

	return (double)table->currSpineSize/(double)table->currSize;


}

static int isFull(hashtable* table){

	return getLoadFactor(table)<MIN_LOAD_FACTOR;

}

hashtable* initHashTable(u_int64_t sizeOfElem){
	
	hashtable* result= malloc(sizeof(hashtable));
	result->spine= malloc(sizeof(DListW*)*HTSTARTSIZE);
	for(u_int64_t i=0;i<HTSTARTSIZE;i++){
		
		result->spine[i]= initDList(sizeOfElem);


	}
	result->sizeOfElem=sizeOfElem;
	result->currSize=0;
	result->currSpineSize=HTSTARTSIZE;
	
	return result;


}

static hashtable* initHashTableInitSize(u_int64_t sizeOfElem,u_int64_t size){
	
	hashtable* result= malloc(sizeof(hashtable));
	result->spine= malloc(sizeof(DListW*)*size);
	for(u_int64_t i=0;i<size;i++){
		
		result->spine[i]= initDList(sizeOfElem);


	}
	result->sizeOfElem=sizeOfElem;
	result->currSize=0;
	result->currSpineSize=size;

	return result;


}

static hashtable* rehash(hashtable* table){
	u_int64_t newTableSize= (table)->currSpineSize*GROWFACTOR;
	hashtable* newTable= initHashTableInitSize((table)->sizeOfElem,newTableSize);	
	for(u_int64_t i=0;i<(table)->currSpineSize;i++){

		if((table)->spine[i]->head){
			DList node=(table)->spine[i]->head;
			for(u_int64_t j=0;j<(table)->spine[i]->currSize;j++){
			
			 addToHT(&newTable,strndup((char*)node->mem,newTable->sizeOfElem));

			node=node->next;

			}

		}

	}
	destroyHashTable(table);
	return newTable;
}

void printHashTable(hashtable* table){

for(u_int64_t i=0;i<table->currSpineSize;i++){

		if(table->spine[i]->head){
			DList node=table->spine[i]->head;
			for(u_int64_t j=0;j<table->spine[i]->currSize;j++){
			
			printf("%s ",(char*)(node->mem));

			node=node->next;

			}
			printf("\n");

		}

	}
}

//pre: mem is sizeOfElem in bytes in size
void addToHT(hashtable** table,void* mem){

	if(isFull(*table)){
		

		*table=rehash(*table);
	}
	
	u_int64_t pos=getTablePosForElem(*table,mem);
	DListW* list= (*table)->spine[pos];
	addElemToListComp(list,mem);
	(*table)->currSize++;



}
void removeFromHT(hashtable* table,void * mem){


	if(!table->currSize){


		return;
	}
	u_int64_t pos=getTablePosForElem(table,mem);
	DListW* list= table->spine[pos];
	remElemFromListComp(list,mem);
	table->currSize--;




}
void destroyHashTable(hashtable* table){

	for(u_int64_t i=0;i<table->currSpineSize;i++){
	
		destroyDList(table->spine[i]);
		table->spine[i]=NULL;
	}
	free(table->spine);
	free(table);
	table=NULL;


}

void* getHTElem(hashtable* table,void* mem){

u_int64_t pos=getTablePosForElem(table,mem);
	
	return findElemListComp(table->spine[pos],mem);


}
