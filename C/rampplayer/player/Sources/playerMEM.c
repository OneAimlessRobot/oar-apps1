#include "../../Includes/preprocessor.h"
#include "../Includes/common.h"
#include "../Includes/playerMEM.h"

Mix_Chunk* music;
extern char* buff;
extern SDL_Thread* thread,*sthread;
extern SDL_mutex* globalmtx,*mtx;
extern SDL_cond*sglobalcond,* condplay,*condswitch;
extern int nextsong,prevsong;
extern int64_t canswitch,playerready,forward,going,playing;


void menu(char c);

static int playMusicMEM(void* args){

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
	duration=getChunkTimeMilliseconds(music)*10;
	if(Mix_PlayChannel(0,music,0)<0){

	        printf("\nERRO!!!!!: Duraçao: %d %s\n",duration,SDL_GetError());
                exit(-1);

        }
	printf("\nDuraçao: %ds\n",duration/1000);	
	while(acessVar(&playing,globalmtx,GET,0)&&!acessVar(&canswitch,globalmtx,GET,0)&&duration){
	
	SDL_mutexP(mtx);
	while(acessVar(&playing,globalmtx,GET,0)&&!acessVar(&going,globalmtx,GET,0)&&!acessVar(&canswitch,globalmtx,GET,0)){
		Mix_Pause(0);
		SDL_CondWait(condplay,mtx);
		Mix_Resume(0);
	}
	duration--;
	SDL_Delay(1);
	SDL_mutexV(mtx);
	}
	Mix_HaltChannel(0);
	if(!duration){
	acessVar(&canswitch,globalmtx,CHANGE,1);
	SDL_CondSignal(sglobalcond);
	}

}

return 0;
}


static void selectsongMEM(metadata* meta,int fd,int numofsong){

int numOfSong=numofsong% meta->numofpairs;
u_int64_t start= meta->pairs[numOfSong].start,end= meta->pairs[numOfSong].end;
lseek(fd,start,SEEK_SET);
buff=malloc(end-start);
memset(buff,0,end-start);
read(fd,buff,end-start);
music=Mix_QuickLoad_RAW((Uint8*)buff,(int)(end-start));





}

static void waitswitchSongMEM(metadata* meta,int fd){

                 SDL_mutexP(mtx);
                 while(!acessVar(&canswitch,globalmtx,GET,0)&&acessVar(&playing,globalmtx,GET,0)){

                         SDL_CondWait(sglobalcond,mtx);

                 }
		acessVar(&canswitch,globalmtx,CHANGE,0);
                if(!acessVar(&playing,globalmtx,GET,0)){
		SDL_mutexV(mtx);
		return;

		}
		Mix_Chunk* ptr=(Mix_Chunk*)acessVar((int64_t*)&music,globalmtx,GET,0);
		if(ptr){
		Mix_FreeChunk(ptr);
		acessVar((int64_t*)&music,globalmtx,CHANGE,0);
		
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
		selectsongMEM(meta,fd,abs(tmpvar));
		printf("Song number: %d\nTitle: %s\n",abs(tmpvar),meta->pairs[abs(tmpvar)].filename);
		if(!music){
		SDL_mutexV(mtx);
		printf("ERRO NA MUSICA!!!!\n");
		exit(-1);
		}
		acessVar(&going,globalmtx,CHANGE,1);
		SDL_CondBroadcast(condswitch);
		SDL_mutexV(mtx);
}
static int songWaiterAndSwitcherMEM(void* args){

	songWaiterArgs * argv=(songWaiterArgs *)args;
	acessVar(&playerready,globalmtx,CHANGE,1);
	SDL_CondSignal(sglobalcond);

while(acessVar(&playing,globalmtx,GET,0)){

waitswitchSongMEM(argv->meta,argv->fd);
		

}

return 0;
}

void initMEMplayer(metadata* meta,int fd){
songWaiterArgs sargs;
	music=NULL;
	buff=NULL;
	mtx=SDL_CreateMutex();
	globalmtx= SDL_CreateMutex();
	condplay=SDL_CreateCond();
	condswitch=SDL_CreateCond();
	sglobalcond=SDL_CreateCond();
	prevsong=meta->numofpairs-1;
	nextsong=0;
	sargs.meta=meta;
	sargs.fd=fd;
	sthread=SDL_CreateThread(songWaiterAndSwitcherMEM,NULL,(void*)&sargs);
	thread=SDL_CreateThread(playMusicMEM,NULL,NULL);
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
	if(music){
		Mix_FreeChunk(music);
	}
		
	SDL_DestroyCond(condplay);
	SDL_DestroyCond(condswitch);
	SDL_DestroyMutex(mtx);
	SDL_DestroyMutex(globalmtx);
	SDL_DestroyCond(sglobalcond);
	free(buff);
	

}
