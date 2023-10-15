#ifndef THREAD_TREE_H
#define THREAD_TREE_H


typedef struct threadTreeFuncArgs{
	void*mem;
	int memsize;
	void* actualArgs;
	void* (*func)(void*);
	int* twostagesem[2];
	pthread_cond_t* running;
	pthread_mutex_t* mutex,*mutex2,*mutex3;
}threadTreeFuncArgs;

typedef struct thread_tree_node{
int nsize;
u_int64_t memsize;
void* mem;
int twostagesem[2];
pthread_cond_t* running;
pthread_mutex_t* mutex,*mutex2,*mutex3;
threadTreeFuncArgs* args;
pthread_t* thread;
struct thread_tree_node** children;
}thread_tree_node;
 

thread_tree_node* generateTree(int nheight,int nsize,u_int64_t memsize,void* (*pfunc)(void*),void* args,int startRunning);


void freezeTree(thread_tree_node *tree);
void terminateTree(thread_tree_node*tree);
int treeIsRunning(thread_tree_node *tree);


void joinTree(thread_tree_node* tree);
void detachTree(thread_tree_node* tree);
void destroyTree(thread_tree_node* tree);
#endif
