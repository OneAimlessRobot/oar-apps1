#include <thread>
#include <list>
#include <vector>
#include "../resourcePaths.h"
#include <SDL2/SDL.h>
#include <random>
#include <cmath>
#include "../aux.h"
#include "../Types/Collider.h"
#include "../Types/GVector.h"
#include "../Types/Entity.h"
#include "../Types/Gun.h"
#include "../Types/physicsAux.h"
#include <iostream>
#include "Interactive.h"

Interactive::Interactive(float maxSpeed,float maxSize,int ammount,float maxMass,float airDensity){
init(maxSpeed,maxSize,ammount, maxMass, airDensity);

}

void Interactive::init(float maxSpeed,float maxSize,int ammount,float maxMass,float airDensity){


std::cout<<"Initializing video\n";
SDL_Init(SDL_INIT_EVERYTHING);


std::cout<<"Done!\n";

std::cout<<"Initializing window\n";
this->win= SDL_CreateWindow("ScrSaver",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE);

std::cout<<"Done!\n";

std::cout<<"Initializing renderer\n";
this->ren=SDL_CreateRenderer(this->win,-1,SDL_RENDERER_ACCELERATED);

std::cout<<"Done!\n";
std::cout<<"Initializing background\n";
this->bgr= SDL_CreateTexture(ren,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,WIDTH,HEIGHT);

std::cout<<"Done!\n";
std::cout<<"Initializing entities\n";
this->ents= SDL_CreateTexture(ren,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,WIDTH,HEIGHT);


std::cout<<"Done!\n";
this->bgrclr=(SDL_Color){255,255,255,255};
this->arena= new Collider(SDL_FALSE,bgrclr,0,0,WIDTH,HEIGHT,500,airDensity);
this->entList= {};
for(int i =0;i<ammount;i++){

    this->entList.emplace(this->entList.begin(),Entity::randEnt(WIDTH,HEIGHT,maxMass,maxSize,maxSpeed));
}
this->pause=SDL_FALSE;
this->rendering=SDL_TRUE;
this->selection=SDL_FALSE;
this->collisions=SDL_TRUE;
this->thetime=0;
this->genCount=0;
this->maxSpeed=maxSpeed;

if(std::fabs(this->maxSpeed)==0){
    this->maxSpeed=0.00001;
}
this->maxSize=maxSize;
this->ammount=ammount;
this->maxMass=maxMass;
this->airDensity=airDensity;
}


void Interactive::mainLoop(){
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

        std::thread entityWorker(&Interactive::handleEntities,this);
        entityWorker.detach();

    if(this->rendering){
    doRendering();
    int endTime= SDL_GetTicks();

if((endTime-startTime)<((1/FRAMERATE)*1000)){

SDL_Delay(((1/FRAMERATE)*1000)-(endTime-startTime));
}


    }

}
}



void Interactive::handleEntities(){

    if(!this->pause){
    PhysicsCommands::handleMovements(this->collisions,this->entList,this->arena,this->gunList);
    if(this->selection){
    generationHandling();
    }
    }


}
void Interactive::addMore(){
if(this->thetime%addMoreInt==0){
for(int i =0;i<howManyToAdd;i++){

    Entity* ent=Entity::randEnt(WIDTH,HEIGHT,maxMass,maxSize,maxSpeed);

    this->entList.emplace(this->entList.begin(),ent);

}
}

}
void Interactive::makeSelection(){

    if(this->thetime%selectFrameInt==0){
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


    std::cout<<"Geraçao numero: "<<this->genCount<<"\n";
this->genCount++;
}
}
void Interactive::doRendering(){

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
void Interactive::generationHandling(){

    this->thetime++;
    addMore();
    makeSelection();


}
void Interactive::printSpeedsAndPos(){



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
void Interactive::handleContPresses(const Uint8*KEYS){
    if(KEYS[SDL_SCANCODE_LEFT]) {
        PhysicsCommands::orbit(this->entList,this->mouseX*1.0,this->mouseY*1.0);
    }
    if(KEYS[SDL_SCANCODE_RIGHT]) {

        PhysicsCommands::homming(this->entList,this->mouseX*1.0,this->mouseY*1.0);
    }
    if(KEYS[SDL_SCANCODE_M]) {
        PhysicsCommands::doBlast(this->entList,this->mouseX*1.0,this->mouseY*1.0);
    }
    if(KEYS[SDL_SCANCODE_DOWN]) {
        shootGuns();
    }

    if(KEYS[SDL_SCANCODE_ESCAPE]) {
    }
}
void Interactive::destroyGuns(){

     std::list<Gun*>::iterator it;
    for (it = this->gunList.begin(); it != this->gunList.end(); ) {
            delete (*it);
            it=this->gunList.erase(it);
    }



}
void Interactive::destroyEntities(){


    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end();) {
        delete (*it);
        it=this->entList.erase(it);
    }


}
void Interactive::monitorGuns(){


     std::list<Gun*>::iterator it;
    for (it = this->gunList.begin(); it != this->gunList.end(); ++it) {

    SDL_FPoint master=(SDL_FPoint){this->mouseX*1.0,this->mouseY*1.0},
                slave=(*it)->getCenter();
    SDL_FPoint vec= Aux::makeUnitVector(slave,master);
    Aux::scaleVec(&vec,(*it)->getShootingForce());
    (*it)->setShootVec(vec);
    (*it)->updateGun();
    }


}
void Interactive::shootGuns(){


     std::list<Gun*>::iterator it;
    for (it = this->gunList.begin(); it != this->gunList.end(); ++it) {
    if(((*it)->canShoot())){
    Entity* bullet= Entity::randEnt(0,0,10,50,0);
    bullet->setPos((*it)->getCenter());
    //dou-lhe o pointer para o vetor da gun. Mais tarde, quando apago as guns, apago o vetor. quando
    //tento apagar as entities, dá merda.
    SDL_FPoint tiltedVec=GVector::tiltVector((*it)->getShootVec(),(*it)->getTilt());
    bullet->setVec(tiltedVec);
    PhysicsAux::railAcceleration(bullet,(*it)->getShootVec(),(*it)->getBarrelLength());
    (*it)->setShootVec(tiltedVec);
    Aux::scaleVec(&tiltedVec,-(*it)->getRecoilFactor());
    (*it)->shoot();
    (*it)->setVec(GVector::add(tiltedVec,((*it)->getVec())));
    this->entList.emplace(this->entList.begin(),bullet);
    }
    }





}

void Interactive::spawnGun(Gun* gun,const char* filePath,float x, float y){

    delete gun;
    gun=Gun::parseGun(filePath);
    gun->setPos((SDL_FPoint){x,y});
    this->gunList.emplace(this->gunList.begin(),gun);
}
void Interactive::handleToggles(const Uint8*KEYS){

    if(KEYS[SDL_SCANCODE_UP]) {
        std::thread printing(&Interactive::printSpeedsAndPos,this);
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
    if(KEYS[SDL_SCANCODE_E]) {
        getTotalEnergy();
//        std::thread showEnergy(&Interactive::getTotalEnergy,this);
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
        std::thread newGun(&Interactive::processGunMenu,this,gun,this->mouseX*1.0,this->mouseY*1.0);
        newGun.detach();

    }

    if(KEYS[SDL_SCANCODE_D]) {

        std::thread deletion(&Interactive::processDeletion,this);
        deletion.detach();

    }
}
void Interactive::processDeletion(){
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
void Interactive::processGunMenu(Gun * gun,float x,float y){

    processGunChoice(gun,x,y);

}
void Interactive::processGunChoice(Gun * gun,float x,float y){

std::cout<<"0- Spawnar uma arma\n";
std::cout<<"1- Ve informacoes de uma arma\n";

    int choice,whatToDo;
    std::cin>>whatToDo;
    Resources::printMenu(Resources::generateGunMenu());
    std::cin>>choice;
    switch(choice){
        case(SRIFLE):{
                if(!whatToDo){
                spawnGun(gun,SRIFLE_PATH,x,y);
                }
                else{
                Gun::printGunInfo(SRIFLE_PATH);

                }


            break;
        }
        case(ARIFLE):{

                if(!whatToDo){
                spawnGun(gun,ARIFLE_PATH,x,y);
                }
                else{
                Gun::printGunInfo(ARIFLE_PATH);

                }


            break;

        }
        case(SMG):{


                if(!whatToDo){
                spawnGun(gun,SMG_PATH,x,y);
                }
                else{
                Gun::printGunInfo(SMG_PATH);

                }


            break;
        }
        case(PISTOL):{

                if(!whatToDo){
                spawnGun(gun,PISTOL_PATH,x,y);
                }
                else{
                Gun::printGunInfo(PISTOL_PATH);

                }


            break;
        }
        default:{

            break;
        }


    }



}
Interactive::~Interactive(){

    this->destroyEntities();
    this->destroyGuns();
    delete this->arena;
SDL_DestroyTexture(this->bgr);
SDL_DestroyTexture(this->ents);
SDL_DestroyRenderer(this->ren);
SDL_DestroyWindow(this->win);

SDL_Quit();
}

