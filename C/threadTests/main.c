#include "Includes/preprocessor.h"

typedef struct funcArgs{

	int size;
	int* arr;

}funcArgs;
typedef struct AfuncArgs{

        int size;
        int* arr;                                     
}AfuncArgs;

int factorial(int num){
	if(!num){
		return 1;
	
	}
	return num*factorial(num-1);

}

void* func(void* args){
	funcArgs* argv= (funcArgs*)args;
	int64_t * result=malloc(sizeof(void*));
	*(result)=0;
	for(int i=0;i<argv->size;i++){

		*(result)+=argv->arr[i];

	}

	return  (void*)result;

}
int* genArr(int size){

int* arr=malloc(sizeof(int)*size);
for(int i=0;i<size;i++){

arr[i]=round(sin(cos(10000*factorial(i))));

}
return arr;


}

void* incArr(void* args){
funcArgs* argv= (funcArgs*)args;
for(int i=0;i<argv->size;i++){

argv->arr[i]+=round(sin(cos(10000*factorial(i))));

}
return malloc(8);
}
int main(int argc, char ** argv){

	funcArgs args;
	args.arr=genArr(10000);
	args.size=10000;

AfuncArgs args2;
args2.size=args.size;
args2.arr=args.arr;
	thread_tree_node* tree=generateTree(9,1,1*sizeof(void*),func,&args,1);
	
thread_tree_node* tree2=generateTree(15,1,1*sizeof(void*),incArr,&args,1);
while(treeIsRunning(tree));
while(treeIsRunning(tree2));

	freezeTree(tree);
	freezeTree(tree2);
//	while(treeIsRunning(tree));
//	printf("Results: %lu\n",sumTreeResults(tree));
	for(int i=0; i<10;i++){
          while(treeIsRunning(tree));
while(treeIsRunning(tree2));

	printf("Results: %ld\n",(int64_t)sumTreeResults(tree));
	freezeTree(tree2);
freezeTree(tree);
	//while(treeIsRunning(tree));
        }	
while(treeIsRunning(tree2));
	terminateTree(tree);
terminateTree(tree2);
	free(args.arr);
//	printf("Results: %lu. Tree is running: %d\n",sumTreeResults(tree),treeIsRunning(tree));
//	printf("Results: %lu\n",sumTreeResults(tree));
//	joinTree(tree);
	destroyTree(tree);
destroyTree(tree2);
	return 0;
}



