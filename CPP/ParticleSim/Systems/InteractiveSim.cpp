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
#include "../aux.h"
#include "../Types/Collider.h"
#include "../Types/GVector.h"
#include "../Types/Bullet.h"
#include "../Types/Entity.h"
#include "../Types/Gun.h"
#include "../Types/physicsAux.h"
#include "../Factorized/physicsCommands.h"
#include "InteractiveSim.h"

InteractiveSim::InteractiveSim(float maxSpeed,float maxSize,int ammount,float maxMass){
init(maxSpeed,maxSize,ammount, maxMass);

}

InteractiveSim::InteractiveSim(){
init(DEFAULTENTMAXMASS,DEFAULTENTMAXSIZE,1000,DEFAULTENTMAXSPEED);

}

void InteractiveSim::init(float maxSpeed,float maxSize,int ammount,float maxMass){


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
this->arena= Collider::parseCollider(DEFAULT_COLLIDER_PATH);

this->maxSpeed=maxSpeed;
if(std::fabs(this->maxSpeed)==0){
    this->maxSpeed=0.00001;
}

this->entList= {};
for(int i =0;i<ammount;i++){

    this->entList.emplace(this->entList.begin(),Entity::randEnt(WIDTH,HEIGHT,maxMass,maxSize,maxSpeed));
}
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
}

InteractiveSim* InteractiveSim::parseGame(){



std::ifstream entSettingsRead(ENTSETTINGS_PATH);
float maxspeed,maxsize,maxmass,ammount;
    std::string dummy;
    while(dummy.rfind(COMMENTPREFIX, 0) == 0){

    std::getline(entSettingsRead,dummy);

    }

if(!entSettingsRead.is_open()){

std::cout<<"ERRO DE FICHEIRO A CARREGAR ARMA!!!!\n"<<ENTSETTINGS_PATH<<"\n";
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



void InteractiveSim::handleEntities(){

    if(!this->pause){
    PhysicsCommands::handleMovements(this->collisions,this->gravity,this->drag,this->entList,this->arena,this->gunList);
    monitorGuns();
    if(this->selection){
    generationHandling();
    }
    }


}
void InteractiveSim::addMore(){
if(this->thetime%addMoreInt==0){
for(int i =0;i<howManyToAdd;i++){

    Entity* ent=Entity::randEnt(WIDTH,HEIGHT,maxMass,maxSize,maxSpeed);
//    if(ent->getPos().x!=ent->getPos().x||ent->getPos().y!=ent->getPos().y){
//    std::cout<<"ERRO!!!!!\n";
//    }
    this->entList.emplace(this->entList.begin(),ent);

}
}

}
void InteractiveSim::makeSelection(){

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
    addMore();
    makeSelection();


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
void InteractiveSim::destroyGuns(){

     std::list<Gun*>::iterator it;
    for (it = this->gunList.begin(); it != this->gunList.end(); ) {
            delete (*it);
            it=this->gunList.erase(it);
    }



}
void InteractiveSim::destroyEntities(){


    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end();) {
        delete (*it);
        it=this->entList.erase(it);
    }


}
void InteractiveSim::monitorGuns(){


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
    std::cout<<"Toggle collisions: M\n";
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
    gun=Gun::parseGun(filePath);
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

        std::thread deletion(&InteractiveSim::processDeletion,this);
        deletion.detach();

    }

    if(KEYS[SDL_SCANCODE_F]) {

        std::thread arenaInfo(&Collider::printColliderInfo,DEFAULT_COLLIDER_PATH);
        arenaInfo.detach();

    }
}

void InteractiveSim::processBulletChoice(caliber* bType){

int choice,whatToDo;
do{
std::cout<<"0- Para escolher um calibre\n";
std::cout<<"1- Para ver informaçoes de um calibre\n";

std::cin>>whatToDo;
std::cout<<"Que calibre queres?\n";

    Resources::printMenu(Resources::generateBulletMenu());
    std::cin>>choice;
    switch(choice){
        case(FFSIX):{
        if(!whatToDo){
            *bType=caliber::parseCaliber(FIVEFIVESIX_PATH);
        }
        else{
            caliber::printCaliberInfo(FIVEFIVESIX_PATH);
        }
            break;
        }
        case(FFORTYF):{
        if(!whatToDo){
            *bType=caliber::parseCaliber(FFORTYF_PATH);
        }
        else{

            caliber::printCaliberInfo(FFORTYF_PATH);
        }
            break;
        }
        case(SEVENSIXNINE):{
        if(!whatToDo){
            *bType=caliber::parseCaliber(SEVENSIXNINE_PATH);
        }
        else{
            caliber::printCaliberInfo(SEVENSIXNINE_PATH);

        }
            break;
        }
        case(THREEOEIGHT):{
        if(!whatToDo){
            *bType=caliber::parseCaliber(THREEOEIGHT_PATH);
        }
        else{
            caliber::printCaliberInfo(THREEOEIGHT_PATH);

        }
            break;
        }
        case(FFTYBMG):{
        if(!whatToDo){
            *bType=caliber::parseCaliber(FFTYBMG_PATH);
        }
        else{
            caliber::printCaliberInfo(FFTYBMG_PATH);

        }
            break;
        }
        default:{

            break;
        }


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

std::cout<<"0- Spawnar uma arma\n";
std::cout<<"1- Ve informacoes de uma arma\n";

    int choice,whatToDo;
    std::cin>>whatToDo;
    Resources::printMenu(Resources::generateGunMenu());
    std::cin>>choice;
    switch(choice){
        case(SRIFLE):{
                if(!whatToDo){

                caliber chosenCaliber;
                processBulletChoice(&chosenCaliber);
                spawnGun(gun,SRIFLE_PATH,x,y,chosenCaliber);
                }
                else{
                Gun::printGunInfo(SRIFLE_PATH);

                }


            break;
        }
        case(ARIFLE):{

                if(!whatToDo){
                caliber chosenCaliber;
                processBulletChoice(&chosenCaliber);
                spawnGun(gun,ARIFLE_PATH,x,y,chosenCaliber);
                }
                else{
                Gun::printGunInfo(ARIFLE_PATH);

                }


            break;

        }
        case(SMG):{


                if(!whatToDo){
                caliber chosenCaliber;
                processBulletChoice(&chosenCaliber);
                spawnGun(gun,SMG_PATH,x,y,chosenCaliber);
                }
                else{
                Gun::printGunInfo(SMG_PATH);

                }


            break;
        }
        case(PISTOL):{

                if(!whatToDo){
                caliber chosenCaliber;
                processBulletChoice(&chosenCaliber);
                spawnGun(gun,PISTOL_PATH,x,y,chosenCaliber);
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
InteractiveSim::~InteractiveSim(){

    this->destroyEntities();
    this->destroyGuns();
    delete this->arena;
SDL_DestroyTexture(this->bgr);
SDL_DestroyTexture(this->ents);
SDL_DestroyRenderer(this->ren);
SDL_DestroyWindow(this->win);

SDL_Quit();
}

