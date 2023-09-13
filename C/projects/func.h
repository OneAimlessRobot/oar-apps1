#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "derivative.h"

void fillarray(int n, int prec, double* array);
void applyfunc(int n, int prec, double (*func)(double), double* domain);
double func(double x);

int main(void)
{
    int n =1000;
    int prec = 1000;
    double* D=malloc(sizeof(double) *2 * n * prec);
    double* CD=malloc(sizeof(double) *2 * n * prec);

    fillarray(n, prec, D);
    fillarray(n, prec, CD);
    applyfunc(n, prec, acos, CD);
    
    free(D);
    free(CD);
}

double func(double x)
{
    return  x+1/x;
}

void applyfunc(int n, int prec, double (*func)(double), double * domain)
{
    for (int i = 0; i < 2*n*prec; i++)
    {
        float j=(*(domain+i));
        (*(domain+i) )= derivadalocal(func,(*(domain+i)));
        printf("f(%f) =%lf\n",j,(*(domain+i)));
    }
}

void fillarray(int n, int prec1, double *array)
{
    int i;
    double prec2 = 1 / prec1;
    double sum;
    *array = sum;
    for (i = 0, sum = (double)-n; sum < n; i++)
    {
       (*(array+i) )= sum;
        sum += (double)1 / prec1;
    }
}