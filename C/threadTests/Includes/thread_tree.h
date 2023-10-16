#ifndef THREAD_TREE_H
#define THREAD_TREE_H

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

void joinTree(thread_tree_node *tree);
void detachTree(thread_tree_node *tree);
void destroyTree(thread_tree_node *tree);
#endif
