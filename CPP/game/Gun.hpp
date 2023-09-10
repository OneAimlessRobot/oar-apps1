#include "ProjectileIterator.hpp"
#include <iostream>

using namespace std;

class Gun{
private:

Projectile **ammo;
Projectile **fired;
int capacity;
int projectSpeed;
int gunX;
int gunY;
int caliber;
int remaining;
int currentSlot;
int ammountFired;

public:

Gun(int gunX,int gunY,int projectSpeed,int caliber,int capacity){

    this->capacity=capacity;
    this->projectSpeed=projectSpeed;
    this->gunX=gunX;
    this->gunY=gunY;
    this->caliber=caliber;
    this->remaining=this->capacity;
    this->currentSlot=0;
    this->ammountFired=this->currentSlot;

    this->ammo=(Projectile**)malloc(sizeof(Projectile*)*this->capacity);
    this->fired=(Projectile**)malloc(sizeof(Projectile*)*this->capacity);

    for(int i=0;i<this->capacity;i++){

        ammo[i]=new Projectile(gunX,gunY,projectSpeed,caliber);
        ammo[i]->hideProjectile();


    }

    for(int i=0;i<this->capacity;i++){

        fired[i]=new Projectile(0,0,0,1);


    }
}

void fireGun(int targetX,int targetY){


    Projectile::projCopy(ammo[currentSlot],fired[currentSlot]);

    fired[currentSlot]->giveProjectileAPurposeInLife(targetX,targetY);
    remaining--;
    currentSlot++;
    ammountFired++;




}

void updateMovingProjectiles(int xOrigin,int yOrigin){

    for(int i=0;i<ammountFired;i++){

        fired[i]->updateMovingProjectile(xOrigin,yOrigin);


    }
}

void updateLaunchPositions(int newX,int newY){

    for(int i=0;i<remaining;i++){

        ammo[i]->updatePosition(newX,newY);
    }
}

void renderFiredProjectiles(SDL_Renderer* rend){

    for(int i=0;i<ammountFired;i++){

        fired[i]->drawProjectile(rend);
    }

}
void initializeEmptyProjectileArray(Projectile**array,int size){

    for(int i=0;i<size;i++){

        array[i]=new Projectile(0,0,0,1);
    }


}

void checkProjectileCollisions(SDL_Rect *box){

    for(int i=0;i<ammountFired;i++){

        int j=fired[i]->hasColisionWithBox(box);
        if(j){
            fired[i]->destroyProjectile();

        }
    }
}

ProjectileIterator*firedAmmoIterator(){

    return new ProjectileIterator(fired,ammountFired);
}

ProjectileIterator* idleAmmoIterator(){

    return new ProjectileIterator(ammo,remaining);
}

void destroyGun(){

    for(int i=0;i<capacity;i++){

        delete(ammo[i]);
    }
    for(int i=0;i<capacity;i++){
        delete(fired[i]);
    }
    
}

};

/*


void printAmmo(){

    for(int i=0;i<capacity;i++){

        cout<<"Posiçao, velocidade da bala "<<i<<":"<<endl;
        cout<<"Posiçao :"<<ammo[i]->getXpos()<<" "<<ammo[i]->getYpos()<<endl;
        cout<<"velocidade :"<<ammo[i]->getSpeed()<<endl;
        cout<<"tamanho :"<<ammo[i]->getSize()<<endl;
    }
}

void copyArray(){

    for(int i=0;i<capacity;i++){


        Projectile::projCopy(ammo[i],fired[i]);


    }
}
Projectile** removeProjectileFromArray(){

    Projectile**aux=(Projectile**)malloc(sizeof(Projectile*)*(this->capacity-1));


    this->initializeEmptyProjectileArray(aux,this->capacity-1);


    for(int i=0;i<(this->capacity-1);i++){

        Projectile::projCopy(ammo[i+1],ammo[i]);
    }

    for(int i=0;i<(this->capacity-1);i++){



        Projectile::projCopy(ammo[i],aux[i]);
    }
    return aux;


}

Projectile** addProjectileToArray(){

    Projectile**aux=(Projectile **)malloc(sizeof(Projectile*)*(this->capacity+1));

    this->initializeEmptyProjectileArray(aux,this->capacity+1);

    for(int i=0;i<this->capacity;i++){

        Projectile::projCopy(fired[i],aux[i]);
    }
    return aux;


}*/