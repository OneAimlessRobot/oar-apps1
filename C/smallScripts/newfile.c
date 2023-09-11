#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void fillarray(int n, int array[n]);
void printarray(int n, int array[n]);

int main(void)
{
    int n;

    int i,a;
    int slot;
    int melhor = 0;

    scanf("%i", &n);
    int *array=malloc(sizeof(int)*n);
fillarray(n,array);
printarray(n,array);

    for (i = 0; i < n; i++)
    {
        for (slot = 0; slot < n -1; slot++)
        {
            if (array[slot+1] <array[slot])
            {
                
                a=array[slot];
                array[slot]=array[slot+1];
                array[slot+1]=a;
            }
            else
            {
            }
        }
       
    }
printarray(n,array);
    
}

void fillarray(int n, int array[n])
{
    int i;
    for (i = n; i >0; i--)
    {
        array[n-i] = i;
    }
}


void printarray(int n, int array[n]){
    int i;
    for( i=0;i<n;i++){
        
        printf("%i\n",array[i]);
    }
    
    
}