
#include "../newLust/newLust/headers/audio.h"


#include <SDL2/SDL.h>

#include <iostream>
#include <thread>
#include <unistd.h>

void playBeep(int nTimes,int mSecPeriod);
int main(int argc, char **argv){

SDL_Init(SDL_INIT_EVERYTHING);
    if(argc<3){
        std::cout<<"Precisas de meter numero de vezes e periodo em microsegundos.\n";
        return 1;

    }
    else {

    playBeep(std::stoi(argv[1]),std::stoi(argv[2]));
    }



SDL_Quit();
return 0;
}


void playBeep(int nTimes,int mSecPeriod){

    initAudio(48000);

for(int i=0; i<nTimes;i++){



    playMusic("/home/k/beep/beep.wav", SDL_MIX_MAXVOLUME);
    SDL_Delay(mSecPeriod);

}

    endAudio();



}
