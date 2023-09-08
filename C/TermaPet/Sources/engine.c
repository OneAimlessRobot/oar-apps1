
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


char* generateStatBar(float stat,float maxStat,float step,const char* title){

    int i=0;
    float cursor=0;
    char *bar=malloc(1128),value[100];
    sprintf(value," %.2f",stat);
    memcpy(bar+i,title,strlen(title));
    i+=strlen(title);
    memcpy(bar+i,value,strlen(value));
    i+=strlen(value);
    bar[i++]='\n';
    bar[i++]='[';
    for(;cursor<stat;cursor+=step,i++){
    bar[i]='|';


    }
    for(;cursor<maxStat;cursor+=step,i++){
    bar[i]=' ';


    }
    bar[i++]=']';
    bar[i++]='\n';
    bar[i++]='\0';
    return bar;

}
char* animalStatHud(Animal animal){

    char* health= generateStatBar(animal.health,animal.maxHealth,STATBARZOOMOUT,"hp:"),
    * boredom= generateStatBar(animal.boredom,animal.maxBoredom,STATBARZOOMOUT,"mood:"),
    * thirst= generateStatBar(animal.thirst,animal.maxThirst,STATBARZOOMOUT,"h20:"),
    * hunger= generateStatBar(animal.hunger,animal.maxHunger,STATBARZOOMOUT,"food:"),
    * energy= generateStatBar(animal.energy,animal.maxEnergy,4*STATBARZOOMOUT,"stm:"),
    * age= malloc(1000);
 memset(age,0,1000);
 sprintf(age,"TEMPO:%d\n",animal.age);
    int totallen= strlen(health)+strlen(boredom)+strlen(thirst)+strlen(hunger)+strlen(age)+1024;
    char* buff=malloc(totallen);
    memset(buff,0,totallen);
    sprintf(buff,"%s%s%s%s%s%s%s",health,boredom,thirst,hunger,energy,age,animal.name);
    free(age);
    free(health);
    free(boredom);
    free(thirst);
    free(energy);
    free(hunger);
    return buff;
}

