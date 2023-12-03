#ifndef BST_H
#define BST_H

#include "comparator.h"

typedef struct BSTNode{

void* mem;
struct BSTNode* left,*right;

}BSTNode;
typedef struct pathStep{

BSTNode* parent;
int isLeft;


}pathStep;


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

void* getBSTNodeMem(BSTNode* node);

void setBSTNodeMem(BSTNode* node, void* mem);

void setLeft(BSTNode* node, BSTNode**newLeft);

void setRight(BSTNode* node, BSTNode**newRight);

int isLeaf(BSTNode* node);

void destroyBSTNode(BSTNode* node);


void printIntBSTreeBreadth(BSTree*tree);

void printIntBSTreeDepth(BSTree*tree);

void printIntBSTreeInfix(BSTree*tree);

void printBSTreePretty(BSTree*tree);

BSTree* makeIntTree(int arr[],int arrSize);
#endif
