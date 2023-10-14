#include "../Includes/preprocessor.h"
	
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

int treeIsRunning(thread_tree* tree){

	
	return checkRunningOnNode(tree->root);


}
static thread_tree_node* createNewThreadNode(int nsize,void* (*pfunc)(pausableFuncArgs*),void* args,int startRunning){
		
		thread_tree_node* node=malloc(sizeof(thread_tree_node));
		node->thread=malloc(sizeof(pthread_t));
		node->children=malloc(nsize*(sizeof(thread_tree_node*)));
		memset(node->children,0,nsize*(sizeof(thread_tree_node*)));
		node->running=malloc(sizeof(pthread_cond_t));
		node->mutex=malloc(sizeof(pthread_mutex_t));
		node->twostagesem[0]=malloc(sizeof(int));
		node->twostagesem[1]=malloc(sizeof(int));
		node->mem=malloc(sizeof(int));


		pausableFunc* newFunc=malloc(sizeof(pausableFunc));
		newFunc->args=malloc(sizeof(pausableFuncArgs));

		newFunc->func=pfunc;
		newFunc->args->running=node->running;
		newFunc->args->mutex=node->mutex;
		newFunc->args->actualArgs=args;
		newFunc->args->twostagesem[0]=node->twostagesem[0];
		newFunc->args->twostagesem[1]=node->twostagesem[1];
		newFunc->args->mem=node->mem;

		pthread_cond_init(node->running,NULL);
		*(node->twostagesem[0])=startRunning;
		*(node->twostagesem[1])=0;
		node->pfunc=newFunc;
		node->nsize=nsize;
		pthread_create(node->thread,NULL,(void*(*)(void*))node->pfunc->func,node->pfunc->args);
		return node;


}

static thread_tree_node* generateWorkHorse(int nheight,int nsize,void* (*pfunc)(pausableFuncArgs*),void* args,int startRunning){
	if(!nheight){

		return createNewThreadNode(nsize,pfunc,args,startRunning);

	}
	else{


		thread_tree_node* node= createNewThreadNode(nsize,pfunc,args,startRunning);

		for(int i=0;i<nsize;i++){

			node->children[i]=generateWorkHorse(nheight-1,nsize,pfunc,args,startRunning);


		}
		return node;
	}


}

thread_tree* generateTree(int nheight,int nsize,void* (*pfunc)(pausableFuncArgs*),void* args,int startRunning){
	
	thread_tree* tree= malloc(sizeof(thread_tree));
	tree->root=generateWorkHorse(nheight,nsize,pfunc,args,startRunning);
	tree->nheight=nheight;
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

void freezeTree(thread_tree*tree){
	
	freezeWorkHorse(tree->root);
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

void terminateTree(thread_tree*tree){
	
	terminateWorkHorse(tree->root);
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



void joinTree(thread_tree* tree){
	
		joinWorkHorse(tree->root);
	
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


void detachTree(thread_tree* tree){

	detachWorkHorse(tree->root);


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
	free(node->pfunc->args->mem);
	free(node->pfunc->args);
	free(node->pfunc);
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

void destroyTree(thread_tree* tree){


	destroyWorkOnNode(tree->root);
	free(tree);
	tree=NULL;
}
