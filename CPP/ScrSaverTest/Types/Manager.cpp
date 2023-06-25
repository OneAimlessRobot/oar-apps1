
#include <list>
#include <SDL2/SDL.h>
#include <random>
#include <cmath>
#include "../aux.h"
#include "Collider.h"
#include "GVector.h"
#include "Entity.h"
#include <iostream>
#include "Manager.h"

Manager::Manager(float maxSpeed,float maxSize,int ammount){

std::cout<<"Initializing video\n";
SDL_Init(SDL_INIT_EVERYTHING);


std::cout<<"Done!\n";

std::cout<<"Initializing window\n";
this->win= SDL_CreateWindow("ScrSaver",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);

std::cout<<"Done!\n";

std::cout<<"Initializing renderer\n";
this->ren=SDL_CreateRenderer(this->win,-1,SDL_RENDERER_ACCELERATED);

std::cout<<"Done!\n";
std::cout<<"Initializing background\n";
this->bgr= SDL_CreateTexture(ren,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,WIDTH,HEIGHT);

std::cout<<"Done!\n";
std::cout<<"Initializing entities\n";
this->ents= SDL_CreateTexture(ren,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,WIDTH,HEIGHT);


std::cout<<"Done!\n";
this->bgrclr=(SDL_Color){255,255,255,255};
this->arena= new Collider(SDL_FALSE,bgrclr,0,0,WIDTH,HEIGHT,50);
this->entList= {};
for(int i =0;i<ammount;i++){

    this->entList.emplace(this->entList.begin(),Entity::randEnt(WIDTH,HEIGHT,maxSize,maxSpeed));
}
}


void Manager::mainLoop(){
SDL_Event e;
SDL_bool quit=SDL_FALSE;
while(!quit){

    while(SDL_PollEvent(&e)){
        if(e.type==SDL_QUIT){

        quit=SDL_TRUE;


        }

    }
    doRendering();
    handleMovements();


}
delete this;

}

void Manager::doRendering(){

    SDL_SetRenderDrawColor(this->ren,this->bgrclr.r,this->bgrclr.g,this->bgrclr.b,this->bgrclr.a);
    SDL_SetRenderTarget(ren,bgr);
    SDL_RenderClear(ren);
    SDL_SetRenderTarget(ren,ents);
    SDL_RenderCopy(ren,bgr,NULL,NULL);
    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {
        (*it)->render(this->ren);
    }
    SDL_SetRenderTarget(ren,NULL);
    SDL_RenderCopy(ren,ents,NULL,NULL);
    SDL_RenderPresent(ren);

}

void Manager::handleMovements(){


    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {
        Entity *current= (*it);
        current->translate();
        SDL_FRect currBody=current->getBody();
        if(this->arena->whereIsColliding(currBody)>0){
        int where=this->arena->whereIsColliding(currBody);
            current->setPos(current->getLastPos());
            GVector* vec=current->getVec();
    if (where==1) {
        GVector::Reflect(vec, new GVector(-1.0f, 0.0f));
    } else if (where==2) {

        GVector::Reflect(vec, new GVector(1.0f, 0.0f));

    } else if (where==3) {

        GVector::Reflect(vec, new GVector(0.0f, -1.0f));
    } else if (where==4) {

        GVector::Reflect(vec, new GVector(0.0f, 1.0f));
        }
        //Problema com colisões diagonais (qual eixo de reflexão escolher?)
    }



}
}
Manager::~Manager(){

    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {

    delete (*it);
    }
SDL_DestroyTexture(this->bgr);
SDL_DestroyTexture(this->ents);
SDL_DestroyRenderer(this->ren);
SDL_DestroyWindow(this->win);

SDL_Quit();
}

