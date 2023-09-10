

#pragma once

class Entity
{

    

public:
    Entity() {}
    static int randNumBetZeroAnd(int lim)
    {

        return round(((random() / ((double)RAND_MAX + 1)) * lim));
    }

    static void drawCrossHair(SDL_Renderer *rend, int size, int x, int y)
    {

        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);

        SDL_RenderDrawLine(rend, x - size, y, x + size, y);

        SDL_RenderDrawLine(rend, x, y - size, x, y + size);
        SDL_RenderPresent(rend);
    }
    static void drawCrossHairF(SDL_Renderer *rend, float size, float x, float y)
    {

        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);

        SDL_RenderDrawLineF(rend, x - size, y, x + size, y);

        SDL_RenderDrawLineF(rend, x, y - size, x, y + size);
        SDL_RenderPresent(rend);
    }
    static void drawLaser(SDL_Renderer *rend, int xOrigin, int yOrigin, int xEnd, int yEnd)
    {

        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);

        SDL_RenderDrawLine(rend, xOrigin, yOrigin, 10000 * cos(atan2((yEnd)-yOrigin, (xEnd)-xOrigin)), 10000 * sin(atan2((yEnd)-yOrigin, (xEnd)-xOrigin)));
        SDL_RenderPresent(rend);
    }
    static double distBetPoints(SDL_Point *src, SDL_Point *dest)
    {

        return SDL_fabs(SDL_sqrt(((src->x) - (dest->x)) * ((src->x) - (dest->x)) + ((src->y) - (dest->y)) * ((src->y) - (dest->y))));
    }
};



class TestObject
{

    SDL_Rect *obj;

public:
    TestObject(int x, int y, int size)
    {

        this->obj->x = x;
        this->obj->y = y;
        this->obj->h = size = this->obj->w;
    }

    void renderIteration(SDL_Renderer *rend)
    {

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        SDL_RenderFillRect(rend, this->obj);

        SDL_RenderPresent(rend);
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    }
};


/*


void printAmmo(){

    for(int i=0;i<maxAmmount;i++){

        cout<<"Posiçao, velocidade da bala "<<i<<":"<<endl;
        cout<<"Posiçao :"<<ammo[i]->getXpos()<<" "<<ammo[i]->getYpos()<<endl;
        cout<<"velocidade :"<<ammo[i]->getSpeed()<<endl;
        cout<<"tamanho :"<<ammo[i]->getSize()<<endl;
    }
}

}*/

