#include <list>
#include <utility>
#include <set>
#include <vector>
#include <iostream>
#include <iterator>
#include <SDL2/SDL.h>
#include "../Includes/auxFuncs.h"
#include "../Includes/GVector.h"
#include "../Includes/Bullet.h"
#include "../Includes/Entity.h"
#include "../Includes/Gun.h"
#include "../Includes/Collider.h"
#include "../Includes/physicsAux.h"
#include "../Includes/Grenade.h"
#include "../Includes/Missile.h"
#include "../Includes/physicsConstants.h"
#include "../Includes/physicsCommands.h"



void PhysicsCommands::handleCollisions(int collisionsEnabled,std::list<Entity*>& entList,std::list<Grenade*>& grenadeList,std::list<Missile*>& missileList,Collider* arena){

    //broken. Maybe will fix
    if(collisionsEnabled){
    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
      handleInterparticleCollisions<Entity>(entList);
      handleInterparticleCollisions<Grenade>(grenadeList);
      handleInterparticleCollisions<Missile>(missileList);
    }

    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
    deleteFreaks<Missile>(missileList);
     handleCollisionsWithArena<Entity>(entList,arena);
    handleCollisionsWithArena<Grenade>(grenadeList,arena);
    handleCollisionsWithArena<Missile>(missileList,arena);

}
void PhysicsCommands::handleForces(int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,std::list<Grenade*>& grenadeList,std::list<Missile*>& missileList,Collider* arena,Entity*worldParticle,int electricity){
	
    if(gravityEnabled){
    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
    deleteFreaks<Missile>(missileList);
      handleInterparticleGravity<Entity>(entList);
      handleInterparticleGravity<Grenade>(grenadeList);
      handleInterparticleGravity<Missile>(missileList);



    }
    if(dragEnabled){
    deleteFreaks<Entity>(entList);

    handleDrag<Entity>(entList, arena);
    deleteFreaks<Grenade>(grenadeList);
    handleDrag<Grenade>(grenadeList, arena);

    deleteFreaks<Missile>(missileList);
    handleDrag<Missile>(missileList, arena);
    }
    if(gravityEnabled){
    deleteFreaks<Entity>(entList);

    handleGroundGravity<Entity>(entList,worldParticle);

    deleteFreaks<Grenade>(grenadeList);
    handleGroundGravity<Grenade>(grenadeList,worldParticle);
    deleteFreaks<Missile>(missileList);
    handleGroundGravity<Missile>(missileList,worldParticle);

    }
    if(electricity){
    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
    deleteFreaks<Missile>(missileList);
      handleInterparticleElectricity<Entity>(entList);
      handleInterparticleElectricity<Grenade>(grenadeList);
      handleInterparticleElectricity<Missile>(missileList);

    }

}
void PhysicsCommands::handleMovements(int collisionsEnabled,int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,Collider* arena,std::list<Grenade*>& grenadeList,std::list<Missile*>& missileList,Entity* worldMassParticle,int electricity){

    handleForces(gravityEnabled,dragEnabled,entList,grenadeList,missileList,arena,worldMassParticle,electricity);

    handleCollisions(collisionsEnabled,entList,grenadeList,missileList,arena);



}
