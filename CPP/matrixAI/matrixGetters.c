#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "vectorClass.h"
#include "matrixStructs.h"
#include "matrixOps.h"
#include "matrixGetters.h"


int isReducedRowForm(Matrix*matrix)
{

    if(isNullMatrix(matrix))
    {
        return 1;
    }
    else
    {
        Pivot collection[matrix->h];
        int counter=0;
        for(int i=0;i<matrix->h;i++){

            if(!(int)getLinePivot(matrix,i).value||getLinePivot(matrix,i).value>1){
                return 0;
            }
            else{

                collection[counter++]=getLinePivot(matrix,i);




            }
        }
        for(int i=0;i<counter-1;i++){
            int k=collection[i].col,l=collection[i+1].col;
            if(k>=l){
                return 0;
                }


        }
        for(int i=0;i<matrix->h;i++){
            Pivot tmp=getLinePivot(matrix,i);
            for(int j=tmp.col+1;j<matrix->w;j++){
                int tmp2=matrix->table[i][j];
                if(tmp2){
                    return 0;
                }
            }
        }
        return 1;

    }


}


void printMatrix(Matrix*matrix){
    for(int i=0;i<matrix->w;i++){

        printf("-");

    }
    printf("\n");
    for(int i=0; i<matrix->h; i++)
    {

        for(int j=0; j<matrix->w; j++)
        {

            printf("%0.1f ",matrix->table[i][j]);

        }
        printf("\n");
    }

    for(int i=0;i<matrix->w;i++){

        printf("-");

    }
    printf("\n");
}

Pivot getLinePivot(Matrix*matrix,int line){
for(int i=0;i<matrix->w;i++){
        if(matrix->table[line][i]){

            return (Pivot){line,i,matrix->table[line][i]};

        }

}
return (Pivot){0,0,0};

}
int isNullMatrix(Matrix*matrix)
{

    for(int i=0; i<matrix->h; i++)
    {
        for(int j=0; j<matrix->w; j++)
        {
            if(matrix->table[i][j])
            {
                return 0;
            }

        }
    }
    return 1;


}
void printRow(Matrix*matrix,int index){

    for(int i=0;i<matrix->w;i++){

        printf(" %f ",matrix->table[index][i]);

    }
    printf("\n");

}
int lineIsNull(Matrix*matrix,int line){

    for(int i=0;i<matrix->w;i++){
        if(matrix->table[line][i]){
            return 0;
        }

    }
    return 1;

}
