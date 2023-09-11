#include <stdio.h>

int geralista(int array[100],int size);

int main(void)
{
    int indexmaximo = 100;
    int lista[100];
    int umalista[]={1,2,3,4,5,6,7};
    geralista(lista, indexmaximo);
}

int geralista(int array[100],int maxindex){

    for(int i=0;i<maxindex;i++){

        array[i]=2*i;
        printf("%i \n",array[i]);
    }


}
