#include "../../Includes/preprocessor.h"
#include "../Includes/common.h"
#include "../Includes/player.h"


Mix_Music* music;
extern char* buff,filename[STRING_SIZE],*helpmenu;
extern SDL_Thread* thread,*sthread;
extern SDL_mutex* varmtx,* playmtx;
extern SDL_cond*condswitching,* condplay,*condswitched;
extern u_int32_t nextsong,prevsong;
extern int64_t canswitch,playerready,forward,going,playing;


void menu(char c);


static int playMusic(void* args){

int duration=0,initduration=0;
	SDL_mutexP(playmtx);
	while(!acessVar(&playerready,varmtx,GET,0)){
		SDL_CondWait(condswitching,playmtx);
	}
	acessVar(&canswitch,varmtx,CHANGE,1);
	SDL_CondSignal(condswitching);
	SDL_mutexV(playmtx);
while(acessVar(&playing,varmtx,GET,0)){

	SDL_mutexP(playmtx);
	while((acessVar(&canswitch,varmtx,GET,0)||!acessVar((int64_t*)&music,varmtx,GET,0))&&acessVar(&playing,varmtx,GET,0)){
		SDL_CondWait(condswitched,playmtx);
		
	}
	if(!acessVar(&playing,varmtx,GET,0)){
	SDL_mutexV(playmtx);
		break;
	}
	
	initduration=duration=((int)(Mix_MusicDuration(music)*1000.0));
	if(Mix_PlayMusic(music,0)<0){
	SDL_mutexV(playmtx);
		
                printf("\nERRO!!!!!: Duraçao: %d %s\n",duration,SDL_GetError());
        	exit(-1);

        }
	SDL_mutexV(playmtx);
	while(acessVar(&playing,varmtx,GET,0)&&!acessVar(&canswitch,varmtx,GET,0)&&duration){
	SDL_mutexP(playmtx);
	while(acessVar(&playing,varmtx,GET,0)&&!acessVar(&going,varmtx,GET,0)){
		Mix_PauseMusic();
		SDL_CondWait(condplay,playmtx);
		Mix_ResumeMusic();
	}
	printf("\e[2J%s\nMusica: %s\nTempo passado: %d s de %d s\n",helpmenu,filename,duration/1000,initduration/1000);
	duration--;
	SDL_Delay(1);
	SDL_mutexV(playmtx);
	
	}
	Mix_HaltMusic();
	if(!duration){
		acessVar(&canswitch,varmtx,CHANGE,1);
		SDL_CondSignal(condswitching);
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

                 SDL_mutexP(playmtx);
                 while(!acessVar(&canswitch,varmtx,GET,0)&&acessVar(&playing,varmtx,GET,0)){

                         SDL_CondWait(condswitching,playmtx);

                 }
 		if(!acessVar(&playing,varmtx,GET,0)){
		SDL_mutexV(playmtx);
		
		
			return;

		}
		Mix_Music* ptr=(Mix_Music*)acessVar((int64_t*)&(music),varmtx,GET,0);
		if(ptr){
		Mix_FreeMusic(ptr);
		acessVar((int64_t*)&(music),varmtx,CHANGE,0);
		
		}
 		free(buff);
                u_int32_t tmpvar;
		if(acessVar(&forward,varmtx,GET,0)){
		tmpvar=nextsong%meta->numofpairs;
		}
		else{
		tmpvar=prevsong%meta->numofpairs;
		}
		prevsong=tmpvar-1;
		nextsong=tmpvar+1;
		selectsong(meta,fd,tmpvar);
		snprintf(filename,STRING_SIZE,"Song number: %d\nTitle: %s\n",abs(tmpvar),meta->pairs[abs(tmpvar)].filename);
		if(!(music)){
		SDL_mutexV(playmtx);
		
		
		printf("ERRO NA MUSICA!!!!\n");
		exit(-1);
		}
		acessVar(&canswitch,varmtx,CHANGE,0);
		SDL_CondBroadcast(condswitched);
		SDL_mutexV(playmtx);
		
		}
static int songWaiterAndSwitcher(void* args){

	songWaiterArgs * argv=(songWaiterArgs *)args;
	acessVar(&playerready,varmtx,CHANGE,1);
	SDL_CondSignal(condswitching);
while(acessVar(&playing,varmtx,GET,0)){

waitswitchSong(argv->meta,argv->fd);
		

}
return 0;

}

void initplayer(metadata* meta,int fd){

songWaiterArgs* sargs=malloc(sizeof(songWaiterArgs));

	music=NULL;
	buff=NULL;
	playmtx=SDL_CreateMutex();
	varmtx= SDL_CreateMutex();
	condplay=SDL_CreateCond();
	condswitched=SDL_CreateCond();
	condswitching=SDL_CreateCond();
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
	fflush(stdin);
	menu(c);



	}while(c!='s');
	SDL_WaitThread(thread,NULL);
	SDL_WaitThread(sthread,NULL);
	if((music)){
		Mix_FreeMusic((music));
	}
	SDL_DestroyCond(condplay);
	SDL_DestroyCond(condswitched);
	SDL_DestroyMutex(playmtx);
	SDL_DestroyMutex(varmtx);	
	SDL_DestroyCond(condswitching);
	free(buff);
	free(sargs);

	

}
