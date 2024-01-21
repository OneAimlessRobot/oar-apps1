#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Includes/entity.hpp"
#include "../Includes/projectile.hpp"
#include "../Includes/projIterator.hpp"
#include "../Includes/volleyGen.hpp"


    VolleyGenerator::VolleyGenerator(float volleySourceX, float volleySourceY, float projectSpeed, float caliber, int maxAmmount)
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

    void VolleyGenerator::addProjectileToVolley(float targetX, float targetY)
    {

        Projectile::projCopy(idleProjectiles[currentSlot], activeVolley[currentSlot]);

        activeVolley[currentSlot]->giveProjectileAPurposeInLife(targetX, targetY);
        remaining--;
        currentSlot++;
    }

    void VolleyGenerator::regen()
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

    bool VolleyGenerator::isEmpty()
    {
        return this->remaining == 0;
    }

    void VolleyGenerator::updateLaunchPositions(float newX, float newY)
    {

        for (int i = 0; i < remaining; i++)
        {

            idleProjectiles[i]->updatePosition(newX, newY);
        }
    }
    void VolleyGenerator::initializeIdleProjectileArray(Projectile **array, int size)
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

    void VolleyGenerator::checkProjectileCollisions(SDL_FRect *box)
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

    ProjectileIterator *VolleyGenerator::projectileTracker()
    {

        return new ProjectileIterator(activeVolley, currentSlot);
    }

    ProjectileIterator *VolleyGenerator::idleAmmoIterator()
    {

        return new ProjectileIterator(idleProjectiles, remaining);
    }

    void VolleyGenerator::destroyVolley()
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
