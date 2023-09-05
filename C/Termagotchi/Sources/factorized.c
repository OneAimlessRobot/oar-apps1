#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "../Include/embeded.h"
#include "../Include/factorized.h"

void initWindows(){
hudx=35;
hudy=15;
title=newwin(10,55,0,30);
pet= newwin(20,26,10,40);
stats=newwin(100,256,30,15);
menu=newwin(100,100,0,100);
sleepMeter=newwin(1,strlen("SLEEPING!")+4,hudx+8,hudy);
boredWarning=newwin(1,strlen("BORED!\n"),hudx+10,hudy);
hungryWarning=newwin(1,strlen("HUNGRY!\n"),hudx+11,hudy);
thirstWarning=newwin(1,strlen("THIRSTY!\n"),hudx+12,hudy);
tiredWarning=newwin(1,strlen("TIRED!\n"),hudx+13,hudy);
pooWarning=newwin(1,strlen("POO!\n"),hudx+14,hudy);
peeWarning=newwin(1,strlen("PEE!\n"),hudx+15,hudy);
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
