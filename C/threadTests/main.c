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
u_int64_t* func(void* args){
	funcArgs* argv= (funcArgs*)args;
	u_int64_t* result=malloc(sizeof(void*));
	*(result)=0;
	for(int i=0;i<argv->size;i++){
		*(result)+=argv->arr[i];
	}
	
	return result;

}

int main(int argc, char ** argv){

	funcArgs args;
	int arr[5]={1,2,3,4,5};
	args.arr=arr;
	args.size=5;
	thread_tree_node* tree=generateTree(2,10,1*sizeof(void*),(void*(*)(void*))func,&args,1);
	printf("generated!!!\n");
	while(treeIsRunning(tree));
	printf("%d\n",sumTreeResults(tree));
	joinTree(tree);
	destroyTree(tree);

	return 0;
}


