#include "../../Includes/preprocessor.h"
#include "../Includes/player.h"

extern SDL_Thread* thread,*sthread;
extern SDL_mutex* globalmtx,*waitmtx;
extern SDL_cond*sglobalcond;
extern int nextsong,prevsong;
extern int64_t canswitch,playerready,forward;


static int playMusic(void* args){

	playMusicArgs* argv= (playMusicArgs*)args;
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
	
	duration=((int)(Mix_MusicDuration(argv->currMusic)*1000.0));
	if(Mix_PlayMusic(argv->currMusic,0)<0){

                printf("Duraçao: %d %s\n",duration,SDL_GetError());
		exit(-1);

        }
	while(!acessVar(&argv->switching,globalmtx,GET,0)&&duration){
	
	SDL_mutexP(argv->mtx);
	while(acessVar(&argv->playing,globalmtx,GET,0)&&!acessVar(&argv->going,globalmtx,GET,0)){
		Mix_PauseMusic();
		SDL_CondWait(argv->condplay,argv->mtx);
		Mix_ResumeMusic();
	}
	duration--;
	SDL_Delay(1);
	SDL_mutexV(argv->mtx);
	
	if(acessVar(&argv->switching,globalmtx,GET,0)||!acessVar(&argv->playing,globalmtx,GET,0)||!duration){
	Mix_HaltMusic();
	
	
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

                 SDL_mutexP(waitmtx);
                 while(!acessVar(&canswitch,globalmtx,GET,0)&&acessVar(&args->playing,globalmtx,GET,0)){

                         SDL_CondWait(sglobalcond,waitmtx);

                 }
		acessVar(&canswitch,globalmtx,CHANGE,0);
                 
		if(!acessVar(&args->playing,globalmtx,GET,0)){
		SDL_mutexV(waitmtx);

			return;

		}
		Mix_Music* ptr=(Mix_Music*)acessVar((int64_t*)&args->currMusic,globalmtx,GET,0);
		if(ptr){
		Mix_FreeMusic(ptr);
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
		(*thing)=selectsong(meta,fd,abs(tmpvar));
		printf("Song number %d\n",abs(tmpvar));
		if(!(*thing)->music){

		printf("ERRO NA MUSICA!!!!\n");
		exit(-1);
		}
		acessVar((int64_t*)&args->currMusic,globalmtx,CHANGE,(int64_t)(*thing)->music);
                acessVar(&args->switching,globalmtx,CHANGE,0);
                SDL_CondSignal(args->condswitch);
 		SDL_mutexV(waitmtx);
}
static int songWaiterAndSwitcher(void* args){

	songWaiterArgs * argv=(songWaiterArgs *)args;
	acessVar(&playerready,globalmtx,CHANGE,1);
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
	waitmtx= SDL_CreateMutex();
	args->condplay=SDL_CreateCond();
	args->condswitch=SDL_CreateCond();
	sglobalcond=SDL_CreateCond();
	prevsong=meta->numofpairs-1;
	nextsong=0;
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
	if(scanf("%c",&c)<1){
		int ch;
		while((ch=getc(stdin))!=EOF && ch != '\n');
		continue;
	}
	menu(c,args);



	}while(c!='s');
	SDL_WaitThread(thread,NULL);
	SDL_WaitThread(sthread,NULL);
	if(args->currMusic){
		Mix_FreeMusic(args->currMusic);
	}
	SDL_DestroyCond(args->condplay);
	SDL_DestroyCond(args->condswitch);
	SDL_DestroyMutex(args->mtx);	
	SDL_DestroyMutex(globalmtx);	
	SDL_DestroyMutex(waitmtx);	
	SDL_DestroyCond(sglobalcond);
	free(thing->buff);
	free(thing);
	free(args);
	free(sargs);

	

}
