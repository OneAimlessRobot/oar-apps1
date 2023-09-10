
class Projectile : public Entity
{

private:
    SDL_Rect *projectile = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    SDL_FPoint *target = (SDL_FPoint *)malloc(sizeof(SDL_FPoint));
    int speed, r, g, b;
    bool hasBeenShot;

public:
    Projectile(int xinit, int yinit, int size, int speed)
    {
        r = randNumBetZeroAnd(255);
        g = randNumBetZeroAnd(255);
        b = randNumBetZeroAnd(255);

        projectile->x = xinit;
        projectile->y = yinit;
        projectile->h = size;
        projectile->w = size;
        this->speed = speed;
        this->hasBeenShot = 1;
    }

    void updateMovingProjectile()
    {
        projectile->x += round(this->speed * cos(atan2(target->y - projectile->y, target->x - projectile->x)));
        projectile->y += round(this->speed * sin(atan2(target->y - projectile->y, target->x - projectile->x)));
    }

    void drawProjectile(SDL_Renderer *someRend)
    {
        if (this->isMoving())
        {
            SDL_SetRenderDrawColor(someRend, r, g, b, 255);
            SDL_RenderFillRect(someRend, projectile);
        }
    }
    void updatePosition(int NewXOrigin, int NewYOrigin)
    {

        projectile->x = NewXOrigin;
        projectile->y = NewYOrigin;
    }

    int getXpos()
    {
        return projectile->x;
    }
    void setRenderable()
    {

        this->hasBeenShot = 1;
    }
    int getYpos()
    {
        return projectile->y;
    }

    void setTarget(int xEnd, int yEnd)
    {

        this->target->x = xEnd;
        this->target->y = yEnd;
    }
    SDL_FPoint *getTarget()
    {
        return this->target;
    }
    void speedUp(int increment)
    {
        this->speed += increment;
    }
    void setSpeed(int newSpeed)
    {
        this->speed = newSpeed;
    }
    void setSize(int newSize)
    {
        this->projectile->h = newSize;
        this->projectile->w = newSize;
    }
    static void projCopy(Projectile *src, Projectile *dest)
    {

        dest->updatePosition(src->getXpos(), src->getYpos());
        dest->setTarget(src->getTarget()->x, src->getTarget()->y);
        dest->setSpeed(src->getSpeed());
        dest->setSize(src->getSize());
    }
    int getSize()
    {
        return this->projectile->h;
    }
    void speedDown(int increment)
    {
        if (this->speed > 0)
        {
            this->speed -= increment;
        }
    }
    int getSpeed()
    {
        return this->speed;
    }

    SDL_Rect *getProjShell()
    {
        return this->projectile;
    }

    void giveProjectileAPurposeInLife(int xEnd, int yEnd)
    {

        this->setRenderable();

        this->setTarget(xEnd, yEnd);
    }
    int isMoving()
    {
        return this->hasBeenShot;
    }

    void hideProjectile()
    {

        this->hasBeenShot = 0;
        /*Fazer isto vai fazer com que na Main o jogo tente aceder ao corpo do projetil que, esta inexistente porque isto executado nos projeteis inicializados na classe gun.
        free(projectile);*/
    }

    SDL_bool detectProjectileCollision(SDL_Rect *box)
    {

        return SDL_HasIntersection(this->getProjShell(), box);
    }
    void destroyProjectile()
    {
        free(projectile);
    }
};
