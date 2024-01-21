#ifndef ENTITY_HPP
#define ENTITY_HPP

class Entity
{

    

public:
    Entity();
    static float randNumBetZeroAnd(float lim);
    static void drawCrossHair(SDL_Renderer *rend, int size, int x, int y);
    static void drawCrossHairF(SDL_Renderer *rend, float size, float x, float y);
    static void drawLaser(SDL_Renderer *rend, float xOrigin, float yOrigin, float xEnd, float yEnd);
    static double distBetPoints(SDL_FPoint *src, SDL_FPoint *dest);
};
#endif
