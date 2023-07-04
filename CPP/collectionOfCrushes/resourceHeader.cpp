#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <iterator>
#include "Types/Crush.h"
#include "Types/Menu.h"


Inclination ResourceParsing::parseInclination(std::string filePath){

std::ifstream incReader(filePath);
float calm,reason,reactiveness,ego,strength,openness,neuroticism,cynnicism;

if(!incReader.is_open()){

std::cerr<<"Nao abriu com sucesso. A carregar inclinaçao default:\n";
return (Inclination){1,1,1,1,1,1,1,1};

}
incReader>>calm>>reason>>reactiveness>>ego>>strength>>openness>>neuroticism>>cynnicism;

return (Inclination){calm,reason,reactiveness,ego,strength,openness,neuroticism,cynnicism};


}

Crush* ResourceParsing::parseCrush(std::string filePath);

Interest* ResourceParsing::parseInterest(std::string filePath);

optionList ResourceParsing::parseMenu(std::string filePath);

