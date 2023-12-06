#include "../../Includes/preprocessor.h"
#include "../Includes/cmdds.h"
#include "../../Includes/minHeap.h"
#include "../../Includes/cmdstruct.h"


cmdstruct dscmds[]={
			{"addelem",1,addElem,"Adiciona elemento"},
			{"print",0,printElems,"Mostra elementos"},
			{"remelem",0,remElem,"remove elemento da queue"},
			{"sairds",0,sairds,"sair"},
			{"showallds",0,showallds,"mostrar comandos disponiveis"},
			{"destroyds",0,destroyds,"destroy queue"},
			{"",0,0,0}
		};
static int compareInts(int* a,int*b){

	
	return (*a)-(*b);

}

minHeap* heap=NULL;
comparator* comp=NULL;
void addElem(int64_t argc,int* toExit, void** argv){
	if(!comp){
		comp=malloc(sizeof(comparator));
		comp->func=(int(*)(void*,void*))compareInts;
	}
	if(!heap){
		
		heap=initMinHeap(comp,sizeof(int));
		
	}
	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	int elem= atoi((char*)argv[1]);
	insertMinHeap(heap,&elem);
}
void printElems(int64_t argc,int* toExit, void** argv){
	if(heap){

		printMinHeapPretty(heap);
	}


}

void destroyds(int64_t argc,int* toExit, void** argv){
	if(heap){

		destroyMinHeap(heap);
		heap=NULL;
	}


}


void remElem(int64_t argc,int* toExit, void** argv){

	if(heap){
		int* ptr=dequeueMinHeap(heap);

		printf("%d\n",*ptr);
		
		free(ptr);
	}

}



void sairds(int64_t argc,int* toExit, void** argv){
	*toExit=1;
}


void showallds(int64_t argc,int* toExit, void** argv){


			int j=0;
			while(dscmds[j].cmdname[0]){
			printf("%s- %s\n",(char*)dscmds[j].cmdname,(char*)dscmds[j].helpdesc);
			j++;
			
			}
			printf("\n");
}


