#ifndef AUXILIAR_H
#define AUXILIAR_H
enum varAcessMode {CHANGE,INC,DEC,GET};
typedef enum varAcessMode varAcessMode;

void printASCII(char* ptrs[2],int fd);

int acessVar(int* var, SDL_mutex* mtx,varAcessMode mode,int value);
Uint32 getChunkTimeMilliseconds(Mix_Chunk* chunk);

#endif
