#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void strToUpper(char* nilEndedBuff){

    for(int i=0;nilEndedBuff[i]!=0;i++){
    char* c=nilEndedBuff+i;
    if(!isalpha(*c)){

        *c='_';
    }
        *c= toupper(*c);

    }



}


int main(int argc, char** argv){

    if(argc<2){
        printf("Tens de meter um nome de ficheiro como argumento\n");
        return 1;

    }
    FILE* file= fopen(argv[1],"rw+");
    if(!file){

        printf("Ficheiro %s nao abriu!!!!!!\n",argv[1]);
        return 2;


    }
    char* fileName=argv[1];
    strToUpper(fileName);
    int sizeOfHeaderStart=strlen("#ifndef ")+strlen(fileName)+strlen("\n#define ")+strlen(fileName)+1;
    char* HGStart=malloc(sizeOfHeaderStart);
    char* HGEnd="#endif";
    char* fileInMem;
    memset(HGStart,0,sizeOfHeaderStart);
    sprintf(HGStart,"#ifndef %s\n#define %s\n",fileName,fileName);

    fseek(file,0,SEEK_END);
    int length=ftell(file);
    fseek(file,0,SEEK_SET);
    fileInMem=malloc(length+1);
    memset(fileInMem,0,length+1);
    int finalSize=sizeOfHeaderStart+length+strlen("#endif")+1;
    char* finalFileBuff=malloc(finalSize+1);
    if(fileInMem){
        fread(fileInMem,1,length,file);
    memset(finalFileBuff,0,finalSize+1);

    sprintf(finalFileBuff,"%s\n%s%s\n",HGStart,fileInMem,HGEnd);
    fwrite(finalFileBuff,1,finalSize,file);

    }
    fclose(file);

    free(HGStart);
    free(fileInMem);
    free(finalFileBuff);




}
