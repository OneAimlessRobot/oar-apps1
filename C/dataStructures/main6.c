#include "Includes/preprocessor.h"
#define ARRSIZE 40
#define STRSIZE 5

static const char* menu="\nEstas sao as opcoes:\na- adicionar elemento\nr- remover elemento\np- imprimir hashtable\ns- sair\n";


int compareStrings(char* a, char* b){
	
	return strcmp(a,b);
}

int main(int argc, char ** argv){
	
	

        struct timespec time;

        clock_gettime(CLOCK_REALTIME, &time);
        srand(time.tv_nsec);

	comparator* comp=malloc(sizeof(comparator));
	comp->func=compareStrings;
	hashtablecomp* tree= initHashTableComp(STRSIZE,comp);
	
	char** arr=randStrArr(STRSIZE, ARRSIZE);
	

	for(int i=0;i<ARRSIZE;i++){


		addToHTComp(&tree,strdup(arr[i]));

	}
	
		
	do{
	char* value=NULL;
	char option=0;
	char  var[128]={0};
	
		//system("clear");
		printf("%s\n",menu);
		if(scanf("%c",&option)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
        	continue;
		}
		switch(option){

		case 's':
		free(comp);
		freeStrArr(arr,ARRSIZE);
		destroyHashTableComp(tree);
		free(value);
		return 0;
		case 'p':
		
		printHashTableComp(tree);

		printf("Tamanho: %lu\n",tree->currSize);
		
		break;
		case 'a':
		if(scanf("%s",&var)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
        	continue;
		}
		value=malloc(STRSIZE+1);
		memset(value,0,STRSIZE+1);
		memcpy(value,var,STRSIZE);
		addToHTComp(&tree,value);
		break;
		case 'r':
		
		if(scanf("%s",&var)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
        	continue;
		}
		char value2[STRSIZE+1];
		memset(value2,0,STRSIZE+1);
		memcpy(value2,var,STRSIZE);
		removeFromHTComp(tree,value2);
		break;
		}
	
		

		
		

	}while(1);
	


	return 0;
}
