#include "Includes/preprocessor.h"
typedef struct funcArgs{

	int num;

}funcArgs;

int factorial(int num){
	if(!num){
		return 1;
	
	}
	return num*factorial(num-1);

}
void* func(pausableFuncArgs* args){
	int* resultMem= args->mem;
	while((*(args->twowaysem[0]))){
		*(resultMem)=0;
	}
	printf("Done!");
	return NULL;	
}



int main(int argc, char ** argv){

	funcArgs args;
	args.num=5;
	thread_tree* tree=generateTree(3,3,func,&args,0);
	printf("generated!!!\n");
	sleep(3);
	printf("unfrozen!!!\n");
	freezeTree(tree);
	joinTree(tree);
	printf("%d\n",sumTreeResults(tree));
	destroyTree(tree);

	


	return 0;
}

