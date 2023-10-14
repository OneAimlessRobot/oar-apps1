#ifndef THREAD_TREE_H
#define THREAD_TREE_H


typedef struct pausableFuncArgs{
	void*mem;
	void* actualArgs;
	int* twostagesem[2];
	pthread_cond_t* running;
	pthread_mutex_t* mutex;
}pausableFuncArgs;

typedef struct pausableFunc{
	
	pausableFuncArgs* args;
	void* (*func)(pausableFuncArgs*);//the int serves the purpose of making the function paused or not
	
}pausableFunc;

typedef struct thread_tree_node{
int nsize;
void* mem;
int* twostagesem[2];
pthread_cond_t* running;
pthread_mutex_t* mutex;
pausableFunc* pfunc;
pthread_t* thread;
struct thread_tree_node** children;
}thread_tree_node;
 

typedef struct thread_tree{
int nheight;
thread_tree_node* root;

}thread_tree;

thread_tree* generateTree(int nheight,int nsize,void* (*pfunc)(pausableFuncArgs*),void* args,int startRunning);


void freezeTree(thread_tree*tree);
void terminateTree(thread_tree*tree);
int treeIsRunning(thread_tree*tree);


void joinTree(thread_tree* tree);
void detachTree(thread_tree* tree);
void destroyTree(thread_tree* tree);
#endif
