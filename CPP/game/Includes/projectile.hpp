#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

class Projectile : public Entity
{

private:
    SDL_FRect *projectile;
    SDL_FPoint *target;
    float speed;
    unsigned char r, g, b;
    bool hasBeenShot;

public:
    Projectile(float xinit, float yinit, float size, float speed);
    void updateMovingProjectile();
    void drawProjectile(SDL_Renderer *someRend);
    void updatePosition(float NewXOrigin, float NewYOrigin);
    float getXpos();
    void setRenderable();
    float getYpos();
    void setTarget(float xEnd, float yEnd);
    SDL_FPoint *getTarget();
    void speedUp(float increment);
    void setSpeed(float newSpeed);
    void setSize(float newSize);
    static void projCopy(Projectile *src, Projectile *dest);
    float getSize();
    void speedDown(float increment);
    float getSpeed();
    SDL_FRect *getProjShell();
    void giveProjectileAPurposeInLife(float xEnd, float yEnd);
    int isMoving();
    void hideProjectile();
    SDL_bool detectProjectileCollision(SDL_FRect *box);
    void destroyProjectile();
};
#endif
