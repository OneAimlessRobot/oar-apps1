#include "../../Includes/preprocessor.h"
#include "../Includes/common.h"
#include "../Includes/player.h"


Mix_Music* music;
extern char* buff;
extern SDL_Thread* thread,*sthread;
extern SDL_mutex* globalmtx,* mtx;
extern SDL_cond*sglobalcond,* condplay,*condswitch;
extern int nextsong,prevsong;
extern int64_t canswitch,playerready,forward,going,playing;


void menu(char c);


static int playMusic(void* args){

int duration=0;
	SDL_mutexP(mtx);
	while(!acessVar(&playerready,globalmtx,GET,0)){
		SDL_CondWait(sglobalcond,mtx);
	}
	acessVar(&canswitch,globalmtx,CHANGE,1);
	SDL_CondSignal(sglobalcond);
	SDL_mutexV(mtx);
while(acessVar(&playing,globalmtx,GET,0)){

	SDL_mutexP(mtx);
	while((acessVar(&canswitch,globalmtx,GET,0)||!acessVar((int64_t*)&music,globalmtx,GET,0))&&acessVar(&playing,globalmtx,GET,0)){
		SDL_CondWait(condswitch,mtx);
		
	}
	SDL_mutexV(mtx);
	if(!acessVar(&playing,globalmtx,GET,0)){
		break;
	}
	
	duration=((int)(Mix_MusicDuration(music)*1000.0));
	if(Mix_PlayMusic(music,0)<0){
		
                printf("\nERRO!!!!!: Duraçao: %d %s\n",duration,SDL_GetError());
        	exit(-1);

        }
	printf("\nDuraçao: %ds\n",duration/1000);

	while(acessVar(&playing,globalmtx,GET,0)&&!acessVar(&canswitch,globalmtx,GET,0)&&duration){

	SDL_mutexP(mtx);
	while(acessVar(&playing,globalmtx,GET,0)&&!acessVar(&going,globalmtx,GET,0)&&!acessVar(&canswitch,globalmtx,GET,0)){
		Mix_PauseMusic();
		SDL_CondWait(condplay,mtx);
		Mix_ResumeMusic();
	}
	duration--;
	SDL_Delay(1);
	SDL_mutexV(mtx);
	
	}
	Mix_HaltMusic();
	
	if(!duration){
	acessVar(&canswitch,globalmtx,CHANGE,1);
	SDL_CondSignal(sglobalcond);
	}
}
return 0;
}



static void selectsong(metadata* meta,int fd,int numofsong){
	

int numOfSong=numofsong% meta->numofpairs;
u_int64_t start= meta->pairs[numOfSong].start,end= meta->pairs[numOfSong].end;
lseek(fd,start,SEEK_SET);
char* tmpfilepath=strcat(INITDIR,"/tmp");
int tmpfd= creat(tmpfilepath,0777);
buff=malloc(end-start);
memset(buff,0,end-start);
read(fd,buff,end-start);
write(tmpfd,buff,end-start);
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
	if(!(music=Mix_LoadMUSType_RW(io,MUS_MP3,1))){

	printf("%s\n",SDL_GetError());
	exit(-1);
	}
	




}
static void waitswitchSong(metadata* meta,int fd){

                 SDL_mutexP(mtx);
                 while(!acessVar(&canswitch,globalmtx,GET,0)&&acessVar(&playing,globalmtx,GET,0)){

                         SDL_CondWait(sglobalcond,mtx);

                 }
		acessVar(&canswitch,globalmtx,CHANGE,0);
 
		if(!acessVar(&playing,globalmtx,GET,0)){
		SDL_mutexV(mtx);

			return;

		}
		Mix_Music* ptr=(Mix_Music*)acessVar((int64_t*)&(music),globalmtx,GET,0);
		if(ptr){
		Mix_FreeMusic(ptr);
		acessVar((int64_t*)&(music),globalmtx,CHANGE,0);
		
		}
 		free(buff);
                int tmpvar;
		if(acessVar(&forward,globalmtx,GET,0)){
		tmpvar=nextsong%meta->numofpairs;
		}
		else{
		tmpvar=prevsong%meta->numofpairs;
		}
		prevsong=abs(tmpvar-1);
		nextsong=abs(tmpvar+1);
		selectsong(meta,fd,abs(tmpvar));
		printf("Song number: %d\nTitle: %s\n",abs(tmpvar),meta->pairs[abs(tmpvar)].filename);
		if(!(music)){
	
		SDL_mutexV(mtx);
		printf("ERRO NA MUSICA!!!!\n");
		exit(-1);
		}
		acessVar(&going,globalmtx,CHANGE,1);
		SDL_CondBroadcast(condswitch);
		SDL_mutexV(mtx);
}
static int songWaiterAndSwitcher(void* args){

	songWaiterArgs * argv=(songWaiterArgs *)args;
	acessVar(&playerready,globalmtx,CHANGE,1);
	SDL_CondSignal(sglobalcond);
while(acessVar(&playing,globalmtx,GET,0)){

waitswitchSong(argv->meta,argv->fd);
		

}
return 0;

}

void initplayer(metadata* meta,int fd){

songWaiterArgs* sargs=malloc(sizeof(songWaiterArgs));

	music=NULL;
	buff=NULL;
	mtx=SDL_CreateMutex();
	globalmtx= SDL_CreateMutex();
	condplay=SDL_CreateCond();
	condswitch=SDL_CreateCond();
	sglobalcond=SDL_CreateCond();
	prevsong=meta->numofpairs-1;
	nextsong=0;
	sargs->meta=meta;
	sargs->fd=fd;
	sthread=SDL_CreateThread(songWaiterAndSwitcher,NULL,(void*)sargs);
	thread=SDL_CreateThread(playMusic,NULL,NULL);
	char c;
	
	do{
	if(scanf("%c",&c)<1){
		int ch;
		while((ch=getc(stdin))!=EOF && ch != '\n');
		continue;
	}
	menu(c);



	}while(c!='s');
	SDL_WaitThread(thread,NULL);
	SDL_WaitThread(sthread,NULL);
	if((music)){
		Mix_FreeMusic((music));
	}
	SDL_DestroyCond(condplay);
	SDL_DestroyCond(condswitch);
	SDL_DestroyMutex(mtx);	
	SDL_DestroyMutex(globalmtx);	
	SDL_DestroyCond(sglobalcond);
	free(buff);
	free(sargs);

	

}
