

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

	thread_tree_node* tree=generateTree(9,1,1*sizeof(void*),func,&args,1);
	
while(treeIsRunning(tree));

	freezeTree(tree);
	for(int i=0; i<10;i++){
          while(treeIsRunning(tree));
while(treeIsRunning(tree));

	printf("Results: %ld\n",(int64_t)sumTreeResults(tree));
	free(incArr(&args));
freezeTree(tree);
    }	
while(treeIsRunning(tree));
	terminateTree(tree);
	free(args.arr);
	joinTree(tree);
	destroyTree(tree);

	return 0;
}



/*#include "Includes/preprocessor.h"

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
	printf("Results: %lu\n",sumTreeResults(tree));
	freezeTree(tree);
	while(treeIsRunning(tree));
	
	
	terminateTree(tree);
	printf("Results: %lu. Tree is running: %d\n",sumTreeResults(tree),treeIsRunning(tree));
	printf("Results: %lu\n",sumTreeResults(tree));
	joinTree(tree);
	destroyTree(tree);

	return 0;
}


*/
