#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <list>
#include <vector>
#include "graphicalLib1.hpp"
#include <iostream>
#include "LTexture.hpp"
    LTexture::LTexture(SDL_Renderer*renderer,float x, float y, float w, float h,const char* path){
    this->rect=(SDL_FRect*)malloc(sizeof(SDL_FRect));
    (*this->rect)=(SDL_FRect){x,y,w,h};
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
    void LTexture::setXPos(float value){
    this->rect->x=value;
    }
    void LTexture::setYPos(float value){
    this->rect->y=value;

    }
    SDL_FPoint LTexture::getPos(){

        return (SDL_FPoint){this->rect->x,this->rect->y};



    }

    SDL_Texture* LTexture::getTexture(){

        return this->texture;



    }
    void LTexture::render(SDL_Renderer* renderer){
            if(this->texture){

                SDL_RenderCopyF(renderer,this->texture,NULL,this->rect);
            }
            else{
                SDL_SetRenderDrawColor(renderer,255,0,255,255);
                SDL_RenderFillRectF(renderer,this->rect);

            }
    }
    LTexture::~LTexture(){
    free(this->rect);
    SDL_DestroyTexture(this->texture);

    }


