#include <stdio.h>
#include "SmallExercises.h"

int triangleNumber(int n){

    if(n==1){
        return 1;
    }
    else{

    return n+triangleNumber(n-1);
    }


}

int arraySum(int numbers[],int length,int pos){

    if(pos>=length){
        return 0;
    }
    if(pos==0){

        return numbers[pos];


    }
    else{

        return numbers[pos]+arraySum(numbers,length,pos-1);

    }


}