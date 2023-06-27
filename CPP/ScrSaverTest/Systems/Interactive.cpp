#include <thread>
#include <list>
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
this->arena= new Collider(SDL_FALSE,bgrclr,0,0,WIDTH,HEIGHT,50,airDensity);
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
    if(!this->pause){
    handleMovements();
    if(this->selection){
    generationHandling();
    }
    }
    if(this->rendering){
    doRendering();
    int endTime= SDL_GetTicks();

if((endTime-startTime)<((1/FRAMERATE)*1000)){

SDL_Delay(((1/FRAMERATE)*1000)-(endTime-startTime));
}


    }

}
}
void Interactive::addMore(){
if(this->thetime%addMoreInt==0){
float average=getAverageQuality();
for(int i =0;i<howManyToAdd;i++){

    Entity* ent=Entity::randEnt(WIDTH,HEIGHT,maxMass,maxSize,maxSpeed);

    this->entList.emplace(this->entList.begin(),ent);

}
}

}
void Interactive::makeSelection(){

    if(this->thetime%selectFrameInt==0){
        float selectQuality=getAverageSpeed();
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
float Interactive::getAverageSpeed(){
    float speedSum=0;
    int totalBodies=0;
        std::list<Entity*>::iterator it;
            for (it = this->entList.begin(); it != this->entList.end(); ++it) {

                speedSum+=GVector::getNorm((*it)->getVec());
                totalBodies++;

        }
        return speedSum/totalBodies;
}
float Interactive::getAverageQuality(){
    float qualitySum=0;
    int totalBodies=0;
        std::list<Entity*>::iterator it;
            for (it = this->entList.begin(); it != this->entList.end(); ++it) {

                qualitySum+=(*it)->getQuality();
                totalBodies++;

        }
        return qualitySum/totalBodies;
}
float Interactive::getTotalEnergy(){
    float energySum=0;
        std::list<Entity*>::iterator it;
            for (it = this->entList.begin(); it != this->entList.end(); ++it) {

                energySum+=(*it)->getTotalEnergy();

        }
        std::cout<<"Energia total: "<<energySum<<"\n";
        return energySum;
}
void Interactive::doRendering(){

    SDL_SetRenderDrawColor(this->ren,this->bgrclr.r,this->bgrclr.g,this->bgrclr.b,this->bgrclr.a);
    SDL_SetRenderTarget(ren,bgr);
    SDL_RenderClear(ren);
    SDL_SetRenderTarget(ren,ents);
    SDL_RenderCopy(ren,bgr,NULL,NULL);
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
void Interactive::handleInterparticleCollisions(){


    std::list<Entity*>::iterator it,it2,endOfSecond;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {
        endOfSecond=this->entList.end();
        endOfSecond--;
        Entity *current= (*it);

    for (it2=it; it2 !=endOfSecond;) {
        ++it2;
        Entity *current2= *(it2);
        if(Entity::areTouching(current,current2)){


            PhysicsAux::separateEntities(current,current2);
            PhysicsAux::rebound(current,current2);

        }

    }



}
}
void Interactive::handleCollisionsWithArena(){


    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {
        Entity *current= (*it);
        SDL_FRect currBody=current->getBody();
        current->translate();
        if(this->arena->whereIsColliding(currBody)>0){

        int where=this->arena->whereIsColliding(currBody);
            current->bounce();
            PhysicsAux::separateEntityFromCollider(current,this->arena,where);
            SDL_FPoint vec=current->getVec();
    if (where==1) {
        GVector::Reflect(&vec, new GVector(-1.0f, 0.0f));
    } else if (where==2) {

        GVector::Reflect(&vec, new GVector(1.0f, 0.0f));

    } else if (where==3) {

        GVector::Reflect(&vec, new GVector(0.0f, -1.0f));
    } else if (where==4) {

        GVector::Reflect(&vec, new GVector(0.0f, 1.0f));
    }
        current->setVec(vec);

        //Problema com colisões diagonais (qual eixo de reflexão escolher?)
    }



}
}
void Interactive::handleCollisions(){

    //broken. Maybe will fix
    if(this->collisions){
    handleInterparticleCollisions();
    }

    handleCollisionsWithArena();

}
void Interactive::handleForces(){

    handleDrag();

}
void Interactive::handleDrag(){


    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {
   SDL_FPoint currentVec= (*it)->getVec();
        SDL_FPoint newVec=Aux::makeUnitVector((SDL_FPoint){0,0},(SDL_FPoint){-currentVec.x,-currentVec.y});
        float dragMagnitude= PhysicsAux::dragNeutralWind(((*it)->getDragConstant()),this->arena->getAirDensity(),GVector::getNorm(currentVec));
        Aux::scaleVec(&newVec,dragMagnitude);
        (*it)->setVec(GVector::add(newVec,currentVec));


}



}
void Interactive::handleMovements(){

    handleForces();

    handleCollisions();

    monitorGuns();



}
void Interactive::orbit(){


    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {
    SDL_FPoint master=(SDL_FPoint){this->mouseX,this->mouseY},
                slave=(*it)->getPos();
        SDL_FPoint newVec=Aux::makeUnitVector(slave,master);
        float magnitude= PhysicsAux::gravForce(slave,master,1000,(*it)->getMass());
        if(Aux::calculateDistance(master ,slave)<=50){
            Aux::scaleVec(&newVec,1);
        }
        else{
        Aux::scaleVec(&newVec,magnitude);
        }
        (*it)->setVec(GVector::add(newVec,(*it)->getVec()));
//        delete newVec;

}

}
void Interactive::homming(){


    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {
    SDL_FPoint master=(SDL_FPoint){this->mouseX,this->mouseY},
                slave=(*it)->getPos();
        SDL_FPoint newVec=Aux::makeUnitVector(slave,master);
        if(Aux::calculateDistance(master ,slave)<=50){
            Aux::scaleVec(&newVec,1);
        }
        else{
        Aux::scaleVec(&newVec,homingSpeed);
        }
        (*it)->setVec(newVec);


}

}
void Interactive::printSpeedsAndPos(){



    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end(); ++it) {
       std::cout<<"Posição: (x,y)= ("<<(*it)->getPos().x<<" , "<<(*it)->getPos().y<<")\n";
       std::cout<<"Velocidade: "<<GVector::getNorm((*it)->getVec())<<"\n";
       std::cout<<"Coeficientes: \n";
       std::cout<<"Elasticidade: "<<(*it)->getElasticity()<<"\n";
       std::cout<<"Massa: "<<(*it)->getMass()<<"\n";
       std::cout<<"Coeficiente de resis. do ar: "<<(*it)->getDragConstant()<<"\n";


}


}
void Interactive::handleContPresses(const Uint8*KEYS){
    if(KEYS[SDL_SCANCODE_LEFT]) {
        orbit();
    }
    if(KEYS[SDL_SCANCODE_RIGHT]) {

        homming();
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
void Interactive::monitorGuns(){


     std::list<Gun*>::iterator it;
    for (it = this->gunList.begin(); it != this->gunList.end(); ++it) {

    SDL_FPoint master=(SDL_FPoint){this->mouseX,this->mouseY},
                slave=(*it)->getCenter();
    SDL_FPoint vec= Aux::makeUnitVector(slave,master);
    Aux::scaleVec(&vec,(*it)->getShootingForce());
    (*it)->setShootVec(vec);
    }


}
void Interactive::shootGuns(){


     std::list<Gun*>::iterator it;
    for (it = this->gunList.begin(); it != this->gunList.end(); ++it) {
    if(!((*it)->isEmpty())){
    Entity* bullet= Entity::randEnt(0,0,10,10,0);
    bullet->setPos((*it)->getCenter());
    //dou-lhe o pointer para o vetor da gun. Mais tarde, quando apago as guns, apago o vetor. quando
    //tento apagar as entities, dá merda.
    bullet->setVec((*it)->getShootVec());
    this->entList.emplace(this->entList.begin(),bullet);
    (*it)->shoot();
    }
    }





}
void Interactive::spawnGun(float reloadTime,int capacity,float force,float barrelLen,float x,float y){


    Gun* gun= new Gun(Aux::randColor(),this->mouseX,this->mouseY,10,10,1,10000000,1,5,5,5,5);
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
    if(KEYS[SDL_SCANCODE_DOWN]) {
        shootGuns();
    }
    if(KEYS[SDL_SCANCODE_E]) {
        getTotalEnergy();
//        std::thread showEnergy(&Interactive::getTotalEnergy,this);
//        showEnergy.detach();
    }
    if(KEYS[SDL_SCANCODE_S]) {
    Entity* ent=Entity::randEnt(WIDTH,HEIGHT,maxMass,maxSize,maxSpeed);
    ent->setPos((SDL_FPoint){this->mouseX,this->mouseY});
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

        spawnGun(0,10,10,0,this->mouseX,this->mouseY);

    }

    if(KEYS[SDL_SCANCODE_D]) {
        destroyGuns();

    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end();) {
        delete (*it);
                    it=this->entList.erase(it);
    }
    }
}

Interactive::~Interactive(){

    std::list<Entity*>::iterator it;
    for (it = this->entList.begin(); it != this->entList.end();) {
        delete (*it);
        it=this->entList.erase(it);
    }
    this->destroyGuns();
    delete this->arena;
SDL_DestroyTexture(this->bgr);
SDL_DestroyTexture(this->ents);
SDL_DestroyRenderer(this->ren);
SDL_DestroyWindow(this->win);

SDL_Quit();
}

