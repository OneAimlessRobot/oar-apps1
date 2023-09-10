#include <stdlib.h>
#include "vectorClass.h"


void arrayInit(arrayWithCounter*vector,int sizeInit)
{

    vector->counter=0;
    vector->initSize=sizeInit;
    vector->array=(int*)malloc(sizeof(int)*vector->initSize);

}
void destroyArray(arrayWithCounter*vector)
{
    free(vector->array);
    free(vector);

}
int getArraySize(arrayWithCounter* vector)
{

    return vector->counter;

}

void addElement(arrayWithCounter*vector,int value)
{
    if(vectorIsFull(vector))
    {
        growArray(vector);
    }
    vector->array[vector->counter++]=value;

}
void growArray(arrayWithCounter*vector)
{

    arrayWithCounter* tmp=(arrayWithCounter*)malloc(sizeof(arrayWithCounter));
    int newSize=vector->counter*2;
    arrayInit(tmp,newSize);
    tmp->counter=vector->counter;

    for(int i=0; i<vector->counter; i++)
    {

        tmp->array[i]=vector->array[i];

    }
    destroyArray(vector);
    vector=tmp;


}
int vectorIsFull(arrayWithCounter* vector)
{

    return vector->counter==vector->initSize;

}
