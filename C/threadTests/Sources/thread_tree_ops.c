#include "../Includes/preprocessor.h"

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
static u_int64_t sumTreeResultsOnArray(thread_tree_node**array,int nsizetwo);

static u_int64_t sumTreeResultsOnNode(thread_tree_node* node);

static u_int64_t sumTreeResultsOnArray(thread_tree_node**array,int nsizetwo){

	if(nsizetwo>=0){
  		return sumTreeResultsOnNode(array[nsizetwo])+sumTreeResultsOnArray(array,nsizetwo-1);
	}
		return 0;
}
static u_int64_t sumTreeResultsOnNode(thread_tree_node* node){
		
		if(!node){

			return 0;
		}

		if(noChildren(node)){
				return (u_int64_t)(*((u_int64_t*)nodeValOp(node,CHECKVAL,NULL,node->memsize)));
                  
		}
		return (u_int64_t)(*((u_int64_t*)nodeValOp(node,CHECKVAL,NULL,node->memsize)))+ sumTreeResultsOnArray(node->children,node->nsize-1);
		
	}

u_int64_t sumTreeResults(thread_tree_node* tree){

	if(!tree){

	return 0;
	}
	return sumTreeResultsOnNode(tree);


}

