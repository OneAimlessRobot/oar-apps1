

#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include"object.hpp"
#include"Menu.hpp"
#include<math.h>
#include<iostream>

int main(){
    TTF_Init();
    SDL_Init(SDL_INIT_EVERYTHING);

        SDL_Window* win=SDL_CreateWindow("OLA",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,1000,(SDL_RENDERER_SOFTWARE,SDL_WINDOW_FULLSCREEN,SDL_WINDOW_MOUSE_CAPTURE));
        if(win==NULL){

        std::cout<<"Could not create window\n";
        }
        SDL_Renderer* ren=SDL_CreateRenderer(win,-1,SDL_TEXTUREACCESS_TARGET|SDL_RENDERER_ACCELERATED);
        if(ren==NULL){

        std::cout<<"Could not create renderer\n";
        }
        textBox * text=new textBox(ren,28,0,0,"/usr/share/fonts/truetype/freefont/FreeSans.ttf",255,255,255,255,"OLA!");


        std::cout<<"Cheguei até aqui\n";
        int mSpeed=0;
        SDL_Event e;
        SDL_bool run=SDL_TRUE,home=SDL_FALSE;

        int desiredDelta=1000/30;
        while(run){
        int initFrame=SDL_GetTicks();
        while(SDL_PollEvent(&e)){

            if(e.type==SDL_QUIT){
                run=SDL_FALSE;
            }

        }
        text->render(ren);

        int delta= SDL_GetTicks()- initFrame;

        if(delta<desiredDelta){

            SDL_Delay(desiredDelta);
        }

        }

        SDL_DestroyRenderer(ren);
        SDL_DestroyWindow(win);
        SDL_Quit();
        TTF_Quit();

}

