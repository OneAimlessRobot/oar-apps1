#include "../Includes/preprocessor.h"

int noChildren(thread_tree_node* node){

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

static void* threadTreeNodeFuncRun(void* argv){
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

void* nodeValOp(thread_tree_node*lootnode,nodeValueOp mode,void* value,u_int64_t memsize){
	void* result=NULL;
	pthread_mutex_lock(lootnode->mutexes[2]);
		
	if(memsize>lootnode->memsize){
		memsize=lootnode->memsize;

	}
	switch(mode){
		case CHECKVAL:
		result=lootnode->mem;;
		break;
		case SETVAL:
		memcpy(lootnode->mem,value,memsize);
		result= NULL;
		break;
		default:
		perror("Invalid value op on node!!!\n");
		result= NULL;
		break;
	}
	pthread_mutex_unlock(lootnode->mutexes[2]);
	
	return result;	

}  


int doOpOnNode(thread_tree_node*worker,int val,int whichVal,nodeOp mode){

		int result=0;
	pthread_mutex_lock(worker->mutexes[1]);
	pthread_mutex_lock(worker->mutexes[0]);
	switch(mode){
		case CHECKVAR:
		result=*(worker->twostagesem[whichVal]);
		break;
		case SETVAR:	
		*(worker->twostagesem[whichVal])=val;
		result= -1;
		break;
		case TOGGLEFREEZE:
		if(*(worker->twostagesem[whichVal])){
		
		*(worker->twostagesem[whichVal])=0;
		
		}
		else{
		
		*(worker->twostagesem[whichVal])=1;
		pthread_cond_signal(worker->condVars[whichVal]);
		
		}
		
		result=-2;
		break;
		case SETFREEVAR:
		
		*(worker->twostagesem[whichVal])=val;
		pthread_cond_signal(worker->condVars[whichVal]);
		result= -3;
		break;
		case CANCELNODE:
		*(worker->twostagesem[1])=1;
		*(worker->twostagesem[0])=0;
		pthread_cond_signal(worker->condVars[0]);
		result= -4;
		break;
		case TOGGLEVARNORMALLY:
		
		if(*(worker->twostagesem[whichVal])){

		*(worker->twostagesem[whichVal])=0;
		
		}
		else{
		*(worker->twostagesem[whichVal])=1;
		
		}
		result= -5;
		break;
		default:
		perror("Bad OP code on node: 0 for checking var with index 'whichVar'\n 1 for setting var with index\n 2 for toggling\n 3 for unlocking with index\n 4 for locking with index\n");
		result= -6;
		break;




	}

pthread_mutex_unlock(worker->mutexes[0]);
pthread_mutex_unlock(worker->mutexes[1]);
		return result;

}

thread_tree_node* createNewThreadNode(int nsize,u_int64_t memsize,void* (*pfunc)(void*),void* args,int startRunning){
		
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
		pthread_create(node->thread,NULL,threadTreeNodeFuncRun,node->args);
		return node;


}

void destroyThreadTreeNode(thread_tree_node* node){

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
