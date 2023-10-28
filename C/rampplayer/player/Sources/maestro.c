#include "../../Includes/preprocessor.h"
#include "../Includes/playerMEM.h"
#include "../Includes/player.h"
#include "../Includes/maestro.h"

SDL_Thread* thread,*sthread;
SDL_mutex* globalmtx;
SDL_cond*sglobalcond;
int currsong=0,canswitch=0,playerready=0,forward=0;

void musicPlayingMaestro(metadata* meta,int fd){

char c;
printf("Queres com ficheiro(f) ou memoria(m)?\n");
scanf("%c",&c);

switch(c){

	case 'm':{
	initMEMplayer(meta,fd);
	break;
	}
	case 'f':{
	initplayer(meta,fd);
	break;
	}



}



}


