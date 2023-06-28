
#ifndef GUN_H
#define GUN_H
#define RELOAD_TIME_SECS 1.0
#define UPDATE_RATE (1000*RELOAD_TIME_SECS*FRAMERATE)
class Gun: public Entity{

private:

float barrelLen,force,x,y,shootperiod;
int capacity,currAmmo,reloadTime,shootCounter,reloadCounter,existenceTime;
GVector* shootVec;
int ready();
public:

Gun(SDL_Color clr,float x, float y, float w, float h,float e,float m,float Car,float force,float barrelLen,int capacity,int reloatTime);
Gun(Entity* ent,float force,float barrelLen,int capacity,int reloatTime);
void reload();
int isEmpty();
int inCooldown();
void updateGun();
int canShoot();
int getReloadTime();
void shoot();
float getShootingForce();
void setShootVec(SDL_FPoint newVec);
SDL_FPoint getShootVec();
static Gun* randGun(float width, float height,float maxMass,float maxSize,float maxSpeed,int capacity,float force);
SDL_FPoint getPos();
~Gun();



};
#endif
