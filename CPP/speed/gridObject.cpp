#include<SDL2/SDL.h>
#include<string>
#include<iostream>
#include <vector>
#include"Menu.hpp"
#include"gridObject.hpp"
#include"graphicalLib1.hpp"


    gridObject::gridObject(int height,int width,int thickness,int horizontalSpacing,int verticalSpacing,int margin,int r,int g,int b, int a,const char* fontPath){
        this->height=height;
        this->width=width;
        this->margin=margin;
        this->horizontalSpacing=horizontalSpacing;
        this->verticalSpacing=verticalSpacing;
        this->color=(SDL_Color){r,g,b,a};

        char i;
        int j=0;
        for(i=fontPath[j];i!='\0';i=fontPath[j++]){
        this->fontPath[j]=i;
        }
        this->fontPath[j+1]='\0';

    }

    void gridObject::renderGrid(SDL_Renderer* renderer,int xOrigin,int yOrigin){
            SDL_SetRenderDrawColor(renderer,this->color.r,this->color.g,this->color.b,this->color.a);
            int xGridStart=xOrigin-this->margin,
                yGridStart=yOrigin-this->margin;
            SDL_Point bottomLeft=(SDL_Point){xOrigin,yOrigin+this->height};
            SDL_Point topLeft=(SDL_Point){xOrigin,yOrigin};
            SDL_Point bottomRight=(SDL_Point){xOrigin+this->width,yOrigin+this->height};
            SDL_Point topRight=(SDL_Point){xOrigin+this->width,yOrigin};

            for(int i=topLeft.x;i<=topRight.x;i+=this->horizontalSpacing){
                    SDL_RenderDrawLine(renderer,i,yOrigin,i,yOrigin+this->height);
                    textBox*numberLabel=new textBox(renderer,this->horizontalSpacing*0.333,i,yGridStart,this->fontPath,this->color.r,this->color.g,this->color.b,this->color.a,std::to_string(i).std::string::c_str());
                    numberLabel->render(renderer);
                    delete(numberLabel);
            }
            graphicalLib1::drawLineThisThick(5,renderer,this->color,xOrigin,yOrigin,xOrigin+this->width,yOrigin,0);
            for(int i=topLeft.y;i<=bottomLeft.y;i+=this->verticalSpacing){
                    SDL_RenderDrawLine(renderer,xOrigin,i,xOrigin+this->width,i);
                    textBox*numberLabel=new textBox(renderer,this->verticalSpacing*0.333,xGridStart,i,this->fontPath,this->color.r,this->color.g,this->color.b,this->color.a,std::to_string(i).std::string::c_str());
                    numberLabel->render(renderer);
                    delete(numberLabel);
            }
            graphicalLib1::drawLineThisThick(5,renderer,this->color,xOrigin,yOrigin,xOrigin,yOrigin+this->height,1);


    }
