#ifndef THREAD_TREE_NODE_H
#define THREAD_TREE_NODE_H

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

void* nodeValOp(thread_tree_node*lootnode,nodeValueOp mode,void* value,u_int64_t memsize);
int noChildren(thread_tree_node* node);

thread_tree_node* createNewThreadNode(int nsize,u_int64_t memsize,void* (*pfunc)(void*),void* args,int startRunning);
int doOpOnNode(thread_tree_node*worker,int val,int whichVal,nodeOp mode);

#endif
