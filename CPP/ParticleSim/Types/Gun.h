
#ifndef GUN_H
#define GUN_H
#define RELOAD_TIME_SECS 1.0
#define UPDATE_RATE (1000*RELOAD_TIME_SECS*FRAMERATE)
class Gun: public Entity{

private:

float barrelLen,force,spreadMaxAngle,recoilFactor;
int capacity,currAmmo,reloadTime,shootCounter,reloadCounter,existenceTime,shootperiod;
caliber bulletType;
GVector* shootVec;
int ready();
public:

Gun(SDL_Color clr,float x, float y, float w, float h,float e,float m,float Car,float force,float recoilFactor,float barrelLen,float spreadIndex,int capacity,int reloadTime,int shootperiod);
void reload();
static Gun* parseGun(std::string filePath);
int isEmpty();
void setCaliber(caliber bType);
int inCooldown();
void updateGun();
int canShoot();
int getReloadTime();
void shoot();
float getBarrelLength();
float getRecoilFactor();
void render(SDL_Renderer* ren);
static void printGunInfo(std::string filePath);
float getShootingForce();
float getTilt();
void setShootVec(SDL_FPoint newVec);
SDL_FPoint getShootVec();
static Gun* randGun(float width, float height,float maxMass,float maxSize,float maxSpeed,int capacity,float force);
static Gun* defaultGun();
SDL_FPoint getPos();
~Gun();



};
#endif
