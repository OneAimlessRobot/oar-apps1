#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "../Include/aux.h"
#include "../Include/embeded.h"
#include "../Include/petEngine.h"
#include "../Include/engine.h"
#include "../Include/factorized.h"

void initWindows(WINDOW** needs){


int hudx=0,hudy=0;
int titleh=9,titlew=62;
int statsw=28,statsh=20,statsx=hudx+titleh,statsy=hudy;
int menuw=18,menuh=10,menux=statsx-1,menuy=hudy+titlew-15;
int warningsx=statsx,warningsy=menuy+menuw;


needs[0]=newwin(titleh,titlew,hudx,hudy);
needs[1]=newwin(statsh,statsw,statsx,statsy);
needs[2]=newwin(menuh,menuw,menux,menuy);
needs[3]= newwin(8,12,statsx+1,hudy+statsw+3);

needs[4]=newwin(1,strlen("SLEEPING!")+4,warningsx,warningsy);
needs[5]=newwin(1,strlen("BORED!\n"),warningsx+1,warningsy);
needs[6]=newwin(1,strlen("HUNGRY!\n"),warningsx+2,warningsy);
needs[7]=newwin(1,strlen("THIRSTY!\n"),warningsx+3,warningsy);
needs[8]=newwin(1,strlen("TIRED!\n"),warningsx+4,warningsy);
needs[9]=newwin(1,strlen("POO!\n"),warningsx+5,warningsy);
needs[10]=newwin(1,strlen("PEE!\n"),warningsx+6,warningsy);





}


void initBuffers(Animal * an,char** buffs){
    buffs[0]=getASCII(_binary_dead_res_end,_binary_dead_res_start);
    buffs[1]=getASCII(_binary_pet_res_end,_binary_pet_res_start);
    buffs[2]=getASCII(_binary_title_res_end,_binary_title_res_start);
    buffs[3]=animalStatHud(*an);


}

void killAllBuffs(char** buffs){

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

void killAllWindows(WINDOW** needs){


for(int i=0;i<6+4;i++){

    delwin(needs[i]);

}
free(needs);

}
