#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

class Calculus
{
    long double dx;

public:
    Calculus(long double precision)
    {

        this->dx = precision;
    }

    long double derivative(long double (*f)(long double), long double x)
    {

        long double x2 = x + dx, x1 = x - dx;

        return (f(x2) - f(x1)) / (x2 - x1);
    }
    long double nDerivative(long double (*f)(long double), long double x, int n)
    {

        long double x2 = x + dx, x1 = x - dx;
        if (n == 0)
        {
            return f(x);
        }
        else
        {
            return (nDerivative(f, x2, n - 1) - (nDerivative(f, x1, n - 1))) / (x2 - x1);
        }
    }
    long double factorial(long double n)
    {

        if (n == 0)
        {
            return 1;
        }
        else
        {
            return n * factorial(n - 1);
        }
    }

    long double taylorPolyFunc(long double (*f)(long double), long double a, long double x, long double n)
    {

        /*cout<<"(("<<x<<" - "<<a<<") ^ "<<n<<") * "<<nDerivative(f,a,n)<<" a dividir por "<<factorial(n)<<" = "<<(powl(x-a,n)*nDerivative(f,a,n)/factorial(n))<<endl;
            */
        if (n == 0)
        {
            return powl(x - a, 0) / factorial(0) * nDerivative(f, a, 0);
        }
        else
        {
            return powl(x - a, n) / factorial(n) * nDerivative(f, a, n) + taylorPolyFunc(f, a, x, n - 1);
        }
    }
    long double taylorPolyTermCoeff(long double (*f)(long double), long double a, long double n)
    {

        return nDerivative(f, a, n) / factorial(n);
    }
    void printTaylorPoly(long double (*f)(long double), long double a, long double n)
    {

        for (int i = n; i >= 0; i--)
        {

            cout << taylorPolyTermCoeff(f, a, i) << "x^" << i << " + ";
        }
        cout << endl;
    }

    long double numIntegral(long double (*f)(long double), long double init, long double end)
    {

        long double sum = 0;

        if (init < end)
        {
            for (long double x = init; x <= end; x += dx)
            {

                sum += f(x) * dx;
            }
        }
        else if (init == end)
        {
            sum = 0;
        }
        else
        {
            for (long double x = end; x <= init; x += dx)
            {
                sum += -f(x) * dx;
            }
        }
        return sum;
    }

    long double *indefIntegral(long double (*g)(long double), long double a, long double x)
    {

        long double i, j, *array = (long double *)malloc(sizeof(long double));
        cout << "primeiro" << endl;
        int index;
        for (i = a, index = 1; i < x; i += dx, index++)
        {
            long double sum = 0;
            for (j = a; j < i; j += dx)
            {

                sum += g(j) * dx;
            }
            (*(array + index)) = sum;

            cout << (*(array + index)) << endl;
            long double *aux = (long double *)malloc(sizeof(long double) * (index + 1));

            cout << sizeof(aux) << endl;

            for (int i = 0; i < index; i++)
            {

                (*(aux + i)) = (*(array + i));
                cout << i << endl;
            }
            free(array);
            cout << (sizeof(aux)) << " Outra vez" << endl;
            array = aux;
            cout << (sizeof(array)) << " Outra vez" << endl;
            aux = NULL;
            cout << (sizeof(array)) << " Tres vezes" << endl;
            for(int i=0;i<index;i++){
                cout<<(*(array+i))<<endl;
            }
        }
        return array;
    }
};