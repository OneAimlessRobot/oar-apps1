#ifndef MINHEAP_H
#define MINHEAP_H
#define DEFAULT_HEAP_SIZE 10
#define HEAP_GROW_FACTOR 2
typedef struct minHeap{


void** arr;
comparator* comp;
u_int64_t currCap,currSize,elemSize;

}minHeap;


minHeap* initMinHeap(comparator* comp, u_int64_t elemSize);

void* dequeueMinHeap(minHeap* heap);

void insertMinHeap(minHeap* heap,void* mem);

u_int64_t getCurrSizeMinHeap(minHeap* heap);

void destroyMinHeap(minHeap* heap);

void printMinHeapPretty(minHeap*heap);

#endif
