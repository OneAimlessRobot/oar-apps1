#ifndef ENT_H
#define ENT_H
class Entity{

private:

SDL_Color bodyColor;
SDL_FRect body;
SDL_FPoint pos,lastPos;
GVector* moveVec,*lastVec;
std::vector<SDL_FPoint> lastPositions;
int historyLen;
float elasticity,mass,Car;
public:

Entity(SDL_Color clr,float x, float y, float w, float h,float e,float m,float Car);
void render(SDL_Renderer*ren);
void setPos(SDL_FPoint point);
void translate();
void bounce();
float getElasticity();
float getDragConstant();
void setLastPos(SDL_FPoint lp);
float getMass();
float getSpeedLoss();
static Entity* randEnt(float width, float height,float maxMass,float maxSize,float maxSpeed);
SDL_FPoint getPos();
SDL_FPoint getLastPos();
GVector* getVec();
SDL_FRect getBody();

void setVec(GVector * vec);

~Entity();



};
#endif
