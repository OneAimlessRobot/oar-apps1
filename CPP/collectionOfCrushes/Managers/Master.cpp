
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <list>
#include <vector>
#include "../auxFuncs.h"
#include "../Types/Menu.h"
#include "../Types/Crush.h"
#include "../resourceHeader.h"
#include "../Tools/CrushGenerator.h"
#include "Master.h"

Master::Master(std::string filePath){

std::ifstream reader(filePath);

float minMass,maxMass,
        minAge,maxAge,
        minHeight,maxHeight;

if(!reader.is_open()){

    std::cerr<<"Nao foi possivel ler ficheiro de settings. Carregando settings default:\n";
    this->gen=new CrushGenerator(70,70,20,20,1.67,1.67);



}
if(!(reader>>maxAge>>
    maxMass>>
    maxHeight>>
    minAge>>
    minMass>>
    minHeight)){


    std::cerr<<"Nao foi possivel ler ficheiro de settings. Carregando settings default:\n";
    this->gen=new CrushGenerator(70,70,20,20,1.67,1.67);



    }
this->gen=new CrushGenerator(minMass,maxMass,minAge,maxAge,minHeight,maxHeight);
}







void Master::mainLoop(){




std::cout<<menu()->toString()<<"\n";




}
Crush* Master::menu(){


std::string choice;
int whatToDo;
do{
std::cout<<"0- Para escolher uma personalidade\n";
std::cout<<"1- Para ver informaçoes de uma personalidade\n";

std::cin>>whatToDo;
std::cout<<"Que crush queres?\n";
    std::string menuPath=STD_MODELS_MENU_PATH;
    optionSet l=ResourceParsing::parseMenu(menuPath);
    std::cout<<Menu::toString(l);
    Menu::safeInput(choice,l,"Nao esta na lista.");
        std::string path=STD_MODELS_PATH+choice;
        if(!whatToDo){
            if(choice==std::string("random")){
                return gen->gen();

            }
            return ResourceParsing::parseCrush(path);
        }
        else{
            Crush*crush;
            if(choice==std::string("random")){
                crush= gen->gen();

            }
            else{
            crush=ResourceParsing::parseCrush(path);
            }
            std::cout<<crush->toString();
            delete crush;
        }
    }while(whatToDo);



}