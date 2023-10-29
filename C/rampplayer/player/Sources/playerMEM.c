#include "../../Includes/preprocessor.h"
#include "../Includes/playerMEM.h"

extern SDL_Thread* thread,*sthread;
extern SDL_mutex* globalmtx,*waitmtx;
extern SDL_cond* sglobalcond;
extern int nextsong,prevsong;
extern int64_t canswitch,playerready,forward;

static int playMusicMEM(void* args){

	playMusicMEMArgs* argv= (playMusicMEMArgs*)args;
int duration=0;
	SDL_mutexP(argv->mtx);
	while(!acessVar(&playerready,globalmtx,GET,0)){
		SDL_CondWait(sglobalcond,argv->mtx);
	}
	acessVar(&canswitch,globalmtx,CHANGE,1);
	SDL_CondSignal(sglobalcond);
	SDL_mutexV(argv->mtx);
while(acessVar(&argv->playing,globalmtx,GET,0)){

	SDL_mutexP(argv->mtx);
	while((acessVar(&argv->switching,globalmtx,GET,0)||!acessVar((int64_t*)&argv->currMusic,globalmtx,GET,0))&&acessVar(&argv->playing,globalmtx,GET,0)){

		SDL_CondWait(argv->condswitch,argv->mtx);

	}
	SDL_mutexV(argv->mtx);
	if(!acessVar(&argv->playing,globalmtx,GET,0)){
		break;
	}
	duration=getChunkTimeMilliseconds(argv->currMusic);
	if(Mix_PlayChannel(0,argv->currMusic,0)<0){

                printf("\nERRO!!!!!: Duraçao: %d %s\n",duration,SDL_GetError());
                exit(-1);

        }
	printf("\nDuraçao: %ds\n",duration/1000);
	while(!acessVar(&argv->switching,globalmtx,GET,0)&&duration){
	
	SDL_mutexP(argv->mtx);
	while(acessVar(&argv->playing,globalmtx,GET,0)&&!acessVar(&argv->going,globalmtx,GET,0)){
		Mix_Pause(0);
		SDL_CondWait(argv->condplay,argv->mtx);
		Mix_Resume(0);
	}
	duration--;
	SDL_Delay(1);
	SDL_mutexV(argv->mtx);
	
	if(acessVar(&argv->switching,globalmtx,GET,0)||!acessVar(&argv->playing,globalmtx,GET,0)||!duration){
	Mix_HaltChannel(0);
	
	acessVar(&canswitch,globalmtx,CHANGE,1);
		
	if(!acessVar(&argv->switching,globalmtx,GET,0)){
		acessVar(&argv->switching,globalmtx,CHANGE,1);
	}
		SDL_CondSignal(sglobalcond);
		break;
	}
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

                 SDL_mutexP(waitmtx);
                 while(!acessVar(&canswitch,globalmtx,GET,0)&&acessVar(&args->playing,globalmtx,GET,0)){

                         SDL_CondWait(sglobalcond,waitmtx);

                 }
		acessVar(&canswitch,globalmtx,CHANGE,0);
                 
		if(!acessVar(&args->playing,globalmtx,GET,0)){
			 SDL_mutexV(waitmtx);
		return;

		}
		Mix_Chunk* ptr=(Mix_Chunk*)acessVar((int64_t*)&args->currMusic,globalmtx,GET,0);
		if(ptr){
		Mix_FreeChunk(ptr);
		acessVar((int64_t*)&args->currMusic,globalmtx,CHANGE,0);
		
		}
		free((*thing)->buff);
                free((*thing));
                int tmpvar;
		if(forward){
		tmpvar=nextsong%meta->numofpairs;
		}
		else{
		tmpvar=prevsong%meta->numofpairs;
		}
		prevsong=abs(tmpvar-1);
		nextsong=abs(tmpvar+1);
		(*thing)=selectsongMEM(meta,fd,abs(tmpvar));
		printf("Song number: %d\nTitle: %s\n",abs(tmpvar),meta->pairs[abs(tmpvar)].filename);
		if(!(*thing)->music){
		printf("ERRO NA MUSICA!!!!\n");
		exit(-1);
		}
		acessVar((int64_t*)&args->currMusic,globalmtx,CHANGE,(int64_t)(*thing)->music);
                acessVar(&args->switching,globalmtx,CHANGE,0);
                 SDL_CondSignal(args->condswitch);
		 SDL_mutexV(waitmtx);
}
static int songWaiterAndSwitcherMEM(void* args){

	songWaiterMEMArgs * argv=(songWaiterMEMArgs *)args;
	acessVar(&playerready,globalmtx,CHANGE,1);
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
	waitmtx= SDL_CreateMutex();
	args.condplay=SDL_CreateCond();
	args.condswitch=SDL_CreateCond();
	sglobalcond=SDL_CreateCond();
	prevsong=meta->numofpairs-1;
	nextsong=0;
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
	if(scanf("%c",&c)<1){
		int ch;
		while((ch=getc(stdin))!=EOF && ch != '\n');
		continue;
	}
	menuMEM(c,&args);



	}while(c!='s');
	SDL_WaitThread(thread,NULL);
	SDL_WaitThread(sthread,NULL);
	if(args.currMusic){
		Mix_FreeChunk(args.currMusic);
	}
		
	SDL_DestroyCond(args.condplay);
	SDL_DestroyCond(args.condswitch);
	SDL_DestroyMutex(args.mtx);
	SDL_DestroyMutex(globalmtx);
	SDL_DestroyMutex(waitmtx);
	SDL_DestroyCond(sglobalcond);
	free(thing->buff);
	free(thing);
	

}
