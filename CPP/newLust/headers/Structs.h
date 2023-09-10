/**
Incluir:
-SDL2/SDL.h
-vector
-future
-thread
-string
-Crush.hpp

por esta ordem
**/

#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct
{
    std::promise<void> *promisePtr;
    std::thread *threadPtr;

} promiseThreadPair;

typedef struct
{

    SDL_Rect *rect;
    SDL_Texture *txtr;
    int w;
    int h;
} convenient;


typedef struct
{
    Crush result;
    int value;
} throwaway;

typedef struct
{

    const char *start;
    const char *end;
    //E, caso seja uma música...
    int freq;

} embededFileStream;

typedef std::vector<std::string> phraseVector;

typedef std::vector<promiseThreadPair> runningMediaVector;

typedef std::vector<embededFileStream> FileStreamVector;

#endif