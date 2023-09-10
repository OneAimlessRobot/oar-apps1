#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <thread>
#include <vector>
#include <limits>
#include <future>
#include <chrono>

#include "headers/audio.c"

#include "headers/fileBinaries.h"
#include "headers/auxiliaryStrutsAndFuncs.h"
#include "headers/globals.h"
#include "headers/CrushStructOperations.h"
#include "headers/auxiliaryMenuStuff.h"
#include "headers/handleList.h"
#include "headers/handleSounds.h"
#include "headers/handleMedia.h"
#include "headers/menuFunction.h"

void printResultsToCSV(double *minEq, lonely *cabecinha);

int main(int argc, char*argv[])
{
    
    if(argc>1&&strcmp(argv[1],"debug")==0){
        g_Debug=1;
    }

    int *numOfCrushes = (int *)malloc(sizeof(int)), option,attempts=0;
    double *requiredEq = (double *)malloc(sizeof(double));
    std::string myInput;
    crush preferida;
    lonely *inicio = NULL, escolhida;
    SDL_Init(SDL_INIT_EVERYTHING);
    initAudio(44100);
    srand(time(NULL));

    if(!g_Debug){
    while (std::cout << "Insere a pass se fores mais de 18" << std::endl && !(std::cin >> myInput) || myInput!=passwordToMatch)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
        std::cout << "passwordIncorreta" << std::endl;
        attempts++;
        if(attempts>=3){
            return 1;
        }
    }
    }

    setup(numOfCrushes, requiredEq);

    inicio = criarlista(inicio, *numOfCrushes);

    if (inicio == NULL)
    {
        return 1;
    }

    printResultsToCSV(requiredEq, inicio);
    throwaway results = getSpecialCrushes(requiredEq, inicio);

    std::cout << "A crush mais inteligente é " << contestOfIQLonely(inicio).modelNo << std::endl;
    std::cout << "A crush mais disponível é " << contestOfEQLonely(inicio).modelNo << std::endl;
    std::cout << "A crush mais well-rounded é " << results.needy.modelNo << std::endl;
    int chosenId = afterResults(inicio, results.ammountOspecial, *numOfCrushes);

    escolhida = findCrushWithId(chosenId,inicio, numOfCrushes);

    destroyList(inicio);

    preferida = convertAndRename(escolhida, MAX_LENGTH);

   if(g_Debug){

       std::cout<<"debug ON"<<std::endl;
       g_Accepted=1;
   }
   else{
       
       g_Accepted =pergunta(preferida.name);

   }
    if (g_Accepted)
    {
        do
        {
            option = menu(preferida);
        } while (option != EXIT);
    }
    clearAudioThreadVector(runningSounds);
    clearImageThreadVector();
    clearAudioThreadVector(runningMusic);
    
    if(g_MusicOn){
    endAudio();
    }
    SDL_Quit();
    free(requiredEq);
    free(numOfCrushes);
}

void printResultsToCSV(double *minEq, lonely *cabecinha)
{
    std::ofstream dataBase("crushes.csv");
    dataBase << "ID,IQ,EQ\n";
    for (lonely *tmp = cabecinha; tmp != NULL; tmp = tmp->phoneNo)
    {
        printLonelyCrushFileLine(*tmp, dataBase);
    }
    dataBase.close();
}
