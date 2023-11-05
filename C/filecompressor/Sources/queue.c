#include "../Includes/preprocessor.h"




queue* initqueue(int size){

queue* q= malloc(sizeof(queue));
q->buff= malloc(size);
memset(q->buff,0,size);
q->size=size;
q->currFront=0;
q->currBack=0;
q->used=0;
}

char enqueue(queue* q,char c){
	q->used++;
	return q->buff[(q->currFront++)%q->size]=c;
	


}
char dequeue(queue* q){

	q->used--;
	return q->buff[(q->currBack++)%q->size];
}

void destroyQueue(queue* q){
	
	free(q->buff);
	free(q);


}



