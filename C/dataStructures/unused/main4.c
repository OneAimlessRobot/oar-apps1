#include "Includes/preprocessor.h"
#define ARRSIZE 20
#define STRSIZE 10
int compareStrs(char* str, char* str2){

	return strcmp(str,str2);
}

int main(int argc, char** argv){

        struct timespec time;

        clock_gettime(CLOCK_REALTIME, &time);
        srand(time.tv_nsec);



	hashtable* table= initHashTable(STRSIZE,sizeof(char*));
	for(int i=0;i<ARRSIZE;i++){

		addToHT(&table,strArr[i]);
	}
	printHashTable(table);
	
	printf("Tamanho: %lu\n, Tamanho espinha %lu\n",table->currSize,table->currSpineSize);
	destroyHashTable(table);
	freeStrArr(strArr,ARRSIZE);
return 0;
}
