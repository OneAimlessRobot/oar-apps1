#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "Menu.hpp"
#include "graphicalLib1.hpp"
#include"auxFunctions.h"
#include "Trail.hpp"


    Trail::Trail(int length,int width,int xInit,int yInit,SDL_Color color){
            this->currentX=xInit;
            this->currentY=yInit;
            this->trailPoints={};
            this->color=color;
            this->trailLength=length;
            this->trailThickness=width;


    }

    int Trail::getThickness(){
        return this->trailThickness;

    }
    void Trail::render(SDL_Renderer* renderer){

        if((this->getLength()>=this->trailLength)){

                trailPoints.erase(trailPoints.begin());


        }
            trailPoints.push_back(getCurrentPos());
        SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);

        graphicalLib1::drawThickLineFromPointVector(renderer,this->color,this->trailThickness,this->trailPoints);




    }
    SDL_Point Trail::getCurrentPos(){
            return (SDL_Point){this->currentX,this->currentY};
    }
    void Trail::setPos(int x, int y){
                this->currentX=x;
                this->currentY=y;
    }
    void Trail::setThickness(int value){

            this->trailThickness=value;
    }
    int Trail::getLength(){
        int result=0;
        if(trailPoints.size()<2){
        return 0;
        }
        for(int i=0;i<trailPoints.size()-1;i++){

            result+=aux::distBetPoints(&trailPoints[i],&trailPoints[i+1]);

        }
        return result;

    }
    Trail::~Trail(){


    }
