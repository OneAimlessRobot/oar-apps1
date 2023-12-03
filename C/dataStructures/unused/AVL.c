#include "../Includes/preprocessor.h"
#include "../Includes/comparator.h"
#include "../Includes/AVL.h"


static pathStep* initAVLLastStep(AVLNode* node, int isLeft){

pathStepAVL* step= malloc(sizeof(pathStepAVL));
step->parent=node;
step->isLeft=isLeft;

return step;

}
static pathStep* setLastStep(pathStep*step,AVLNode* node, int isLeft){

step->parent=node;
step->isLeft=isLeft;

return step;

}

static void destroyPathStep(pathStepAVL*step){

free(step);
step=NULL;

}


static void prinAVLTreePrettyAux(AVLNode*node, int numOfSpaces){


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

				printAVLreePrettyAux(node->right,numOfSpaces+1);
			
			}
			
			if(node->left){
				
				printAVLreePrettyAux(node->left,numOfSpaces+1);
			}
			
			
		
		}

	}



AVLNode* initAVLNode(void*initmem,AVLNode* left, AVLNode* right,AVLNodeType type){
AVLNode* node= initNakedAVLNode(initmem,type);
node->left=left;
node->right=right;
return node;



}
AVLNode* initNakedAVLNode(void*initmem,AVLNodeType type){
AVLNode* node= malloc(sizeof(AVLNode));
node->left=NULL;
node->right=NULL;
node->mem= initmem;
node->type=type;
return node;



}

AVLTree* initAVLree(comparator*comp){

AVLTree* tree= malloc(sizeof(AVLTree));
tree->root=NULL;
tree->currSize=0;
tree->comp=comp;
tree->lastStep=initDLStack();
pushDLStack(initLastStep(NULL,0));
return tree;



}

static void rotateNodesAVLTreeInsertion(AVLTree* tree){
  boolean grew= true;
        PathStep<T> lastStep=null;
        try {
                lastStep = path.pop();
        } catch (StackEmptyException e) {
        }
        AVLBSTNode<T> parent= (AVLBSTNode<T>)lastStep.parent;
        while(grew && parent!=null) {
                if(lastStep.isLeftChild) {
                        switch(parent.getType()) {
                        case E:
                                parent.setType(NodeType.L);
                                break;
                        case L:
                                rotateNodesLeft(parent);
                                grew=false;
                                break;
                        case R:
                                parent.setType(NodeType.E);
                                grew=false;
                                break;
                        default:
                                break;


                        }


                }else {

                        switch(parent.getType()) {
                        case E:
                                parent.setType(NodeType.R);
                                break;
                        case R:
                                rotateNodesRight(parent);
                                grew=false;
                                break;
                        case L:
                                parent.setType(NodeType.E);
                                grew=false;
                                break;
                        default:
                                break;


                        }

                }

                        lastStep = path.pop();
                
                parent= (AVLBSTNode<T>)lastStep.parent;

        }




}



}
void addToAVLTree(AVLTree* tree,void* elem){






}
void removeFromAVLTree(AVLTree* tree,void* elem);

void destroyAVLTree(AVLTree* tree);

void* findInAVLTree(AVLTree* tree, void* data);




static void findNodeInAVLTree(){


AVLNode* result=tree->root;
	tree->lastStep=setLastStep(tree->lastStep,result,0);
	if(!tree->root){
		return NULL;

	}
	while(result&&tree->comp->func(data,result->mem)){
	if(tree->comp->func(data,result->mem)<0){

	tree->lastStep=setLastStep(tree->lastStep,result,1);
		
	result=result->left;

	}
	else if(tree->comp->func(data,result->mem)>0){

		
	tree->lastStep=setLastStep(tree->lastStep,result,0);
	result=result->right;
	}
	}
	return result;

}
void* getAVLNodeMem(AVLNode* node);

void setAVLNodeMem(AVLNode* node, void* mem);

void setLeft(AVLNode* node, AVLNode**newLeft);

void setRight(AVLNode* node, AVLNode**newRight);

int isLeaf(AVLNode* node);

void destroyAVLNode(AVLNode* node);


void printIntAVLTreeBreadth(AVLTree*tree);

void printIntAVLTreeDepth(AVLTree*tree);

void printIntAVLTreeInfix(AVLTree*tree);

void printAVLTreePretty(AVLTree*tree);

AVLTree* makeIntAVLTree(int arr[],int arrSize);
