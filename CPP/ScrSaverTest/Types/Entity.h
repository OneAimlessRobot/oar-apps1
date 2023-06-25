#ifndef ENT_H
#define ENT_H
class Entity{

private:

SDL_Color bodyColor;
SDL_FRect body;
SDL_FPoint pos,lastPos;
GVector* moveVec;
public:

Entity(SDL_Color clr,float x, float y, float w, float h);
void render(SDL_Renderer*ren);
void setPos(SDL_FPoint point);
void translate();
static Entity* randEnt(float x, float y);
SDL_FPoint getPos();
SDL_FPoint getLastPos();
GVector* getVec();
SDL_FRect getBody();

void setVec(GVector * vec);

~Entity();



};
#endif
