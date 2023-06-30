#include <string>
#include <fstream>
#include <iostream>
#include "../constantHeaders/IOSettings.h"
#include "../constantHeaders/bulletSettings.h"
#include "Bullet.h"


void caliber::printCaliberInfo(std::string filePath){
std::ifstream bulletReader(filePath);
float size,mass,e,Car;
if(!bulletReader.is_open()){

std::cout<<"ERRO DE FICHEIRO A CARREGAR ARMA!!!!\n"<<filePath<<"\n";

}
std::string dummy;
    while(dummy.rfind(COMMENTPREFIX, 0) == 0){

    std::getline(bulletReader,dummy);

    }
bulletReader>>size>>mass>>e>>Car;
std::cout<<"Características:\n";
std::cout<<"Tamanho: "<<size<<"\n";
std::cout<<"Massa: "<<mass<<"\n";
std::cout<<"Coeficiente de restituiçao invertido: "<<e<<"\n";
std::cout<<"Coeficiente de atrito aerodinamico: "<<Car<<"\n";
bulletReader.close();


}

//
caliber caliber::parseCaliber(std::string filePath){
std::ifstream bulletReader(filePath);
float size,mass,e,Car;
if(!bulletReader.is_open()){

std::cout<<"ERRO DE FICHEIRO A CARREGAR ARMA!!!!\n"<<filePath<<"\n";
return defaultCaliber();


}
bulletReader>>size>>mass>>e>>Car;
bulletReader.close();
return (caliber){size,mass,e,Car};



}
caliber caliber::defaultCaliber(){

    return (caliber){DEFAULTBULLETSIZE,DEFAULTBULLETM,DEFAULTBULLETE,DEFAULTBULLETCAR};


}
