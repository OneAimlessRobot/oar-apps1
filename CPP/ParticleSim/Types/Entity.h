#ifndef ENT_H
#define ENT_H
class Entity{
protected:

SDL_FRect body;
SDL_Color bodyColor;
SDL_FPoint pos,lastPos;
GVector* moveVec,*lastVec;
std::vector<SDL_FPoint> lastPositions;
private:

int historyLen;
float inve,mass,Car;
public:

Entity(SDL_Color clr,float x, float y, float w, float h,float inve,float m,float Car);
void render(SDL_Renderer*ren);
void setPos(SDL_FPoint point);
void translate();
void bounce();
float getInvElasticity();
float getDragConstant();
void setLastPos(SDL_FPoint lp);
float getMass();
float getSpeedLoss();
static Entity* randEnt(float width, float height,float maxMass,float maxSize,float maxSpeed);
static int areTouching(Entity*a,Entity*b);
SDL_FPoint getPos();
SDL_FPoint getLastPos();
SDL_FPoint getVec();
SDL_FRect getBody();
SDL_FPoint getCenter();
float getRadius();
float getQuality();
float getTotalEnergy();

void setVec(SDL_FPoint point);

~Entity();



};
#endif
