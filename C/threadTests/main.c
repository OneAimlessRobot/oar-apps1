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
	u_int64_t* result=malloc(sizeof(void*));
	*(result)=5;
	return (void*) result;

}

int main(int argc, char ** argv){

	funcArgs args;
	int arr[5]={1,2,3,4,5};
	args.arr=arr;
	args.size=5;
	thread_tree_node* tree=generateTree(3,10,1*sizeof(void*),func,&args,1);
	while(treeIsRunning(tree));
//	printf("Results: %lu\n",sumTreeResults(tree));
	for(int i=0; i<10;i++){
          while(treeIsRunning(tree));
	freezeTree(tree);
	while(treeIsRunning(tree));
	printf("Results: %lu\n",sumTreeResults(tree));
        }	
	terminateTree(tree);
//	printf("Results: %lu. Tree is running: %d\n",sumTreeResults(tree),treeIsRunning(tree));
//	printf("Results: %lu\n",sumTreeResults(tree));
//	joinTree(tree);
	destroyTree(tree);

	return 0;
}


