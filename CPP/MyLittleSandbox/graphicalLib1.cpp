#include<SDL2/SDL.h>
#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#include "graphicalLib1.hpp"

    void graphicalLib1::drawLineThisThick(float thickness,SDL_Renderer* renderer,SDL_Color color,float x1,float y1,float x2,float y2,int mode){
                SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
                if(mode){
                for(float i=-thickness*0.5;i<=thickness*0.5;i++){

                        SDL_RenderDrawLineF(renderer,x1+i,y1,x2+i,y2);
                }
                }
                else{
                for(float i=-thickness*0.5;i<=thickness*0.5;i++){

                        SDL_RenderDrawLineF(renderer,x1,y1+i,x2,y2+i);
                }


                }

    }


    void graphicalLib1::drawWireFrameNAgon(SDL_Renderer* renderer,SDL_Color color,int xOrigin,int yOrigin,int radius,int nSides,int facing){

                    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
                    std::vector<SDL_Point> vertexes={};
                    SDL_Point origin;
                    if(facing==0){
                        origin=(SDL_Point){xOrigin,yOrigin-radius};
                    }
                    else if(facing==1){
                        origin=(SDL_Point){xOrigin,yOrigin+radius};
                    }
                    else if(facing==2){
                        origin=(SDL_Point){xOrigin+radius,yOrigin};
                    }
                    else if(facing==3){
                        origin=(SDL_Point){xOrigin-radius,yOrigin};
                    }
                        vertexes.push_back(origin);
                    for(int i=1;i<=nSides;i++){

                        SDL_Point point=(SDL_Point){origin.x+(cos(i*M_PI/(0.5*nSides))*radius),origin.y+(sin(i*M_PI/(0.5*nSides))*radius)};
                        vertexes.push_back(point);


                    }
//                    for(int i=0;i<nSides;i++){
//                        SDL_RenderDrawLine(renderer,xOrigin,yOrigin,vertexes[i].x,vertexes[i].y);
//
//
//                    }
                    size_t i=0;
                    for(i;i<nSides;i++){
                        SDL_RenderDrawLine(renderer,vertexes[i+1].x,vertexes[i+1].y,vertexes[i].x,vertexes[i].y);


                    }
                        SDL_RenderDrawLine(renderer,vertexes[i].x,vertexes[i].y,vertexes[0].x,vertexes[0].y);

        }
        void graphicalLib1::drawEquation(SDL_Renderer*renderer,int (*f)(int),SDL_Color color, int xOrigin,int yOrigin,int xEnd){
                    SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);
                    std::vector<SDL_Point> vertexes={};
            for(size_t i=xOrigin;i<xEnd;i++){
            SDL_Point point=(SDL_Point){i,f(i)};
                    vertexes.push_back(point);

            }

                    for(std::iterator it=vertexes.begin();it!=vertexes.end();i++){
                        SDL_RenderDrawLineF(renderer,(*(it-1)).x,(*(it-1)).y,(*it).x,(*it).y);


                    }



        }
        void graphicalLib1::drawLineFromPointVector(SDL_Renderer*renderer,SDL_Color color, std::vector<SDL_FPoint> vec){

                SDL_SetRenderDrawColor(renderer,color.r,color.g,color.b,color.a);

                for(std::iterator it=vec.begin();it!=vec.end();i++){

                    SDL_RenderDrawLine(renderer,(*it).x,(*it).y,(*(it-1)).x,(*(it-1)).y);
                }

        }
        void graphicalLib1::drawThickLineFromPointVector(SDL_Renderer*renderer,SDL_Color color, float thickness,std::vector<SDL_FPoint> vec){


                for(std::iterator it= vec.begin()+1;it!= vec.end();it++){

                    drawLineThisThick(thickness,renderer,color,(*it).x,(*it).y,(*(it+1)).x,(*(it+1)).y,0);
                }

        }
        void graphicalLib1::drawCircunference(SDL_Renderer*renderer,SDL_Color color, float radius,float xCenter,float yCenter,float precision){
            float per=0,newX,newY;
            std::vector<SDL_FPoint> points={};
        while((per<2*precision)){

        newX=radius*cos(per*M_PI/precision)+xCenter;
        newY=radius*sin(per*M_PI/precision)+yCenter;
        SDL_FPoint point=(SDL_FPoint){newX,newY};
        points.push_back(point);

        per++;
        }

        drawLineFromPointVector(renderer,color,points);

        }

        void graphicalLib1::drawCircle(SDL_Renderer*renderer,SDL_Color color, float radius,float x,float y){

            for(radius;radius>0;radius--){
                drawCircunference(renderer,color,radius,x,y,100);



            }

        }

//    static void graphicalLib1::drawWireFrameArrow(SDL_Renderer* renderer,SDL_Color color,int xOrigin,int yOrigin,int radius,int tailLength){
//
//            drawWireFrameTriangle(renderer,color,xOrigin,yOrigin,radius);
//
//            SDL_RenderDrawLine(renderer,xOrigin,yOrigin,xOrigin)
//
//    }
    clockCounter::clockCounter(int initial,int modulus,int unlimitted){
        this->current=initial;
        this->modulus=modulus;
        this->unlimitted=unlimitted;

    }
    void clockCounter::increment(){
        if(this->current<this->modulus-1||this->unlimitted){
            this->current++;
        }
        else{
            this->current=0;

        }
    }
    void clockCounter::decrement(){
        if((this->current>0)||unlimitted){
            this->current--;
        }
        else{
            this->current=this->modulus-1;


        }
    }
    int clockCounter::getCurrent(){
            return this->current;
    }
    int clockCounter::getModulus(){
            return this->modulus;
    }
    void clockCounter::setCurrent(int value){
            this->current=value;
    }
    void clockCounter::setModulus(int value){
            this->modulus=value;
    }

