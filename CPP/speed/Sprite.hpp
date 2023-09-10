

#ifndef SPRITE_H
#define SPRITE_H
class Sprite{
    clockCounter* frameCounter,*cycleCounter;
    std::vector<TemporaryTexture*> frames;
    int timePerFrame,xInit,yInit,unlimitted;

public:
    Sprite(SDL_Renderer*renderer,int x,int y,const char* pathToSprite,int unlimitted,int cycleNumber);

    void setPos(int x, int y);
    SDL_Point getPos();
    void render(SDL_Renderer* renderer);
    int isOver();
    void resetSprite();

    ~Sprite();



};
#endif