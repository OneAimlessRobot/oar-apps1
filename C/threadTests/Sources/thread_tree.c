#include "../Includes/preprocessor.h"

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

