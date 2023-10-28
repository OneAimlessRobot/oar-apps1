#include "../Includes/preprocessor.h"


int acessVar(int* var, SDL_mutex* mtx,varAcessMode mode,int value){
        SDL_mutexP(mtx);
        int result=0;
        switch(mode){
                case CHANGE:{
                (*var)=value;
                break;
                }
                case INC:{
                (*var)++;

                break;
                }
                case DEC:{
                (*var)--;

                break;
                }
                case GET:{
                result=(*var);

                break;
                }
                default:
                break;

        }
        SDL_mutexV(mtx);
        return result;



}

void printASCII(char *ptrs[2],int fd)
{
    int buffsize=1024;


    for (char* i=ptrs[0]; i < ptrs[1];)
    {

        if(i+buffsize<ptrs[1]){

        write(1,i,ptrs[1]-i);
        write(fd,i,ptrs[1]-i);
        i+=ptrs[1]-i;
        }
        else{

                write(fd,i,buffsize);
                i+=buffsize;
        }

    }
        close(fd);
}
Uint32 getChunkTimeMilliseconds(Mix_Chunk* chunk)
{
Uint32 points = 0;
Uint32 frames = 0;
int freq = 0;
Uint16 fmt = 0;
int chans = 0;
/* Chunks are converted to audio device format… */
if (!Mix_QuerySpec(&freq, &fmt, &chans))
return 0; /* never called Mix_OpenAudio()?! */

 /* bytes / samplesize == sample points */
 points = (chunk->alen / ((fmt & 0xFF) / 8));

 /* sample points / channels == sample frames */
 frames = (points / chans);

 /* (sample frames * 1000) / frequency == play length in ms */
 return (frames * 1000) / freq;
}

