#include <stdlib.h>
#include <stdio.h>
#include <complex.h>
#include <unistd.h>
#include <string.h>
#include "matrixStructs.h"
#include "matrixGetters.h"
#include "matrixOps.h"



int main(void)
{
    int h,w;
    float current;

    scanf("%i , %i",&h,&w);
    Matrix*matrix3=createNullMatrix(h,w);

    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            scanf("%f",&current);
            matrix3->table[i][j]=current;
        }

    }
    printMatrix(matrix3);
    Matrix*matrix4=getInverseAndPutInRRF(matrix3);

    return 0;
}
