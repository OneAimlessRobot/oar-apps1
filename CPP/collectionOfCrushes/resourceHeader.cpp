#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <unistd.h>
#include <fstream>
#include <iterator>
#include "Types/Crush.h"
#include "Types/Menu.h"
#include "resourceHeader.h"

void parseCrushInterests(Crush* result,std::ifstream& crushReader,std::string filePath){

std::iostream::pos_type pos=crushReader.tellg();
do{
Interest inter=ResourceParsing::parseInterest(filePath,pos);
std::string interPath=STD_INTERESTS_PATH+inter.name;
std::string traitPath=STD_TRAITS_PATH+inter.name;
Inclination incVec= ResourceParsing::parseInterestDelta(vecPath);
result->setInclination(Inclination::add(result->getInclination(),incVec));
result->addInterest(inter);
crushReader.seekg(pos,std::ios_base::beg);
}while(crushReader.get()!=';');
result->setInclination(Inclination::normalize(result->getInclination()));


}

void parseCrushTraits(Crush* result,std::ifstream& crushReader,std::string filePath){

std::iostream::pos_type pos=crushReader.tellg();
do{
Trait inter=ResourceParsing::parseInterest(filePath,pos);
std::string traitPath=STD_TRAITS_PATH+inter.name;
Inclination incVec= ResourceParsing::parseInterestDelta(traitPath);
result->setInclination(Inclination::add(result->getInclination(),incVec));
result->addInterest(inter);
crushReader.seekg(pos,std::ios_base::beg);
}while(crushReader.get()!=';');
result->setInclination(Inclination::normalize(result->getInclination()));


}
Inclination ResourceParsing::parsePersonality(std::string &filePath){





}

Inclination ResourceParsing::parseInclination(std::string& filePath){

std::ifstream incReader(filePath);
float calm,reason,reactiveness,ego,strength,openness,neuroticism,cynnicism;

if(!incReader.is_open()){
std::cout<<filePath<<"\n";
std::cerr<<"Nao abriu com sucesso. A carregar inclinaçao default:\n";
return (Inclination){1,1,1,1,1,1,1,1};

}
incReader>>calm>>reason>>reactiveness>>ego>>strength>>openness>>neuroticism>>cynnicism;

return (Inclination){calm,reason,reactiveness,ego,strength,openness,neuroticism,cynnicism};


}

Crush* ResourceParsing::parseCrush(std::string &filePath){


std::ifstream crushReader(filePath);
std::string line;
float mass,age,height;
std::string incName,filePathAux=filePath;
if(!crushReader.is_open()){
std::cout<<filePath<<"\n";

std::cerr<<"Nao abriu com sucesso. A carregar inclinaçao default:\n";
return new Crush(1,1,1,(Inclination){1,1,1,1,1,1,1,1});

}
crushReader>>incName>>mass>>age>>height;
std::string incPath=STD_PERSONALITY_PATH+incName;
Crush* result= new Crush(mass,age,height,parseInclination(incPath));
parseCrushInterests(result,crushReader,filePath);
parseCrushTraits(result,crushReader,filePath);
crushReader.close();
return result;

}
Interest ResourceParsing::parseInterest(std::string& filePath,std::iostream::pos_type& pos){

std::string intName;
float intensity;
std::ifstream interReader(filePath);
interReader.seekg(pos,std::ios_base::beg);
if(!interReader.is_open()){
std::cout<<filePath<<"\n";

std::cerr<<"Nao abriu com sucesso. A carregar inclinaçao default:\n";
return (Interest){std::string("Basica"),1};

}
interReader>>intName>>intensity;
std::string intPath=STD_INTERESTS_PATH+intName;
//std::cout<<intPath<<"\n";
pos=interReader.tellg();
return (Interest){intName,intensity};

}

Inclination ResourceParsing::parseInterestDelta(std::string& filePath){


return Inclination::normalize(ResourceParsing::parseInclination(filePath));




}
optionList ResourceParsing::parseMenu(std::string& filePath){


optionList menu={};
std::ifstream menuReader(filePath);
std::string line;
if(!menuReader.is_open()){
std::cout<<filePath<<"\n";

std::cerr<<"Menu não abriu com sucesso.\n";
return (optionList){};
}
while(std::getline(menuReader,line)){

menu.push_back(line);

}

return menu;



}

Crush* ResourceParsing::randCrush(){




}
