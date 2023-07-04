#include <string>
#include <cmath>
#include <list>
#include <iterator>
#include "Crush.h"

std::string Inclination::toString(){
std::string str=std::string("Coracao: ")+ std::to_string(this->heart) +
                    std::string("\n")+
                std::string("Razao: ")+ std::to_string(this->reason) +
                    std::string("\n")+
                std::string("Reatividade: ")+ std::to_string(this->reactiveness) +
                    std::string("\n")+
                std::string("Ego: ")+ std::to_string(this->ego) +
                    std::string("\n")+
                std::string("Força: ")+ std::to_string(this->strength) +
                    std::string("\n")+
                std::string("Abertura de espirito: ")+ std::to_string(this->openness) +
                    std::string("\n")+
                std::string("Neuroticismo: ")+ std::to_string(this->neuroticism) +
                    std::string("\n")+
                std::string("Cinicismo: ")+ std::to_string(this->cynnicism) +
                    std::string("\n");
    return str;



}


Inclination Inclination::add(Inclination inc1,Inclination inc2){
    return (Inclination){inc1.heart+inc2.heart,
                        inc1.reason+inc2.reason,
                        inc1.reactiveness+inc2.reactiveness,
                        inc1.ego+inc2.ego,
                        inc1.strength+inc2.strength,
                        inc1.openness+inc2.openness,
                        inc1.neuroticism+inc2.neuroticism,
                        inc1.cynnicism+inc2.cynnicism
                        };


}

Inclination Inclination::multiply(Inclination inc, float factor){


    return (Inclination){inc.heart*factor,
                        inc.reason*factor,
                        inc.reactiveness*factor,
                        inc.ego*factor,
                        inc.strength*factor,
                        inc.openness*factor,
                        inc.neuroticism*factor,
                        inc.cynnicism*factor
                        };


}

Inclination Inclination::normalize(Inclination inc){

    return Inclination::multiply(inc,1/Inclination::norm(inc));
}
float Inclination::norm(Inclination inc){

return std::sqrt(inc.heart*inc.heart+
                    inc.reason*inc.reason+
                    inc.reactiveness*inc.reactiveness+
                    inc.ego*inc.ego+
                    inc.strength*inc.strength+
                    inc.openness*inc.openness+
                    inc.neuroticism*inc.neuroticism+
                    inc.cynnicism*inc.cynnicism);

}

std::string Interest::toString(){

std::string str=std::string("Nome: ")+ this->name +
                    std::string("\n")+
                std::string("Intensidade: ")+ std::to_string(this->intensity) +
                    std::string("\n");
    return str;


}


Crush::Crush(float mass,float age,float height,Inclination inc){

this->mass=mass;
this->age=age;
this->height=height;
this->inc=inc;
this->interests={};

}
Crush::Crush(){
this->mass=70;
this->age= 30;
this->height=1.75;
this->inc=(Inclination){1,1,1,1,1,1,1,1};
this->interests={};



}

std::string Crush::toString(){

std::string result=std::string("Massa: ")+ std::to_string(this->mass) +
                    std::string("\n")+
                std::string("Idade: ")+ std::to_string(this->age) +
                    std::string("\n")+
                std::string("Altura: ")+ std::to_string(this->height) +
                    std::string("\n")+
                std::string("Esta e a inclinaçao: \n")+this->inc.toString();
std::list<Interest>::iterator it;
for(it=this->interests.begin();it!=this->interests.end();it++){

    result+=(*it).toString();


}
    return result;



}
float Crush::getMass(){

return this->mass;
}
float Crush::getAge(){

return this->age;
}
float Crush::getHeight(){

return this->height;
}
Inclination Crush::getInclination(){

return this->inc;

}


void Crush::setInclination(Inclination inc){

    this->inc=inc;

}
void Crush::addInterest(Interest added){

    this->interests.emplace(this->interests.begin(),added);

}
