#include <iostream>
#include <fstream>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <limits>
#include <future>
#include <chrono>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

#include "headers/audio.c"

#include "headers/fileBinaries.h"
#include "headers/classesAndAuxiliaryStuff.h"
#include "headers/globals.h"
#include "headers/auxiliaryMenuStuff.h"
#include "headers/handleList.h"
#include "headers/handleSounds.h"
#include "headers/handleMedia.h"
#include "headers/roleplay.h"
#include "headers/menuFunction.h"

void printResultsToCSV(double *minEq);

int main(int argc, char *argv[])
{
    std::string myInput,newname;
    crush escolhida = crush();

    if (argc > 1 && strcmp(argv[1], "debug") == 0)
    {
        g_Debug = 1;
    }

    SDL_Init(SDL_INIT_EVERYTHING);
    srand(time(NULL));

    if (!g_Debug)
    {
        while ((std::cout << "Insere a pass se fores mais de 18" << std::endl) && (!(std::cin >> myInput) || myInput != passwordToMatch))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
            std::cout << "passwordIncorreta" << std::endl;
            g_Attempts++;
            if (g_Attempts >= 3)
            {
                return 1;
            }
        }
    }

    setup(&g_numOfCrushes, &requiredEq);

    fillList(g_numOfCrushes);

    printResultsToCSV(&requiredEq);
    throwaway results = getSpecialCrushes(&requiredEq);

    std::cout << "A crush mais inteligente é " << contestOfIQLonely().getId() << std::endl;
    std::cout << "A crush mais disponível é " << contestOfEQLonely().getId() << std::endl;
    std::cout << "A crush mais well-rounded é " << results.result.getId() << std::endl;

    int chosenId = afterResults(results.value);

    escolhida = findCrushWithId(chosenId);
    newname = getFilteredInput(newname, "Não lhe queres dar um nome? (Acaba quando carregares em ENTER)");

    escolhida.rename(newname);
    std::cout << "UUiiiii que fofo.... ela agora chama-se " << escolhida.getName() << std::endl;

    if (g_Debug)
    {

        std::cout << "debug ON" << std::endl;

        do
        {
            g_Option = menu(escolhida);
        } while (g_Option != EXIT);

    }
    else
    {

        g_Accepted = escolhida.pergunta();

    if (g_Accepted)
    {
        escolhida.flirt();
        do
        {
            g_Option = menu(escolhida);
        } while (g_Option != EXIT);
    }
    }
    clearMediaThreadVector(runningSounds);
    clearMediaThreadVector(runningImages);
    clearMediaThreadVector(runningMusic);

    SDL_Quit();
        if (g_Debug)
        {
            std::cout << "g_MusicOn= " << g_MusicOn << std::endl;
            std::cout << "g_SoundOn= " << g_SoundOn << std::endl;
            std::cout << "tamanho de runningImages= " << runningImages.size() << std::endl;
            std::cout << "tamanho de runningSounds= " << runningSounds.size() << std::endl;
            std::cout << "tamanho de runningMusic= " << runningMusic.size() << std::endl;
        }
        return 0;
}

void printResultsToCSV(double *minEq)
{
    std::ofstream dataBase("crushes.csv");
    dataBase << "ID,IQ,EQ\n";
    for (crush i : crushes)
    {
        i.printCrushFileLine(dataBase);
    }
    dataBase.close();
}
