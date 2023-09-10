#include <SDL2/SDL.h>
#include <math.h>
#include <vector>
#include "Menu.hpp"
#include "auxFunctions.h"
#include "graphicalLib1.hpp"
#include "GeometricVector.hpp"
#include "ODESolver.hpp"


    ODESolver::ODESolver(int x, int y, int width,int height,int stepW,int stepH,double(*Yprime)(double, double)){

    this->Yprime=Yprime;
    this->x=x;
    this->y=y;
    this->width=width;
    this->height=height;
    this->stepH=stepH;
    this->stepW=stepW;
//    this->slopeField={};

    }
    void ODESolver::drawCurve(SDL_Renderer* renderer, SDL_FPoint point,double step, int n){
        SDL_FPoint* points=(SDL_FPoint*)malloc(sizeof(SDL_FPoint)*n);
        double currentX=point.x,currentY=point.y,i;
        int j=0;
         SDL_FPoint newPoint=point;
    for(i=currentX,j=0;j<n;i+=(double)step,j++){
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

                GeometricVector<double>* vec=new GeometricVector<double>(i,j,1,Yprime((double)(i),(double)(j)),positive,this->stepW);
                vec->render(renderer,color);
                delete(vec);



            }

        }


    }