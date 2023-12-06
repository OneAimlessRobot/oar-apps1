#include "../../Includes/preprocessor.h"
#include "../Includes/cmdsstack.h"
#include "../../Includes/doublelist.h"
#include "../../Includes/stackList.h"
#include "../../Includes/cmdstruct.h"


cmdstruct stackcmds[]={
			{"addelem",1,addElemStack,"Adiciona elemento"},
			{"print",0,printElemsStack,"Mostra elementos"},
			{"remelem",0,remElemStack,"remove elemento da stack"},
			{"sairds",0,sairStack,"sair"},
			{"showallds",0,showallStack,"mostrar comandos disponiveis"},
			{"destroyds",0,destroyStack,"destroy stack"},
			{"",0,0,""}
		};
static int compareInts(int* a,int*b){

	
	return (*a)-(*b);

}

static stackList* stck=NULL;


void addElemStack(int64_t argc,int* toExit, void** argv){

	if(!stck){
		
		stck=initDLStack(sizeof(int));
		
	}
	
	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	int elem= atoi((char*)argv[1]);
	pushDLStack(stck,&elem);
	
}
void printElemsStack(int64_t argc,int* toExit, void** argv){

	if(stck){


		printIntList(stck->list);
	}

}


void remElemStack(int64_t argc,int* toExit, void** argv){


	if(stck){
		int* ptr=popDLStack(stck);

		printf("%d\n",*ptr);
		
		free(ptr);
	}


}
void sairStack(int64_t argc,int* toExit, void** argv){

	*toExit=1;

}
void showallStack(int64_t argc,int* toExit, void** argv){

			int j=0;
			while(stackcmds[j].cmdname[0]){
			printf("%s- %s\n",(char*)stackcmds[j].cmdname,(char*)stackcmds[j].helpdesc);
			j++;
			
			}
			printf("\n");


}
void destroyStack(int64_t argc,int* toExit, void** argv){

	if(stck){

		destroyDLStack(stck);
		stck=NULL;
	}



}



