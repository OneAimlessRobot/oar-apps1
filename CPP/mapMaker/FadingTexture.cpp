#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "graphicalLib1.hpp"
#include "FadingTexture.hpp"
#include <iostream>
    FadingTexture::FadingTexture(int x, int y, int w, int h, SDL_Texture *texture, int ticks,int startFadingTick,int endFadingTick,Uint8 startingAlpha){
   this->rect=(SDL_Rect*)malloc(sizeof(SDL_Rect));
    (*this->rect)=(SDL_Rect){x,y,w,h};
    this->counter=new clockCounter(1,ticks,0);
    this->texture=texture;
    this->startFadingTick=startFadingTick;
    this->endFadingTick=endFadingTick;
    this->currentAlpha=startingAlpha;
    this->startingAlpha=startingAlpha;


    }
    FadingTexture::FadingTexture(SDL_Renderer* renderer,int x, int y, int w, int h, const char* path, int ticks,int startFadingTick,int endFadingTick,Uint8 startingAlpha){
    this->rect=(SDL_Rect*)malloc(sizeof(SDL_Rect));
    (*this->rect)=(SDL_Rect){x,y,w,h};
    this->counter=new clockCounter(1,ticks,0);

    SDL_Surface*surface=IMG_Load(path);
    if(!surface){
            return;

    }
    this->texture=SDL_CreateTextureFromSurface(renderer,surface);
    if(!texture){

        std::cerr<<"Could not create texture\n";
        return;

    }
    SDL_FreeSurface(surface);

    this->startFadingTick=startFadingTick;
    this->endFadingTick=endFadingTick;
    this->currentAlpha=startingAlpha;
    this->startingAlpha=startingAlpha;


    }

    void FadingTexture::setXPos(int value){
    this->rect->x=value;
    }
    void FadingTexture::setYPos(int value){
    this->rect->y=value;

    }
    SDL_Point FadingTexture::getPos(){

        return (SDL_Point){this->rect->x,this->rect->y};



    }
    void FadingTexture::render(SDL_Renderer* renderer){

        if(this->counter->getCurrent()>=this->startFadingTick){
            this->currentAlpha=getAlphaFading();

        }
        else{
            this->currentAlpha=this->startingAlpha;
        }
        if(this->counter->getCurrent()&&this->counter->getCurrent()<=this->endFadingTick){
            if(this->texture){

                SDL_SetTextureAlphaMod(this->texture,this->currentAlpha);
                SDL_SetTextureBlendMode(this->texture,SDL_BLENDMODE_BLEND);
                SDL_RenderCopy(renderer,this->texture,NULL,this->rect);
            }
            else{
                SDL_SetRenderDrawColor(renderer,255,0,255,this->currentAlpha);
                SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
                SDL_RenderFillRect(renderer,this->rect);

            }
            increment();
        }

    }
    void FadingTexture::increment(){
        this->counter->increment();

    }
    int FadingTexture::getCurrentValue(){
        return this->counter->getCurrent();

    }
    void FadingTexture::resetFading(){
        this->counter->setCurrent(this->startFadingTick);

    }

    Uint8 FadingTexture::getAlphaFading(){
    return(Uint8) (255-(255*((double)(this->counter->getCurrent()-this->startFadingTick)/(this->endFadingTick-this->startFadingTick))));


    }


    FadingTexture::~FadingTexture(){
    free(this->rect);
    delete(this->counter);
    SDL_DestroyTexture(this->texture);

    }


