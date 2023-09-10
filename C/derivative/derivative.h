#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
/*
const char ESQUERDA ='E';
const char DIREITA ='D';*/

const long double delta = 1e-10;

/*Retorna a derivada local da função dada como primeiro parametro no ponto dado no segundo paramentro. É derivada à esquerda se lado = E ou á direta se lado =D*/
long double derivadalocal(long double (*f)(long double), long double x0)
{
        long double x1 = x0; /*- delta;*/
        long double x2 = x0 + delta;
    return (f(x2) - f(x1)) / (x2 - x1);
}


const char* tangente(long double(*f)(long double), long double x)
{

    char *string=malloc(sizeof(char)*128);
    long double b;
         b = f(x) - derivadalocal(f, x) * x;
        snprintf(string, sizeof(char)*128, "%Lfx+%Lf", derivadalocal(f, x), b);

    return string;

    /*y=f'x*x+b<=><=>b=y-f'x*x*/
}
