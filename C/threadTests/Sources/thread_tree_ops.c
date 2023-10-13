#include "../Includes/preprocessor.h"

int sumTreeResults(thread_tree* tree){
  
	
int noChildren(thread_tree_node* node){

	
	for(int i=0;i<node->nsize;i++){

		if(node->children[i]){

			return 0;
		}
	}
	return 1;


}

	int sumTreeResultsOnNode(thread_tree_node* node){


		int sumTreeResultsOnArray(thread_tree_node**array,int nsizetwo){

		if(nsizetwo>=0){
  			return sumTreeResultsOnNode(array[nsizetwo])+sumTreeResultsOnArray(array,nsizetwo-1);
			}
			return 0;
			}
	
		if(noChildren(node)){
				return (int)(node->mem[0]);
                  
			}
		
		return (int)(node->mem[0])+ sumTreeResultsOnArray(node->children,tree->nsize-1);
		
	}

	return sumTreeResultsOnNode(tree->root);


}

