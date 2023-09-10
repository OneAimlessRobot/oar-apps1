#include <iostream>
#include <windows.h>
#include "include/SDL.h"
#include "include/SDL_image.h"
#include "include/displayImage.h"
#ifdef main
# undef main
#endif
int main(){
SDL_SetMainReady();
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window * window=SDL_CreateWindow("",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,1000, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *rend=SDL_CreateRenderer(window,-1,0);

    convenient dados=initializeEmbededImage("img.PNG", rend);
SDL_Event event;
bool quit=false;
    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, dados.txtr, NULL, dados.rect);
        SDL_RenderPresent(rend);
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
}
