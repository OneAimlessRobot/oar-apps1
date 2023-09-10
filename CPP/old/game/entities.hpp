

#pragma once

class Entity
{

    

public:
    Entity() {}
    static int randNumBetZeroAnd(int lim)
    {

        return round(((random() / ((double)RAND_MAX + 1)) * lim));
    }

    static void drawCrossHair(SDL_Renderer *rend, int size, int x, int y)
    {

        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);

        SDL_RenderDrawLine(rend, x - size, y, x + size, y);

        SDL_RenderDrawLine(rend, x, y - size, x, y + size);
        SDL_RenderPresent(rend);
    }
    static void drawCrossHairF(SDL_Renderer *rend, float size, float x, float y)
    {

        SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);

        SDL_RenderDrawLineF(rend, x - size, y, x + size, y);

        SDL_RenderDrawLineF(rend, x, y - size, x, y + size);
        SDL_RenderPresent(rend);
    }
    static void drawLaser(SDL_Renderer *rend, int xOrigin, int yOrigin, int xEnd, int yEnd)
    {

        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);

        SDL_RenderDrawLine(rend, xOrigin, yOrigin, 10000 * cos(atan2((yEnd)-yOrigin, (xEnd)-xOrigin)), 10000 * sin(atan2((yEnd)-yOrigin, (xEnd)-xOrigin)));
        SDL_RenderPresent(rend);
    }
    static double distBetPoints(SDL_Point *src, SDL_Point *dest)
    {

        return SDL_fabs(SDL_sqrt(((src->x) - (dest->x)) * ((src->x) - (dest->x)) + ((src->y) - (dest->y)) * ((src->y) - (dest->y))));
    }
};
class TestObject
{

    SDL_Rect *obj;

public:
    TestObject(int x, int y, int size)
    {

        this->obj->x = x;
        this->obj->y = y;
        this->obj->h = size = this->obj->w;
    }

    void renderIteration(SDL_Renderer *rend)
    {

        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        SDL_RenderFillRect(rend, this->obj);

        SDL_RenderPresent(rend);
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
    }
};

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

class ProjectileIterator
{

private:
    Projectile **internalArray;
    int nextSlot, capacity;

public:
    ProjectileIterator(Projectile **array, int capacity)
    {

        this->internalArray = array;
        this->capacity = capacity;
        nextSlot = 0;
    }

    Projectile *next()
    {

        Projectile *p = NULL;

        if (this->hasNext())
        {

            p = this->internalArray[nextSlot++];
        }
        return p;
    }

    int hasNext()
    {

        return this->nextSlot < this->capacity;
    }
};

class VolleyGenerator : public Entity
{
private:
    Projectile **idleProjectiles, **activeVolley;
    int maxAmmount, projectSpeed, volleySourceX, volleySourceY, caliber, remaining, currentSlot;

public:
    VolleyGenerator(int volleySourceX, int volleySourceY, int projectSpeed, int caliber, int maxAmmount)
    {

        this->maxAmmount = maxAmmount;
        this->projectSpeed = projectSpeed;
        this->volleySourceX = volleySourceX;
        this->volleySourceX = volleySourceY;
        this->caliber = caliber;
        this->remaining = this->maxAmmount;
        this->currentSlot = 0;

        this->idleProjectiles = (Projectile **)malloc(sizeof(Projectile *) * this->maxAmmount);
        this->activeVolley = (Projectile **)malloc(sizeof(Projectile *) * this->maxAmmount);

        for (int i = 0; i < this->maxAmmount; i++)
        {

            idleProjectiles[i] = new Projectile(volleySourceX, volleySourceY, projectSpeed, caliber);
            idleProjectiles[i]->hideProjectile();
        }

        for (int i = 0; i < this->maxAmmount; i++)
        {

            activeVolley[i] = new Projectile(0, 0, 0, 1);
        }
    }

    void addProjectileToVolley(int targetX, int targetY)
    {

        Projectile::projCopy(idleProjectiles[currentSlot], activeVolley[currentSlot]);

        activeVolley[currentSlot]->giveProjectileAPurposeInLife(targetX, targetY);
        remaining--;
        currentSlot++;
    }

    void regen()
    {

        for (int i = 0; i < this->maxAmmount; i++)
        {
            delete (idleProjectiles[i]);
        }
        for (int i = 0; i < this->maxAmmount; i++)
        {

            idleProjectiles[i] = new Projectile(volleySourceX, volleySourceY, projectSpeed, caliber);
            idleProjectiles[i]->hideProjectile();
        }
        this->initializeIdleProjectileArray(activeVolley, this->maxAmmount);

        this->currentSlot = 0;
        this->remaining = this->maxAmmount;
    }

    bool isEmpty()
    {
        return this->remaining == 0;
    }

    void updateLaunchPositions(int newX, int newY)
    {

        for (int i = 0; i < remaining; i++)
        {

            idleProjectiles[i]->updatePosition(newX, newY);
        }
    }
    void initializeIdleProjectileArray(Projectile **array, int size)
    {

        for (int i = 0; i < size; i++)
        {

            delete (array[i]);
        }

        for (int i = 0; i < size; i++)
        {

            array[i] = new Projectile(0, 0, 0, 1);
        }
    }

    void checkProjectileCollisions(SDL_Rect *box)
    {

        for (int i = 0; i < currentSlot; i++)
        {

            int j = activeVolley[i]->detectProjectileCollision(box);
            if (j)
            {
                activeVolley[i]->destroyProjectile();
            }
        }
    }

    ProjectileIterator *projectileTracker()
    {

        return new ProjectileIterator(activeVolley, currentSlot);
    }

    ProjectileIterator *idleAmmoIterator()
    {

        return new ProjectileIterator(idleProjectiles, remaining);
    }

    void destroyVolley()
    {

        for (int i = 0; i < maxAmmount; i++)
        {

            delete (idleProjectiles[i]);
        }
        free(idleProjectiles);
        for (int i = 0; i < maxAmmount; i++)
        {
            delete (activeVolley[i]);
        }
        free(activeVolley);
    }
};

/*


void printAmmo(){

    for(int i=0;i<maxAmmount;i++){

        cout<<"Posiçao, velocidade da bala "<<i<<":"<<endl;
        cout<<"Posiçao :"<<ammo[i]->getXpos()<<" "<<ammo[i]->getYpos()<<endl;
        cout<<"velocidade :"<<ammo[i]->getSpeed()<<endl;
        cout<<"tamanho :"<<ammo[i]->getSize()<<endl;
    }
}

}*/

class Player : public Entity
{
private:
    SDL_Rect *body = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    int size;

public:
    Player(int xInit, int yInit, int size)
    {

        this->body->x = xInit;
        this->body->y = yInit;
        this->size = size;
        this->body->w = this->size;
        this->body->h = this->size;
    }

    void movePlayerX(int dist)
    {

        this->body->x += dist;
    }
    void movePlayerY(int dist)
    {

        this->body->y += dist;
    }

    void growPlayer(int increment)
    {

        body->h += increment;
        body->w += increment;
    }

    void shrinkPlayer(int increment)
    {

        if (body->w != 0)
        {
            body->h -= increment;
            body->w -= increment;
        }
    }
    int getSize()
    {
        return body->h;
    }
    int getPlayerX()
    {

        return this->body->x;
    }
    int getPlayerY()
    {

        return this->body->y;
    }

    SDL_Rect *keepPlayerVisible(SDL_Renderer *someRend, int *mousex, int *mousey)
    {

        SDL_SetRenderDrawColor(someRend, 100, 100, 100, 255);

        SDL_RenderFillRect(someRend, body);

        SDL_GetMouseState(mousex, mousey);

        drawCrossHair(someRend, 4, *mousex, *mousey);
        return body;
    }

    void destroyPlayer()
    {
        free(body);
    }
};