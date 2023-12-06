#include "../Includes/preprocessor.h"
#include "../Includes/minHeap.h"





minHeap* initMinHeap(comparator* comp,u_int64_t elemSize){


minHeap* result=malloc(sizeof(minHeap));
result->elemSize=elemSize;

result->arr= malloc(sizeof(void*)*DEFAULT_HEAP_SIZE);
for(u_int64_t j=0;j<DEFAULT_HEAP_SIZE;j++){
	result->arr[j]=malloc(result->elemSize);
	}
	result->currCap=DEFAULT_HEAP_SIZE;
result->currSize=0;
result->comp=comp;
return result;

}


void grow(minHeap* heap){
	u_int64_t newSize= heap->currCap* HEAP_GROW_FACTOR;
	void** arr= malloc(sizeof(void*)*newSize);

	for(u_int64_t j=0;j<heap->currCap;j++){

		arr[j]=malloc(heap->elemSize);
		memcpy(arr[j],heap->arr[j],heap->elemSize);

	}
	for(u_int64_t j=heap->currCap;j<newSize;j++){

		arr[j]=malloc(heap->elemSize);

	}
	for(u_int64_t j=0;j<heap->currCap;j++){
	free(heap->arr[j]);
	heap->arr[j]=NULL;
	}
	free(heap->arr);
	heap->arr=arr;
	heap->currCap=newSize;

}


static void percolateDown(minHeap* heap,u_int64_t index){
	void* targetMem=heap->arr[index];
	u_int64_t hole= index,child=index*2+1;
	
	while(child<heap->currSize){

        if ( child < heap->currSize - 1 && heap->comp->func(heap->arr[child+1],heap->arr[child]) < 0 ){
	
        child++;
	}
	if(heap->comp->func(heap->arr[child],targetMem)<0){

		swap(heap->arr+hole,heap->arr+child);
		hole=child;
		child=hole*2+1;
	}
	else{

		break;
	}
	}
	memcpy(heap->arr[hole],targetMem,heap->elemSize);

}
static void percolateUp(minHeap* heap,u_int64_t index,void*mem){
	u_int64_t hole= index,child=(index-1)/2;
	
	while ( hole > 0 && heap->comp->func(mem,heap->arr[child]) < 0 ){

		swap(heap->arr+hole,heap->arr+child);
		hole=child;
		child=(hole-1)/2;
	}
	memcpy(heap->arr[hole],mem,heap->elemSize);
		
}
static int isFull(minHeap* heap){

	return heap->currSize==heap->currCap;

}

static int isEmpty(minHeap* heap){

	return !heap->currSize;

}


void* dequeueMinHeap(minHeap* heap){
	if(isEmpty(heap)){
		return NULL;
	}
	void* result=malloc(heap->elemSize);
	memcpy(result,heap->arr[0],heap->elemSize);
	heap->currSize--;
	swap(heap->arr,heap->arr+heap->currSize);
	if(heap->currSize>1){
	percolateDown(heap,0);
	}
	return result;

}

void insertMinHeap(minHeap* heap,void* mem){
	if(isFull(heap)){

		grow(heap);
	}
	percolateUp(heap,heap->currSize,mem);
	heap->currSize++;


}
u_int64_t getCurrSizeMinHeap(minHeap* heap);


void destroyMinHeap(minHeap* heap){

	for(u_int64_t j=0;j<heap->currCap;j++){
	free(heap->arr[j]);
	heap->arr[j]=NULL;
	}
	free(heap->arr);
	heap->arr=NULL;
	free(heap);
	heap=NULL;



}

static void printMinHeapPrettyAux(minHeap*heap,u_int64_t index, int numOfSpaces){


	if(!heap->arr[index]){

		return;
	}
	if(index>=heap->currSize-1){

		for(int i=0;i<numOfSpaces;i++){

		printf("|");

		}
		printf("%d\n",*(int*)(heap->arr[heap->currSize-1]));

	}
	else {
		for(int i=0;i<numOfSpaces;i++){

		printf("|");

		}
		printf("%d\n",*(int*)(heap->arr[index]));
			if(index*2+1<heap->currSize){
			if(heap->arr[index*2+1]){
				printMinHeapPrettyAux(heap,index*2+1,numOfSpaces+1);
			}
			}
			if(index*2+2<heap->currSize){
			if(heap->arr[index*2+2]){

				printMinHeapPrettyAux(heap,index*2+2,numOfSpaces+1);
			
			}
			}
			
			
			
		
		}

	}

void printMinHeapPretty(minHeap*heap){

	if(!isEmpty(heap))
	{
		printMinHeapPrettyAux(heap,0,0);
	}

}
