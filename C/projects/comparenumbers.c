#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int compare(int f,double g);

int main(int argc, char *argv[])
{
    
    int f=9;
    double g=10;
    
    int h=compare(f,g);
    printf("%i\n",h);
    
}

int  compare(int f,double g){
    
    if( f==g){
        
        return 1;
    }
    else{
    return 0;
    }
    

}