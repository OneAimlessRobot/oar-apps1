#include <stdio.h>
#include <stdlib.h>


int main(){

int n=128,i=0;
while(n!=0){

i=n%2;
printf("%i",i);

n=n/2;
}

return 0;
}
