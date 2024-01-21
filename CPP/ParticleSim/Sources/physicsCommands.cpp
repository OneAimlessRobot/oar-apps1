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
#include "../Includes/physicsConstants.h"
#include "../Includes/physicsCommands.h"



void PhysicsCommands::handleCollisions(int collisionsEnabled,std::list<Entity*>& entList,std::list<Gun*>& gunList,std::list<Grenade*>& grenadeList,Collider* arena){

    //broken. Maybe will fix
    if(collisionsEnabled){
    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
      handleInterparticleCollisions<Entity>(entList);
      handleInterparticleCollisions<Grenade>(grenadeList);
    }

    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
    deleteFreaks<Gun>(gunList);
     handleCollisionsWithArena<Entity>(entList,arena);
    handleCollisionsWithArena<Gun>(gunList,arena);
    handleCollisionsWithArena<Grenade>(grenadeList,arena);

}
void PhysicsCommands::handleForces(int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,std::list<Grenade*>& grenadeList,Collider* arena,Entity*worldParticle,int electricity){
	
    if(gravityEnabled){
    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
      handleInterparticleGravity<Entity>(entList);
      handleInterparticleGravity<Grenade>(grenadeList);



    }
    if(dragEnabled){
    deleteFreaks<Entity>(entList);

    handleDrag<Entity>(entList, arena);
    deleteFreaks<Grenade>(grenadeList);
    handleDrag<Grenade>(grenadeList, arena);

    }
    if(gravityEnabled){
    deleteFreaks<Entity>(entList);

    handleGroundGravity<Entity>(entList,worldParticle);

    deleteFreaks<Grenade>(grenadeList);
    handleGroundGravity<Grenade>(grenadeList,worldParticle);

    }
    if(electricity){
    deleteFreaks<Entity>(entList);
    deleteFreaks<Grenade>(grenadeList);
      handleInterparticleElectricity<Entity>(entList);
      handleInterparticleElectricity<Grenade>(grenadeList);

    }

}
void PhysicsCommands::handleMovements(int collisionsEnabled,int gravityEnabled,int dragEnabled,std::list<Entity*>& entList,Collider* arena,std::list<Gun*>& gunList,std::list<Grenade*>& grenadeList,Entity* worldMassParticle,int electricity){

    handleForces(gravityEnabled,dragEnabled,entList,grenadeList,arena,worldMassParticle,electricity);

    handleCollisions(collisionsEnabled,entList,gunList,grenadeList,arena);



}
