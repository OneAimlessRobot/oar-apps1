#include <stdio.h>
#include <math.h>

int fillarray(int n, int array[n]);
int produtoescalar(int n,int array[n], int array2[n]);

int main(void){
    int n =5; 
    int lista[n]; 
    int lista2[n];
    int i=0;
    int j=0;

    do{
        i++;
        scanf("%i",&lista[i]);

    }while(i<n);
    for(j; j<n; j++){
        scanf("%i",&lista2[j]);
    }
    /*
    fillarray(n,lista);
    fillarray(n,lista2);*/
    int l = produtoescalar(n,lista,lista2);
    printf("%i\n",l);

}

int produtoescalar(int n,int array[n], int array2[n]){
int arraymult=0;
    for(int i=0;i<n;i++){
            array[i]*=array2[i];
         arraymult +=array[i];

    }
    return arraymult;

}

/*int fillarray(int n, int array[n]){
int i;
array[i];
    for(i; i<n; i++){
        scanf("%i",&array[i]);
    }
    return 0;
}*/