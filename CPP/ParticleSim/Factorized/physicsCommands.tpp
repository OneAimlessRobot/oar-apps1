
template <typename T>  void PhysicsCommands::handleCollisionsWithArena(std::list<T*>& ents,Collider* arena){


  typename std::list<T*>::iterator it;
    for (it = ents.begin(); it != ents.end(); ++it) {
        T *current= (*it);
        SDL_FRect currBody=current->getBody();
        current->translate();
        if(arena->whereIsColliding(currBody)>0){

//    std::cout<<current->getPos().x<<" , "<<current->getPos().y<<"\n";
        int where=arena->whereIsColliding(currBody);
            current->bounce();
            PhysicsAux::separateEntityFromCollider(current,arena,where);
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

template <typename T>

void PhysicsCommands::handleInterparticleCollisions(std::list<T*>& ents){


    typename std::list<T*>::iterator it,it2,endOfSecond;
    for (it = ents.begin(); it != ents.end(); ++it) {
        endOfSecond=ents.end();
        endOfSecond--;
        T *current= (*it);

    for (it2=it; it2 !=endOfSecond;) {
        ++it2;
        T *current2= *(it2);
        if(Entity::areTouching(current,current2)){


            PhysicsAux::rebound(current,current2);
            PhysicsAux::separateEntities(current,current2);

        }

    }



}
}

template <typename T>
void PhysicsCommands::deleteFreaks(std::list<T*>& ents){


    typename std::list<T*>::iterator it;
    for (it = ents.begin(); it != ents.end();) {
        SDL_FPoint v= (*it)->getVec(),p=(*it)->getPos();
        if(v.x!=v.x||v.y!=v.y||p.x!=p.x||p.y!=p.y){
    std::cout<<"ERRO!!!!!\n";
    delete (*it);
    it=ents.erase(it);
    }
    else{
    ++it;

    }



}
}
template <typename T>
void PhysicsCommands::handleInterparticleGravity(std::list<T*>& ents){

    typename std::list<T*>::iterator it,it2,endOfSecond;
    for (it = ents.begin(); it != ents.end(); ++it) {
        endOfSecond=ents.end();
        endOfSecond--;
        T *current= (*it);

    for (it2=it; it2 !=endOfSecond;) {
        ++it2;
        T *current2= *(it2);
        PhysicsAux::accelerateEntity((current2),PhysicsAux::gravVector(current->getCenter(),current2->getCenter(),current->getMass(),current2->getMass()));
        PhysicsAux::accelerateEntity((current),PhysicsAux::gravVector(current2->getCenter(),current->getCenter(),current->getMass(),current2->getMass()));

    }



}
}
template <typename T>
void PhysicsCommands::handleGroundGravity(std::list<T*>& ents,Entity*worldParticle){


    typename std::list<T*>::iterator it;
    for (it = ents.begin(); it != ents.end(); ++it) {
        T *current= (*it);
        PhysicsAux::accelerateEntity((worldParticle),PhysicsAux::gravVector(current->getCenter(),worldParticle->getCenter(),current->getMass(),worldParticle->getMass()));
        PhysicsAux::accelerateEntity((current),PhysicsAux::gravVector(worldParticle->getCenter(),current->getCenter(),current->getMass(),worldParticle->getMass()));



}


}
