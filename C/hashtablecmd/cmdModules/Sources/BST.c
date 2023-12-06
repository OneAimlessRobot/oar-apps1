#include "../../Includes/preprocessor.h"
#include "../Includes/preprocessor.h"
#include "../../Includes/nodes.h"
#include "../Includes/BST.h"

static pathStep* initLastStep(BSTNode* node, int isLeft){

pathStep* step= malloc(sizeof(pathStep));
step->parent=node;
step->isLeft=isLeft;

return step;

}
static pathStep* setLastStep(pathStep*step,BSTNode* node, int isLeft){

step->parent=node;
step->isLeft=isLeft;

return step;

}

static void destroyPathStep(pathStep*step){

free(step);
step=NULL;

}


static BSTNode* initNakedBSTNode(void*initmem){
BSTNode* node= malloc(sizeof(BSTNode));
node->left=NULL;
node->right=NULL;
node->mem= initmem;
return node;
}


static BSTNode* initBSTNode(void*initmem,BSTNode* left, BSTNode* right){
BSTNode* node= initNakedBSTNode(initmem);
node->left=left;
node->right=right;
return node;


}



static int isLeaf(BSTNode* node){

	return !node->left && !node->right;
}
static void destroyBSTNode(BSTNode* node){

	if(node->left){
	node->left=NULL;
	}
	if(node->right){
	node->right=NULL;
	}
	
	free(node->mem);
	node->mem=NULL;
	free(node);
	node=NULL;
	
}
static void clearBSTNode(BSTNode* node){

	free(node->mem);
	node->mem=NULL;

}

static void printBSTreePrettyAux(BSTNode*node, int numOfSpaces){


	if(!node){

		return;
	}
	if(isLeaf(node)){

		for(int i=0;i<numOfSpaces;i++){

		printf("|");

		}
		printf("%d\n",*(int*)(node->mem));
		

	}
	else {
		
		for(int i=0;i<numOfSpaces;i++){

		printf("|");

		}
		printf("%d\n",*(int*)(node->mem));
				
			if(node->right){

				printBSTreePrettyAux(node->right,numOfSpaces+1);
			
			}
			
			if(node->left){
				
				printBSTreePrettyAux(node->left,numOfSpaces+1);
			}
			
			
		
		}

	}

void printBSTreePretty(BSTree*tree){



	if(!tree->root){

		return;
	}
	printBSTreePrettyAux(tree->root,0);
	

}


static BSTNode* findNodeInBSTree(BSTree* tree,void* data){
	
	BSTNode* result=tree->root;
	tree->lastStep=setLastStep(tree->lastStep,result,0);
	if(!tree->root){
		return NULL;

	}
	while(result&&memcmp(data,result->mem,tree->elemSize)){
	if(memcmp(data,result->mem,tree->elemSize)<0){

	tree->lastStep=setLastStep(tree->lastStep,result,1);
		
	result=result->left;

	}
	else if(memcmp(data,result->mem,tree->elemSize)>0){

		
	tree->lastStep=setLastStep(tree->lastStep,result,0);
	result=result->right;
	}
	}
	return result;


}

BSTree* initBSTree(u_int64_t elemSize){

BSTree* tree= malloc(sizeof(BSTree));
tree->root=NULL;
tree->currSize=0;
tree->elemSize=elemSize;
tree->lastStep=initLastStep(NULL,0);
return tree;


}

static void linkSubtree(BSTree*tree,BSTNode* node){
	if(!tree->lastStep){
		
		return;

	}
	
	if(tree->lastStep->parent){
		
		if(tree->lastStep->isLeft){
			tree->lastStep->parent->left=node;
			return;
		}
		else{
			tree->lastStep->parent->right=node;
			return;
		}
		
		
		
	}
	


}
void addToBSTree(BSTree* tree,void* elem){
BSTNode* node= initNakedBSTNode(elem);
	if(!tree->root){

		tree->root=node;
		tree->currSize++;
		return;
	}
	else{
		void* result=NULL;
		if(!(result=findInBSTree(tree,elem))){
		linkSubtree(tree,node);
		tree->currSize++;
		}
		else{
		destroyBSTNode(node);
		}

	}


}

static BSTNode* minNode(BSTree* tree,BSTNode* node){

	BSTNode* result= node;
	
	while(result->left){
		setLastStep(tree->lastStep,result,1);
		result=result->left;
		
	}
	return result;


}
void removeFromBSTree(BSTree* tree,void* elem){

	if(tree->root){
		BSTNode* node=NULL;
		if((node=findNodeInBSTree(tree,elem))){
			
			printf("%d\n",*(int*)(node->mem));
		if(isLeaf(node)){
			
			if(tree->lastStep->isLeft){
			tree->lastStep->parent->left=NULL;
			destroyBSTNode(node);
			
			}
			else{
			tree->lastStep->parent->right=NULL;
			destroyBSTNode(node);
			
			}

		}
		else if(!node->left&&node->right){

			linkSubtree(tree,node->right);
			destroyBSTNode(node);


		}
		else if(!node->right&&node->left){

			linkSubtree(tree,node->left);
			destroyBSTNode(node);
		}
		else{
			BSTNode* minNodeHere=node;
			if(node->right){
			minNodeHere=node->right;
			}

			setLastStep(tree->lastStep,node,0);
			minNodeHere=minNode(tree,minNodeHere);
			memset(node->mem,0,tree->elemSize);
			memcpy(node->mem,minNodeHere->mem,tree->elemSize);
			linkSubtree(tree,minNodeHere->right);
			destroyBSTNode(minNodeHere);
			
			}
		tree->currSize--;
		}
	}
}


void printIntBSTreeDepth(BSTree*tree){


	if(!tree->root){

		return;
	}

	stackList*stck= initDLStack(sizeof(BSTNode));
	pushDLStack(stck,tree->root);
	
	while(!isEmptyDLStack(stck)){

		BSTNode* node=popDLStack(stck);
		printf("%d\n",*(int*)(node->mem));
		
		if(node){
		if(!isLeaf(node)){
			if(node->left){

			pushDLStack(stck,node->left);
			}
			
			if(node->right){

			pushDLStack(stck,node->right);
			}
			
		
		}
		}

	}
	destroyDLStack(stck);



}


void printIntBSTreeInfix(BSTree*tree){



	if(!tree->root){

		return;
	}

	stackList*stck= initDLStack(sizeof(BSTNode));
	BSTNode* node=tree->root;
	pushDLStack(stck,(node=tree->root));
	while(node->left){
	
		pushDLStack(stck,node->left);
		node=node->left;
		
	}
	while(!isEmptyDLStack(stck)){

		BSTNode* node=popDLStack(stck);
		printf("%d\n",*(int*)(node->mem));
		
		if(node){
			if(node->right){
			pushDLStack(stck,node->right);
			node=node->right;
			while(node->left){
				
				pushDLStack(stck,node->left);
				node=node->left;
			}
			
		
		}
		}

	}
	destroyDLStack(stck);

}
void printIntBSTreeBreadth(BSTree*tree){

	if(!tree->root){

		return;
	}

	queueList*q= initDLQueue(sizeof(BSTNode));
	enqueueDLQueue(q,tree->root);
	
	while(!isEmptyDLQueue(q)){

		BSTNode* node=dequeueDLQueue(q);
		printf("%d\n",*(int*)(node->mem));
		
		if(node){
		if(!isLeaf(node)){
			if(node->left){

			enqueueDLQueue(q,node->left);
			}
			
			if(node->right){

			enqueueDLQueue(q,node->right);
			}
			
		
		}
		}

	}
	destroyDLQueue(q);


}
static void destroyBSTreeAux(BSTNode* node){

	if(!node){
	return;
	}
	
	if(node->left&&!node->right){
	destroyBSTreeAux(node->left);
	}
	else if(node->right&&!node->left){
	destroyBSTreeAux(node->right);
	}
	else if(!isLeaf(node)){
	destroyBSTreeAux(node->right);
	destroyBSTreeAux(node->left);
	}

	destroyBSTNode(node);

}
void destroyBSTree(BSTree* tree){

	destroyBSTreeAux(tree->root);
	free(tree->lastStep);
	tree->lastStep=NULL;
	free(tree);
	tree=NULL;
}



void* findInBSTree(BSTree* tree, void* data){

	BSTNode* result=NULL;
	if((result=findNodeInBSTree(tree,data))){
		
		return result->mem;

	}
	return NULL;
}


static int compareInts(int* a, int* b){
	
	return (*a)-(*b);
}

BSTree* makeIntTree(int arr[],int arrSize){

	BSTree* tree= initBSTree(sizeof(int));
	
	for(int i=0;i<arrSize;i++){
	int * ptr=malloc(sizeof(int));
	*ptr=i;
	addToBSTree(tree,ptr);
		
	}
	return tree;



}
