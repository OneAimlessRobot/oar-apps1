#include <stdio.h>
#include <stdlib.h>

int main(void){

    FILE* ficheiro=fopen("teste1.exe","w");

    for(int i=0;i<28823;i++){

        fprintf(ficheiro, "%i",i);
    }
    fclose(ficheiro);
}