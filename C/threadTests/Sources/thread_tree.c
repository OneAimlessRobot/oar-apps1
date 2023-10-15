#include "../Includes/preprocessor.h"

void* nodeValOp(thread_tree_node*lootnode,nodeValueOp mode,void* value,u_int64_t memsize){
	void* result=NULL;
	if(memsize>lootnode->memsize){
		memsize=lootnode->memsize;

	}
	switch(mode){
		case CHECKVAL:
		pthread_mutex_lock(lootnode->mutexes[2]);
		result=lootnode->mem;
		pthread_mutex_unlock(lootnode->mutexes[2]);
		return result;
		case SETVAL:
		pthread_mutex_lock(lootnode->mutexes[2]);
		memcpy(lootnode->mem,value,memsize);
		pthread_mutex_unlock(lootnode->mutexes[2]);
		return NULL;
		default:
		perror("Invalid value op on node!!!\n");
		return NULL;
	}

}  


static int doOpOnNode(thread_tree_node*worker,int val,int whichVal,nodeOp mode){

		int result=0;
	switch(mode){
		case CHECKVAR:
		pthread_mutex_lock(worker->mutexes[whichVal]);
		result=*(worker->twostagesem[whichVal]);
		pthread_mutex_unlock(worker->mutexes[whichVal]);
		return result;
		break;
		case SETVAR:	
		pthread_mutex_lock(worker->mutexes[whichVal]);
		*(worker->twostagesem[whichVal])=val;
		pthread_mutex_unlock(worker->mutexes[whichVal]);
		return -1;
		break;
		case TOGGLEFREEZE:
		pthread_mutex_lock(worker->mutexes[whichVal]);
		if(*(worker->twostagesem[whichVal])){
		
		*(worker->twostagesem[whichVal])=0;
		
		}
		else{
		
		*(worker->twostagesem[whichVal])=1;
		pthread_cond_signal(worker->condVars[whichVal]);
		
		}
		pthread_mutex_unlock(worker->mutexes[whichVal]);

		return -2;
		break;
		case SETFREEVAR:
		
		pthread_mutex_lock(worker->mutexes[whichVal]);
		*(worker->twostagesem[whichVal])=val;
		pthread_cond_signal(worker->condVars[whichVal]);
		pthread_mutex_unlock(worker->mutexes[whichVal]);
		return -3;
		break;
		case CANCELNODE:
		pthread_mutex_lock(worker->mutexes[1]);
		pthread_mutex_lock(worker->mutexes[0]);
		*(worker->twostagesem[1])=1;
		*(worker->twostagesem[0])=0;
		pthread_cond_signal(worker->condVars[0]);
		pthread_mutex_unlock(worker->mutexes[1]);
		pthread_mutex_unlock(worker->mutexes[0]);
		return -4;
		break;
		case TOGGLEVARNORMALLY:
		pthread_mutex_lock(worker->mutexes[whichVal]);
		
		if(*(worker->twostagesem[whichVal])){

		*(worker->twostagesem[whichVal])=0;
		
		}
		else{
		*(worker->twostagesem[whichVal])=1;
		
		}
		pthread_mutex_unlock(worker->mutexes[whichVal]);
		return -5;
		break;
		default:
		perror("Bad OP code on node: 0 for checking var with index 'whichVar'\n 1 for setting var with index\n 2 for toggling\n 3 for unlocking with index\n 4 for locking with index\n");
		return -6;
		break;




	}



}

static void* threadTreeFuncRun(void* argv){
	threadTreeFuncArgs* args=(threadTreeFuncArgs*)argv;
	while(1){
		pthread_mutex_lock(args->spawner->mutexes[0]);
		while(!*(args->spawner->twostagesem[1])&&!*(args->spawner->twostagesem[0])){

		pthread_cond_wait(args->spawner->condVars[0],args->spawner->mutexes[0]);
		}
		pthread_mutex_unlock(args->spawner->mutexes[0]);
		if(doOpOnNode(args->spawner,0,0,CHECKVAR)){
			void*resultMem=args->func(args->actualArgs);
			nodeValOp(args->spawner,SETVAL,resultMem,args->spawner->memsize);
			free(resultMem);
		}
		doOpOnNode(args->spawner,0,0,SETVAR);
		if(doOpOnNode(args->spawner,0,1,CHECKVAR)){

			return NULL;
		}
	}
	return NULL;



}
static int noChildren(thread_tree_node* node){

	if(!node){

		return 1;
	}
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
				
		if(!node){

			return 0;
		}



		if(noChildren(node)){
			return doOpOnNode(node,0,0,CHECKVAR);
			}
		return doOpOnNode(node,0,0,CHECKVAR) ||checkRunningOnArray(node->children,node->nsize-1);
			
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
		node->mutexes[0]=malloc(sizeof(pthread_mutex_t));
		node->mutexes[1]=malloc(sizeof(pthread_mutex_t));
		node->mutexes[2]=malloc(sizeof(pthread_mutex_t));
		node->condVars[0]=malloc(sizeof(pthread_cond_t));
		node->twostagesem[0]=malloc(sizeof(int));
		node->twostagesem[1]=malloc(sizeof(int));
		node->mem=malloc(memsize);
		node->memsize=memsize;
		node->args=malloc(sizeof(threadTreeFuncArgs));
		node->nsize=nsize;
		
		
		node->args->func=pfunc;
		node->args->actualArgs=args;
		node->args->spawner=node;

		pthread_mutex_init(node->mutexes[0],NULL);
		pthread_mutex_init(node->mutexes[1],NULL);
		pthread_mutex_init(node->mutexes[2],NULL);
		pthread_cond_init(node->condVars[0],NULL);
		*(node->twostagesem[0])=startRunning;
		*(node->twostagesem[1])=0;
		pthread_create(node->thread,NULL,threadTreeFuncRun,node->args);
		return node;


}

static thread_tree_node* generateWorkHorse(int nheight,int nsize,u_int64_t memsize,void* (*pfunc)(void*),void* args,int startRunning){
	if(nheight==1){

		return createNewThreadNode(nsize,memsize,pfunc,args,startRunning);

	}
	else{


		thread_tree_node* node= createNewThreadNode(nsize,memsize,pfunc,args,startRunning);
		nheight--;
		for(int i=0;i<nsize;i++){

			node->children[i]=generateWorkHorse(nheight,nsize,memsize,pfunc,args,startRunning);


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

static void loopWorkHorse(thread_tree_node* tree){
	
	if(!tree){

		return;
	}
	for(int i=0;i<tree->nsize;i++){


	
	if(tree->children[i]){
	
		doOpOnNode(tree->children[i],0,3,TOGGLEVARNORMALLY);
	}


	}
	doOpOnNode(tree,0,3,TOGGLEVARNORMALLY);
	
}

void loopTree(thread_tree_node*tree){
	
	if(!tree){

	return;
	}
	loopWorkHorse(tree);
}

static void freezeWorkHorse(thread_tree_node* tree){
	
	if(!tree){

		return;
	}
	if(noChildren(tree)){
		
	doOpOnNode(tree,0,0,TOGGLEFREEZE);
	

	}
	for(int i=0;i<tree->nsize;i++){


	
	if(tree->children[i]){
	
		freezeWorkHorse(tree->children[i]);
	}


	}
	doOpOnNode(tree,0,0,TOGGLEFREEZE);
	

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
	if(noChildren(tree)){
		
	doOpOnNode(tree,0,0,CANCELNODE);
	

	}
	for(int i=0;i<tree->nsize;i++){


	
	if(tree->children[i]){

		terminateWorkHorse(tree->children[i]);
	
	}


	}
		doOpOnNode(tree,1,1,CANCELNODE);
			

		
			
	
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
		
		joinWorkHorse(tree->children[i]);
		pthread_join(*(tree->children[i]->thread),NULL);
	}


	}
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
	pthread_cond_destroy(node->condVars[0]);
	pthread_mutex_destroy(node->mutexes[0]);
	pthread_mutex_destroy(node->mutexes[1]);
	pthread_mutex_destroy(node->mutexes[2]);

	free(node->mutexes[0]);
	free(node->mutexes[1]);
	free(node->mutexes[2]);
	free(node->condVars[0]);
	free(node->twostagesem[0]);
	free(node->twostagesem[1]);
	free(node->mem);
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
