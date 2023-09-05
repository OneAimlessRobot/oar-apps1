#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "../Include/embeded.h"
#include "../Include/engine.h"
#include "../Include/petEngine.h"
#include "../Include/factorized.h"

void initWindows(){
needs=malloc(sizeof(WINDOW*)*6);
int hudx=0,hudy=0;
int titleh=9,titlew=56;
int statsw=28,statsh=20,statsx=hudx+titleh,statsy=hudy;
int menuw=18,menuh=10,menux=statsx-1,menuy=hudy+titlew-10;
int warningsx=statsx,warningsy=menuy+menuw;


title=newwin(titleh,titlew,hudx,hudy);
stats=newwin(statsh,statsw,statsx,statsy);
menu=newwin(menuh,menuw,menux,menuy);
pet= newwin(8,12,statsx,hudy+statsw+3);

sleepMeter=newwin(1,strlen("SLEEPING!")+4,warningsx,warningsy);
boredWarning=newwin(1,strlen("BORED!\n"),warningsx+1,warningsy);
hungryWarning=newwin(1,strlen("HUNGRY!\n"),warningsx+2,warningsy);
thirstWarning=newwin(1,strlen("THIRSTY!\n"),warningsx+3,warningsy);
tiredWarning=newwin(1,strlen("TIRED!\n"),warningsx+4,warningsy);
pooWarning=newwin(1,strlen("POO!\n"),warningsx+5,warningsy);
peeWarning=newwin(1,strlen("PEE!\n"),warningsx+6,warningsy);


needs[0]=sleepMeter;
needs[1]=boredWarning;
needs[2]=hungryWarning;
needs[3]=thirstWarning;
needs[4]=tiredWarning;
needs[5]=pooWarning;
needs[6]=peeWarning;

}


void initBuffers(Animal * an){

    buffs= malloc(sizeof(char*)*4);
    deadLettering=getASCII(_binary_dead_res_end,_binary_dead_res_start);
    petBuff=getASCII(_binary_pet_res_end,_binary_pet_res_start);
    titleBuff=getASCII(_binary_title_res_end,_binary_title_res_start);
    statBuff=animalStatHud(*an);


}

void killAllBuffs(){

    for(int i=0;i<4;i++){

        free(buffs[i]);

    }
    free(buffs);

}
void initAllColors(){

 init_pair(30,COLOR_GREEN,COLOR_BLACK); //Title color
 init_pair(31,COLOR_WHITE,COLOR_BLACK); //default
 init_pair(32,COLOR_BLACK,COLOR_RED); //DEATH color


init_pair(1,COLOR_BLACK,COLOR_WHITE);//sleeping color //
init_pair(2,COLOR_WHITE,COLOR_RED);//hungry color //
init_pair(3,COLOR_WHITE,COLOR_CYAN);//thirsty color //
init_pair(4,COLOR_BLACK,COLOR_MAGENTA);//tired //
init_pair(5,COLOR_WHITE,COLOR_BLACK);//poo //
init_pair(6,COLOR_BLACK,COLOR_YELLOW);//pee //
init_pair(7,COLOR_BLACK,COLOR_BLACK);//neutral //
init_pair(8,COLOR_MAGENTA,COLOR_MAGENTA);//bored //
init_pair(9,COLOR_RED,COLOR_CYAN);//Pet color

}

void killAllWindows(){


for(int i=0;i<6;i++){

    delwin(needs[i]);

}
delwin(title);
delwin(stats);
delwin(menu);
delwin(pet);
free(needs);

}
