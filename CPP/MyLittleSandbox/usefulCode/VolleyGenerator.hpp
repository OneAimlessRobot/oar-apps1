
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

