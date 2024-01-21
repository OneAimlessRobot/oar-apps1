#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Includes/entity.hpp"
#include "../Includes/projectile.hpp"
#include "../Includes/projIterator.hpp"

    ProjectileIterator::ProjectileIterator(Projectile **array, int capacity)
    {

        this->internalArray = array;
        this->capacity = capacity;
        nextSlot = 0;
    }

    Projectile *ProjectileIterator::next()
    {

        Projectile *p = NULL;

        if (this->hasNext())
        {

            p = this->internalArray[nextSlot++];
        }
        return p;
    }

    int ProjectileIterator::hasNext()
    {

        return this->nextSlot < this->capacity;
    }
