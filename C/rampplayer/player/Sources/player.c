#include "../../Includes/preprocessor.h"
#include "../Includes/player.h"

extern SDL_Thread* thread,*sthread;
extern SDL_mutex* globalmtx;
extern SDL_cond*sglobalcond;
extern int currsong,canswitch,playerready,forward;


static int playMusic(void* args){

	playMusicArgs* argv= (playMusicArgs*)args;
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
		Mix_FreeMusic(argv->currMusic);
		}
		break;
	}

	SDL_mutexV(argv->mtx);
	duration=((int)(Mix_MusicDuration(argv->currMusic)*1000.0));
	if(Mix_PlayMusic(argv->currMusic,0)<0){

                printf("Duraçao: %d %s\n",duration,SDL_GetError());
		exit(-1);

        }
	while(!acessVar(&argv->switching,globalmtx,GET,0)&&duration){
	
	SDL_mutexP(argv->mtx);
	while(argv->playing&&!argv->going){
		Mix_PauseMusic();
		SDL_CondWait(argv->condplay,argv->mtx);
		Mix_ResumeMusic();
	}
	SDL_mutexV(argv->mtx);
	duration--;
	SDL_Delay(1);
	
	if(argv->switching||!argv->playing||!duration){
	Mix_HaltMusic();
	if(argv->currMusic){
        Mix_FreeMusic(argv->currMusic);
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

	return 0;}



static returnthing* selectsong(metadata* meta,int fd,int numofsong){
	

returnthing* result= malloc(sizeof(returnthing));
int numOfSong=numofsong% meta->numofpairs;
u_int64_t start= meta->pairs[numOfSong].start,end= meta->pairs[numOfSong].end;
lseek(fd,start,SEEK_SET);
char* tmpfilepath=strcat(INITDIR,"/tmp");
int tmpfd= creat(tmpfilepath,0777);
result->buff=malloc(end-start);
memset(result->buff,0,end-start);
read(fd,result->buff,end-start);
write(tmpfd,result->buff,end-start);
close(tmpfd);

        SDL_RWops *io = SDL_RWFromFile(tmpfilepath, "rb");
        if (io != NULL) {
        char name[256];
        if (io->read(io, name, sizeof (name), 1) > 0) {
                printf("Hello! Music loaded!\n");
        }
        }
        remove(tmpfilepath);
	free(tmpfilepath);
	if(!(result->music=Mix_LoadMUSType_RW(io,MUS_MP3,1))){

	printf("%s\n",SDL_GetError());
	exit(-1);
	}
	
return result;
      




}
static void waitswitchSong(returnthing** thing,metadata* meta,int fd,playMusicArgs* args){

                 SDL_mutexP(args->mtx);
                 while(!acessVar(&canswitch,globalmtx,GET,0)&&acessVar(&args->playing,globalmtx,GET,0)){

                         SDL_CondWait(sglobalcond,args->mtx);

                 }
		acessVar(&canswitch,globalmtx,CHANGE,0);
                 
		if(!acessVar(&args->playing,globalmtx,GET,0)){
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
		(*thing)=selectsong(meta,fd,tmpvar);
		printf("Song number %d\n",tmpvar);
		if(!(*thing)->music){

		exit(-1);
		}
		args->currMusic=(*thing)->music;
                acessVar(&args->switching,globalmtx,CHANGE,0);
                SDL_CondSignal(args->condswitch);
 		SDL_mutexV(args->mtx);
}
static int songWaiterAndSwitcher(void* args){

	songWaiterArgs * argv=(songWaiterArgs *)args;
	playerready=1;
	SDL_CondSignal(sglobalcond);
while(acessVar(&argv->args->playing,globalmtx,GET,0)){

waitswitchSong(argv->thing,argv->meta,argv->fd,argv->args);
		

}
return 0;

}

static void menu(char c, playMusicArgs* args){

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


void initplayer(metadata* meta,int fd){

playMusicArgs* args=malloc(sizeof(playMusicArgs));

songWaiterArgs* sargs=malloc(sizeof(songWaiterArgs));

	
	returnthing* thing=malloc(sizeof(returnthing));
	thing->music=NULL;
	thing->buff=NULL;
	args->currMusic=NULL;
	args->mtx=SDL_CreateMutex();
	globalmtx= SDL_CreateMutex();
	args->condplay=SDL_CreateCond();
	args->condswitch=SDL_CreateCond();
	sglobalcond=SDL_CreateCond();
	args->going=1;
	args->playing=1;
	args->switching=0;
	sargs->meta=meta;
	sargs->args=args;
	sargs->thing=&thing;
	sargs->fd=fd;
	sthread=SDL_CreateThread(songWaiterAndSwitcher,NULL,(void*)sargs);
	thread=SDL_CreateThread(playMusic,NULL,(void*)args);
	char c;
	
	do{
	scanf("%c",&c);
	menu(c,args);



	}while(c!='s');
	SDL_WaitThread(thread,NULL);
	SDL_WaitThread(sthread,NULL);
	SDL_DestroyCond(args->condplay);
	SDL_DestroyCond(args->condswitch);
	SDL_DestroyMutex(args->mtx);	
	SDL_DestroyCond(sglobalcond);
	free(thing->buff);
	free(thing);
	free(args);
	free(sargs);

	

}
