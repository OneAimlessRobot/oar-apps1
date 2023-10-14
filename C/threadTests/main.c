#include "Includes/preprocessor.h"
typedef struct funcArgs{

	int fd;
	
}funcArgs;


int factorial(int num){
	if(!num){
		return 1;
	
	}
	return num*factorial(num-1);

}
void* func(pausableFuncArgs* args){
	int* resultMem=(int*) args->mem;
	while(!(*(args->twostagesem[1]))){
		pthread_mutex_lock(args->mutex);
		while(!(*args->twostagesem[0])&&!(*(args->twostagesem[1]))){
			
			pthread_cond_wait(args->running,args->mutex);

		}
		pthread_mutex_unlock(args->mutex);
		if(*(args->twostagesem[0])){
			
			write(((funcArgs*)args->actualArgs)->fd,".",1);
		}
		*(args->twostagesem[0])=0;
		
	}
	return NULL;	
}



int main(int argc, char ** argv){

	funcArgs args;
	int fd= creat(argv[1],0777);
	args.fd=1;
	thread_tree* tree=generateTree(0,1,func,&args,0);
	printf("generated!!!\n");
	args.fd=fd;
	freezeTree(tree);
	while(treeIsRunning(tree));
	printf("%d\n",treeIsRunning(tree));
	joinTree(tree);
	destroyTree(tree);
	close(fd);
	


	return 0;
}


