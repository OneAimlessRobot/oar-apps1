#include <SDL2/SDL.h>
#include <math.h>
#include <vector>
#include "Menu.hpp"
#include "auxFunctions.h"
#include "graphicalLib1.hpp"
#include "GeometricVector.hpp"
#include "ODESolver.hpp"


    ODESolver::ODESolver(int x, int y, int width,int height,int stepW,int stepH,float(*Yprime)(float, float)){

    this->Yprime=Yprime;
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    this->stepH=stepH;
    this->stepW=stepW;
//    this->slopeField={};

    }
    void ODESolver::drawCurve(SDL_Renderer* renderer, SDL_FPoint point,float step, int n){
        SDL_FPoint* points=(SDL_FPoint*)malloc(sizeof(SDL_FPoint)*n);
        float currentX=point.x,currentY=point.y,i;
        int j=0;
         SDL_FPoint newPoint=point;
    for(i=currentX,j=0;j<n;i+=(float)step,j++){
//
          newPoint=(SDL_FPoint){i,newPoint.y+this->Yprime(newPoint.x,newPoint.y)*step};
          points[j]=newPoint;

    }

        SDL_RenderDrawLinesF(renderer,points,n);
        free(points);



    }
    void ODESolver::drawSlopeField(SDL_Renderer*renderer, SDL_Color color){

        for(int i=this->x;i<this->width;i+=this->stepW*2){
            for(int j=this->y;j<this->height;j+=this->stepH*2){

                GeometricVector<float>* vec=new GeometricVector<float>(i,j,1,Yprime((float)(i),(float)(j)),positive,this->stepW);
                vec->render(renderer,color);
                delete(vec);



            }

        }


    }