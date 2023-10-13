#include "../Includes/preprocessor.h"


int treeIsFrozen(thread_tree*tree){

	return !(*(tree->twowaysem[0]));

}
static thread_tree_node* createNewThreadNode(int nsize,void* (*pfunc)(pausableFuncArgs*),void* args,int* semaphore[2]){
		
		pausableFunc* newFunc=malloc(sizeof(pausableFunc));
		newFunc->args=malloc(sizeof(pausableFuncArgs));
		newFunc->args->mem=malloc(sizeof(int));
		thread_tree_node* node=malloc(sizeof(thread_tree_node));
		newFunc->func=pfunc;
		newFunc->args->actualArgs=args;
		newFunc->args->twowaysem[0]=semaphore[0];
		newFunc->args->twowaysem[1]=semaphore[1];
		node->pfunc=newFunc;
		node->mem=newFunc->args->mem;
		node->nsize=nsize;
		node->thread=malloc(sizeof(pthread_t));
		node->children=malloc(node->nsize*(sizeof(thread_tree_node*)));
		memset(node->children,0,node->nsize*(sizeof(thread_tree_node*)));
		pthread_create(node->thread,NULL,(void*(*)(void*))node->pfunc->func,node->pfunc->args);
		return node;


}

static thread_tree_node* generateWorkHorse(int nheight,int nsize,void* (*pfunc)(pausableFuncArgs*),void* args,int*semaphore[2]){
	if(!nheight){

		return createNewThreadNode(nsize,pfunc,args,semaphore);

	}
	else{


		thread_tree_node* node= createNewThreadNode(nsize,pfunc,args,semaphore);

		for(int i=0;i<nsize;i++){

			node->children[i]=generateWorkHorse(nheight-1,nsize,pfunc,args,semaphore);


		}
		return node;
	}


}

thread_tree* generateTree(int nheight,int nsize,void* (*pfunc)(pausableFuncArgs*),void* args,int startFrozen){
	
	thread_tree* tree= malloc(sizeof(thread_tree));
	tree->twowaysem[0]= malloc(sizeof(int));
	tree->twowaysem[1]=malloc(sizeof(int));
	*(tree->twowaysem[0])= !startFrozen;
	*(tree->twowaysem[1])=0;
	tree->root=generateWorkHorse(nheight,nsize,pfunc,args,tree->twowaysem);
	tree->nsize=nsize;
	tree->nheight=nheight;
	return tree;


}

void freezeTree(thread_tree*tree){
	
	if(*(tree->twowaysem[0])){
		*(tree->twowaysem[0])=0;
		return;
	}
	*(tree->twowaysem[0])=1;
}


static void joinWorkHorse(thread_tree_node* tree){
	
	if(!tree){

		return;
	}
	for(int i=0;i<tree->nsize;i++){


	if(!tree->children[i]){
		
	}
	else{
		joinWorkHorse(tree->children[i]);
		pthread_join(*(tree->children[i]->thread),NULL);
	}


	}
	pthread_join(*(tree->thread),NULL);
	
}



void joinTree(thread_tree* tree){
	
	
	*(tree->twowaysem[0])=0;
	
	*(tree->twowaysem[1])=1;
	
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
	free(tree->twowaysem[0]);
	free(tree->twowaysem[1]);
	free(tree);
	tree=NULL;
}
