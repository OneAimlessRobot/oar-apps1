#include<SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "graphicalLib1.hpp"

class LTexture{

    SDL_Texture*texture;
    SDL_Rect* rect;

public:
    LTexture(SDL_Renderer* renderer,int x, int y, int w, int h, const char* path);
    void setXPos(int value);
    void setYPos(int value);
    SDL_Point getPos();
    SDL_Texture* getTexture();
    void render(SDL_Renderer* renderer);
    ~LTexture();



};