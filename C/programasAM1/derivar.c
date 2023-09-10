#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "derivative.h"
static const double dx =1e-10;

double derivar(double (*f)(double), double x0);

double func(double x);


int main(int argc, char*argv[])
{
    double x;
    
    scanf("%lf",&x);
    
    double j =derivar(func,x);
    
    printf("%lf\n",j);
    
    
    
}




double derivar(double (*f)(double), double x0){
    
    
    double x1=x0-dx;
    double x2=x0+dx;
    return (f(x1)-f(x2))/(x1-x2);
    
    
    
}


double func(double x){
    return sin(x);
    
}