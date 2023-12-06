#ifndef BST_H
#define BST_H

typedef struct BSTree{

u_int64_t currSize, elemSize;
BSTNode* root;
pathStep* lastStep;

}BSTree;



BSTree* initBSTree(u_int64_t elemSize);


void addToBSTree(BSTree* tree,void* elem);

void removeFromBSTree(BSTree* tree,void* elem);

void destroyBSTree(BSTree* tree);

void* findInBSTree(BSTree* tree, void* data);




void printIntBSTreeBreadth(BSTree*tree);

void printIntBSTreeDepth(BSTree*tree);

void printIntBSTreeInfix(BSTree*tree);

void printBSTreePretty(BSTree*tree);

BSTree* makeIntTree(int arr[],int arrSize);
#endif
