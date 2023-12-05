#include "Includes/preprocessor.h"

#define ARRSIZE 10
#define STRSIZE 5

static const char* menu="\nEstas sao as opcoes:\na- adicionar elemento\nr- dequeue da minHeap\np- imprimir minHeap\ns- sair\n";


int compareInts(int* a, int* b){
	
	return (*a)-(*b);
}

int main(int argc, char ** argv){
	
	

        struct timespec time;

        clock_gettime(CLOCK_REALTIME, &time);
        srand(time.tv_nsec);

	comparator* comp=malloc(sizeof(comparator));
	comp->func=compareInts;
	int*arr= getRandIntArr(0,1000,40);
	minHeap* tree=initMinHeap(comp,sizeof(int));
	

	for(int i=0;i<ARRSIZE;i++){

		insertMinHeap(tree,arr+i);

	}
		
		free(arr);
	
		printMinHeapPretty(tree);

	do{
	char option=0;
	int* ptr=NULL;
	int var=0;
		//system("clear");
		printf("%s\n",menu);
		fflush(stdout);
		if(scanf("%c",&option)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
        	break;
		}
		switch(option){

		case 's':
		free(comp);
		destroyMinHeap(tree);
		return 0;
		case 'p':
		
		printMinHeapPretty(tree);

		printf("Tamanho: %lu\n",tree->currSize);
		
		break;
		case 'a':
		if(scanf("%d",&var)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
		break;
        	}
		insertMinHeap(tree,&var);
		break;
		case 'r':
		ptr=(int*)dequeueMinHeap(tree);
		if(!ptr){
			printf("Queue vazia!!!!!");
			break;
		}
		printf("Elemento %d\n",*ptr);
		break;
		}
	
		

		
		

	}while(1);
	


	return 0;
}
