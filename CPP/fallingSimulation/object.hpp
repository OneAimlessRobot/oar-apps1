#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;

class Object{


    private:

    SDL_Rect* object=(SDL_Rect*)malloc(sizeof(SDL_Rect));
    float speed;

    public:

    Object(SDL_Rect*rect,int speed,int size){

        this->object=rect;
        this->speed=speed;
        this->object->w=this->object->h=size;
    }


    void updateObjectPosition(int xOrigin,int yOrigin,SDL_Point*point){

        object->x+=speed* cos(atan2(point->y-yOrigin,point->x-xOrigin));
        object->y+=speed* sin(atan2(point->y-yOrigin,point->x-xOrigin));

    }

    void renderObject(SDL_Renderer*rend,int r,int g,int b){


        SDL_SetRenderDrawColor(rend,r,g,b,255);

        SDL_RenderFillRect(rend,this->object);


    }

    SDL_Point* getPosition(){

        SDL_Point* aux;
        aux->x=this->object->x;
        aux->y=this->object->y;

        return aux;
    }

    void destroyObject(){

        free(this->object);


    }



};