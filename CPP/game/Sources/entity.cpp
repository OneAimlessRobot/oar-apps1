#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Includes/entity.hpp"

    Entity::Entity() {}
    float Entity::randNumBetZeroAnd(float lim)
    {

        return ((random() / ((float)RAND_MAX + 1)) * lim);
    }

    void Entity::drawCrossHair(SDL_Renderer *rend, int size, int x, int y)
    {

        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);

        SDL_RenderDrawLine(rend, x - size, y, x + size, y);

        SDL_RenderDrawLine(rend, x, y - size, x, y + size);
        SDL_RenderPresent(rend);
    }
    void Entity::drawCrossHairF(SDL_Renderer *rend, float size, float x, float y)
    {

        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);

        SDL_RenderDrawLineF(rend, x - size, y, x + size, y);

        SDL_RenderDrawLineF(rend, x, y - size, x, y + size);
        SDL_RenderPresent(rend);
    }
    void Entity::drawLaser(SDL_Renderer *rend, float xOrigin, float yOrigin, float xEnd, float yEnd)
    {

        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);

        SDL_RenderDrawLineF(rend, xOrigin, yOrigin, 10000 * cos(atan2((yEnd)-yOrigin, (xEnd)-xOrigin)), 10000 * sin(atan2((yEnd)-yOrigin, (xEnd)-xOrigin)));
        SDL_RenderPresent(rend);
    }
    double Entity::distBetPoints(SDL_FPoint *src, SDL_FPoint *dest)
    {

        return SDL_fabs(SDL_sqrt(((src->x) - (dest->x)) * ((src->x) - (dest->x)) + ((src->y) - (dest->y)) * ((src->y) - (dest->y))));
    }

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
