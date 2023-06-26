#ifndef COL_H
#define COL_H
class Collider{
private:
SDL_FRect containedObject,top,bottom,left,right;
SDL_bool type;
float airDensity;
SDL_Color bodyColor;
public:
Collider(SDL_bool type,SDL_Color color,float x,float y,float w,float h,float thickness,float airDensity);
void fullRender(SDL_Renderer* ren);
void render(SDL_Renderer* ren);
int whereIsColliding(SDL_FRect rect);
float getAirDensity();


};
#endif
