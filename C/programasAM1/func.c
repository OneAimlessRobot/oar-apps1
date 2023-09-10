#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void fillarray(int n, int prec, double array[2 * n]);
void applyfunc(int n, int prec, double (*func)(double), double domain[2 * n * prec]);

int main(void)
{
    int n = 1000;
    int prec = 1000;
    double D[2 * n * prec];

    fillarray(n, prec, D);
    applyfunc(n, prec, sin, D);
}

double func(double x)
{
    return 1 / x;
}

void applyfunc(int n, int prec, double (*func)(double), double domain[2 * n * prec])
{
    for (int i = 0; i < 2*n*prec; i++)
    {
        float j=domain[i];
        domain[i] = func(domain[i]);
        printf("f(%.4f) =%lf\n",j, domain[i]);
    }
}

void fillarray(int n, int prec1, double array[2 * n * prec1])
{
    int i;
    double prec2 = 1 / prec1;
    double sum;
    int count = 0;
    array[0] = sum;
    for (i = 0, sum = (double)-n; sum < n; i++)
    {
        array[i] = sum;
        sum += (double)1 / prec1;
        printf("o numero em %i %lf\n", i, array[i]);
        if (array[i] < 0)
        {
            count++;
        }
    }
    printf("count de numeros negatibos e = %i", count);
}