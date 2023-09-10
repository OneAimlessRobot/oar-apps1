

typedef struct
{

    SDL_Rect *rect;
    SDL_Texture *txtr;
    int w;
    int h;
} convenient;

convenient initializeEmbededImage(const char *filename, SDL_Renderer *rend)
{

    int *w = new int(1), *h = new int(1);
    SDL_Texture *img = IMG_LoadTexture(rend, filename);
    remove(filename);
    SDL_QueryTexture(img, NULL, NULL, w, h);
    SDL_Rect *hole = new SDL_Rect();
    *hole = {0, 0, *w, *h};
    convenient dados = {hole, img, hole->w, hole->h};
    delete w;
    delete h;
    return dados;
}


void runImageLoop(convenient data, SDL_Renderer *rend, SDL_Window *window)
{
    SDL_Event event;
    bool running = true;

    // Eu não percebo como funciona a segunda parte desta condição e copiei da net porque queria que o programa corresse bem antes de
    // Deixar de trabalhar nele

    while (running)
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
        SDL_RenderCopy(rend, data.txtr, NULL, data.rect);
        SDL_RenderPresent(rend);
    }
    SDL_DestroyTexture(data.txtr);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);
}
