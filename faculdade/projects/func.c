#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "derivative.h"
#include "integrate.h"

void fillarray(int n, int prec,long double* array);
void applyfunc(int n, int prec,long double (*func)(long double), long double * domain);
long double func(long double x);

int main(void)
{
    int n =1;
    int prec = 10000;
    long double* D=malloc(sizeof(long double) *2 * n * prec);
    long double* CD=malloc(sizeof(long double) *2 * n * prec);

    fillarray(n, prec, D);
    fillarray(n, prec, CD);
    applyfunc(n, prec, acosl, CD);
    
    free(D);
    free(CD);
}

long double func(long double x)
{
    return  7;
}

void applyfunc(int n, int prec,long double (*func)(long double), long double * domain)
{
    for (int i = 0; i < 2*n*prec; i++)
    {
        long double j=(*(domain+i));
        (*(domain+i) )= integrateNum(func,0,(*(domain+i)));
        printf("f(%Lf) =%Lf\n",j,(*(domain+i)));
    }
}

void fillarray(int n, int prec1,long double *array)
{
    int i;
    long double prec2 = 1 / prec1;
    long double sum;
    *array = sum;
    for (i = 0, sum = (long double)-n; sum < n; i++)
    {
       (*(array+i) )= sum;
        sum += (long double)1 / prec1;
    }
}