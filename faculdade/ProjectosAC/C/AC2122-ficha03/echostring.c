#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

char*str=(char*)malloc(10);

do{
fgets(str,10,stdin);

printf("->%s\n",str);


}while(strcmp(str,"fim!\n")!=0);

free(str);
return 0;


}


