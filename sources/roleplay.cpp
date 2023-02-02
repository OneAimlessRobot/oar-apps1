#include <SDL2/SDL.h>
#include <iostream>
#include <iterator>
#include <future>
#include <vector>
#include <thread>
#include <string>
#include <unistd.h>
#include "../headers/Crush.hpp"
#include "../headers/Structs.h"
#include "../headers/auxFuncs.h"
#include "../headers/globals.h"
#include "../headers/fileBinaries.h"
#include "../headers/roleplay.h"
#include "../headers/handleMedia.h"
#include "../headers/handleSounds.h"
void roleplay()
{

    phraseVector vec=getLinesFromFile("resources/phrases/roleplay.txt");

    for(phraseVector::iterator it=vec.begin(); it!=vec.end(); it++)
    {
        if((*it)=="(*kiss*)")
        {
            int number=std::stoi((*(it+1))),
                dt=std::stoi((*(it+2)));
            kissesAndMoans(dt,number,(*(it+3)));
            it=it+3;
        }
        else if((*it)=="(*orgasmo dela*)")
        {

            printASCII(_binary_resources_embeded_file2_txt_end, _binary_resources_embeded_file2_txt_start, 1500);
            std::cout << "\nAI CEUS!\n";

            exportEmbededFile("3", _binary_resources_embeded_splash_end, _binary_resources_embeded_splash_start);
            createAudioPlayingThread(44100, "3", 2000, &g_SoundOn);
        }
        else if((*it)=="(*estimulos na vagina*)")
        {

            int number=std::stoi((*(it+1))),
                dt=std::stoi((*(it+2))),
                dtSub=std::stoi((*(it+3)));
            acceleratingMoans(dt,number,dtSub,(*(it+4)));
            it=it+4;
        }

        else if((*it)=="(*orgasmo meu*)")
        {

            std::cout << "\nAI CEUS! Ohh... vieste-te, fofo...\n";
        }
        else if((*it)=="(*sleep*)")
        {
            usleep(std::stoi((*(it+1))));
            it++;
        }
        else if((*it)=="(*long kissing noises*)")
        {

            exportEmbededFile("4", _binary_resources_embeded_kissing2_end, _binary_resources_embeded_kissing2_start);
            createAudioPlayingThread(44100, "4", 19000, &g_SoundOn);
            std::cout << "Hmmm... sabes tão bem...\n";
        }
        else
        {
            std::cout<<(*it)<<std::endl;
        }
    }

}
