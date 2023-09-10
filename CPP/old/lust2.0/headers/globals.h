
/*pre: chance E [0,1)*/
static int
g_Accepted=0,
g_MusicOn=0,
g_SoundOn=0,
g_numOfCrushes,
g_Option,
g_Attempts = 0;
static double requiredEq;

#define EXIT (10)

phraseVector mediaOptions = {"Parar imagens",
                               "Parar música",
                               "Voltar ao menu"};
phraseVector mainMenuOptions = {
    "Despir-se para ti ;)",
    "Humilhar-te",
    "Podes acariciá-la",
    "Podes tocar musica ;)",
    "Parar media.",
    "Características.",
    "Desabafo.",
    "E podes sair... se não tiveres coração e a quiseres deixar perdida no meio da tua memória fria e confusa >P"};



runningMediaVector runningImages = {};
runningMediaVector runningSounds = {};
runningMediaVector runningMusic = {};


FileStreamVector images={
{_binary_resources_embeded_img1_start,_binary_resources_embeded_img1_end},
{_binary_resources_embeded_img2_start,_binary_resources_embeded_img2_end},
{_binary_resources_embeded_img3_start,_binary_resources_embeded_img3_end},
{_binary_resources_embeded_img5_start,_binary_resources_embeded_img5_end},
{_binary_resources_embeded_img6_start,_binary_resources_embeded_img6_end},
{_binary_resources_embeded_img7_start,_binary_resources_embeded_img7_end},
{_binary_resources_embeded_img8_start,_binary_resources_embeded_img8_end},
{_binary_resources_embeded_img9_start,_binary_resources_embeded_img9_end},
{_binary_resources_embeded_img10_start,_binary_resources_embeded_img10_end},
{_binary_resources_embeded_img11_start,_binary_resources_embeded_img11_end},
{_binary_resources_embeded_img4_start,_binary_resources_embeded_img4_end}
};

FileStreamVector music={
{_binary_resources_embeded_musica_start,_binary_resources_embeded_musica_end,22050},
{_binary_resources_embeded_musica2_start,_binary_resources_embeded_musica2_end,44100},
{_binary_resources_embeded_musica3_start,_binary_resources_embeded_musica3_end,44100}
};



const static std::string passwordToMatch=removeNLastCharactersFromString(_binary_resources_embeded_password_start,6);

crushVector crushes={};
