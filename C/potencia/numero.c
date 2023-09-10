#include <cs50.h>
#include <stdio.h>

float umterco(float x);

int main(void){


float z=1;

float w = umterco(z);
printf("w é%f\n",w);


}


float umterco(float x){

float y = x*0.33333333333;
float t = y*10;
float h = t*10;
return h;

}