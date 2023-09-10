
#ifndef HITBOX_H
#define HITBOX_H
class HitBox{

    SDL_FRect    *left,
                *right,
                *up,
                *down;
    float      x,
                y,
                w,
                h,
                thickness;
    int    type;
public:
    HitBox(float x,float y, float w, float h,float thickness,int type);
    int getType();
    void setPos(float x,float y);
    SDL_FPoint getPos();
    float getThickness();
    float getOuterWidth();
    float getInnerWidth();
    float getOuterHeight();
    float getInnerHeight();
    void setInnerWidth(float value);
    void setInnerHeight(float value);
    int hitLeft(const SDL_FRect* rect);
    int hitRight(const SDL_FRect* rect);
    int hitUp(const SDL_FRect* rect);
    int hitDown(const SDL_FRect* rect);
    void render(SDL_Renderer *renderer);

    ~HitBox();


};
#endif
