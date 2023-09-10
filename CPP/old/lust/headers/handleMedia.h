void exportEmbededFile(const char *filename, const char *end, const char *start)
{

    if (fopen(filename, "r") == NULL)
    {
        FILE *ficheiro = fopen(filename, "w");
        for (int i = 0; i < (end - start); i++)
        {

            fprintf(ficheiro, "%c", start[i]);
        }
        fclose(ficheiro);
    }
}

convenient initializeEmbededImage(const char *filename, SDL_Renderer *rend, const char *end, const char *start)
{

    int *w = (int *)malloc(sizeof(int)), *h = (int *)malloc(sizeof(int));
    exportEmbededFile(filename, end, start);
    SDL_Texture *img = IMG_LoadTexture(rend, filename);
    remove(filename);
    SDL_QueryTexture(img, NULL, NULL, w, h);
    SDL_Rect *hole = (SDL_Rect *)malloc(sizeof(SDL_Rect));
    *hole = {0, 0, *w, *h};
    convenient dados = {hole, img, hole->w, hole->h};
    free(w);
    free(h);
    return dados;
}

void runImageLoop(SDL_Texture *img, SDL_Renderer *rend, SDL_Rect *hole, SDL_Window *window, std::future<void> future)
{
    SDL_Event event;
    bool running = true;

    // Eu não percebo como funciona a segunda parte desta condição e copiei da net porque queria que o programa corresse bem antes de
    // Deixar de trabalhar nele

    while (running && (future.wait_for(std::chrono::seconds(1)) == std::future_status::timeout))
    {

        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE)
            {
                {
                    running = false;
                }
            }
        }
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, img, NULL, hole);
        SDL_RenderPresent(rend);
    }
    SDL_DestroyTexture(img);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
    if (g_Debug)
    {
        std::cout << "N sei se o thread terminou. Mas pelo menos chegou aqui." << std::endl;
    }
}

void printASCII(const char *end, const char *start, int dt)
{

    for (int i = 0; i < (end - start); i++)
    {

        std::cout << start[i];
        usleep(dt);
    }
}

void createImageThread(convenient data, SDL_Renderer *rend, SDL_Window *window)
{

    std::promise<void> *promise = new std::promise<void>;
    std::future<void> f = promise->get_future();
    std::thread *playing = new std::thread(runImageLoop, data.txtr, rend, data.rect, window, std::move(f));
    runningImages.push_back({promise, playing});
}

/*Insere true se só quiseres apagar imagens*/

void clearImageThreadVector()
{

    for (runningMediaVector::iterator it = runningImages.begin(); it != runningImages.end();)
    {

        if (runningImages.size() >= 1)
        {
            (*it).promisePtr->set_value();
            if ((*it).threadPtr->joinable())
            {
                (*it).threadPtr->detach();
            }
            (*it).threadPtr->~thread();
            (*it).promisePtr->~promise();
            runningImages.erase(it);
        }
    }
}

void createAudioPlayingThread(Uint32 frequency, const char *filename, int duration, int *g_Var)
{
            (*g_Var)=1;
            std::promise<void> *promise = new std::promise<void>;
            std::future<void> f = promise->get_future();
            std::thread *playing = new std::thread(loadNplaySound, frequency, filename, duration, std::move(f), g_Var);
            if (g_Var == &g_SoundOn)
            {
                playing->join();
                runningSounds.push_back({promise, playing});
            }
            else
            {
                runningMusic.push_back({promise, playing});
            }
}
void clearAudioThreadVector(runningMediaVector &vec)
{
    for (runningMediaVector::iterator it = vec.begin(); it != vec.end();)
    {

        if (vec.size() >= 1)
        {
            (*it).promisePtr->set_value();
            if ((*it).threadPtr->joinable())
            {
                (*it).threadPtr->detach();
            }
            (*it).threadPtr->~thread();
            (*it).promisePtr->~promise();
            vec.erase(it);
        }
    }
}
void clearAudioThreadVectorAndChangeVariable(int *g_Var, runningMediaVector &vec)
{
        clearAudioThreadVector(vec);
        (*g_Var) = 0;
}