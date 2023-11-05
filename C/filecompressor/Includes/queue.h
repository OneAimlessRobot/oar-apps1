#ifndef QUEUE_H
#define QUEUE_H
#define QUEUE_SIZE 1024
#define FULLQUEUE(a) (a->used==a->size)
#define EMPTYQUEUE(a) (a->used==0)

typedef struct queue{

char* buff;
int size,currFront,currBack,used;


}queue;


queue* initqueue(int size);

char enqueue(queue* q,char c);

char dequeue(queue* q);

void destroyQueue(queue* q);

#endif
