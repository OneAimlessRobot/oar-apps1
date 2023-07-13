#ifndef GRENADE_H
#define GRENADE_H
class Grenade:public Entity{
private:

float chargeForce;
int timer,currTime,active,explosionDuration,explosionHappening;
void deactivate();
public:

Grenade(float x,float y,float chargeForce,int explosionDuration,int timer);

float getChargeForce();

static Grenade* defaultGrenade();

void update();
int blowingUp();
int isActive();
~Grenade();


};


#endif
