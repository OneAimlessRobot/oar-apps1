#include <cs50.h>
#include <stdio.h>

bool validity(float x, float y, float z){


    if(x+y<z||x+z<y||y+z<x){
        return false;
    }
    else
    return true;
}


int main(void){
    float x;

do
{
    x =get_float("dá-me um valor positivo para o 1º lado\n");

} while (x<0);

float y;
do
{
    y =get_float("dá-me um valor positivo para o 2º lado\n");
    
} while (y<0);

float z;
do
{
    z =get_float("dá-me um valor positivo para o 3º lado\n");
    
} while (z<0);


    bool u = validity(x,y,z);

    if (u==true){
        printf("boa\n");
    }
    else {
        printf("má\n");
    }

}