#include <iostream>
#include <stdio.h>
#include "Calculus.hpp"

using namespace std;

long double func(long double x);

int main(){

    long double prec,a,n;

    cin>>prec>>a>>n;

    Calculus*lib=new Calculus(prec);
    FILE* graph=fopen("graph.dat","w");
    FILE*graph2=fopen("graph2.dat","w");

    for(long double i=-20;i<20;i+=0.01){

        fprintf(graph,"%LF %LF\n",i,func(i));
    }
    for(long double i=-20;i<20;i+=0.01){

        fprintf(graph2,"%LF %LF\n",i,lib->taylorPolyFunc(func,a,i,n));
    }
    fclose(graph);
    fclose(graph2);

    

}

long double func(long double x){

    return sinl(x)/x;
}
