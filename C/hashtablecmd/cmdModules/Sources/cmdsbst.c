#include "../../Includes/preprocessor.h"
#include "../Includes/cmdsbst.h"
#include "../../Includes/BSTcomp.h"
#include "../../Includes/cmdstruct.h"


cmdstruct bstcmds[]={
			{"addelem",1,addElemBST,"Adiciona elemento"},
			{"print",0,printElemsBST,"Mostra elementos"},
			{"remelem",1,remElemBST,"remove elemento da bst"},
			{"sairds",0,sairBST,"sair"},
			{"showallds",0,showallBST,"mostrar comandos disponiveis"},
			{"destroyds",0,destroyBST,"destroy bst"},
			{"",0,0,""}
		};
static int compareInts(int* a,int*b){

	
	return (*a)-(*b);

}

static BSTreeComp* tree=NULL;
static comparator* comp=NULL;

void addElemBST(int64_t argc,int* toExit, void** argv){
	if(!comp){

		comp=malloc(sizeof(comparator));
		comp->func=compareInts;

	}
	if(!tree){
		
		tree=initBSTreeComp(sizeof(int),comp);
		
	}
	
	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	int elem= atoi((char*)argv[1]);
	addToBSTreeComp(tree,&elem);
	
}
void printElemsBST(int64_t argc,int* toExit, void** argv){

	if(tree){



		printIntBSTreeInfixComp(tree);


	}

}

void remElemBST(int64_t argc,int* toExit, void** argv){

	if(argc!=2){
		printf("Numero de argumentos errado!!!\n");
		return;
	}
	
	if(tree){
		int value= atoi((char*)argv[1]);
		removeFromBSTreeComp(tree,&value);

	}


}
void sairBST(int64_t argc,int* toExit, void** argv){

	*toExit=1;

}
void showallBST(int64_t argc,int* toExit, void** argv){

			int j=0;
			while(bstcmds[j].cmdname[0]){
			printf("%s- %s\n",(char*)bstcmds[j].cmdname,(char*)bstcmds[j].helpdesc);
			j++;
			
			}
			printf("\n");


}
void destroyBST(int64_t argc,int* toExit, void** argv){

	if(tree){
		free(comp);
		comp=NULL;
		destroyBSTreeComp(tree);
		tree=NULL;
	}



}



