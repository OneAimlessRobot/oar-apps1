#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integrate.h"
#include "taylor.h"

long double func(long double x);
int main(int argc, char *argv[])
{

  FILE *gnuplot = fopen("poly.dat", "w");
  FILE * gnuplot2=fopen("normal.dat","w");
  for(long double j=-10; j<10;j+=0.01){
    fprintf(gnuplot,"%Lf %Lf\n",j,taylorPoly(cosl,j,0,3));
  }
  for(long double j=-10; j<10;j+=0.01){
    fprintf(gnuplot2,"%Lf %Lf\n",j,cosl(j));
  }
fprintf(gnuplot, "e\n");
fclose(gnuplot);
fclose(gnuplot2);
  /* (x,y,z)=(1,2,3)+i(2,3,4)+j(5,6,7), k,m E R
  x=1+2*i+5*j
  y=2+3*i+6*j
  z=3+4*i+7*j
  */
}

long double func(long double x){
    return -1/(x*x);
    
    }
