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
#include "../Includes/gunCommands.h"



void gunCommands::monitorGuns(std::list<Gun*> &gunList,std::list<GLauncher*> &gLauncherList,float xtarget,float ytarget){



     std::list<Gun*>::iterator it;
    for (it = gunList.begin(); it != gunList.end(); ++it) {
    (*it)->setTarget(xtarget,ytarget);
    (*it)->updateGun();
    }

     std::list<GLauncher*>::iterator it2;
    for (it2 = gLauncherList.begin(); it2 != gLauncherList.end(); ++it2) {
    (*it2)->setTarget(xtarget,ytarget);
    (*it2)->updateGLauncher();
    }


}

void gunCommands::shootGuns(std::list<Gun*> &gunList,std::list<GLauncher*> &gLauncherList,std::list<Entity*> &entList,std::list<Grenade*> &grenadeList){
       
 std::list<Gun*>::iterator it;
    for (it = gunList.begin(); it != gunList.end(); ++it) {
    if(((*it)->canShoot())){

        entList.emplace(entList.begin(),(*it)->shoot());
    }
    }
    std::list<GLauncher*>::iterator it2;
    for (it2= gLauncherList.begin(); it2 != gLauncherList.end(); ++it2) {
    if(((*it2)->canShoot())){

        grenadeList.emplace(grenadeList.begin(),(*it2)->shoot());
    }
    }
}

void gunCommands::spawnGun(std::list<Gun*> &gunList,std::string filePath,float x, float y,caliber bType){



    Gun* gun=EntityManagement::parseGun(filePath);
    gun->setPos((SDL_FPoint){x,y});
    gun->setCaliber(bType);
    gunList.emplace(gunList.begin(),gun);
}


void gunCommands::spawnGLauncher(std::list<GLauncher*> &gLauncherList,float x, float y){
    GLauncher*gLauncher=GLauncher::defaultGLauncher();
    gLauncher->setPos((SDL_FPoint){x,y});
    gLauncherList.emplace(gLauncherList.begin(),gLauncher);
}


