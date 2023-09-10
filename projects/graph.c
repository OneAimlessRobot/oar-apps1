#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include "taylor.h"
#include "integrate.h"
long double func(long double x);
int main(void){

    int o=DETECT,gm;
    int x;
    int y;
    int i;
    initgraph (& o,& gm,NULL);
    for(x=0,y=480;x<1000;x++){
        y-=(int)3*func((int)x);
        lineto(x,y);
    }

    delay(500000);
    closegraph();
}

long double func(long double x){
    if(x>1/480){
    return 1/x;
    }
    else{
        return 0;
    }
}