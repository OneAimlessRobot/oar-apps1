#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Includes/entity.hpp"
#include "../Includes/projectile.hpp"
    Projectile::Projectile(float xinit, float yinit, float size, float speed)
    {
	
    	projectile = (SDL_FRect *)malloc(sizeof(SDL_FRect));
    	target = (SDL_FPoint *)malloc(sizeof(SDL_FPoint));

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

    void Projectile::Projectile::updateMovingProjectile()
    {
        projectile->x += this->speed * cos(atan2(target->y - projectile->y, target->x - projectile->x));
        projectile->y += this->speed * sin(atan2(target->y - projectile->y, target->x - projectile->x));
    }

    void Projectile::Projectile::drawProjectile(SDL_Renderer *someRend)
    {
        if (this->isMoving())
        {
            SDL_SetRenderDrawColor(someRend, r, g, b, 255);
            SDL_RenderFillRectF(someRend, projectile);
        }
    }
    void Projectile::updatePosition(float NewXOrigin, float NewYOrigin)
    {

        projectile->x = NewXOrigin;
        projectile->y = NewYOrigin;
    }

    float Projectile::getXpos()
    {
        return projectile->x;
    }
    void Projectile::setRenderable()
    {

        this->hasBeenShot = 1;
    }
    float Projectile::getYpos()
    {
        return projectile->y;
    }

    void Projectile::setTarget(float xEnd, float yEnd)
    {

        this->target->x = xEnd;
        this->target->y = yEnd;
    }
    SDL_FPoint *Projectile::getTarget()
    {
        return this->target;
    }
    void Projectile::speedUp(float increment)
    {
        this->speed += increment;
    }
    void Projectile::setSpeed(float newSpeed)
    {
        this->speed = newSpeed;
    }
    void Projectile::setSize(float newSize)
    {
        this->projectile->h = newSize;
        this->projectile->w = newSize;
    }
    void Projectile::projCopy(Projectile *src, Projectile *dest)
    {

        dest->updatePosition(src->getXpos(), src->getYpos());
        dest->setTarget(src->getTarget()->x, src->getTarget()->y);
        dest->setSpeed(src->getSpeed());
        dest->setSize(src->getSize());
    }
    float Projectile::getSize()
    {
        return this->projectile->h;
    }
    void Projectile::speedDown(float increment)
    {
        if (this->speed > 0)
        {
            this->speed -= increment;
        }
    }
    float Projectile::getSpeed()
    {
        return this->speed;
    }

    SDL_FRect *Projectile::getProjShell()
    {
        return this->projectile;
    }

    void Projectile::giveProjectileAPurposeInLife(float xEnd, float yEnd)
    {

        this->setRenderable();

        this->setTarget(xEnd, yEnd);
    }
    int Projectile::isMoving()
    {
        return this->hasBeenShot;
    }

    void Projectile::hideProjectile()
    {

        this->hasBeenShot = 0;
        /*Fazer isto vai fazer com que na Main o jogo tente aceder ao corpo do projetil que, esta inexistente porque isto executado nos projeteis inicializados na classe gun.
        free(projectile);*/
    }

    SDL_bool Projectile::detectProjectileCollision(SDL_FRect *box)
    {

        return SDL_HasIntersectionF(this->getProjShell(), box);
    }
    void Projectile::destroyProjectile()
    {
        free(projectile);
    }
