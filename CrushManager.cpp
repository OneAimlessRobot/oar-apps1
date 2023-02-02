#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <vector>
#include <future>
#include <thread>
#include <string>
#include <fstream>
#include "../headers/Crush.hpp"
#include "../headers/Structs.h"
#include "../headers/globals.h"
#include "../headers/CrushManager.h"
CrushManager::CrushManager(){
this->ammount=0;
this->quality=0;
}

CrushManager::CrushManager(int ammount,int quality){
this->ammount=ammount;
this->quality=quality;
}

Crush CrushManager::findCrushWithId(long long int id)
{
    Crush chosenOne;
    for(int i=0; i<this->crushes.size(); i++)
    {

        if(this->crushes[i].getId()==id)
        {

            Crush::crushCopy(&this->crushes[i],&chosenOne);

        }

    }
    return chosenOne;
}

void CrushManager::fillList()
{
    for(int i=1; i<=this->ammount; i++)
    {
        this->crushes.push_back(Crush(i));
    }
}


void CrushManager::setup()
{
    /*https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input*/
    /*std::cout<<"Não lhe queres dar um nome? (Acaba quando carregares em ENTER)"<<std::endl sempre retorna 1
    std::cin.getline(newname,80) retorna 0 num estado "mau" (input "errada")
    (com micro modificações minhas para adaptar ao que eu quero)*/
    while ((std::cout << "Escreve aqui o numero de crushes perdidas :( que queres encontrar:\n") && (!(std::cin >> (this->ammount)) || ((this->ammount) <= 0)))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    while ((std::cout << "Qual é a qualidade de crush que desejas?\n") && (!(std::cin >> (this->quality)) || ((this->quality) <= 0 || (this->quality) > 100)))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int CrushManager::afterResults()
{
    int id;
    /*https://stackoverflow.com/questions/10349857/how-to-handle-wrong-data-type-input*/
    /*std::cout<<"Não lhe queres dar um nome? (Acaba quando carregares em ENTER)"<<std::endl sempre retorna 1
    std::cin.getline(newname,80) retorna 0 num estado "mau" (input "errada")
    (com micro modificações minhas para adaptar ao que eu quero)*/

    while ((std::cout << "Queres dar casa a alguma delas :(? Por favor? (Insere o identificador)" << std::endl) && (!(std::cin >> id) || (id<crushes[0].getId()||id>crushes.size())))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
        std::cout << "Ainda não a encontraste :(" << std::endl;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return id;
}

Crush CrushManager::contestOfIQLonely()
{

    Crush best=Crush();
    for (Crush i:this->crushes)
    {

        if (i.getIQ()> best.getIQ())
        {
            Crush::crushCopy(&i,&best);
        }
    }
    return best;
}

Crush CrushManager::contestOfEQLonely()
{
    Crush best= Crush();
    for (Crush i:this->crushes)
    {

        if (i.getEQ()>best.getEQ())
        {
            Crush::crushCopy(&i,&best);
        }
    }
    return best;
}


Crush CrushManager::contestOfStrengthLonely()
{
    Crush best= Crush();
    for (Crush i:this->crushes)
    {

        if (i.getStrength()>best.getStrength())
        {
            Crush::crushCopy(&i,&best);
        }
    }
    return best;
}
Crush CrushManager::cyclistTestLonely(){

    Crush best= Crush();
    for (Crush i:this->crushes)
    {

        if (i.getStrength()>best.getStrength()&&i.getWeight()<best.getWeight())
        {
            Crush::crushCopy(&i,&best);
        }
    }
    return best;

}

Crush CrushManager::getSpecialcrushes()
{
    int crushCount = 0, specialCount = 0, currentIqSum = 0,currentStrengthSum=0;
    Crush best = Crush();
    for (Crush i:this->crushes)
    {
        currentIqSum += i.getIQ();
        currentStrengthSum += i.getStrength();
        crushCount++;
        if (i.getIQ() > round((double)currentIqSum / crushCount) && (i.getEQ() > (this->quality)))
        //&& i.getStrength() > round((double)currentStrengthSum / crushCount)
        {
            Crush::crushCopy(&i,&best);
            specialCount++;
        }
    }
    std::cout << specialCount << " das " << crushCount << " crushes são especiais ;)\n";
    return best;
}