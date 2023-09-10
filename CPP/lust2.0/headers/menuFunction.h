int menu(crush& chosenOne)
{
    int wtfAmICoding, mainOption;

    sleep(1);

    mainOption = safeMenuInput("MENU", mainMenuOptions);
// MENU PRINCIPAL--------------------------------------------------------------------------------------------------------------------------------------------------------------
    switch (mainOption)
    {
    case 1:
    {
        printASCII(_binary_resources_embeded_file_txt_end, _binary_resources_embeded_file_txt_start, 1500);

        wtfAmICoding = inquerito("\nCá estou eu, fofo. Gostas do que vês?\n\n1- OH..MEU...DEUS...SIM!!!!!\n0- N... Não...\n", "Não te preocupes, coisa boa:) Todos levam o seu tempo...\n", "\0");

        if (wtfAmICoding)
        {
            std::cout << "Eu sabia que não me irias resistir...\n";
        }
        else
        {
            std::cout << "Pára de fingir! :|\n";
        }
    }
    break;

    //FIM DO MENU DE STRIP TEASE-------------------------------------------------------------------------------
    //INCIO DO MENU DE IMAGENS ALEATORIAS-------------------------------------------------------------------------------
    case 2:
    {
    spawnRandomImage();
    }
    break;

    //FIM DO MENU DE IMAGENS ALEATORIAS-------------------------------------------------------------------------------
    //INCIO DO MENU DE CARÍCIAS-------------------------------------------------------------------------------
    case 3:
    {
        std::cout<<"Uiiiii ;) Escolheste roleplay..."<<std::endl;
        roleplay();

    }
    break;

    //FIM DO MENU DE CARÍCIAS-------------------------------------------------------------------------------
    //INCIO DO MENU DE MUSICA-------------------------------------------------------------------------------

    case 4:
    {
        if(!g_MusicOn){

        embededFileStream img= music[randNumBetZeroAnd(music.size() - 1)];
        exportEmbededFile("2",img.end,img.start);
        createAudioPlayingThread(img.freq, "2", 1000000,&g_MusicOn);
        }
        else{
            std::cout<<"A musica já está ativa"<<std::endl;
        }
    }
    break;

    //FIM DO MENU DE MUSICA-------------------------------------------------------------------------------
    //INCIO DO MENU DE MEDIA-------------------------------------------------------------------------------
    case 5:
    {
        wtfAmICoding = safeMenuInput("Escolhe o tipo de media que queres parar:", mediaOptions);
        switch (wtfAmICoding)
        {
        case 1:
        {

            clearMediaThreadVector(runningImages);
        }
        break;
        case 2:
        {
            if(g_MusicOn){

            clearMediaThreadVectorAndChangeVariable(&g_MusicOn, runningMusic);
            }
            else{
                std::cout<<"Já n ha musica"<<std::endl;
            }
        }
        break;
        case EXIT:
        {
        }
        break;
        default:
        {
            break;
        }
        }
    }
    break;

    //FIM DO MENU DE MEDIA-------------------------------------------------------------------------------
    //INCIO DO MENU DE CARACTERISTICAS-------------------------------------------------------------------------------
    case 6:
    {
        std::cout<<"IQ= "<<chosenOne.getIQ()<<std::endl;
        std::cout<<"EQ= "<<chosenOne.getEQ()<<std::endl;
        std::cout<<"nome= "<<chosenOne.getName()<<std::endl;
    }
    break;

    //FIM DO MENU DE CARACTERISTICAS-------------------------------------------------------------------------------
    //INCIO DO MENU DE DESABAFOS------------------------------------------------------------------------------
    case 7:
    {
        int nLines;
    while ((std::cout << "Insere o numero de linhas" << std::endl) && (!(std::cin >> nLines) || nLines<=0))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
    }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        desabafo(nLines,"resources/phrases/desabafos.txt");
    }
    break;
    case 11:
    {
        if (g_Debug)
        {
            std::cout << "g_MusicOn= " << g_MusicOn << std::endl;
            std::cout << "g_SoundOn= " << g_SoundOn << std::endl;
            std::cout << "tamanho de runningImages= " << runningImages.size() << std::endl;
            std::cout << "tamanho de runningSounds= " << runningSounds.size() << std::endl;
            std::cout << "tamanho de runningMusic= " << runningMusic.size() << std::endl;
        }
    }
    break;

    //OPÇÃO DE SAIR-------------------------------------------------------------------------------
    case (EXIT):
    {
        putchar(263);
        std::cout << "\nSEU MAU!!!!! >P\n";
    }
    break;
    default:
    {
        break;
    }
    }
    return mainOption;

    //FIM DO MENU PRICIPAL
}
