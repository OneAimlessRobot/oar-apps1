#include"Menu.hpp"
#include<math.h>
#include <stdint.h>
#include<string>
#include<cstring>
#include"auxFunctions.h"
   int aux::randNumBetZeroAnd(int lim)
    {

        return round(((random() / ((double)RAND_MAX + 1)) * lim));
    }
    int aux::OnesAreContained(Uint16 mask1,Uint16 mask2){

        return (mask1&mask2)==mask2;



    }
    std::string aux::printMask(Uint16 mask){
    Uint16 value=mask;
    std::string result;
    result+=std::to_string(mask&1);
        for(int i=0;i<16;i++){
                value>>=1;
                result+=std::to_string(value&1);

        }
        return result;



    }
   textBox* aux::createTextBoxForVariable(SDL_Renderer* renderer,int fontSize,int x,int y,const char* fontFileName,Uint8 r, Uint8 g,Uint8 b,Uint8 a,int*variable,const char* label)
    {

            std::string text;
            if(variable!=NULL){

                text=label+std::to_string((*variable));
            }
            else{
                text=label;
            }
            return new textBox(renderer,fontSize,x,y,fontFileName,255,255,255,255,text.std::string::c_str());

    }

    double aux::distBetPoints(SDL_Point *src, SDL_Point *dest)
    {

        return fabs(sqrt(((src->x) - (dest->x)) * ((src->x) - (dest->x)) + ((src->y) - (dest->y)) * ((src->y) - (dest->y))));
    }
    double aux::distBetPointsInts(int x1,int y1,int x2,int y2)
    {

        return fabs(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
    }

