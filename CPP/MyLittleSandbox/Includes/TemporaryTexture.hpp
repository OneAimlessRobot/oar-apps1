

#ifndef TEMP_TEXT_H
#define TEMP_TEXT_H
class TemporaryTexture{

    clockCounter* counter;
    SDL_Texture*texture;
    SDL_FRect* rect;

public:
    TemporaryTexture(float x, float y, float w, float h, SDL_Texture *texture, int ticks);
    TemporaryTexture(SDL_Renderer*renderer,float x, float y, float w, float h,const char* pathToImg, int ticks);
    TemporaryTexture(SDL_Renderer*renderer,float x, float y, float w, float h,const char* pathToImg, int ticks,int uselessValue);
    void setXPos(float value);
    void setYPos(float value);
    void increment();
    void reset();
    int getCurrentValue();
    int getMaxTicks();
    float getHeight();
    float getWidth();
    SDL_FPoint getPos();
    void render(SDL_Renderer* renderer);
    ~TemporaryTexture();



};
#endif
