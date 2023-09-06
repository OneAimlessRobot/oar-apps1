
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <time.h>
#include "../Include/aux.h"
#include "../Include/graphicalDefines.h"
#include "../Include/petEngine.h"
#include "../Include/engine.h"

void printASCII(const char *end, const char *start)
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

char* getASCII(const char *end, const char *start)
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

    char* health= generateStatBar(animal.health,animal.maxHealth,STATBARZOOMOUT,"VIDA"),
    * boredom= generateStatBar(animal.boredom,animal.maxBoredom,STATBARZOOMOUT,"ANIMO"),
    * thirst= generateStatBar(animal.thirst,animal.maxThirst,STATBARZOOMOUT,"AGUA"),
    * hunger= generateStatBar(animal.hunger,animal.maxHunger,STATBARZOOMOUT,"COMIDA"),
    * energy= generateStatBar(animal.energy,animal.maxEnergy,4*STATBARZOOMOUT,"STAMINA"),
    * age= malloc(1000);
 memset(age,0,1000);
 sprintf(age,"TEMPO DE VIDA:%d HORAS\n",animal.age);
    int totallen= strlen(health)+strlen(boredom)+strlen(thirst)+strlen(hunger)+strlen(age)+1024;
    char* buff=malloc(totallen);
    memset(buff,0,totallen);
    sprintf(buff,"%s%s%s%s%s%s%s\n",health,boredom,thirst,hunger,energy,age,animal.name);
    free(age);
    free(health);
    free(boredom);
    free(thirst);
    free(energy);
    free(hunger);
    return buff;
}

