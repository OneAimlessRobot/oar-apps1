#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cutString(char* string, int ndest,int direction);

int main(int argc, char* argv[]){

char* string;
if(argc==4){

char*string=argv[1];

printf("%s\n",argv[1]);
string=cutString(string, atoi(argv[2]), atoi(argv[3]));
if(atoi(argv[2])>=0){

printf("A string é: %s\n",string);
}
else{
printf("Parâmetros inválidos\n");
}
}



return 0;
}

char* cutString(char* string,int ndest,int direction){


char * newString= (char*)malloc(sizeof(char)*ndest);

if(ndest<=strlen(string)){
switch (direction){
case 1:{
for(int i=0;i<ndest;i++){

(*(newString+i))=(*(string+i));
}
break;
}
case -1:{
int delta=strlen(string)-ndest;
for(int i=delta;i<strlen(string);i++){

(*(newString+i-(delta)))=(*(string+i));



}
break;
}
default:{
break;
}
}
}

return newString;




}
