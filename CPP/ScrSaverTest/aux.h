#ifndef AUX_H
#define AUX_H
#include <SDL2/SDL.h>

namespace Aux{

float getRandomFloat(float min, float max);
float calculateDistance(SDL_FPoint p1,  SDL_FPoint p2);
SDL_Color randColor();
bool AreFRectsEqual(const SDL_FRect& rect1, const SDL_FRect& rect2);
}

#endif
