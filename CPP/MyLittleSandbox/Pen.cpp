#include <SDL2/SDL.h>
#include <vector>
#include "Pen.hpp"


    Pen::Pen(float thickness,SDL_Color color){

        this->thickness=thickness;
        this->inkColor=color;
    }


    void Pen::renderDrawing(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer,this->inkColor.r,this->inkColor.g,this->inkColor.b,this->inkColor.a);

        for(SDL_FRect rect:this->drawing){

            SDL_RenderFillRectF(renderer,&rect);

        }



    }
    void Pen::draw(float x,float y){
        this->drawing.push_back((SDL_FRect){x-this->thickness*0.5,y-this->thickness*0.5,this->thickness,this->thickness});

    }
    void Pen::clearDrawing(){


            int finished= drawing.size();
            for(int i=0;i<finished;i++){
                drawing.pop_back();
            }
    }

    Pen::~Pen(){


    }