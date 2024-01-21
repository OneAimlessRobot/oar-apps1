
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <vector>
#include "../Includes/HitBox.hpp"
#include "../Includes/Obstacle.hpp"
    Obstacle::Obstacle(SDL_Renderer*renderer,float x,float y, float w, float h, float thickness,int type,SDL_Color color,const char* path){
    this->color=color;
    this->thickness=thickness;
    SDL_Surface *surface=IMG_Load(path);
    this->texture=SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    this->hitBox=new HitBox(x,y,w,h,thickness,type);
    this->body=(SDL_FRect*)malloc(sizeof(SDL_FRect));
    *(this->body)=(SDL_FRect){x+thickness,y+thickness,w-(2*thickness),h-(2*thickness)};
                            this->setInnerHeight(h);
                            this->setInnerWidth(w);

    }

    int Obstacle::getHitBoxType(){

        return this->hitBox->getType();
    }
    void Obstacle::setPos(float x,float y){

        this->hitBox->setPos(x,y);
    }
    SDL_FPoint Obstacle::getCorePos(){

        return (SDL_FPoint){this->hitBox->getPos().x+this->thickness,
                            this->hitBox->getPos().y+this->thickness};
    }
    SDL_FPoint Obstacle::getShellPos(){

        return this->hitBox->getPos();
    }

    float Obstacle::getOuterWidth(){
            return this->hitBox->getOuterWidth();

    }
    float Obstacle::getInnerWidth(){
            return this->hitBox->getInnerWidth();
    }
    float Obstacle::getOuterHeight(){

            return this->hitBox->getOuterHeight();


    }
    float Obstacle::getInnerHeight(){
            return this->hitBox->getInnerHeight();
    }
    float Obstacle::getThickness(){
        return this->thickness;
    }
    void Obstacle::setInnerHeight(float value){

        this->hitBox->setInnerHeight(value);
        this->body->h=value;
    }
    void Obstacle::setInnerWidth(float value){
        this->hitBox->setInnerWidth(value);
        this->body->w=value;
    }
    int Obstacle::boxHitLeft(const SDL_FRect* rect){

        return this->hitBox->hitLeft(rect);
    }
    int Obstacle::boxHitRight(const SDL_FRect* rect){

        return this->hitBox->hitRight(rect);
    }
    int Obstacle::boxHitUp(const SDL_FRect* rect){

        return this->hitBox->hitUp(rect);
    }
    int Obstacle::boxHitDown(const SDL_FRect* rect){

        return this->hitBox->hitDown(rect);
    }
    int Obstacle::boxContains(const SDL_FRect* rect){

        return this->hitBox->hitDown(rect);
    }
    void Obstacle::render(SDL_Renderer* renderer){
    if(this->texture){

        SDL_RenderCopyF(renderer,this->texture,NULL,this->body);

    }else{
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer,this->color.r,this->color.g,this->color.b,120);
        SDL_RenderFillRectF(renderer,this->body);
        }


    }
    void Obstacle::renderBodyOnly(SDL_Renderer* renderer){

        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer,this->color.r,this->color.g,this->color.b,120);
        SDL_RenderFillRectF(renderer,this->body);

    }
    Obstacle::~Obstacle(){

        delete(hitBox);
        SDL_DestroyTexture(this->texture);
        free(this->body);
    }

