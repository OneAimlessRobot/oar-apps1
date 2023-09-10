
/*pre: chance E [0,1)*/
static int g_Debug=0;

static double g_ChanceOfFailure=0.8;

static int g_Accepted=0;

static int g_MusicOn=0;

static int g_SoundOn=0;


#define MAX_LENGTH (128)
#define EXIT (10)



phraseVector cuddlingOptions = {"Lamber-lhe e beijá-la nos seios?",
                                "Tocar-lhe na.... &$# de forma repetida?",
                                "Dar-lhe uma festinha no rosto e dar-lhe um beijinho",
                                "Voltar ao menu"};
phraseVector kissingOptions = {"Na boca?",
                               "Na %%$#!?",
                               "Na barriguinha?",
                               "Na cara?",
                               "Voltar ao menu"};
phraseVector mediaOptions = {"Parar imagens",
                               "Parar música",
                               "Voltar ao menu"};

phraseVector randomPhraseOptions={
    "Dizer algo...fofo",
    "Dizer algo profundo",
    "Dizer algo engraçado",
    "Voltar ao menu"};
phraseVector mainMenuOptions = {
    "Podes beijá-la",
    "Dizer algo",
    "Despir-se para ti ;)",
    "Humilhar-te",
    "Podes acariciá-la",
    "Podes tocar musica ;)",
    "Parar media.",
    "Características.",
    "Desabafo.",
    "E podes sair... se não tiveres coração e a quiseres deixar perdida no meio da tua memória fria e confusa >P"};

phraseVector courses = {
    "Engenharia Biomédica",
    "Engenharia Informática",
    "Psicologia",
    "Economia",
    "Matemática",
    "Engenharia Mecânica"
    };




runningMediaVector runningImages = {};
runningMediaVector runningSounds = {};
runningMediaVector runningMusic = {};


FileStreamVector images={
{_binary_resources_embeded_img1_start,_binary_resources_embeded_img1_end,_binary_resources_embeded_img1_size},
{_binary_resources_embeded_img2_start,_binary_resources_embeded_img2_end,_binary_resources_embeded_img2_size},
{_binary_resources_embeded_img3_start,_binary_resources_embeded_img3_end,_binary_resources_embeded_img3_size}
};


const static std::string passwordToMatch=removeNLastCharactersFromString(_binary_resources_embeded_password_start,6);