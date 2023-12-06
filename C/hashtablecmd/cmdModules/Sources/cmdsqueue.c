#include "../../Includes/preprocessor.h"
#include "../Includes/cmdsqueue.h"
#include "../../Includes/doublelist.h"
#include "../../Includes/queueList.h"
#include "../../Includes/cmdstruct.h"


cmdstruct queuecmds[]={
			{"addelem",1,addElemQueue,"Adiciona elemento"},
			{"print",0,printElemsQueue,"Mostra elementos"},
			{"remelem",0,remElemQueue,"remove elemento da queue"},
			{"sairds",0,sairQueue,"sair"},
			{"showallds",0,showallQueue,"mostrar comandos disponiveis"},
			{"destroyds",0,destroyQueue,"destroy queue"},
			{"",0,0,""}
		};
static int compareInts(int* a,int*b){

	
	return (*a)-(*b);

}

static queueList* q=NULL;


void addElemQueue(int64_t argc,int* toExit, void** argv){

	if(!q){
		
		q=initDLQueue(sizeof(int));
		
	}
	
	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	int elem= atoi((char*)argv[1]);
	enqueueDLQueue(q,&elem);
	
}
void printElemsQueue(int64_t argc,int* toExit, void** argv){



	if(q){


		printIntList(q->list);
	}

}

void remElemQueue(int64_t argc,int* toExit, void** argv){


	if(q){
		int* ptr=dequeueDLQueue(q);

		printf("%d\n",*ptr);
		
		free(ptr);
	}


}
void sairQueue(int64_t argc,int* toExit, void** argv){

	*toExit=1;

}
void showallQueue(int64_t argc,int* toExit, void** argv){

			int j=0;
			while(queuecmds[j].cmdname[0]){
			printf("%s- %s\n",(char*)queuecmds[j].cmdname,(char*)queuecmds[j].helpdesc);
			j++;
			
			}
			printf("\n");


}
void destroyQueue(int64_t argc,int* toExit, void** argv){

	if(q){

		destroyDLQueue(q);
		q=NULL;
	}



}



