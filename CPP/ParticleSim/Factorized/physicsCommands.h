#ifndef PHYSICSCOMMANDS_H
#define PHYSICSCOMMANDS_H

constexpr int selectFrameInt= 180;
constexpr int addMoreInt= 60;
constexpr int howManyToAdd= 5;
constexpr int homingSpeed= 5;

namespace PhysicsCommands{
void handleCollisions(int collisionsEnabled,std::list<Entity*>& entList,std::list<Gun*>& gunList,Collider*arena);
template <typename T>
void handleInterparticleCollisions(std::list<T*>& ents);
template <typename T>
void handleInterparticleGravity(std::list<T*>& ents);
template <typename T>
void deleteFreaks(std::list<T*>& ents);
template <typename T>
void handleCollisionsWithArena(std::list<T*>& ents,Collider*arena);

void handleMovements(int collisionsEnabled,int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,Collider* arena,std::list<Gun*>& gunList);

void homming(std::list<Entity*>& entList,float x, float y);
void handleForces(int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,Collider* arena);
void doBlast(std::list<Entity*>& entList,float x, float y);
void orbit(std::list<Entity*>& entList,float x, float y);
void handleDrag(std::list<Entity*>& entList,Collider* arena);
float getAverageSpeed(std::list<Entity*>& entList);
float getAverageQuality(std::list<Entity*>& entList);
float getTotalEnergy(std::list<Entity*>& entList);


}
#include "../Systems/physicsCommands.tpp"
#endif
