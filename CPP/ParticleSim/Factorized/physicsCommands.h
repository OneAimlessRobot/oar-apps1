#ifndef PHYSICSCOMMANDS_H
#define PHYSICSCOMMANDS_H

namespace PhysicsCommands{

template <typename T>
void handleInterparticleCollisions(std::list<T*> ents);
template <typename T>
void handleCollisionsWithArena(std::list<T*> ents);

void handleMovements(int collisionsEnabled,std::list<Entity*> entList,Collider* arena,std::list<Gun*> gunList);

void homming(std::list<Entity*> entList,float x, float y);
void handleForces(std::list<Entity*> entList,Collider* arena);
void doBlast(std::list<Entity*> entList,float x, float y);
void orbit(std::list<Entity*> entList,float x, float y);
void handleDrag(std::list<Entity*> entList,Collider* arena);
float getAverageSpeed(std::list<Entity*> entList);
float getAverageQuality(std::list<Entity*> entList);
float getTotalEnergy(std::list<Entity*> entList);


}
#include "physicsCommands.tpp"
#endif
