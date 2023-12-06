#include "../../Includes/preprocessor.h"
#include "../Includes/cmdsdlist.h"
#include "../../Includes/doublelist.h"
#include "../../Includes/cmdstruct.h"


cmdstruct dlistcmds[]={
			{"addelem",1,addElemDList,"Adiciona elemento"},
			{"print",0,printElemsDList,"Mostra elementos"},
			{"remelem",0,remElemDList,"remove elemento da stack"},
			{"sairds",0,sairDList,"sair"},
			{"showallds",0,showallDList,"mostrar comandos disponiveis"},
			{"destroyds",0,destroyDListW,"destroy stack"},
			{"",0,0,""}
		};
static int compareInts(int* a,int*b){

	
	return (*a)-(*b);

}

static DListW* list=NULL;

void addElemDList(int64_t argc,int* toExit, void** argv){

	if(!list){
		
		list=initDList(sizeof(int));
		
	}
	
	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	int elem= atoi((char*)argv[1]);
	addElemToListComp(list,&elem);
	
}
void printElemsDList(int64_t argc,int* toExit, void** argv){

	if(list){



		printIntList(list);


	}

}

void remElemDList(int64_t argc,int* toExit, void** argv){

	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	if(list){
		int value= atoi((char*)argv[1]);
		remElemFromListComp(list,&value);

	}


}
void sairDList(int64_t argc,int* toExit, void** argv){

	*toExit=1;

}
void showallDList(int64_t argc,int* toExit, void** argv){

			int j=0;
			while(dlistcmds[j].cmdname[0]){
			printf("%s- %s\n",(char*)dlistcmds[j].cmdname,(char*)dlistcmds[j].helpdesc);
			j++;
			
			}
			printf("\n");


}
void destroyDListW(int64_t argc,int* toExit, void** argv){

	if(list){

		destroyDList(list);
		list=NULL;
	}



}



