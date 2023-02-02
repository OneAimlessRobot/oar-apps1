#include <iostream>
#include <string>
#include <unistd.h>
#include <thread>
#include <future>
#include <vector>
#include "../headers/audio.h"
#include "../headers/Crush.hpp"
#include "../headers/Structs.h"
#include "../headers/globals.h"
#include "../headers/auxFuncs.h"
#include "../headers/handleSounds.h"

void kissPlusMoan(int dt2, std::string sentence)
{

    usleep(dt2);
    std::cout << "\n(...)\n";
    usleep(dt2);
    std::cout << sentence << "\a\n";
}

void kissesAndMoans(int dt2, int repeats, std::string sentence)
{

    for (int z = 0; z <= repeats; z++)
    {
        kissPlusMoan(dt2, sentence);
    }
}

void acceleratingMoans(int dt, int repeats, int dtSubtract, std::string sentence)
{

    for (int z = 0; z <= repeats; z++, dt = dt - dtSubtract)
    {
        kissPlusMoan(dt, sentence);
    }
}

void loadNplaySound(Uint32 freq,const char*filename,int time,std::future<void> future,int *g_Var)
{

    initAudio(freq);
    playMusic(filename, SDL_MIX_MAXVOLUME);
    remove(filename);
    int i=0;
    while(future.wait_for(std::chrono::milliseconds(1))==std::future_status::timeout&&i<time)
    {

        i++;
    }
    endAudio();
    (*g_Var)=0;


    if(g_Debug)
    {
        std::cout<<"Thread de som terminou"<<std::endl;
        std::cout<<"O valor da variavel é= "<<(*g_Var)<<std::endl;
    }
}
