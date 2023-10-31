#include "../../Includes/preprocessor.h"
#include "../Includes/common.h"
#include "../Includes/playerMEM.h"
#include "../Includes/player.h"
#include "../Includes/maestro.h"
char* buff;
SDL_Thread* thread,*sthread;
SDL_mutex* globalmtx,* mtx;
SDL_cond*sglobalcond,* condplay,*condswitch;
int nextsong,prevsong;
int64_t canswitch=0,playerready=0,forward=0,going=1,playing=1;

void menu(char c){

switch(c){
	
	case ' ':{
		int value=acessVar(&going,globalmtx,GET,0);
		value=(value+1)%2;
		acessVar(&going,globalmtx,CHANGE,value);
		SDL_CondSignal(condplay);
		SDL_CondSignal(sglobalcond);
		break;
	}
	case 's':{
		acessVar(&playing,globalmtx,CHANGE,0);
		SDL_CondSignal(condplay);
		SDL_CondSignal(condswitch);
		SDL_CondSignal(sglobalcond);
	break;
	}
	case 'n':{
		acessVar(&canswitch,globalmtx,CHANGE,1);
		acessVar(&forward,globalmtx,CHANGE,1);
		SDL_CondSignal(condplay);
		SDL_CondSignal(sglobalcond);
		
		SDL_mutexP(mtx);
		while(acessVar(&canswitch,globalmtx,GET,0)){

		SDL_CondWait(condswitch,mtx);

		}
		SDL_mutexV(mtx);
		break;
	}
	case 'p':{
		acessVar(&canswitch,globalmtx,CHANGE,1);
		acessVar(&forward,globalmtx,CHANGE,0);
		SDL_CondSignal(condplay);
		SDL_CondSignal(sglobalcond);
		
		SDL_mutexP(mtx);
		while(acessVar(&canswitch,globalmtx,GET,0)){

		SDL_CondWait(condswitch,mtx);

		}
		SDL_mutexV(mtx);
		break;
	}
	default:
	break;


}

}


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



