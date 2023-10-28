#ifndef PLAYER_H
#define PLAYER_H

typedef struct playMusicArgs{
Mix_Music* currMusic;
SDL_mutex* mtx;
SDL_cond* condplay,*condswitch;
int going,playing,switching;
}playMusicArgs;


typedef struct returnthing{
Mix_Music* music;
char* buff;
}returnthing;


typedef struct songWaiterArgs{
returnthing**thing;
metadata*meta;
int fd;
playMusicArgs* args;
}songWaiterArgs;


void initplayer(metadata* meta,int fd);

#endif
