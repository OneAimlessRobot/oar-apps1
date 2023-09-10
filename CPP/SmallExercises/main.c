#include <stdio.h>
#include "SmallExercises.h"


int main(void){

    printf("Triangulo de 5: %i\n",triangleNumber(5));
    int length=9;
    int numbers[length]={1,2,3,4, 5};
    printf("Soma recursiva: %i\n",arraySum(numbers,5,4));
    return 0;
}