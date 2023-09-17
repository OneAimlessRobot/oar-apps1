
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <time.h>
#include "../Includes/auxFuncs.h"


double genRanddouble(double min, double max){

    if (max < min) {
        fprintf(stderr, "Error: max must be greater than or equal to min\n");
        return 0.0f;
    }
    
    // Generate a random double between 0 and 1
    double random = ((double)rand() / RAND_MAX);
    
    // Scale and shift the random value to fit within the desired range
    return (random * (max - min)) + min;

}

int genRandInt(int min, int max) {
    if (max < min) {
        fprintf(stderr, "Error: max must be greater than or equal to min\n");
    	return 0;
	}
    
    // Generate a random integer between min and max
    return (rand() % (max - min + 1)) + min;
}


int factorial(int n){
        if(n==0){

                return 1;
        }
        int result=1;
        for(int i=2;i<n;i++){
        
                result*=i;

        }
        return result;




}



int lessThanEpsilon(double num){


        return fabs(num)<EPSILON;

}
