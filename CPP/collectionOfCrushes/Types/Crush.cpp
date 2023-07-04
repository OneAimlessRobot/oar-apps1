#include <string>
#include "Crush.h"

std::string Inclination::toString(){
std::string str=std::string("Calma: ")+ std::to_string(this->calm) +
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

std::string Interest::toString(){

std::string str=std::string("Nome: ")+ this->name +
                    std::string("\n")+
                std::string("Razao: ")+ std::to_string(this->intensity) +
                    std::string("\n");
    return str;


}
Crush::Crush(float mass,float age,float height,Inclination inc){

this->mass=mass;
this->age=age;
this->height=height;
this->inc=inc;

}
Crush::Crush(){
this->mass=70;
this->age= 30;
this->height=1.75;
this->inc=(Inclination){1,1,1,1,1,1,1,1};



}

std::string Crush::toString(){

std::string result=std::string("Massa: ")+ std::to_string(this->mass) +
                    std::string("\n")+
                std::string("Idade: ")+ std::to_string(this->age) +
                    std::string("\n")+
                std::string("Altura: ")+ std::to_string(this->height) +
                    std::string("\n")+
                std::string("Esta e a inclinaçao: \n")+this->inc.toString();
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
