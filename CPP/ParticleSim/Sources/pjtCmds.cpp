#include <thread>
#include <list>
#include <fstream>
#include <vector>
#include "../Includes/resourcePaths.h"
#include "../Includes/allSettings.h"
#include <SDL2/SDL.h>
#include <random>
#include <cmath>
#include <iostream>
#include "../Includes/auxFuncs.h"
#include "../Includes/Collider.h"
#include "../Includes/GVector.h"
#include "../Includes/Bullet.h"
#include "../Includes/Entity.h"
#include "../Includes/Gun.h"
#include "../Includes/Grenade.h"
#include "../Includes/GLauncher.h"
#include "../Includes/physicsAux.h"
#include "../Includes/physicsCommands.h"
#include "../Includes/EntityMgmnt.h"
#include "../Includes/pjtCmds.h"




void projCommands::attentionEveryone(std::list<Entity*> &entList,Collider* arena){
std::list<Entity*>::iterator it;

        for (it = entList.begin(); it != entList.end();) {
                Entity * next= (*it);
        if(!arena->bodyIsInside(next->getBody())){
    std::cout<<"ERRO!!!!!\n";
    delete (*it);
    it=entList.erase(it);
    }
    else{
    ++it;

    }
}


}
void projCommands::freezeEveryone(std::list<Entity*> &entList){
std::list<Entity*>::iterator it;

        for (it = entList.begin(); it != entList.end();++it) {
                Entity * next= (*it);
                next->setVec((SDL_FPoint){0.0f,0.0f});

    }
}


void projCommands::teleportEntityList(std::list<Entity*> &entList,float x, float y){
std::list<Entity*>::iterator it;

        for (it = entList.begin(); it != entList.end(); it++) {
                Entity * next= (*it);
                next->setPos((SDL_FPoint){x,y});

        }

}
void projCommands::cleanGrenades(std::list<Grenade*> &grenadeList){

    std::list<Grenade*>::iterator it;
    for (it = grenadeList.begin(); it != grenadeList.end();) {
        if(!(*it)->isActive()){
    delete (*it);
    it=grenadeList.erase(it);
    }
    else{
    ++it;

    }



}
}

void projCommands::monitorGrenades(std::list<Grenade*> &grenadeList,std::list<Entity*> &entList){
	std::list<Grenade*>::iterator it2;
	for(it2= grenadeList.begin();it2!= grenadeList.end();++it2){

		if((*it2)->blowingUp()){

			PhysicsCommands::doBlast<Entity>(entList,(*it2)->getCenter().x,(*it2)->getCenter().y,(*it2)->getForce());
		}
		(*it2)->update();
	}


}
