#include <string>
#include <iostream>
#include <set>
#include <fstream>
#include <limits>
#include <tuple>

#include "Menu.h"


int Menu::optionInList(std::string& opt,optionSet& l){

    optionSet::iterator it;
    for(it=l.begin();it!=l.end();it++){
        std::cout<<(*it)<<" "<<opt<<"\n";
        if(opt==(*it)){
            return 1;
        }


    }
    return 0;

}
void Menu::safeInput(std::string& var,optionSet ol,std::string errorMsg){


    while(!(std::cin>>var) || !Menu::optionInList(var,ol)){
        std::cout << errorMsg << std::endl;
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }


}

std::string Menu::toString(optionSet& l){

std::string result=std::string("");
int counter=0;
optionSet::iterator it;
for(it=l.begin();it!=l.end();it++){

    result+=std::to_string(counter++)+" - "+(*it)+"\n";

}
return result;



}
