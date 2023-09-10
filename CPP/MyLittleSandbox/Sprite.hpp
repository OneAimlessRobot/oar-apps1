

#ifndef SPRITE_H
#define SPRITE_H
class Sprite{
    clockCounter* frameCounter,*cycleCounter;
    std::list<TemporaryTexture*> frames;
    int timePerFrame,xInit,yInit,unlimitted;

public:
    Sprite(SDL_Renderer*renderer,float x,float y,const char* pathToSprite,int unlimitted,int cycleNumber);

    void setPos(float x,float y);
    SDL_FPoint getPos();
    void render(SDL_Renderer* renderer);
    int isOver();
    void resetSprite();

    ~Sprite();



};
#endif