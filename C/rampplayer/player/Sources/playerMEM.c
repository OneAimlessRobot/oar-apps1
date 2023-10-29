#include "../../Includes/preprocessor.h"
#include "../Includes/playerMEM.h"

extern SDL_Thread* thread,*sthread;
extern SDL_mutex* globalmtx;
extern SDL_cond* sglobalcond;
extern int currsong,canswitch,playerready,forward;

static int playMusicMEM(void* args){

	playMusicMEMArgs* argv= (playMusicMEMArgs*)args;
int duration=0;
	SDL_mutexP(argv->mtx);
	while(!playerready){
		SDL_CondWait(sglobalcond,argv->mtx);
	}
	canswitch=1;
	SDL_CondSignal(sglobalcond);
	SDL_mutexV(argv->mtx);
while(acessVar(&argv->playing,globalmtx,GET,0)){

	SDL_mutexP(argv->mtx);
	while((argv->switching||!argv->currMusic)&&argv->playing){

		SDL_CondWait(argv->condswitch,argv->mtx);

	}
	if(!argv->playing){
		if(argv->currMusic){
		Mix_FreeChunk(argv->currMusic);
		}
		break;
	}
	SDL_mutexV(argv->mtx);
	duration=getChunkTimeMilliseconds(argv->currMusic);
	if(Mix_PlayChannel(0,argv->currMusic,0)<0){

                printf("Duraçao: %d %s\n",duration,SDL_GetError());
                exit(-1);

        }
	while(!acessVar(&argv->switching,globalmtx,GET,0)&&duration){
	
	SDL_mutexP(argv->mtx);
	while(argv->playing&&!argv->going){
		Mix_Pause(0);
		SDL_CondWait(argv->condplay,argv->mtx);
		Mix_Resume(0);
	}
	duration--;
	SDL_Delay(1);
	
	if(argv->switching||!argv->playing||!duration){
	Mix_HaltChannel(0);
	if(argv->currMusic){
        Mix_FreeChunk(argv->currMusic);
	argv->currMusic=NULL;
	}
	
	canswitch=1;
		
	if(!argv->switching){
		argv->switching=1;
	}
		SDL_CondSignal(sglobalcond);
		SDL_mutexV(argv->mtx);
		break;
	}
	SDL_mutexV(argv->mtx);
	}
	

}

return 0;
}


static returnthingMEM* selectsongMEM(metadata* meta,int fd,int numofsong){

returnthingMEM * thing= malloc(sizeof(returnthingMEM));

int numOfSong=numofsong% meta->numofpairs;
u_int64_t start= meta->pairs[numOfSong].start,end= meta->pairs[numOfSong].end;
lseek(fd,start,SEEK_SET);
thing->buff=malloc(end-start);
memset(thing->buff,0,end-start);
read(fd,thing->buff,end-start);
thing->music=Mix_QuickLoad_RAW((Uint8*)thing->buff,(int)(end-start));

return thing;
      




}

static void waitswitchSongMEM(returnthingMEM** thing,metadata* meta,int fd,playMusicMEMArgs* args){

                 SDL_mutexP(args->mtx);
                 while(!canswitch&&args->playing){

                         SDL_CondWait(sglobalcond,args->mtx);

                 }
		canswitch=0;
                 
		if(!args->playing){
			return;

		}
                free((*thing)->buff);
                free((*thing));
                int tmpvar=currsong%meta->numofpairs;
		if(forward){
		
		currsong=(currsong+1);
		}
		else{
		currsong=abs(currsong-1);
		}
		(*thing)=selectsongMEM(meta,fd,tmpvar);
		printf("Song number %d\n",tmpvar);
		if(!(*thing)->music){

		exit(-1);
		}
		args->currMusic=(*thing)->music;
                 acessVar(&args->switching,globalmtx,CHANGE,0);
                 SDL_CondSignal(args->condswitch);
		 SDL_mutexV(args->mtx);
}
static int songWaiterAndSwitcherMEM(void* args){

	songWaiterMEMArgs * argv=(songWaiterMEMArgs *)args;
	
	playerready=1;
	SDL_CondSignal(sglobalcond);

while(acessVar(&argv->args->playing,globalmtx,GET,0)){

waitswitchSongMEM(argv->thing,argv->meta,argv->fd,argv->args);
		

}

return 0;
}

static void menuMEM(char c, playMusicMEMArgs* args){

switch(c){
	
	case ' ':{
		int value=acessVar(&args->going,globalmtx,GET,0);
		
		value=(value+1)%2;
		acessVar(&args->going,globalmtx,CHANGE,value);
		SDL_CondSignal(args->condplay);
		break;
	}
	case 's':{
		acessVar(&args->playing,globalmtx,CHANGE,0);
		SDL_CondSignal(args->condplay);
		SDL_CondSignal(args->condswitch);
		break;
	}
	case 'n':{
		acessVar(&args->switching,globalmtx,CHANGE,1);
		acessVar(&forward,globalmtx,CHANGE,1);
		SDL_CondSignal(sglobalcond);
		break;
	}
	case 'p':{
		acessVar(&args->switching,globalmtx,CHANGE,1);
		acessVar(&forward,globalmtx,CHANGE,0);
		SDL_CondSignal(sglobalcond);
		break;
	}
	default:
	break;


}



}

void initMEMplayer(metadata* meta,int fd){
playMusicMEMArgs args;
songWaiterMEMArgs sargs;
	returnthingMEM* thing=malloc(sizeof(returnthingMEM));
	thing->music=NULL;
	thing->buff=NULL;
	args.currMusic=NULL;
	args.mtx=SDL_CreateMutex();
	globalmtx= SDL_CreateMutex();
	args.condplay=SDL_CreateCond();
	args.condswitch=SDL_CreateCond();
	sglobalcond=SDL_CreateCond();
	args.going=1;
	args.playing=1;
	args.switching=0;
	sargs.thing=&thing;
	sargs.meta=meta;
	sargs.args=&args;
	sargs.fd=fd;
	sthread=SDL_CreateThread(songWaiterAndSwitcherMEM,NULL,(void*)&sargs);
	thread=SDL_CreateThread(playMusicMEM,NULL,(void*)&args);
	char c;
	
	do{
	scanf("%c",&c);
	menuMEM(c,&args);



	}while(c!='s');
	SDL_WaitThread(thread,NULL);
	SDL_WaitThread(sthread,NULL);
	SDL_DestroyCond(args.condplay);
	SDL_DestroyCond(args.condswitch);
	SDL_DestroyMutex(args.mtx);
	SDL_DestroyMutex(globalmtx);
	SDL_DestroyCond(sglobalcond);
	free(thing->buff);
	free(thing);
	

}
