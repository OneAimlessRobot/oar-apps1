#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "graphicalLib1.hpp"
#include <iostream>
#include "LTexture.hpp"
    LTexture::LTexture(SDL_Renderer*renderer,int x, int y, int w, int h,const char* path){
    this->rect=(SDL_Rect*)malloc(sizeof(SDL_Rect));
    (*this->rect)=(SDL_Rect){x,y,w,h};
    SDL_Surface* surface=IMG_Load(path);
    if(!surface){

        std::cerr<<"Could not create surface\n";
        return;
    }
    this->texture=SDL_CreateTextureFromSurface(renderer,surface);
    if(!texture){

        std::cerr<<"Could not creaate texture\n";
        return;
    }
    SDL_FreeSurface(surface);


    }
    void LTexture::setXPos(int value){
    this->rect->x=value;
    }
    void LTexture::setYPos(int value){
    this->rect->y=value;

    }
    SDL_Point LTexture::getPos(){

        return (SDL_Point){this->rect->x,this->rect->y};



    }

    SDL_Texture* LTexture::getTexture(){

        return this->texture;



    }
    void LTexture::render(SDL_Renderer* renderer){
            if(this->texture){

                SDL_RenderCopy(renderer,this->texture,NULL,this->rect);
            }
            else{
                SDL_SetRenderDrawColor(renderer,255,0,255,255);
                SDL_RenderFillRect(renderer,this->rect);

            }
    }
    LTexture::~LTexture(){
    free(this->rect);
    SDL_DestroyTexture(this->texture);

    }


