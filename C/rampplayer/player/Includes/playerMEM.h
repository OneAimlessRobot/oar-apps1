#ifndef PLAYERMEM_H
#define PLAYERMEM_H

typedef struct returnthingMEM{
Mix_Chunk* music;
char* buff;
}returnthingMEM;

typedef struct playMusicMEMArgs{
Mix_Chunk* currMusic;
SDL_mutex* mtx;
SDL_cond* condplay,*condswitch;
int going,playing,switching;
}playMusicMEMArgs;

typedef struct songWaiterMEMArgs{
returnthingMEM**thing;
metadata*meta;
int fd;
playMusicMEMArgs* args;
}songWaiterMEMArgs;

void initMEMplayer(metadata* meta,int fd);


#endif

