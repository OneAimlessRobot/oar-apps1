
#include "derivative.h"

void fillarray(int n, int prec1, long double *array)
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


void applyfunc(int n, int prec, double (*func)(double), double * domain)
{
    for (int i = 0; i < 2*n*prec; i++)
    {
        float j=(*(domain+i));
        (*(domain+i) )= derivadalocal(func,(*(domain+i)));
        printf("f(%f) =%lf\n",j,(*(domain+i)));
    }
}
