
#include<SDL2/SDL.h>
#include<vector>
#include<future>
#include<thread>
#include <string>
#include <fstream>
#include"../Includes/Crush.hpp"
#include "../Includes/Structs.h"
#include "../Includes/auxFuncs.h"
#include "../Includes/fileBinaries.h"
#include "../Includes/globals.h"


char * passwordToMatch = "1234";
int
g_Accepted=0,
g_MusicOn=0,
g_SoundOn=0,
g_Option=0,
g_Debug=0,
g_Attempts=0;

phraseVector mediaOptions =
{
    "Parar imagens",
    "Parar música",
    "Voltar ao menu"
};
phraseVector mainMenuOptions =
{
    "Despir-se para ti ;)",
    "Humilhar-te",
    "Podes acariciá-la",
    "Podes tocar musica ;)",
    "Parar media.",
    "Características.",
    "Desabafo.",
    "E podes sair... se não tiveres coração e a quiseres deixar perdida no meio da tua memória fria e confusa >P"
};



runningMediaVector runningImages = {},
                   runningSounds = {},
                   runningMusic = {};


FileStreamVector images=
{
    {_binary_resources_embeded_img1_res_start,_binary_resources_embeded_img1_res_end},
    {_binary_resources_embeded_img2_res_start,_binary_resources_embeded_img2_res_end},
    {_binary_resources_embeded_img3_res_start,_binary_resources_embeded_img3_res_end},
    {_binary_resources_embeded_img5_res_start,_binary_resources_embeded_img5_res_end},
    {_binary_resources_embeded_img6_res_start,_binary_resources_embeded_img6_res_end},
    {_binary_resources_embeded_img7_res_start,_binary_resources_embeded_img7_res_end},
    {_binary_resources_embeded_img8_res_start,_binary_resources_embeded_img8_res_end},
    {_binary_resources_embeded_img9_res_start,_binary_resources_embeded_img9_res_end},
    {_binary_resources_embeded_img10_res_start,_binary_resources_embeded_img10_res_end},
    {_binary_resources_embeded_img11_res_start,_binary_resources_embeded_img11_res_end},
    {_binary_resources_embeded_img4_res_start,_binary_resources_embeded_img4_res_end}
},

music=
{
    {_binary_resources_embeded_musica_res_start,_binary_resources_embeded_musica_res_end,22050},
    {_binary_resources_embeded_musica2_res_start,_binary_resources_embeded_musica2_res_end,44100},
    {_binary_resources_embeded_musica3_res_start,_binary_resources_embeded_musica3_res_end,44100}
};



