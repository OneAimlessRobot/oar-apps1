#include "../../Includes/preprocessor.h"
#include "../Includes/common.h"
#include "../Includes/playerMEM.h"
#include "../Includes/player.h"
#include "../Includes/maestro.h"

char* buff,filename[STRING_SIZE],*pleasesiryouhavetounpauseitfirst="\e[2JDespausa essa merda!!!\n",
		*helpmenu="-------------------------------------------------\nChoose one of the following characters and press enter:\nn -> next song\np -> previous song\ns -> exit rampplayer\nw -> Increase volume.\nq -> Decrease volume\n(SPACE) -> pause (Just like real music players omg im so cool)\n-------------------------------------------------";

SDL_Thread* thread,*sthread;
SDL_mutex* varmtx,* playmtx;
SDL_cond*condswitching,* condplay,*condswitched,*condpause;
u_int32_t nextsong,prevsong;
int64_t canswitch=0,playerready=0,forward=0,going=1,playing=1,pausepls=0;
int16_t volume=0;
u_int8_t mode;
void menu(char c){
switch(c){
	
	case ' ':{
		int value=acessVar(&going,varmtx,GET,0);
		value=(value+1)%2;
		acessVar(&going,varmtx,CHANGE,value);
		SDL_CondSignal(condplay);
		SDL_mutexP(playmtx);
		while(!acessVar(&pausepls,varmtx,GET,0)){
			SDL_CondWait(condpause,playmtx);
		}
		SDL_mutexV(playmtx);
	break;
	}
	case 's':{
		acessVar(&playing,varmtx,CHANGE,0);
		SDL_CondSignal(condplay);
		SDL_CondSignal(condswitched);
		SDL_CondSignal(condswitching);
	break;
	}
	case 'n':{
		if(!acessVar(&going,varmtx,GET,0)){
			
			printf("%s\n",pleasesiryouhavetounpauseitfirst);
			break;
		}
		acessVar(&canswitch,varmtx,CHANGE,1);
		acessVar(&forward,varmtx,CHANGE,1);
		SDL_CondSignal(condswitching);
		SDL_mutexP(playmtx);
		while(acessVar(&canswitch,varmtx,GET,0)){

		SDL_CondWait(condswitched,playmtx);

		}
		SDL_mutexV(playmtx);
		break;
	}
	case 'p':{
		
		if(!acessVar(&going,varmtx,GET,0)){

			printf("%s\n",pleasesiryouhavetounpauseitfirst);
			break;
		}
		acessVar(&canswitch,varmtx,CHANGE,1);
		acessVar(&forward,varmtx,CHANGE,0);
		SDL_CondSignal(condswitching);
		SDL_mutexP(playmtx);
		while(acessVar(&canswitch,varmtx,GET,0)){

		SDL_CondWait(condswitched,playmtx);

		}
		SDL_mutexV(playmtx);
		break;
	}
	case 'w':{
		/*int tmpvolume=volume+8;
		Mix_VolumeMusic(tmpvolume);
		tmpvolume=Mix_VolumeMusic(-1);
		acessVar(&volume,varmtx,CHANGE,tmpvolume);
		*/
		volume+=10;
		if(volume>MIX_MAX_VOLUME){
		volume=MIX_MAX_VOLUME;
		}
		if(!mode){
		Mix_VolumeMusic(volume);
		volume=Mix_VolumeMusic(-1);
		}
		else{
		Mix_Volume(0,volume);
		volume=Mix_Volume(0,-1);
		}
		break;
	}
	case 'q':{
		/*
		int tmpvolume=volume-8;
		Mix_VolumeMusic(tmpvolume);
		tmpvolume=Mix_VolumeMusic(-1);
		acessVar(&volume,varmtx,CHANGE,tmpvolume);
		*/
		
		volume-=10;
		if(volume<=0){
		volume=0;
		}
		if(!mode){
		Mix_VolumeMusic(volume);
		volume=Mix_VolumeMusic(-1);
		}
		else{
		Mix_Volume(0,volume);
		volume=Mix_Volume(0,-1);
		}
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
	mode=1;
	initMEMplayer(meta,fd);
	break;
	}
	case 'f':{
	mode=0;
	initplayer(meta,fd);
	break;
	}



}



}



