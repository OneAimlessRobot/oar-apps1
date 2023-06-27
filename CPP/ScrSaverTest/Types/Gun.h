
#ifndef GUN_H
#define GUN_H
class Gun: public Entity{

private:

float barrelLen,force,reloadTime,x,y;
int capacity,currAmmo;
GVector* shootVec;
public:

Gun(SDL_Color clr,float x, float y, float w, float h,float e,float m,float Car,float force,float barrelLen,int capacity,float reloatTime);
Gun(Entity* ent,float force,float barrelLen,int capacity,float reloatTime);
void reload();
int isEmpty();
float getReloadTime();
void shoot();
float getShootingForce();
void setShootVec(SDL_FPoint newVec);
SDL_FPoint getShootVec();
static Gun* randGun(float width, float height,float maxMass,float maxSize,float maxSpeed,int capacity,float force);
SDL_FPoint getPos();
~Gun();



};
#endif
