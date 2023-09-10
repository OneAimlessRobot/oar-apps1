#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "derivative.h"

long double factorial(long double x)
{

    if (x == 0)
    {
        return 1;
    }
    else
    {
        return x * factorial(x - 1);
    }
}
/*pre: n>=0*/
long double nOrderDerivative(long double (*f)(long double), long double x, long double n)
{

    long double x1, x2;

    x1 = x - delta;

    x2 = x + delta;

    if (n == 0)
    {
        return f(x);
    }
    else
    {

        return (nOrderDerivative(f, x2, n - 1) - nOrderDerivative(f, x1, n - 1)) / (x2 - x1);
    }
}

long double taylorPoly(long double (*f)(long double), long double x, long double a, int n)
{
    if (n == 0)
    {
        return powl(x - a, 0) / factorial(0) * nOrderDerivative(f, a, 0);
    }
    else
    {
        return powl(x - a, n) / factorial(n) * nOrderDerivative(f, a, n) + taylorPoly(f, x, a, n - 1);
    }
}
