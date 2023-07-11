#include <thread>
#include <list>
#include <fstream>
#include <vector>
#include "../resourcePaths.h"
#include "../constantHeaders/allSettings.h"
#include <SDL2/SDL.h>
#include <random>
#include <cmath>
#include <iostream>
#include "../auxFuncs.h"
#include "../Types/Collider.h"
#include "../Types/GVector.h"
#include "../Types/Bullet.h"
#include "../Types/Entity.h"
#include "../Types/Gun.h"
#include "../Types/physicsAux.h"
#include "../Factorized/physicsCommands.h"
#include "../Factorized/EntityMgmnt.h"
#include "InteractiveSim.h"

InteractiveSim::InteractiveSim(float maxSpeed,float maxSize,int ammount,float maxMass){
init(maxSpeed,maxSize,ammount, maxMass);

}

InteractiveSim::InteractiveSim(){
init(DEFAULTENTMAXMASS,DEFAULTENTMAXSIZE,1000,DEFAULTENTMAXSPEED);

}

int InteractiveSim::init(float maxSpeed,float maxSize,int ammount,float maxMass){


std::cout<<"Initializing video\n";


if(!SDL_Init(SDL_INIT_EVERYTHING)){
std::cout<<"Done!\n";
}
else{
std::cerr<<"Error loading video. Exiting...(Code 1)\n";
return 1;
}
std::cout<<"Initializing window\n";

this->win= SDL_CreateWindow("ScrSaver",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);
if(this->win){
std::cout<<"Done!\n";
}
else{
std::cerr<<"Error loading window. Exiting...(Code 2)\n";
return 2;
}

std::cout<<"Initializing renderer\n";


this->ren=SDL_CreateRenderer(this->win,-1,SDL_RENDERER_ACCELERATED);
if(this->ren){
std::cout<<"Done!\n";
}
else{
std::cerr<<"Error loading window. Exiting...(Code 3)\n";
return 3;
}


std::cout<<"Initializing background\n";
this->bgr= SDL_CreateTexture(ren,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,WIDTH,HEIGHT);

if(this->bgr){
std::cout<<"Done!\n";
}
else{
std::cerr<<"Error loading background. Exiting...(Code 4)\n";
return 4;
}
std::cout<<"Initializing entities\n";
this->ents= SDL_CreateTexture(ren,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,WIDTH,HEIGHT);

if(this->ents){
std::cout<<"Done!\n";
}
else{
std::cerr<<"Error loading background. Exiting...(Code 5)\n";
return 5;
}

this->maxSpeed=maxSpeed;
if(std::fabs(this->maxSpeed)==0){
    this->maxSpeed=0.00001;
}

this->entList= {};
this->pause=0;
this->rendering=1;
this->selection=0;
this->collisions=0;
this->drag=0;
this->gravity=0;
this->thetime=0;
this->genCount=0;
this->maxSize=maxSize;
this->ammount=ammount;
this->maxMass=maxMass;
this->airDensity=airDensity;

std::cout<<"Initializing arena\n";

this->arena= EntityManagement::parseCollider(DEFAULT_COLLIDER_PATH);
if(this->arena){
std::cout<<"Done!\n";
}
else{
std::cerr<<"Error loading arena. Exiting...(Code 6)\n";
return 6;
}
std::cout<<"Starting to populate the simulation....\n";
std::thread populatingWorker(&InteractiveSim::populateEntityList,this,ammount);
populatingWorker.detach();

this->worldMassParticle=new Entity(Aux::randColor(),WORLDX,WORLDY,WORLDRADIUS*2,WORLDRADIUS*2,1,WORLDMASS,1);

}

InteractiveSim* InteractiveSim::parseGame(){



std::ifstream entSettingsRead(ENTSETTINGS_PATH);
float maxspeed,maxsize,maxmass,ammount;
    std::string dummy;
    while(dummy.rfind(COMMENTPREFIX, 0) == 0){

    std::getline(entSettingsRead,dummy);

    }

if(!entSettingsRead.is_open()){

std::cout<<"ERRO DE FICHEIRO A CARREGAR JOGO!!!!\n"<<ENTSETTINGS_PATH<<"\n";
return new InteractiveSim();

}
entSettingsRead>>maxspeed>>maxsize>>ammount>>maxmass;
entSettingsRead.close();
return new InteractiveSim(maxspeed,maxsize,ammount,maxmass);







}
InteractiveSim* InteractiveSim::defaultGame(){
return new InteractiveSim();

}
void InteractiveSim::mainLoop(){
SDL_Event e;
SDL_bool quit=SDL_FALSE;
const Uint8* KEYS = SDL_GetKeyboardState(nullptr);

while(!quit){

int startTime= SDL_GetTicks();

    SDL_GetMouseState(&this->mouseX,&this->mouseY);

    while(SDL_PollEvent(&e)){
        if(e.type==SDL_QUIT){

        quit=SDL_TRUE;


        }if (e.type == SDL_KEYDOWN && e.key.repeat == 0) {
            handleToggles(KEYS);
  }


    }
    handleContPresses(KEYS);

    handleEntities();
    if(this->rendering){
    doRendering();
    int endTime= SDL_GetTicks();

if((endTime-startTime)<((1/FRAMERATE)*1000)){

SDL_Delay(((1/FRAMERATE)*1000)-(endTime-startTime));
}


    }

}
}

void InteractiveSim::populateEntityList(int ammount){


for(int i =0;i<ammount;i++){

    this->entList.emplace(this->entList.begin(),Entity::randEnt(WIDTH,HEIGHT,this->maxMass,this->maxSize,this->maxSpeed));
}




}

void InteractiveSim::handleEntities(){

    if(!this->pause){
    PhysicsCommands::handleMovements(this->collisions,this->gravity,this->drag,this->entList,this->arena,this->gunList,this->worldMassParticle);
    monitorGuns();
    if(this->selection){
    generationHandling();
    }
    }


}
void InteractiveSim::makeSelection(){
        float selectQuality=PhysicsCommands::getAverageSpeed(this->entList);
        std::list<Entity*>::iterator it;
            for (it = this->entList.begin(); it != this->entList.end(); ) {

                if(GVector::getNorm((*it)->getVec())<selectQuality){
                    delete (*it);
                    it=this->entList.erase(it);

                }
                else{
                    it++;
                }


}
}
void InteractiveSim::doRendering(){

    SDL_SetRenderDrawColor(this->ren,this->bgrclr.r,this->bgrclr.g,this->bgrclr.b,this->bgrclr.a);
    SDL_SetRenderTarget(ren,bgr);
    SDL_RenderClear(ren);
    SDL_SetRenderTarget(ren,ents);
    SDL_RenderCopy(ren,bgr,NULL,NULL);
    this->arena->fullRender(ren);
    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {
        (*it)->render(this->ren);
    }
    std::list<Gun*>::iterator it2;
    for (it2 = this->gunList.begin(); it2 != this->gunList.end(); ++it2) {
        (*it2)->render(this->ren);
    }
    SDL_SetRenderTarget(ren,NULL);
    SDL_RenderCopy(ren,ents,NULL,NULL);
    SDL_RenderPresent(ren);

}
void InteractiveSim::generationHandling(){

    this->thetime++;
if(this->thetime%addMoreInt==0){
    std::thread addWorker(&InteractiveSim::populateEntityList,this,howManyToAdd);
    addWorker.detach();
    }

    if(this->thetime%selectFrameInt==0){
    makeSelection();
    std::cout<<"Geraçao numero: "<<this->genCount<<"\n";
    this->genCount++;
    }


}
void InteractiveSim::printSpeedsAndPos(){



    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {
       std::cout<<"Posição: (x,y)= ("<<(*it)->getPos().x<<" , "<<(*it)->getPos().y<<")\n";
       std::cout<<"Velocidade: "<<GVector::getNorm((*it)->getVec())<<"\n";
       std::cout<<"Coeficientes: \n";
       std::cout<<"Elasticidade: "<<1-(*it)->getInvElasticity()<<"\n";
       std::cout<<"Massa: "<<(*it)->getMass()<<"\n";
       std::cout<<"Coeficiente de resis. do ar: "<<(*it)->getDragConstant()<<"\n";


}


}
void InteractiveSim::handleContPresses(const Uint8*KEYS){
    if(KEYS[SDL_SCANCODE_LEFT]) {
        std::thread orbitWorker(&PhysicsCommands::orbit,std::ref(this->entList),mouseX*1.0,mouseY*1.0);
        orbitWorker.detach();
    }
    if(KEYS[SDL_SCANCODE_RIGHT]) {

        std::thread hommingWorker(&PhysicsCommands::homming,std::ref(this->entList),this->mouseX*1.0,this->mouseY*1.0);
        hommingWorker.detach();
    }
    if(KEYS[SDL_SCANCODE_M]) {
        std::thread blastingWorker(&PhysicsCommands::doBlast,std::ref(this->entList),this->mouseX*1.0,this->mouseY*1.0);
        blastingWorker.detach();
    }
    if(KEYS[SDL_SCANCODE_DOWN]) {
        std::thread shootingWorker(&InteractiveSim::shootGuns,this);
        shootingWorker.detach();
    }

    if(KEYS[SDL_SCANCODE_ESCAPE]) {
    }
}
void InteractiveSim::destroyGuns(){

    EntityManagement::clearList<Gun>(this->gunList);

}
void InteractiveSim::destroyEntities(){


    EntityManagement::clearList<Entity>(this->entList);


}
void InteractiveSim::monitorGuns(){


     std::list<Gun*>::iterator it;
    for (it = this->gunList.begin(); it != this->gunList.end(); ++it) {
    (*it)->setTarget(this->mouseX*1.0,this->mouseY*1.0);
    (*it)->updateGun();
    }


}
void InteractiveSim::shootGuns(){


     std::list<Gun*>::iterator it;
    for (it = this->gunList.begin(); it != this->gunList.end(); ++it) {
    if(((*it)->canShoot())){

        this->entList.emplace(this->entList.begin(),(*it)->shoot());
    }
    }





}

void InteractiveSim::printSimVarsAndStats(){

    std::cout<<"=============================Variaveis de estado=============================================\n";
    std::cout<<"Quantidade de particulas na simulação: "<<this->entList.size()<<"\n";
    std::cout<<"============================Variaveis de teclado:============================================\n";
    std::cout<<"Gravidade ativa?: "<<this->gravity<<"\n";
    std::cout<<"Atrito do ar ativo?: "<<this->drag<<"\n";
    std::cout<<"Colisões ativas?: "<<this->collisions<<"\n";
    std::cout<<"============================Variaveis de configuraçao por ficheiro:==========================\n";
    std::cout<<"Massa maxima de particula: "<<this->maxMass<<"\n";
    std::cout<<"Velocidade maxima de particula: "<<this->maxSpeed<<"\n";
    std::cout<<"Tamanho maximo de particula: "<<this->maxSize<<"\n";
    std::cout<<"Atrito do ar: "<<arena->getAirDensity()<<"\n";


}

void InteractiveSim::printKeyboardHelp(){


    std::cout<<"=============================Comandos de Spawning=============================================\n";
    std::cout<<"Arma: G\n";
    std::cout<<"Particula: S\n";
    std::cout<<"Disparar armas disponiveis: DOWNARROW\n";
    std::cout<<"Apagar objetos: D\n";
    std::cout<<"============================Comandos de efeitos:============================================\n";
    std::cout<<"Toggle Gravity: E\n";
    std::cout<<"Make explosion around mouse: M\n";
    std::cout<<"Toggle collisions: C\n";
    std::cout<<"Toggle gravity around mouse: LEFTARROW\n";
    std::cout<<"Puxar particulas: RIGHTARROW\n";
    std::cout<<"Toggle pause: P\n";
    std::cout<<"Toggle selection mode: N\n";
    std::cout<<"Toggle rendering: R\n";
    std::cout<<"============================Comandos de feedback:============================================\n";
    std::cout<<"Mostrar energia total: J\n";
    std::cout<<"Mostrar estado de todas as particulas: UPARROW\n";
    std::cout<<"Mostrar ajuda: H\n";
    std::cout<<"Mostrar estado da simulaçao: T\n";
    std::cout<<"Informaçoes do ambiente: F\n";



}
void InteractiveSim::spawnGun(Gun* gun,std::string filePath,float x, float y,caliber bType){

    delete gun;
    gun=EntityManagement::parseGun(filePath);
    gun->setPos((SDL_FPoint){x,y});
    gun->setCaliber(bType);
    this->gunList.emplace(this->gunList.begin(),gun);
}
void InteractiveSim::handleToggles(const Uint8*KEYS){

    if(KEYS[SDL_SCANCODE_UP]) {
        std::thread printing(&InteractiveSim::printSpeedsAndPos,this);
        printing.detach();
    }
    if(KEYS[SDL_SCANCODE_P]) {
    if(this->pause){
        this->pause=SDL_FALSE;
    }
    else{
        this->pause=SDL_TRUE;
    }
    }
    if(KEYS[SDL_SCANCODE_J]) {
        PhysicsCommands::getTotalEnergy(this->entList);
//        std::thread showEnergy(&InteractiveSim::getTotalEnergy,this);
//        showEnergy.detach();
    }
    if(KEYS[SDL_SCANCODE_S]) {
    Entity* ent=Entity::randEnt(WIDTH,HEIGHT,maxMass,maxSize,maxSpeed);
    ent->setPos((SDL_FPoint){this->mouseX*1.0,this->mouseY*1.0});
    this->entList.emplace(this->entList.begin(),ent);
    }
    if(KEYS[SDL_SCANCODE_R]) {
    if(this->rendering){
        this->rendering=SDL_FALSE;
    }
    else{
        this->rendering=SDL_TRUE;
    }
    }

    if(KEYS[SDL_SCANCODE_A]) {
    if(this->drag){
        this->drag=SDL_FALSE;
    }
    else{
        this->drag=SDL_TRUE;
    }
    }

    if(KEYS[SDL_SCANCODE_E]) {
    if(this->gravity){
        this->gravity=SDL_FALSE;
    }
    else{
        this->gravity=SDL_TRUE;
    }
    }
    if(KEYS[SDL_SCANCODE_C]) {
    if(this->collisions){
        this->collisions=SDL_FALSE;
    }
    else{
        this->collisions=SDL_TRUE;
    }
    }
    if(KEYS[SDL_SCANCODE_N]) {
    if(this->selection){
        this->selection=SDL_FALSE;
    }
    else{
        this->selection=SDL_TRUE;
    }
    }
    if(KEYS[SDL_SCANCODE_G]) {
        Gun* gun=Gun::defaultGun();
        std::thread newGun(&InteractiveSim::processGunChoice,this,gun,this->mouseX*1.0,this->mouseY*1.0);
        newGun.detach();

    }

    if(KEYS[SDL_SCANCODE_T]) {
        std::thread statsWorker(&InteractiveSim::printSimVarsAndStats,this);
        statsWorker.detach();

    }

    if(KEYS[SDL_SCANCODE_H]) {
        std::thread helpMenuWorker(&InteractiveSim::printKeyboardHelp,this);
        helpMenuWorker.detach();

    }

    if(KEYS[SDL_SCANCODE_D]) {

        processDeletion();

    }

    if(KEYS[SDL_SCANCODE_F]) {

        std::thread arenaInfo(&EntityManagement::printColliderInfo,DEFAULT_COLLIDER_PATH);
        arenaInfo.detach();

    }
}

void InteractiveSim::processBulletChoice(caliber* bType){

std::string choice;
int whatToDo;
do{
std::cout<<"0- Para escolher um calibre\n";
std::cout<<"1- Para ver informaçoes de um calibre\n";

std::cin>>whatToDo;
std::cout<<"Que calibre queres?\n";

    Resources::printMenu(Resources::generateBulletMenu());
    std::cin>>choice;
        std::string path=CALIBERS_PATH+choice;
if(!whatToDo){
            *bType=EntityManagement::parseCaliber(path);
    std::cout<<bType->size<<" , "<<bType->mass<<",  "<<bType->e<<" , "<<bType->Car<<" \n";
        }
        else{
            EntityManagement::printCaliberInfo(path);
        }
    }while(whatToDo);
}
void InteractiveSim::processDeletion(){
int choice;
std::cout<<"Queres apagar...\n";
Resources::printMenu(Resources::generateDeleteMenu());
std::cin>>choice;
switch (choice){
    case 0:{
        destroyEntities();
        destroyGuns();

    break;
    }
    case 1:{


        destroyGuns();


    break;
    }
    case 2:{


        destroyEntities();


    break;
    }



}




}
void InteractiveSim::processGunChoice(Gun * gun,float x,float y){

    std::string choice;
    int whatToDo;
    do{
std::cout<<"0- Spawnar uma arma\n";
std::cout<<"1- Ve informacoes de uma arma\n";

    std::cin>>whatToDo;
    Resources::printMenu(Resources::generateGunMenu());
    std::cin>>choice;
    std::string path= GUNSPATH+choice+GUNSUFFIX;

        if(!whatToDo){
                caliber chosenCaliber;
                processBulletChoice(&chosenCaliber);
                spawnGun(gun,path,x,y,chosenCaliber);
                }
                else{
                EntityManagement::printGunInfo(path);
                }

   }while(whatToDo);



}
InteractiveSim::~InteractiveSim(){

    this->destroyEntities();
    this->destroyGuns();
    delete this->worldMassParticle;
    delete this->arena;
SDL_DestroyTexture(this->bgr);
SDL_DestroyTexture(this->ents);
SDL_DestroyRenderer(this->ren);
SDL_DestroyWindow(this->win);

SDL_Quit();
}

