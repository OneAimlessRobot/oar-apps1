#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <future>
#include <vector>
#include <thread>
#include <string>
#include <unistd.h>
#include "../headers/Crush.hpp"
#include "../headers/Structs.h"
#include "../headers/globals.h"
#include "../headers/handleSounds.h"
#include "../headers/auxFuncs.h"
#include "../headers/handleMedia.h"
void printASCII(const char *end, const char *start, int dt)
{

    for (int i = 0; i < (end - start); i++)
    {

        std::cout << start[i];
        usleep(dt);
    }
}


void exportEmbededFile(const char *filename, const char *end, const char *start)
{
    std::ofstream fileWriter(filename);

    for (int i = 0; i < (end - start); i++)
    {

        fileWriter<<start[i];
    }

    fileWriter.close();
}

convenient initializeEmbededImage(const char *filename, SDL_Renderer *rend, const char *end, const char *start)
{

    int *w = new int(1), *h = new int(1);
    exportEmbededFile(filename, end, start);
    SDL_Texture *img = IMG_LoadTexture(rend, filename);
    remove(filename);
    SDL_QueryTexture(img, NULL, NULL, w, h);
    SDL_Rect *hole = new SDL_Rect();
    *hole = {0, 0, *w, *h};
    convenient dados = {hole, img, hole->w, hole->h};
    delete w;
    delete h;
    return dados;
}


void runImageLoop(convenient data, SDL_Renderer *rend, SDL_Window *window, std::future<void> future)
{
    SDL_Event event;
    bool running = true;

    // Eu não percebo como funciona a segunda parte desta condição e copiei da net porque queria que o programa corresse bem antes de
    // Deixar de trabalhar nele

    while (running && (future.wait_for(std::chrono::seconds(1)) == std::future_status::timeout))
    {

        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE)
            {
                {
                    running = false;
                }
            }
        }
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, data.txtr, NULL, data.rect);
        SDL_RenderPresent(rend);
    }
    SDL_DestroyTexture(data.txtr);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    if (g_Debug)
    {
        std::cout << "N sei se o thread terminou. Mas pelo menos chegou aqui." << std::endl;
    }
}

void runImageLoopUnthreaded(convenient data, SDL_Renderer *rend, SDL_Window *window)
{
    SDL_Event event;
    bool running = true;

    while (running)
    {

        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE)
            {
                {
                    running = false;
                }
            }
        }
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, data.txtr, NULL, data.rect);
        SDL_RenderPresent(rend);
    }
    SDL_DestroyTexture(data.txtr);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    if (g_Debug)
    {
        std::cout << "Janela fechou." << std::endl;
    }
}

void createImageThread(convenient data, SDL_Renderer *rend, SDL_Window *window)
{

    std::promise<void> *promise = new std::promise<void>;
    std::future<void> f = promise->get_future();
    std::thread *playing = new std::thread(runImageLoop, data, rend, window, std::move(f));
    runningImages.push_back({promise, playing});
}

void spawnRandomImage()
{


    SDL_Window *window = SDL_CreateWindow("Ola, coisa boa ;)", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 100, 100, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, (SDL_RENDERER_TARGETTEXTURE));
    embededFileStream img = (images)[randNumBetZeroAnd((images).size() - 1)];
    convenient data = initializeEmbededImage("_", rend, img.end, img.start);
    SDL_SetWindowSize(window, data.w, data.h);
    createImageThread(data, rend, window);
}

void createAudioPlayingThread(Uint32 frequency, const char *filename, int duration, int *g_Var)
{
    (*g_Var)=1;
    std::promise<void> *promise = new std::promise<void>;
    std::future<void> f = promise->get_future();
    std::thread *playing = new std::thread(loadNplaySound, frequency, filename, duration, std::move(f), g_Var);
    if (g_Var == &g_SoundOn)
    {
        playing->join();
        (runningSounds).push_back({promise, playing});
    }
    else
    {
        (runningMusic).push_back({promise, playing});
    }
}
void clearMediaThreadVector(runningMediaVector &vec)
{
    for (runningMediaVector::iterator it = vec.begin(); it != vec.end();)
    {

        if (vec.size() >= 1)
        {
            (*it).promisePtr->set_value();
            if ((*it).threadPtr->joinable())
            {
                (*it).threadPtr->detach();
            }
            (*it).threadPtr->~thread();
            (*it).promisePtr->~promise();
            vec.erase(it);
        }
    }
}
void clearMediaThreadVectorAndChangeVariable(int *g_Var, runningMediaVector &vec)
{
    clearMediaThreadVector(vec);
    (*g_Var) = 0;
}
