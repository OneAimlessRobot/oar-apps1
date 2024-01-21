#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <unistd.h>
#include <future>
#include <vector>
#include <iterator>
#include "../Includes/Crush.hpp"
#include "../Includes/Structs.h"
#include "../Includes/globals.h"
#include "../Includes/auxFuncs.h"

std::string removeNLastCharactersFromString(std::string src, int n){

    std::string::iterator it;
    int i;
    for (it = src.end() - 1, i = 0; it != src.begin() && i < n + 1; it--, i++)
    {

        if(g_Debug)
        {
            std::cout << "Posição " << it - src.begin() << " Da string" << std::endl;
        }
        src.erase(it);
    }

    return src;
}
phraseVector getLinesFromFile(std::string filepath)
{

    phraseVector vec = {};

    std::ifstream ficheiro(filepath);
    std::string placeholder;
    while (std::getline(ficheiro, placeholder))
    {

        vec.push_back(placeholder);
    }
    return vec;
}

int randNumBetZeroAnd(int lim)
{
    int num = round(((random() / ((double)RAND_MAX + 1)) * lim));
    std::cout << num << std::endl;

    return num;
}

void loading()
{

    std::cout << "loading";

    for (int i = 0; i < 3; i++)
    {
        std::cout << ".";
        sleep(1);
    }
}

void displayMenu(phraseVector menu)
{
    int index = 1;
    if (menu.size() >= 1)
    {
        for (phraseVector::iterator it = menu.begin(); it != menu.end(); it++)
        {

            if (std::next(it) == menu.end())
            {

                index = 10;
            }
            std::cout << index << "- " << *it << std::endl;
            index++;
        }
    }
    else
    {
        std::cout << "Não há opções para este menu" << std::endl;
    }
}

void displayRandomPhrase(phraseVector phraseVec)
{
    if (phraseVec.size() >= 1)
    {
        loading();
        std::cout << phraseVec[randNumBetZeroAnd(phraseVec.size())] << "\n";
        loading();
    }
    else
    {
        std::cout << "Este comando não tem frases" << std::endl;
    }
}

int inquerito(std::string demand, std::string insist, std::string otherwise)
{
    int option;

    while ((std::cout << demand && !(std::cin >> option)) || (((option) != 1) && ((option) != 0)))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << insist << std::endl;
    }
    if (option)
    {
        std::cout << otherwise << std::endl;
    }
    return option;
}
int safeMenuInput(std::string demand, phraseVector vec)
{
    int option;
    std::cout << demand << std::endl;
    displayMenu(vec);

    while (!(std::cin >> option))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return option;
}
void desabafo(int nLines, std::string filepath)
{

    std::fstream fileWriter;
    fileWriter.open(filepath, std::ios_base::app);
    std::string line;
    std::cout << "Desabafo" << std::endl;
    for (int i = 0; i < nLines; i++)
    {
        while (!(std::getline(std::cin,line)))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
        }
        if (line=="nLinhas")
        {
            std::cout << "Tens mais " << nLines - i << " linhas restantes" << std::endl;

            line=removeNLastCharactersFromString(line,line.length()+1);

            i--;
        }
        fileWriter << line << std::endl;
    }
    fileWriter.close();
}
