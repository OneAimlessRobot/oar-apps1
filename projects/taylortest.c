#include "taylor.h"
long double func(long double x);
int main(void){

    printf("dá-me um numero\n:");
    long double x;
    scanf("%Lf",&x);
    printf("%Lf\n",factorial(x));
    for(long double i=-1;i<10;i+=0.0001){
        printf("%Lf %Lf\n",i,nOrderDerivative(func,i,2));
    }
}

long double func(long double x){

    return x*x*x*x;
}