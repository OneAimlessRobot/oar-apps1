#include <string>
#include <math.h>
#include "auxFuncs.h"
int randNumBetween(int bottom,int top)
    {

        return round(((random() / ((float)RAND_MAX + 1)) * bottom)+top-bottom);
    }
void randomNLongString(int length,std::string* str){


    for(int i=0;i<length;i++){

        (*str)+=(char)randNumBetween(33,122);

    }



}
