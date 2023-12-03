#include "../Includes/preprocessor.h"
#include "../Includes/hashtablecomp.h"


static u_int64_t hashCode(hashtablecomp* table,char* mem){

u_int64_t hash= 5381;

	u_int64_t count=0;

for(;count<table->sizeOfElem;count++){

hash= ((hash << 5) + hash) +mem[count];
}
return hash;

}

static u_int64_t getTablePosForElem(hashtablecomp * table, void* mem){


	return hashCode(table,(char*)mem)%table->currSpineSize;


}

static  double getLoadFactor(hashtablecomp* table){

	return (double)table->currSpineSize/(double)table->currSize;


}

static int isFull(hashtablecomp* table){

	return getLoadFactor(table)<MIN_LOAD_FACTOR;

}

hashtablecomp* initHashTableComp(u_int64_t sizeOfElem,comparator*comp){
	
	hashtablecomp* result= malloc(sizeof(hashtablecomp));
	result->spine= malloc(sizeof(DListWComp*)*STARTSIZE);
	for(u_int64_t i=0;i<STARTSIZE;i++){
		
		result->spine[i]= initDListComp(sizeOfElem,comp);


	}
	result->sizeOfElem=sizeOfElem;
	result->currSize=0;
	result->comp=comp;
	result->currSpineSize=STARTSIZE;
	
	return result;


}

static hashtablecomp* initHashTableInitSizeComp(u_int64_t sizeOfElem,u_int64_t size,comparator*comp){
	
	hashtablecomp* result= malloc(sizeof(hashtablecomp));
	result->spine= malloc(sizeof(DListWComp*)*size);
	for(u_int64_t i=0;i<size;i++){
		
		result->spine[i]= initDListComp(sizeOfElem,comp);


	}
	result->sizeOfElem=sizeOfElem;
	result->currSize=0;
	result->comp=comp;
	result->currSpineSize=size;

	return result;


}

static hashtablecomp* rehash(hashtablecomp* table){
	u_int64_t newTableSize= (table)->currSpineSize*GROWFACTOR;
	hashtablecomp* newTable= initHashTableInitSizeComp((table)->sizeOfElem,newTableSize,table->comp);	
	for(u_int64_t i=0;i<(table)->currSpineSize;i++){

		if((table)->spine[i]->head){
			DList node=(table)->spine[i]->head;
			for(u_int64_t j=0;j<(table)->spine[i]->currSize;j++){
			
			 addToHTComp(&newTable,strndup((char*)node->mem,newTable->sizeOfElem));

			node=node->next;

			}

		}

	}
	destroyHashTableComp(table);
	return newTable;
}

void printHashTableComp(hashtablecomp* table){

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
void addToHTComp(hashtablecomp** table,void* mem){

	if(isFull(*table)){
		

		*table=rehash(*table);
	}
	
	u_int64_t pos=getTablePosForElem(*table,mem);
	DListWComp* list= (*table)->spine[pos];
	addElemToListComp(list,mem);
	(*table)->currSize++;



}
void removeFromHTComp(hashtablecomp* table,void * mem){


	if(!table->currSize){


		return;
	}
	u_int64_t pos=getTablePosForElem(table,mem);
	DListW* list= table->spine[pos];
	remElemFromListComp(list,mem);
	table->currSize--;




}
void destroyHashTableComp(hashtablecomp* table){

	for(u_int64_t i=0;i<table->currSpineSize;i++){
	
		destroyDList(table->spine[i]);
		table->spine[i]=NULL;
	}
	free(table->spine);
	free(table);
	free(table->comp);
	table->comp=NULL;
	table=NULL;


}
