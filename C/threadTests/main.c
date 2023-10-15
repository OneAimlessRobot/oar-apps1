#include "Includes/preprocessor.h"

typedef struct funcArgs{

	int* arr;
	int size;
	
}funcArgs;


int factorial(int num){
	if(!num){
		return 1;
	
	}
	return num*factorial(num-1);

}
void* func(void* args){
	funcArgs* argv= (funcArgs*)args;
	int* result=malloc(sizeof(void*));
	*(result)=0;

	for(int i=0;i<argv->size;i++){
		*(result)+=argv->arr[i];
	}
	
	return (void*) result;

}

int main(int argc, char ** argv){

	funcArgs args;
	int arr[5]={1,2,3,4,5};
	args.arr=arr;
	args.size=5;
	thread_tree_node* tree=generateTree(1,0,1*sizeof(void*),func,&args,1);
	printf("generated!!!\n");
	while(treeIsRunning(tree));
        printf("generated!!!\n");
        joinTree(tree);
	printf("generated!!!\n");
        destroyTree(tree);
	

	return 0;
}


