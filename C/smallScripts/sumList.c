#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int * allocMem(int len){

	int* mem=malloc(sizeof(int)*len);
	memset(mem,0,sizeof(int)*len);
	return mem;

}

int sumArray(int* ptr,int len,int pos){
	
	if(pos==len-1){
	
		return *(ptr+pos);
	
	}
	else{
		return *(ptr+pos)+sumArray(ptr,len,pos+1);
	}
	

}

int main(void){
	
	int *mem= allocMem(11);
	
	for(int i=0;i<11;i++){
		
		*(mem+i)=i;
		
	}
	printf("%d\n",sumArray(mem,11,0));
	free(mem);
	
	return 0;
}
