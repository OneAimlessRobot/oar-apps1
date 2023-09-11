#include <stdlib.h>
#include <stdio.h>
#include "hash.h"

int main(void)
{
    int n = 9, i = 0;
    table **hash=malloc(sizeof(table)*n);
    for (int j = 0; j < n; j++)
    {
        *(hash+j) = NULL;
    }
    for (int j = 0; j < n; j++)
    {
    
    for (i = 0; i < 99; i++)
    {
        table *tmp = malloc(sizeof(table));

        tmp->pointer = *(hash+j);
        *(hash+j) = tmp;
        (*(hash+j))->value = i;
    }
    }
for(int j=0;j<n;j++){
    printf("\nlista %i \n",j);
    for (table *tmp = *(hash+j); tmp != NULL; tmp = tmp->pointer)
    {
        printf("%i ", tmp->value);
    }
}
table*tmp;
int k;
   for(int j=0;j<n;j++){
    
    
    
    for(k=0;tmp!=NULL;k++){
        tmp=(*(hash+j))->pointer;
        free(*(hash+j));
        (*(hash+j))=tmp;
        
        
    
}
   }
}
