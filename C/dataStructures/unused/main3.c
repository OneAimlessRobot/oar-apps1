#include "Includes/preprocessor.h"
static const char* menu="\nEstas sao as opcoes:\na- adicionar elemento\nr- remover elemento\np- imprimir arvore\ns- sair\n";


int compareIntsTwo(int* a, int* b){
	
	return (*a)-(*b);
}

int main(int argc, char ** argv){
	
	

        struct timespec time;

        clock_gettime(CLOCK_REALTIME, &time);
        srand(time.tv_nsec);



	BSTree* tree= initBSTree(sizeof(int));
	int number=0;
	int numberOfElements=0;
	char type=0;
	system("clear");
        printf("Insere como gerar arvore( r= random. m = manual):\n");
	if(scanf("%c",&type)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
        }
	
	if(type=='m'){
        system("clear");
        printf("Insere no de elementos a adicionar:\n");
	if(scanf("%d",&numberOfElements)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
        }
	
	int* arr=malloc(numberOfElements*sizeof(int));
	while(numberOfElements>0){
        system("clear");
        printf("Insere elementos um a um e carrega enter:\n");

	if(scanf("%d",&number)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
                continue;
        }
	
	arr[numberOfElements-1]=number;
	
	addToBSTree(tree,arr+numberOfElements-1);
	numberOfElements--;
	}
	BSTNode*node=tree->root;
	char opt=0;
	while(opt!='s'&&node){
        system("clear");
        printf("Escolhe l para esquerda ou r para direita ou s para sair e carrega enter:\n");
	printf("Elemento atual:%d\n",*(int*)(node->mem));
	if(scanf("%c",&opt)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
                continue;
        }
	
	if(opt=='l'){

	node=node->left;

	}
	else if(opt=='r'){

	node=node->right;

	}
	if(!node){

		printf("Saindo! Atingiste um nó null!\n");
		printIntBSTreeBreadth(tree);
	}
	}
	free(arr);
	}
	else if(type=='r'){
	int* arr=getRandIntArr(0, 100, 50);

//	BSTree* tree2=makeIntTree(arr,50);
	
	free(arr);
	}
	char option=0;
	int value=0;
	int* ptr=NULL;	
	
	do{
		//system("clear");
		printf("%s\n",menu);
		if(scanf("%c",&option)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
        	continue;
		}
		switch(option){

		case 's':
		destroyBSTree(tree);
		return 0;
		case 'p':
		
		printBSTreePretty(tree);

		printf("Tamanho: %lu\n",tree->currSize);
		
		break;
		case 'a':
		value=0;
		if(scanf("%d",&value)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
        	continue;
		}
		ptr=malloc(sizeof(int));
		*ptr=value;
		addToBSTree(tree,ptr);
		break;
		case 'r':
		
		value=0;
		if(scanf("%d",&value)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
        	continue;
		}
		
		removeFromBSTree(tree,&value);
		
		break;
		}
	
		

		
		

	}while(1);
	       	



	return 0;
}
