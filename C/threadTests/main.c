

#include "Includes/preprocessor.h"

typedef struct funcArgs{

	int size;
	int* arr;

}funcArgs;
typedef struct AfuncArgs{

        int size;
        int* arr;                                     
}AfuncArgs;

int factorial(int num){
	if(!num){
		return 1;
	
	}
	return num*factorial(num-1);

}

void* func(void* args){
	funcArgs* argv= (funcArgs*)args;
	int64_t * result=malloc(sizeof(void*));
	*(result)=0;
	for(int i=0;i<argv->size;i++){

		*(result)+=argv->arr[i];

	}

	return  (void*)result;

}
int* genArr(int size){

int* arr=malloc(sizeof(int)*size);
for(int i=0;i<size;i++){

arr[i]=round(sin(cos(10000*factorial(i))));

}
return arr;


}

void* incArr(void* args){
funcArgs* argv= (funcArgs*)args;
for(int i=0;i<argv->size;i++){

argv->arr[i]+=round(sin(cos(10000*factorial(i))));

}
return malloc(8);
}
int main(int argc, char ** argv){

return 0;
}
