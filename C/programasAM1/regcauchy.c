#include <stdio.h>
#include <math.h>
#include "derivative.h"
long double identidade(long double x);
long double indeterminacao(long double x);
int main(void){

    long double ponto;
    scanf("%Lf",&ponto);

    long double resultado= derivadalocal(expl,ponto)/derivadalocal(identidade,ponto);

    printf("%Lf\n",resultado);





    
}

long double identidade(long double x){
    return x;
}

long double indeterminacao(long double x){

    return (expl(x)-1);
}