#include "entities.hpp"
#include "Player.hpp"
#include "audio.c"
#include <SDL2/SDL_image.h>
#include <thread>

#define WIDTH 1000
#define HEIGHT 500

int musicOn;

void tocarmusica(void)
{
    if (musicOn == 0)
    {
        initAudio();
        FILE *ficheiro2 = fopen("musica.wav", "rb");
        playMusic("musica.wav", SDL_MIX_MAXVOLUME);
        SDL_Delay(100);

        musicOn = 1;
    }
    else if (musicOn == 1)
    {
        printf("A música já está a tocar\n");
    }
}
void pararmusica(void)
{

    if (musicOn == 1)
    {

        musicOn = 0;
        endAudio();
    }
    else if (musicOn == 0)
    {

        printf("A música já parou\n");
    }
}

int main()
{

    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    int step = 10, mousex, mousey, ammo, bulletCreated = 0;

    cin >> ammo;

    SDL_Window *window = SDL_CreateWindow("OLA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, (SDL_RENDERER_TARGETTEXTURE, SDL_RENDERER_ACCELERATED));
    SDL_Texture *texture = SDL_CreateTexture(rend, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, WIDTH, HEIGHT);
    Player *player = new Player(0, 0, 30);

    Gun *gun = new Gun(player->getPlayerX(), player->getPlayerY(), 10, 10, ammo);

    const Uint8 *KEYBOARD = SDL_GetKeyboardState(NULL);

    bool running = true;
    SDL_Event event;

    while (running)
    {

        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {

                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if (ammo == 0)
                    {

                        cout << "cabou" << endl;
                    }
                    else
                    {
                        ammo--;
                        gun->fireGun(2000 * cos(atan2((mousey)-player->getPlayerY(), (mousex)-player->getPlayerX())), 2000 * sin(atan2((mousey)-player->getPlayerY(), (mousex)-player->getPlayerX())));
                    }
                }
            }
            if (event.type == SDL_KEYDOWN)
            {

                if (KEYBOARD[SDL_SCANCODE_S])
                {
                    player->movePlayerY(step);
                }

                if (KEYBOARD[SDL_SCANCODE_W])
                {

                    player->movePlayerY(-step);
                }

                if (KEYBOARD[SDL_SCANCODE_A])
                {

                    player->movePlayerX(-step);
                }
                if (KEYBOARD[SDL_SCANCODE_D])
                {

                    player->movePlayerX(step);
                }

                if (KEYBOARD[SDL_SCANCODE_S] && KEYBOARD[SDL_SCANCODE_A])
                {

                    player->movePlayerY(step);
                    player->movePlayerX(-step);
                }
                if (KEYBOARD[SDL_SCANCODE_W] && KEYBOARD[SDL_SCANCODE_A])
                {

                    player->movePlayerY(-step);
                    player->movePlayerX(-step);
                }
                if (KEYBOARD[SDL_SCANCODE_S] && KEYBOARD[SDL_SCANCODE_D])
                {

                    player->movePlayerY(step);
                    player->movePlayerX(step);
                }
                if (KEYBOARD[SDL_SCANCODE_W] && KEYBOARD[SDL_SCANCODE_A])
                {

                    player->movePlayerY(-step);
                    player->movePlayerX(-step);
                }

                if (KEYBOARD[SDL_SCANCODE_SPACE])
                {

                    cout << "Posiçao do Player: " << player->getPlayerX() << " , " << player->getPlayerY() << endl;
                }
                if (KEYBOARD[SDL_SCANCODE_ESCAPE])
                {

                    running = false;
                }
                if (KEYBOARD[SDL_SCANCODE_UP])
                {

                    ProjectileIterator *it2 = gun->idleAmmoIterator();
                    while (it2->hasNext())
                    {

                        Projectile *r = it2->next();

                        r->speedUp(1);
                    }
                }

                if (KEYBOARD[SDL_SCANCODE_DOWN])
                {

                    ProjectileIterator *it2 = gun->idleAmmoIterator();
                    while (it2->hasNext())
                    {

                        Projectile *r = it2->next();

                        r->speedDown(1);
                    }
                }

                if (KEYBOARD[SDL_SCANCODE_LEFT])
                {
                    player->shrinkPlayer(1);
                }

                if (KEYBOARD[SDL_SCANCODE_RIGHT])
                {
                    player->growPlayer(1);
                }

                if (KEYBOARD[SDL_SCANCODE_M])
                {
                    if (musicOn == 0)
                    {
                        thread worker(tocarmusica);
                        worker.detach();
                    }
                    else
                    {
                        thread worker2(pararmusica);
                        worker2.detach();
                    }
                }
            }
            if (event.type == SDL_QUIT)
            {

                running = false;
            }
        }
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_SetRenderTarget(rend, texture);
        SDL_RenderClear(rend);
        player->keepPlayerVisible(rend, &mousex, &mousey);
        gun->updateMovingProjectiles(player->getPlayerX(), player->getPlayerY());
        gun->renderFiredProjectiles(rend);
        gun->updateLaunchPositions(player->getPlayerX(), player->getPlayerY());
        ProjectileIterator *it2 = gun->firedAmmoIterator();

        while (it2->hasNext())
        {
            Projectile *r = it2->next();

            if (!r->hasColisionWithBox(&SDL_GetWindowSurface(window)->clip_rect))
            {

                r->hideProjectile();

                r->updatePosition(player->getPlayerX(), player->getPlayerY());
            }
        }

        SDL_SetRenderTarget(rend, NULL);
        SDL_RenderCopy(rend, texture, NULL, NULL);
        SDL_RenderPresent(rend);
    }
    player->destroyPlayer();
    gun->destroyGun();
    delete (gun);
    delete (player);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();
}