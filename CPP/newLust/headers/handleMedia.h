/**
Include:
-SDL2/SDL.h
-Structs.h


**/

#ifndef MEDIA_H
#define MEDIA_H

void printASCII(const char *end, const char *start, int dt);


void exportEmbededFile(const char *filename, const char *end, const char *start);

convenient initializeEmbededImage(const char *filename, SDL_Renderer *rend, const char *end, const char *start);


void runImageLoop(convenient data, SDL_Renderer *rend, SDL_Window *window, std::future<void> future);

void runImageLoopUnthreaded(convenient data, SDL_Renderer *rend, SDL_Window *window);

void createImageThread(convenient data, SDL_Renderer *rend, SDL_Window *window);

void spawnRandomImage();

void createAudioPlayingThread(Uint32 frequency, const char *filename, int duration, int *g_Var);

void clearMediaThreadVector(runningMediaVector &vec);

void clearMediaThreadVectorAndChangeVariable(int *g_Var, runningMediaVector &vec);

#endif