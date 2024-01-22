#ifndef PJTCMDS_H
#define PJTCMDS_H
namespace projCommands{

void attentionEveryone(std::list<Entity*> &entList,Collider* arena);
void freezeEveryone(std::list<Entity*> &entList);
void teleportEntityList(std::list<Entity*> &entList,float x, float y);
void cleanGrenades(std::list<Grenade*> &grenadeList);
void monitorGrenades(std::list<Grenade*> &grenadeList,std::list<Entity*> &entList);



}
#endif
