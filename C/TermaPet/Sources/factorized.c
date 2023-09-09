#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "../Include/aux.h"
#include "../Include/embeded.h"
#include "../Include/petEngine.h"
#include "../Include/graphicalDefines.h"
#include "../Include/engine.h"
#include "../Include/factorized.h"

void initWindows(WINDOW** needs){


int hudx=0,hudy=0;
int titleh=3,titlew=44;
int statsw=(int)(STATBARSIZES)+3,statsh=15,statsx=hudx+1,statsy=hudy;
int peth=5,petw=11,petx=hudx+statsx+3,pety=hudy+statsw+1;
int menuw=9,menuh=10,menux=statsx,menuy=pety+petw+3;
int warningsx=statsx+2,warningsy=menuy+menuw+1;


needs[0]=newwin(titleh,titlew,hudx,hudy);
needs[1]=newwin(statsh,statsw,statsx,statsy);
needs[2]=newwin(menuh,menuw,menux,menuy);
needs[3]= newwin(peth,petw,petx,pety);

needs[4]=newwin(1,strlen("SLEEPING!"),warningsx,warningsy);
needs[5]=newwin(1,strlen("BORED!"),warningsx+1,warningsy);
needs[6]=newwin(1,strlen("HUNGRY!"),warningsx+2,warningsy);
needs[7]=newwin(1,strlen("THIRSTY!"),warningsx+3,warningsy);
needs[8]=newwin(1,strlen("TIRED!"),warningsx+4,warningsy);
needs[9]=newwin(1,strlen("POO!"),warningsx+5,warningsy);
needs[10]=newwin(1,strlen("PEE!"),warningsx+6,warningsy);





}


void initBuffers(Animal * an,char** buffs){
    buffs[0]=getASCII(_binary_dead_res_end,_binary_dead_res_start);
    buffs[1]=getASCII(_binary_pet_res_end,_binary_pet_res_start);
    buffs[2]=getASCII(_binary_title_res_end,_binary_title_res_start);
    buffs[3]=animalStatHud(*an);
    buffs[4]=getASCII(_binary_pethurt_res_end,_binary_pethurt_res_start);
    buffs[5]=getASCII(_binary_petholding_res_end,_binary_petholding_res_start);
    buffs[6]=getASCII(_binary_petinpain_res_end,_binary_petinpain_res_start);
    buffs[7]=getASCII(_binary_pethappy_res_end,_binary_pethappy_res_start);



}

void showTitleScreen(WINDOW* logo,char* buff,int x,int y){

    wbkgdset(logo,COLOR_PAIR(30));
    makeWinWithText(logo,buff,x,y);
    wrefresh(logo);
    usleep((int)(TICK_DURATION_MICROSECS*GAME_SMOOTHNESS_FACTOR)*3);
    delwin(logo);


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
 init_pair(33,COLOR_RED,COLOR_BLACK);//commands highlight color

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
