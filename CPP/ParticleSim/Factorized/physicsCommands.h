#ifndef PHYSICSCOMMANDS_H
#define PHYSICSCOMMANDS_H

constexpr int selectFrameInt= 180;
constexpr int addMoreInt= 60;
constexpr int howManyToAdd= 5;
constexpr int homingSpeed= 5;

namespace PhysicsCommands{
void handleCollisions(int collisionsEnabled,std::list<Entity*>& entList,std::list<Gun*>& gunList,std::list<Grenade*>& grenadeList,Collider*arena);
template <typename T>
void handleInterparticleCollisions(std::list<T*>& ents);
template <typename T>
void handleInterparticleGravity(std::list<T*>& ents);
template <typename T>
void deleteFreaks(std::list<T*>& ents);
template <typename T>
void handleGroundGravity(std::list<T*>& ents,Entity* worldParticle);
template <typename T>
void handleCollisionsWithArena(std::list<T*>& ents,Collider*arena);
void handleForces(int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,std::list<Grenade*>& grenadeList,Collider* arena,Entity*worldParticle);

void handleMovements(int collisionsEnabled,int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,Collider* arena,std::list<Gun*>& gunList,std::list<Grenade*>& grenadeList,Entity* worldMassParticle);
template <typename T>
void homming(std::list<T*>& entList,float x, float y);
template <typename T>
void doBlast(std::list<T*>& entList,float x, float y);
template <typename T>
void orbit(std::list<T*>& entList,float x, float y);
template <typename T>
void handleDrag(std::list<T*>& entList,Collider* arena);
template <typename T>
float getAverageSpeed(std::list<T*>& entList);
template <typename T>
float getAverageQuality(std::list<T*>& entList);
template <typename T>
float getTotalEnergy(std::list<T*>& entList);


}
#include "physicsCommands.tpp"
#endif
