#include <stdio.h>
#include <stdlib.h>

const long double dx = 1e-5;
const long double closeToZero = 1e-10;

long double procSum(long double (*f)(long double), long double init, long double end)
{

    long double sum = 0;
    if (init < end)
    {
        init = init;
        end = end;
        for (long double x = init; x < end; x += dx)
        {
            sum += f(x) * dx;
        }
    }
    else if (init > end)
    {

        for (long double x = init; x > end; x -= dx)
        {
            sum -= f(x) * dx;
        }
    }
    return sum;
}
long double procSumNegative(long double (*f)(long double), long double init, long double end)
{

    long double sum = 0;

    for (long double x = init; x > end; x -= dx)
    {
        sum += f(x) * dx;
    }

    return sum;
}

long double integrateNum(long double (*f)(long double), long double a, long double b)
{
    long double ini;
    long double end;

    if (a < b)
    {
        ini = a;
        end = b;
    }
    else if (b < a)
    {
        ini = b;
        end = a;
    }

    else
    {
        return 0;
    }

    return procSum(f, ini, end);
}
/*Pre: The function does not approach infinity in any real number passed as a and is continuous in all of its domain*/
long double Primitive(long double (*f)(long double), long double a, const long double CONST)
{

    long double res = 0;
        
        res = procSum(f, closeToZero, a) + CONST;

    return res;
}

/*long double nOrderPrimitive(long double (*f)(long double), long double x,long double a, long double CONST, long double n)
{

    if (n == 0)
    {

        return Primitive(f, x, CONST);
    }
    else
    {
        long double sum=0;
        for (long double x = closeToZero; x < a; x += dx)
        {
            sum += f(x) * dx;
        }
        return 
    }
}*/
