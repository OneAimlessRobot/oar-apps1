#include <string>
#include <iostream>
#include <list>
#include <limits>
#include <tuple>

#include "Menu.h"


int Menu::optionInList(std::string& opt,optionList& l){

    optionList::iterator it;
    for(it=l.begin();it!=l.end();it++){

        if(opt==(*it)){
            return 1;
        }


    }
    return 0;

}
void Menu::safeInput(std::string& var,optionList ol,std::string errorMsg){


    while(!(std::cin>>var) && !Menu::optionInList(var,ol)){
        std::cout << errorMsg << std::endl;
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }


}
