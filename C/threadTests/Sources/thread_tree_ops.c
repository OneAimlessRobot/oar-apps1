#include "../Includes/preprocessor.h"

static int64_t sumTreeResultsOnArray(thread_tree_node**array,int nsizetwo);

static int64_t sumTreeResultsOnNode(thread_tree_node* node);

static int64_t sumTreeResultsOnArray(thread_tree_node**array,int nsizetwo){

	if(nsizetwo>=0){
  		return sumTreeResultsOnNode(array[nsizetwo])+sumTreeResultsOnArray(array,nsizetwo-1);
	}
		return 0;
}
static int64_t sumTreeResultsOnNode(thread_tree_node* node){
		
		if(!node){

			return 0;
		}

		if(noChildren(node)){
				return (int64_t)(*((int64_t*)nodeValOp(node,CHECKVAL,NULL,node->memsize)));
                  
		}
		return (int64_t)(*((int64_t*)nodeValOp(node,CHECKVAL,NULL,node->memsize)))+ sumTreeResultsOnArray(node->children,node->nsize-1);
		
	}

int64_t sumTreeResults(thread_tree_node* tree){

	if(!tree){

	return 0;
	}
	return sumTreeResultsOnNode(tree);


}

