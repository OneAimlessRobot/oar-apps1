

#ifndef TEMP_TEXT_H
#define TEMP_TEXT_H
class TemporaryTexture{

    clockCounter* counter;
    SDL_Texture*texture;
    SDL_Rect* rect;

public:
    TemporaryTexture(int x, int y, int w, int h, SDL_Texture *texture, int ticks);
    TemporaryTexture(SDL_Renderer*renderer,int x, int y, int w, int h,const char* pathToImg, int ticks);
    TemporaryTexture(SDL_Renderer*renderer,int x, int y, int w, int h,const char* pathToImg, int ticks,int uselessValue);
    void setXPos(int value);
    void setYPos(int value);
    void increment();
    void reset();
    int getCurrentValue();
    int getMaxTicks();
    int getHeight();
    int getWidth();
    SDL_Point getPos();
    void render(SDL_Renderer* renderer);
    ~TemporaryTexture();



};
#endif
