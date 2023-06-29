#include <string>
#include <fstream>
#include "Bullet.h"


caliber::caliber(float size,float mass,float e,float Car){
this->size=size;
this->mass=mass;
this->e=e;
this->Car=Car;


}


caliber caliber::parseCaliber(std::string filePath){
std::ifstream bulletReader(filePath);
float size,mass,e,Car;
if(!bulletReader.is_open()){

std::cerr<<"ERRO DE FICHEIRO A CARREGAR ARMA!!!!\n"<< strerror(errno) <<"\n"<<filePath<<"\n";
return caliber::defaultCaliber();

}
bulletReader>>size>>mass>>e>>Car;

return (caliber){size,mass,e,Car};


}


caliber caliber::defaultCaliber(){

    return (caliber){10,0.1,0.5,0};


}
