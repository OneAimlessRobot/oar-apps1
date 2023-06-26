#ifndef AUX_H
#define AUX_H

#define COLLDISTANCE 2
#define TRAILLENGTH (COLLDISTANCE + 0)

#include <SDL2/SDL.h>
#include "Types/GVector.h"

namespace Aux{
float getRandomFloat(float min, float max);
float calculateDistance(SDL_FPoint p1,  SDL_FPoint p2);
SDL_Color randColor();
bool AreFRectsEqual(const SDL_FRect& rect1, const SDL_FRect& rect2);
GVector* makeUnitVector(SDL_FPoint origin, SDL_FPoint head);
void scaleVec(GVector* vec,float scalar);
}

#endif
