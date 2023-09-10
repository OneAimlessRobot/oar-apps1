#include "object.hpp"
#include "../game/entities.hpp"
#include <box2d/box2d.h>


int main(){


    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window*window=SDL_CreateWindow("ola",0,0,1000,500,(SDL_WINDOW_RESIZABLE));
    SDL_Renderer*rend= SDL_CreateRenderer(window,-1,(SDL_RENDERER_ACCELERATED,SDL_RENDERER_TARGETTEXTURE));
    SDL_Texture* texture=SDL_CreateTexture(rend,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,1000,500);

    SDL_Rect*rect=(SDL_Rect*)malloc(sizeof(SDL_Rect));

    rect->x=0;
    rect->y=0;
    Object*object=new Object(rect,4,10);


SDL_Event *e=(SDL_Event*)malloc(sizeof(SDL_Event));

bool running=true;

int checkpoint,init, mousex,mousey;

while(running){

    SDL_GetMouseState(&mousex,&mousey);

    SDL_Point*point=(SDL_Point*)malloc(sizeof(SDL_Point));

    point->x=mousex;
    point->y=mousey;

    SDL_Point*pos=object->getPosition();


    object->updateObjectPosition(mousex,mousey,pos);
    init=SDL_GetTicks();

    float delta=init-checkpoint;

    if(1/delta>30){

        SDL_Delay(16);
    }






    while(SDL_PollEvent(e)){


        if(e->type==SDL_QUIT){
        running=false;
        }
    }


    SDL_SetRenderDrawColor(rend,0,0,0,255);
    SDL_SetRenderTarget(rend,texture);
    SDL_RenderClear(rend);

    object->renderObject(rend,0,255,255);
    Useful::drawCrossHairF(rend,5,mousex,mousey);

    SDL_SetRenderTarget(rend,NULL);
    SDL_RenderCopy(rend,texture,NULL,NULL);

    checkpoint=SDL_GetTicks();
}

free(e);
SDL_DestroyRenderer(rend);
SDL_DestroyWindow(window);
SDL_DestroyTexture(texture);

SDL_Quit();


}