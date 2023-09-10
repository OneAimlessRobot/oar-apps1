
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <vector>
#include "HitBox.hpp"
#include "Obstacle.hpp"
    Obstacle::Obstacle(SDL_Renderer*renderer,int x,int y, int w, int h, int thickness,int type,SDL_Color color,const char* path){
    this->color=color;
    this->thickness=thickness;
    this->path2Img=path.std::string::c_str();
    SDL_Surface *surface=IMG_Load(path);
    this->texture=SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    this->hitBox=new HitBox(x,y,w,h,thickness,type);
    this->body=(SDL_Rect*)malloc(sizeof(SDL_Rect));
    *(this->body)=(SDL_Rect){x+thickness,y+thickness,w-(2*thickness),h-(2*thickness)};
                            this->setInnerHeight(h);
                            this->setInnerWidth(w);

    }

    int Obstacle::getHitBoxType(){

        return this->hitBox->getType();
    }
    void Obstacle::setPos(int x,int y){

        this->hitBox->setPos(x,y);
    }
    SDL_Point Obstacle::getCorePos(){

        return (SDL_Point){this->hitBox->getPos().x+this->thickness,
                            this->hitBox->getPos().y+this->thickness};
    }
    SDL_Point Obstacle::getShellPos(){

        return this->hitBox->getPos();
    }
    std::string Obstacle::getPath2Img(){
            return this->path2Img;

    }

    int Obstacle::getOuterWidth(){
            return this->hitBox->getOuterWidth();

    }
    int Obstacle::getInnerWidth(){
            return this->hitBox->getInnerWidth();
    }
    int Obstacle::getOuterHeight(){

            return this->hitBox->getOuterHeight();


    }
    int Obstacle::getInnerHeight(){
            return this->hitBox->getInnerHeight();
    }
    int Obstacle::getThickness(){
        return this->thickness;
    }
    void Obstacle::setInnerHeight(int value){

        this->hitBox->setInnerHeight(value);
        this->body->h=value;
    }
    void Obstacle::setInnerWidth(int value){
        this->hitBox->setInnerWidth(value);
        this->body->w=value;
    }
    int Obstacle::boxHitLeft(const SDL_Rect* rect){

        return this->hitBox->hitLeft(rect);
    }
    int Obstacle::boxHitRight(const SDL_Rect* rect){

        return this->hitBox->hitRight(rect);
    }
    int Obstacle::boxHitUp(const SDL_Rect* rect){

        return this->hitBox->hitUp(rect);
    }
    int Obstacle::boxHitDown(const SDL_Rect* rect){

        return this->hitBox->hitDown(rect);
    }
    int Obstacle::boxContains(SDL_Point*point){

        return SDL_PointInRect(point,this->body);
    }
    void Obstacle::renderObstacle(SDL_Renderer* renderer){
    if(this->texture){

        SDL_RenderCopy(renderer,this->texture,NULL,this->body);

    }else{
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer,this->color.r,this->color.g,this->color.b,120);
        SDL_RenderFillRect(renderer,this->body);
        }


    }
    void Obstacle::renderObstacleFillOnly(SDL_Renderer* renderer){

        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(renderer,this->color.r,this->color.g,this->color.b,120);
        SDL_RenderFillRect(renderer,this->body);

    }
    Obstacle::~Obstacle(){

        delete(hitBox);
        SDL_DestroyTexture(this->texture);
        free(this->body);
    }

