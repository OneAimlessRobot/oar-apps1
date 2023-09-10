
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

