
#ifndef FADING_TEXT_H
#define FADING_TEXT_H
class FadingTexture{

    clockCounter* counter;
    SDL_Texture*texture;
    SDL_FRect* rect;

    int startFadingTick, endFadingTick;
    Uint8 currentAlpha,startingAlpha;

    Uint8 getAlphaFading();
public:
    FadingTexture(float x, float y, float w, float h, SDL_Texture *texture, int ticks,int startFadingTick,int endFadingTick,Uint8 startingAlpha);
    FadingTexture(SDL_Renderer* renderer,float x, float y, float w, float h, const char* path, int ticks,int startFadingTick,int endFadingTick,Uint8 startingAlpha);
    void setXPos(float value);
    void setYPos(float value);
    void resetFading();
    void increment();
    int getCurrentValue();
    SDL_FPoint getPos();
    void render(SDL_Renderer* renderer);
    ~FadingTexture();



};
#endif