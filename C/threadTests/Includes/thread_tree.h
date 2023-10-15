#ifndef THREAD_TREE_H
#define THREAD_TREE_H

enum nodeValueOp {CHECKVAL,SETVAL};
typedef enum nodeValueOp nodeValueOp;

enum nodeOp {CHECKVAR,SETVAR,TOGGLEFREEZE,SETFREEVAR,TOGGLEVARNORMALLY,CANCELNODE};
typedef enum nodeOp nodeOp;

struct thread_tree_node;


typedef struct threadTreeFuncArgs{
	void* actualArgs;
	void* (*func)(void*);
	struct thread_tree_node* spawner;

}threadTreeFuncArgs;

typedef struct thread_tree_node{
int nsize;
u_int64_t memsize;
void* mem;
threadTreeFuncArgs* args;
pthread_t* thread;
pthread_cond_t* condVars[1];
pthread_mutex_t* mutexes[3];
int* twostagesem[2];
struct thread_tree_node** children;
}thread_tree_node;
/*
typedef struct thread_tree{
int* twostagesem[2];
thread_tree_node* root;
pthread_cond_t* running;
pthread_mutex_t* mutex;
int aliveNodes,totalNodes;
}thread_tree;
*/
thread_tree_node* generateTree(int nheight,int nsize,u_int64_t memsize,void* (*pfunc)(void*),void* args,int startRunning);


void freezeTree(thread_tree_node *tree);
void loopTree(thread_tree_node *tree);
void terminateTree(thread_tree_node*tree);
int treeIsRunning(thread_tree_node *tree);
/*
void freezeTree(thread_tree_node *tree);
void terminateTree(thread_tree_node*tree);
int treeIsRunning(thread_tree_node *tree);
*/
/*
void joinTree(thread_tree *tree);
void detachTree(thread_tree *tree);
void destroyTree(thread_tree *tree);
*/
void* nodeValOp(thread_tree_node*lootnode,nodeValueOp mode,void* value,u_int64_t memsize);

void joinTree(thread_tree_node *tree);
void detachTree(thread_tree_node *tree);
void destroyTree(thread_tree_node *tree);
#endif
