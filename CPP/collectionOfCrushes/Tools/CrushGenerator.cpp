#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unistd.h>
#include <fstream>
#include <iterator>
#include <vector>
#include "../auxFuncs.h"
#include "Types/Crush.h"
#include "Types/Menu.h"
#include "resourceHeader.h"
#include "CrushGenerator.h"


CrushGenerator::CrushGenerator(float minMass,float maxMass,float minAge,float maxAge,float minHeight,float maxHeight){
    this->maxAge=maxAge;
    this->maxMass=maxMass;
    this->maxHeight=maxHeight;
    this->minAge=minAge;
    this->minMass=minMass;
    this->minHeight=minHeight;


}


Crush* CrushGenerator::gen(){

float mass,age,height;

mass=AuxFuncs::getRandomFloat(40,100);
age=AuxFuncs::getRandomFloat(18,35);
height=AuxFuncs::getRandomFloat(1.5,2.2);
std::string interMenu=STD_INTERESTS_MENU_PATH,starterMenu=STD_PERSONALITY_MENU_PATH,
interDir=STD_INTERESTS_PATH,namesPath=STD_NAMES_MENU_PATH,persPath=STD_PERSONALITY_PATH;
optionSet names=ResourceParsing::parseMenu(namesPath);
optionSet interests=ResourceParsing::parseMenu(interMenu);
optionSet starting=ResourceParsing::parseMenu(starterMenu);
std::string starter=AuxFuncs::randItemFromList<std::string>(starting);
std::string persFile=persPath+starter;
std::string name=AuxFuncs::randItemFromList<std::string>(names);
Inclination startPersona= ResourceParsing::parseInclination(persFile);
Crush* result= new Crush(name,mass,age,height,startPersona);


for(int i=0;i<4;i++){
float intensity=AuxFuncs::getRandomFloat(1,100);
std::string interName=AuxFuncs::randItemFromList<std::string>(interests);
interests.erase(interName);
std::string interPath= interDir+interName;
Interest added=(Interest){interName,intensity};
result->addInterest(added);
Inclination inc= Inclination::normalize(ResourceParsing::parseInterestDelta(interPath));
result->setInclination(Inclination::add(result->getInclination(),inc));

}

return result;

}