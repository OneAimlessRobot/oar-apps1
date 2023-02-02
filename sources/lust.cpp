#include "../headers/includesAndDefs.h"


void printResultsToCSV(CrushManager mgr);
//
//int main(){
//
//std::cout<<"Compilei!\n";
//
//}

int main(int argc, char *argv[])
{
    std::string myInput,newname;
    Crush escolhida = Crush();

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

    CrushManager mgr= CrushManager();

    mgr.setup();

    mgr.fillList();

    printResultsToCSV(mgr);
    Crush results = mgr.getSpecialcrushes();

    Crush smart=mgr.contestOfIQLonely(),
                kind=mgr.contestOfEQLonely(),
                aerobic=mgr.cyclistTestLonely(),
                strong=mgr.contestOfStrengthLonely();

    std::cout << "A crush mais inteligente é " << smart.getId() <<" com "<<smart.getIQ()<<" de QI."<< std::endl;
    std::cout << "A crush mais disponível é " << kind.getId() <<" com "<<kind.getEQ()<<" de QE."<< std::endl;
    std::cout << "A crush mais forte é " << strong.getId() <<" com "<<strong.getStrength()<<" de percentagem de força."<< std::endl;
    std::cout << "A melhor ciclista é " << aerobic.getId() <<" com:\n"<<aerobic.getStrength()<<" de percentagem de força e\n"<<aerobic.getWeight()<<"kg de massa."<< std::endl;
    std::cout << "A crush mais well-rounded é " << results.getId() << std::endl;

    int chosenId = mgr.afterResults();

    escolhida = mgr.findCrushWithId(chosenId);
    newname = getFilteredInput(newname, "Não lhe queres dar um nome? (Acaba quando carregares em ENTER)");

    escolhida.rename(newname);
    std::cout << "UUiiiii que fofo.... ela agora chama-se " << escolhida.getName() << std::endl;

    if (g_Debug)
    {

        std::cout << "debug ON" << std::endl;

        do
        {
            g_Option = menu(escolhida);
        }
        while (g_Option != EXIT);

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
            }
            while (g_Option != EXIT);
        }
    }
    clearMediaThreadVector(runningSounds);
    clearMediaThreadVector(runningImages);
    clearMediaThreadVector(runningMusic);

    SDL_Quit();
    if (g_Debug)
    {
        std::cout << "g_MusicOn= " << g_MusicOn << std::endl;
        std::cout << "g_SoundOn= " <<g_SoundOn << std::endl;
        std::cout << "tamanho de runningImages= " << runningImages.size() << std::endl;
        std::cout << "tamanho de runningSounds= " << runningSounds.size() << std::endl;
        std::cout << "tamanho de runningMusic= " << runningMusic.size() << std::endl;
    }
    return 0;
}


void printResultsToCSV(CrushManager mgr)
{
    std::ofstream dataBase("crushes.csv");
    dataBase << "ID,FORÇA,IQ,EQ,ALTURA,MASSA\n";
    for (Crush i : mgr.crushes)
    {
        i.printCrushFileLine(dataBase);
    }
    dataBase.close();
}


