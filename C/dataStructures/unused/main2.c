#include "Includes/preprocessor.h"

int compareIntsTwo(int* a, int* b){
	
	return (*a)-(*b);
}

int main(int argc, char ** argv){
	
        struct timespec time;

        clock_gettime(CLOCK_REALTIME, &time);
        srand(time.tv_nsec);

	
	int* arr=getRandIntArr(0, 1000, 10);

	BSTree* tree=makeIntTree(arr,10);
	
	printf("Arvore em largura\n");
        printIntBSTreeBreadth(tree);
	printf("Arvore em profundidade\n");
        printIntBSTreeDepth(tree);
	printf("Arvore infixo\n");
        printIntBSTreeInfix(tree);
	
	free(arr);
	
	destroyBSTree(tree);


	return 0;
}
