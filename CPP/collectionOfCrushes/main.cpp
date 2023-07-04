#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <vector>
#include "Types/Menu.h"
#include "Types/Crush.h"
#include "resourceHeader.h"
Crush* menu();
int main(int argc, char**argv){
std::string path=std::string(RESOURCES_PATH_AUX);
std::cout<<path<<"\n";
Crush *crush=menu();
std::cout<<crush->toString()<<"\n";

return 0;

}

Crush* menu(){


std::string choice;
int whatToDo;
do{
std::cout<<"0- Para escolher uma personalidade\n";
std::cout<<"1- Para ver informaçoes de uma personalidade\n";

std::cin>>whatToDo;
std::cout<<"Que crush queres?\n";
    std::string menuPath=STD_MODELS_MENU_PATH;
    optionList l=ResourceParsing::parseMenu(menuPath);
    std::cout<<Menu::toString(l);
    std::cin>>choice;
        std::string path=STD_MODELS_PATH+choice;
        if(!whatToDo){

            return ResourceParsing::parseCrush(path);
        }
        else{
            Crush* crush=ResourceParsing::parseCrush(path);
            std::cout<<crush->toString();
            delete crush;
        }
    }while(whatToDo);



}
