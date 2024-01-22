#ifndef GUNCOMMS_H
#define GUNCOMMS_H

namespace gunCommands{

void spawnGLauncher(std::list<GLauncher*> &gLauncherList,float x, float y);
void spawnMLauncher(std::list<MLauncher*> &mLauncherList,float x, float y);
void spawnGun(std::list<Gun*> &gunList,std::string filePath,float x, float y,caliber bType);
void shootGuns(std::list<Gun*> &gunList,std::list<GLauncher*> &gLauncherList,std::list<MLauncher*> &mLauncherList,std::list<Entity*> &entList,std::list<Grenade*> &grenadeList,std::list<Missile*> &missileList);
void monitorGuns(std::list<Gun*> &gunList,std::list<GLauncher*> &gLauncherList,std::list<MLauncher*> &mLauncherList,float xtarget,float ytarget);

}


#endif
