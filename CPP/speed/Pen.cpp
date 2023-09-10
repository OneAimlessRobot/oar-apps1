#include <SDL2/SDL.h>
#include <vector>
#include "Pen.hpp"


    Pen::Pen(int thickness,SDL_Color color){

        this->thickness=thickness;
        this->inkColor=color;
    }


    void Pen::renderDrawing(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer,this->inkColor.r,this->inkColor.g,this->inkColor.b,this->inkColor.a);

        for(SDL_Rect rect:this->drawing){

            SDL_RenderFillRect(renderer,&rect);

        }



    }
    void Pen::draw(int x, int y){
        this->drawing.push_back((SDL_Rect){x-this->thickness*0.5,y-this->thickness*0.5,this->thickness,this->thickness});

    }
    void Pen::clearDrawing(){

        for(SDL_Rect rect:this->drawing){
            this->drawing.pop_back();

        }
    }

    Pen::~Pen(){


    }