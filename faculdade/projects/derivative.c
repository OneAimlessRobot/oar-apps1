#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "derivative.h"

long double funcao(long double x);
int main(void){
    
    const char*string;
    long double ponto;
    scanf("%Lf",&ponto);

    string=tangente(funcao,ponto);
    long double j=derivadalocal(funcao,ponto);
    
    printf("A derivada é %Lf e a reta tangente é %s\n",j,string);

}

long double funcao(long double x){

    return tan(x);
}