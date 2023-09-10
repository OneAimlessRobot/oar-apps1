int menu(crush chosenOne)
{
    int kissingOption, wtfAmICoding, mainOption, worship, howLongHaveIBeenWorkingOnThis, mediaType;

    sleep(1);

    mainOption = safeMenuInput("MENU", mainMenuOptions);
// MENU PRINCIPAL--------------------------------------------------------------------------------------------------------------------------------------------------------------
    switch (mainOption)
    {
    case 1:
        loading();

        kissingOption = safeMenuInput("Hmmmmm... Escolheste beijá-la ;). Onde é que o vais fazer?", kissingOptions);

        switch (kissingOption)
        {
        case 1:
        {
            exportEmbededFile("sfile4", _binary_resources_embeded_kissing2_end, _binary_resources_embeded_kissing2_start);
            createAudioPlayingThread(44100, "sfile4", 19000, &g_SoundOn);
            std::cout << "Hmmm... sabes tão bem...\n";
        }

        break;
        case 2:
            usleep(500000);

            std::cout << "\a\n";
            kissPlusMoan(1000000, "AI CÉUS QUE BOM! MESMO aí.....");
            break;
        case 3:
            kissPlusMoan(1000000, "Que bommmmmm... adoro este calorzinho....");
            break;
        case 4:
            kissPlusMoan(1000000, "Ohhh... foi.... suave....");
            break;
        case EXIT:
        {
            break;
        }
        break;
        default:
            break;
        }
        break;
        //FIM DO MENU DE BEIJOS-------------------------------------------------------------------------------
        //INICIO DO MENU DE FRASES ALEATORIAS-------------------------------------------------------------------------------
    case 2:
    {

            wtfAmICoding = safeMenuInput("Ok, o que queres que ela diga", randomPhraseOptions);
        switch (wtfAmICoding)
        {
        case 1:
        {

            wtfAmICoding = inquerito("Estás pronto?(0=não e 1=SIM!)\n", "tsc, tsc, tsc.... Tens de responder sim ou não. Não )faças rodeios...Ou eu perco a paciência\n", "Não te preocupes, coisa boa:) Todos levam o seu tempo...\n");

            if (wtfAmICoding)
            {
                displayRandomPhrase(getLinesFromFile("resources/phrases/hornySetences.txt"));
            }
        }
        break;
        case 2:
        {
            displayRandomPhrase(getLinesFromFile("resources/phrases/deepSetences.txt"));
        }
        break;

        break;
        case 3:
        {
            displayRandomPhrase(getLinesFromFile("resources/phrases/funnySetences.txt"));
        }
        break;
        case 4:
        {
            displayRandomPhrase(getLinesFromFile("resources/phrases/funnySetences.txt"));
        }
        break;
        case EXIT:
        {
            break;
        }
        break;
        default:
        {
            break;
        }
        }
    }
    break;
    //FIM DO MENU DE FRASES ALEATORIAS-------------------------------------------------------------------------------
    //INCIO DO MENU DE... STRIP TEASE-------------------------------------------------------------------------------

    case 3:
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
    case 4:
    {

        SDL_Window *window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 10, 10, SDL_WINDOW_RESIZABLE);
        SDL_Renderer *rend = SDL_CreateRenderer(window, -1, (SDL_RENDERER_TARGETTEXTURE, SDL_RENDERER_SOFTWARE));

        embededFileStream img = images[randNumBetZeroAnd(images.size() - 1)];
        convenient data = initializeEmbededImage("ifile1", rend, img.end, img.start);
        SDL_SetWindowSize(window, data.w, data.h);
        createImageThread(data, rend, window);
    }
    break;

    //FIM DO MENU DE IMAGENS ALEATORIAS-------------------------------------------------------------------------------
    //INCIO DO MENU DE CARÍCIAS-------------------------------------------------------------------------------
    case 5:
    {
        loading();

        wtfAmICoding = safeMenuInput("Ok, então escolheste acariciá-la.... Como é que o preferes fazer? Preferes...:", cuddlingOptions);

        switch (wtfAmICoding)
        {
        case 1:
            printASCII(_binary_resources_embeded_file3_txt_end, _binary_resources_embeded_file3_txt_start, 1000);

            sleep(1);

            std::cout << "\nPodes começar;)\n";
            kissPlusMoan(1000000, "Ai céus, isso sabe tão bem...continua.");
            kissPlusMoan(1000000, "Ai céus! Que BOM!.");
            kissesAndMoans(1000000, 6, "Vai!");
            std::cout << "\n(...)\n";

            sleep(1);

            std::cout << "Ai que BOOOOOMMMMMMMM!.\a\n";
            break;
        case 2:
        {
            acceleratingMoans(1000000, 6, 150000, "Ai que bom.");
            kissPlusMoan(1000000, "Ai que booooooommmmmm....Mesmo aí.... A mamã gosta..... ai céus...");
            kissPlusMoan(2000000, "AIIII.... esse foi mais longo");
            kissPlusMoan(3000000, "AIIIIIIIII que delIIICIAAA!!!!! CONTINUA! NÃO PARES!!!!");
            printASCII(_binary_resources_embeded_file2_txt_end, _binary_resources_embeded_file2_txt_start, 1500);
            std::cout << "\nAI CEUS!\n";

            exportEmbededFile("sfile1", _binary_resources_embeded_splash_end, _binary_resources_embeded_splash_start);
            createAudioPlayingThread(44100, "sfile1", 6000, &g_SoundOn);

            sleep(1);

            kissesAndMoans(400000, 3, "Vai!");
            kissesAndMoans(150000, 6, "VAI!");
            std::cout << "\n(...)\n";

            sleep(1);

            std::cout << "VAIII! VAIIII VAIIIII!!!!\n";
            kissesAndMoans(50000, 19, "SIM!");

            sleep(1);

            std::cout << "PÁRA! PÁRA! PÁRA! Senão acaba muito rápido.... faz outra coisa antes que eu inunde a memória do teu computador\n";

            sleep(1);
        }

        break;
        case 3:
        {
            exportEmbededFile("sfile2", _binary_resources_embeded_kissing_end, _binary_resources_embeded_kissing_start);
            createAudioPlayingThread(44100, "sfile2", 7000, &g_SoundOn);
            std::cout << "\n(...)\nOhhh....\nOh.... isso foi..\n\n.. gracioso...\n";
        }
        break;
        case EXIT:
        {
            break;
        }
        break;
        default:
        {
            break;
        }
        }
    }
    break;

    //FIM DO MENU DE CARÍCIAS-------------------------------------------------------------------------------
    //INCIO DO MENU DE MUSICA-------------------------------------------------------------------------------
   
    case 6:
    {
        if(!g_MusicOn){

        exportEmbededFile("sfile3", _binary_resources_embeded_musica_end, _binary_resources_embeded_musica_start);
        createAudioPlayingThread(22050, "sfile3", 1000000,&g_MusicOn);
        }
        else{
            std::cout<<"A musica já está ativa"<<std::endl;
        }
    }
    break;

    //FIM DO MENU DE MUSICA-------------------------------------------------------------------------------
    //INCIO DO MENU DE MEDIA-------------------------------------------------------------------------------
    case 7:
    {
        wtfAmICoding = safeMenuInput("Escolhe o tipo de media que queres parar:", mediaOptions);
        switch (wtfAmICoding)
        {
        case 1:
        {

            clearImageThreadVector();
        }
        break;
        case 2:
        {
            if(g_MusicOn){

            clearAudioThreadVectorAndChangeVariable(&g_MusicOn, runningMusic);
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
    case 8:
    {
        std::cout<<"IQ= "<<chosenOne.iq<<std::endl;
        std::cout<<"EQ= "<<EQN(chosenOne)<<std::endl;
        std::cout<<"nome= "<<chosenOne.name<<std::endl;
    }
    break;

    //FIM DO MENU DE CARACTERISTICAS-------------------------------------------------------------------------------
    //INCIO DO MENU DE DESABAFOS------------------------------------------------------------------------------
    case 9:
    {
        int nLines;
    while (std::cout << "Insere o numero de linhas" << std::endl && !(std::cin >> nLines) || nLines<=0)
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
