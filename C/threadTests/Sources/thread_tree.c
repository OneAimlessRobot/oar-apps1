#include "../Includes/preprocessor.h"

static void* threadTreeFuncRun(threadTreeFuncArgs* args){
	
	while(!(*(args->twostagesem[1]))){
		pthread_mutex_lock(args->mutex);
		while(!(*args->twostagesem[0])&&!(*(args->twostagesem[1]))){
			
			pthread_cond_wait(args->running,args->mutex);

		}
		pthread_mutex_unlock(args->mutex);
		if(*(args->twostagesem[0])){
			u_int64_t*resultMem=args->func(args->actualArgs);
			memcpy(args->mem,resultMem,args->memsize);
			free(resultMem);
		}
		*(args->twostagesem[0])=0;
		
	}
	return NULL;	



}
static int noChildren(thread_tree_node* node){

	
	for(int i=0;i<node->nsize;i++){

		if(node->children[i]){

			return 0;
		}
	}
	return 1;


}

static int checkRunningOnArray(thread_tree_node**array,int nsizetwo);

static int checkRunningOnNode(thread_tree_node* node);

static int checkRunningOnArray(thread_tree_node**array,int nsizetwo){

	if(nsizetwo>=0){
  		return checkRunningOnNode(array[nsizetwo])||checkRunningOnArray(array,nsizetwo-1);
	}
		return 0;
}
static int checkRunningOnNode(thread_tree_node* node){


		if(noChildren(node)){
				return (*(node->twostagesem[0]));
			}
		return (*(node->twostagesem[0])) || checkRunningOnArray(node->children,node->nsize-1);
	}

int treeIsRunning(thread_tree_node* tree){

	if(!tree){
		return 0;
	}
	return checkRunningOnNode(tree);


}
static thread_tree_node* createNewThreadNode(int nsize,u_int64_t memsize,void* (*pfunc)(void*),void* args,int startRunning){
		
		thread_tree_node* node=malloc(sizeof(thread_tree_node));
		node->thread=malloc(sizeof(pthread_t));
		node->children=malloc(nsize*(sizeof(thread_tree_node*)));
		memset(node->children,0,nsize*(sizeof(thread_tree_node*)));
		node->running=malloc(sizeof(pthread_cond_t));
		node->mutex=malloc(sizeof(pthread_mutex_t));
		node->twostagesem[0]=malloc(sizeof(int));
		node->twostagesem[1]=malloc(sizeof(int));
		node->mem=malloc(memsize);
		node->memsize=memsize;

		threadTreeFuncArgs* treeArgs=malloc(sizeof(threadTreeFuncArgs));
			
		treeArgs->func=(u_int64_t*(*)(void*))pfunc;
		treeArgs->running=node->running;
		treeArgs->mutex=node->mutex;
		treeArgs->actualArgs=args;
		treeArgs->twostagesem[0]=node->twostagesem[0];
		treeArgs->twostagesem[1]=node->twostagesem[1];
		treeArgs->mem=node->mem;
		treeArgs->memsize=node->memsize;

		pthread_cond_init(node->running,NULL);
		*(node->twostagesem[0])=startRunning;
		*(node->twostagesem[1])=0;
		node->args=treeArgs;
		node->nsize=nsize;
		pthread_create(node->thread,NULL,(void*(*)(void*))threadTreeFuncRun,node->args);
		return node;


}

static thread_tree_node* generateWorkHorse(int nheight,int nsize,u_int64_t memsize,void* (*pfunc)(void*),void* args,int startRunning){
	if(nheight==1){

		return createNewThreadNode(nsize,memsize,pfunc,args,startRunning);

	}
	else{


		thread_tree_node* node= createNewThreadNode(nsize,memsize,pfunc,args,startRunning);

		for(int i=0;i<nsize;i++){

			node->children[i]=generateWorkHorse(nheight-1,nsize,memsize,pfunc,args,startRunning);


		}
		return node;
	}


}
thread_tree_node* generateTree(int nheight,int nsize,u_int64_t memsize,void* (*pfunc)(void*),void* args,int startRunning){
	if(nheight<=0){
		perror("A node has to have 1 or more height. NULL tree will be returned\n");
		return NULL;
	}
	thread_tree_node* tree=generateWorkHorse(nheight,nsize,memsize,pfunc,args,startRunning);
	return tree;


}

static void freezeWorkHorse(thread_tree_node* tree){
	
	if(!tree){

		return;
	}
	for(int i=0;i<tree->nsize;i++){


	
	if(tree->children[i]){
		if(*(tree->children[i]->twostagesem[0])){

			pthread_mutex_lock(tree->children[i]->mutex);
			*(tree->children[i]->twostagesem[0])=0;
			pthread_mutex_unlock(tree->children[i]->mutex);
	
		}
		else{
			
			pthread_mutex_lock(tree->children[i]->mutex);
			*(tree->children[i]->twostagesem[0])=1;
			pthread_cond_signal(tree->children[i]->running);
			pthread_mutex_unlock(tree->children[i]->mutex);
	
		}
	
	}


	}
	if(*(tree->twostagesem[0])){

			pthread_mutex_lock(tree->mutex);
			*(tree->twostagesem[0])=0;
			pthread_mutex_unlock(tree->mutex);
		}
		else{

			pthread_mutex_lock(tree->mutex);
			*(tree->twostagesem[0])=1;
			pthread_cond_signal(tree->running);
			pthread_mutex_unlock(tree->mutex);
		
	}
	
	
}

void freezeTree(thread_tree_node*tree){
	
	if(!tree){

	return;
	}
	freezeWorkHorse(tree);
}

static void terminateWorkHorse(thread_tree_node* tree){
	
	if(!tree){

		return;
	}
	for(int i=0;i<tree->nsize;i++){


	
	if(tree->children[i]){

			
		*(tree->children[i]->twostagesem[1])=1;
	
	
	}


	}
			*(tree->twostagesem[1])=1;
	
	
}

void terminateTree(thread_tree_node*tree){
	
	if(!tree){

	return;
	}
	terminateWorkHorse(tree);
}

static void joinWorkHorse(thread_tree_node* tree){
	
	if(!tree){

		return;
	}
	for(int i=0;i<tree->nsize;i++){


	if(tree->children[i]){
		*(tree->children[i]->twostagesem[1])=1;
		joinWorkHorse(tree->children[i]);
		pthread_join(*(tree->children[i]->thread),NULL);
	}


	}
	*(tree->twostagesem[1])=1;
	pthread_join(*(tree->thread),NULL);
	
}



void joinTree(thread_tree_node* tree){
		
	if(!tree){

	return;
	}
		joinWorkHorse(tree);
	
}

static void detachWorkHorse(thread_tree_node* tree){
	
	if(!tree){

		return;
	}
	for(int i=0;i<tree->nsize;i++){


	if(!tree->children[i]){
		
	}
	else{
		detachWorkHorse(tree->children[i]);
		pthread_detach(*(tree->children[i]->thread));
	}


	}
	pthread_detach(*(tree->thread));
	
}


void detachTree(thread_tree_node* tree){
	
	if(!tree){

	return;
	}
	detachWorkHorse(tree);


}


static void destroyThreadTreeNode(thread_tree_node* node){

	if(!node){

	return;
	}
	pthread_cond_destroy(node->running);
	pthread_mutex_destroy(node->mutex);
	free(node->running);
	free(node->mutex);
	free(node->twostagesem[0]);
	free(node->twostagesem[1]);
	free(node->args->mem);
	free(node->args);
	free(node->thread);
	free(node->children);
	free(node);
	node=NULL;
	
}
static void destroyWorkOnNode(thread_tree_node* tree);
	

static void destroyWorkOnArray(thread_tree_node** array,int size);
	

static void destroyWorkOnArray(thread_tree_node** array,int size){
	

	for(int i=0;i<size;i++){
		destroyWorkOnNode(array[i]);
		
	}

}
   
static void destroyWorkOnNode(thread_tree_node* tree){
	
	if(!tree){

		return;
	}	

		destroyWorkOnArray(tree->children,tree->nsize);
		destroyThreadTreeNode(tree);

}

void destroyTree(thread_tree_node* tree){

	
	if(!tree){

	return;
	}
	destroyWorkOnNode(tree);
}
