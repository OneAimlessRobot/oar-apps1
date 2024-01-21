#ifndef PROJITERATOR_HPP
#define PROJITERATOR_HPP


class ProjectileIterator
{

private:
    Projectile **internalArray;
    int nextSlot, capacity;

public:
    ProjectileIterator(Projectile **array, int capacity);
    Projectile *next();
    int hasNext();
};
#endif