#ifndef VOLLEYGEN_HPP
#define VOLLEYGEN_HPP




class VolleyGenerator : public Entity
{
private:
    Projectile **idleProjectiles, **activeVolley;
    int maxAmmount, projectSpeed, volleySourceX, volleySourceY, caliber, remaining, currentSlot;

public:
    VolleyGenerator(float volleySourceX, float volleySourceY, float projectSpeed, float caliber, int maxAmmount);
    void addProjectileToVolley(float targetX, float targetY);
    void regen();
    bool isEmpty();
    void updateLaunchPositions(float newX, float newY);
    void initializeIdleProjectileArray(Projectile **array, int size);
    void checkProjectileCollisions(SDL_FRect *box);
    ProjectileIterator *projectileTracker();
    ProjectileIterator *idleAmmoIterator();
    void destroyVolley();
};
#endif
