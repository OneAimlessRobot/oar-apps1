#ifndef THREAD_TREE_H
#define THREAD_TREE_H


typedef struct pausableFuncArgs{
	int*mem;
	void* actualArgs;
	int* twowaysem[2];

}pausableFuncArgs;

typedef struct pausableFunc{
	
	pausableFuncArgs* args;
	void* (*func)(pausableFuncArgs*);//the int serves the purpose of making the function paused or not
	
}pausableFunc;

typedef struct thread_tree_node{
int nsize;
int* mem;
pausableFunc* pfunc;
pthread_t* thread;
struct thread_tree_node** children;
}thread_tree_node;
 

typedef struct thread_tree{
int nsize,nheight;
int* twowaysem[2];
thread_tree_node* root;

}thread_tree;

thread_tree* generateTree(int nheight,int nsize,void* (*pfunc)(pausableFuncArgs*),void* args,int startFrozen);


void freezeTree(thread_tree*tree);

int treeIsFrozen(thread_tree*tree);


void joinTree(thread_tree* tree);
void detachTree(thread_tree* tree);
void destroyTree(thread_tree* tree);
#endif
