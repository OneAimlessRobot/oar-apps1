#include "../Includes/preprocessor.h"
  
	
static int noChildren(thread_tree_node* node){

	
	for(int i=0;i<node->nsize;i++){

		if(node->children[i]){

			return 0;
		}
	}
	return 1;


}
static int sumTreeResultsOnArray(thread_tree_node**array,int nsizetwo);

static int sumTreeResultsOnNode(thread_tree_node* node);

static int sumTreeResultsOnArray(thread_tree_node**array,int nsizetwo){

	if(nsizetwo>=0){
  		return sumTreeResultsOnNode(array[nsizetwo])+sumTreeResultsOnArray(array,nsizetwo-1);
	}
		return 0;
}
static int sumTreeResultsOnNode(thread_tree_node* node){


	
		if(noChildren(node)){
				return (int)(*((int*)node->mem));
                  
			}
		
		return (int)(*((int*)node->mem))+ sumTreeResultsOnArray(node->children,node->nsize-1);
		
	}

int sumTreeResults(thread_tree_node* tree){

	if(!tree){

	return 0;
	}
	return sumTreeResultsOnNode(tree);


}

