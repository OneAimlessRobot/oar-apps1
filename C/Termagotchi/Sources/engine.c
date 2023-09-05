
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include "../Include/engine.h"
int getRandomInteger(int min, int max) {
    // Seed the random number generator with the current time.
    srand(time(NULL));

    // Generate a random number between 0 and RAND_MAX.
    int random = rand();

    // Scale the random number to fit within the specified range.
    int result = (random % (max - min + 1)) + min;

    return result;
}
void incAndTruncateNum(int* var,int sign,int value,int inc){

    if(sign){
        if(*var>value){
            *var=value;
        return;

        }
        *var+=inc;
    }
    if(!sign){

        if(*var<value){
            *var=value;
        return;
        }
        *var-=inc;

    }

}
void printASCII(const char *end, const char *start, int dt)
{
    char buff[end-start+1];
    int i=0;
    for (; i < (end - start); i++)
    {

        buff[i]=start[i];
    }
    buff[i]='\0';
    mvprintw(0,0,buff);
}

char* getASCII(const char *end, const char *start, int dt)
{
    char* buff=malloc(end-start+1);
    int i=0;
    for (; i < (end - start); i++)
    {

        buff[i]=start[i];
    }
    buff[i]='\0';
    return buff;
}

void makeWinWithText(WINDOW* win,char* text,int x, int y){


    mvwprintw(win,x,y,text);


}


char* generateStatBar(int stat,int maxStat,int step,const char* title){

    char *bar=malloc(1128);
    int i=0,cursor=0;
    bar[i++]='[';
    for(;cursor<stat;cursor+=step,i++){
    bar[i]='|';


    }
    for(;cursor<maxStat;cursor+=step,i++){
    bar[i]=' ';


    }
    bar[i++]=']';
    bar[i++]='\n';
    memcpy(bar+i,title,strlen(title));
    i+=strlen(title);
    bar[i++]='\n';
    bar[i++]='\0';
    return bar;

}
char* animalStatHud(Animal animal){

    char* health= generateStatBar(animal.health,animal.maxHealth,5,"saude"),
    * boredom= generateStatBar(animal.boredom,animal.maxBoredom,5,"animo"),
    * thirst= generateStatBar(animal.thirst,animal.maxThirst,5,"agua"),
    * hunger= generateStatBar(animal.hunger,animal.maxHunger,5,"comida"),
    * energy= generateStatBar(animal.energy,animal.maxEnergy,20,"stamina"),
    * age= malloc(1000);
 memset(age,0,1000);
 sprintf(age,"ANOS DE VIDA:%d HORAS\n",animal.age);
    int totallen= strlen(health)+strlen(boredom)+strlen(thirst)+strlen(hunger)+strlen(age)+1024;
    char* buff=malloc(totallen);
    memset(buff,0,totallen);
    sprintf(buff,"%s%s%s%s%s%s%s\n",health,boredom,thirst,hunger,energy,age,animal.name);
    free(age);
    return buff;
}

