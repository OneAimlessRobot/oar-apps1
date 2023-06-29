
template <typename T>  void PhysicsCommands::handleCollisionsWithArena(std::list<T*> ents,Collider* arena){


  typename std::list<T*>::iterator it;
    for (it = ents.begin(); it != ents.end(); ++it) {
        Entity *current= (*it);
        SDL_FRect currBody=current->getBody();
        current->translate();
        if(arena->whereIsColliding(currBody)>0){

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

void PhysicsCommands::handleInterparticleCollisions(std::list<T*> ents){


    typename std::list<T*>::iterator it,it2,endOfSecond;
    for (it = ents.begin(); it != ents.end(); ++it) {
        endOfSecond=ents.end();
        endOfSecond--;
        Entity *current= (*it);

    for (it2=it; it2 !=endOfSecond;) {
        ++it2;
        Entity *current2= *(it2);
        if(Entity::areTouching(current,current2)){


            PhysicsAux::rebound(current,current2);
            PhysicsAux::separateEntities(current,current2);

        }

    }



}
}
