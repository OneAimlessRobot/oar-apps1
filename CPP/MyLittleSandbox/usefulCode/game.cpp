#include <SDL2/SDL.h>
#include <stdlib.h>
#include <iostream>
#include "../Includes/entities.hpp"
#include "../Includes/Projectile.hpp"
#include "../Includes/ProjectileIterator.hpp"
#include "../Includes/VolleyGenerator.hpp"
#include "../Includes/Player.hpp"

using namespace std;
#define WIDTH 1000
#define HEIGHT 500
#define STEP 10


void detetarRicochete(VolleyGenerator*gun);
void doTheRendering(SDL_Renderer*rend,SDL_Texture*texture,VolleyGenerator*gun,Player*player,int* mousex,int* mousey);
void updateMovements(VolleyGenerator*gun,Player*player);
bool handleKeyboard(SDL_Event event, const Uint8 *KEYBOARD,Player*player,bool running,VolleyGenerator *gun);
int main()
{

    SDL_Init(SDL_INIT_EVERYTHING);
    int  mousex, mousey, ammo;

    cin >> ammo;

    SDL_Window *window = SDL_CreateWindow("OLA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
    SDL_Renderer *rend = SDL_CreateRenderer(window, -1, (SDL_RENDERER_TARGETTEXTURE, SDL_RENDERER_ACCELERATED));
    SDL_Texture* texture = SDL_CreateTexture(rend,SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_TARGET,WIDTH,HEIGHT);

    Player *player = new Player(0, 0, 30);

    VolleyGenerator *gun = new VolleyGenerator(player->getPlayerX(), player->getPlayerY(), 10, 10, ammo);

    const Uint8 *KEYBOARD = SDL_GetKeyboardState(NULL);

    bool running = true;
    SDL_Event event;

    int r=Entity::randNumBetZeroAnd(255),g=Entity::randNumBetZeroAnd(255),b=Entity::randNumBetZeroAnd(255);

    while (running)
    {


        while (SDL_PollEvent(&event))
        {

            if (event.type == SDL_MOUSEBUTTONDOWN)
            {

                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    if(!gun->isEmpty()){
                        gun->addProjectileToVolley(2000 * cos(atan2((mousey)-player->getPlayerY(), (mousex)-player->getPlayerX())), 2000 * sin(atan2((mousey)-player->getPlayerY(), (mousex)-player->getPlayerX())));
                    }
                    else{
                        cout<<"cabou"<<endl;
                    }
                }
            } 
            running=handleKeyboard(event,KEYBOARD,player,running,gun);
            if (event.type == SDL_QUIT)
            {

                running = false;
            }
        }

        updateMovements(gun,player);
        doTheRendering(rend,texture,gun,player,&mousex,&mousey);

    }

    player->destroyPlayer();
    gun->destroyVolley();
    delete (gun);
    delete (player);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(window);

    SDL_Quit();
}

void detetarRicochete(VolleyGenerator*gun){


        ProjectileIterator *it2 = gun->projectileTracker();
                    while (it2->hasNext())
                    {

                        Projectile *r = it2->next();
                if(r->getXpos()<=0){
                    r->updatePosition(1,r->getYpos());
                r->setTarget(-r->getTarget()->x,r->getTarget()->y);
                    r->speedDown(1);
                }
                else if(r->getXpos()>=WIDTH){
                    r->updatePosition(WIDTH-1,r->getYpos());
                r->setTarget(-r->getTarget()->x,r->getTarget()->y);
                    r->speedDown(1);
                
                }
                else if(r->getYpos()<=0){

                    r->updatePosition(r->getXpos(),1);
                r->setTarget(r->getTarget()->x,-r->getTarget()->y);
                    r->speedDown(1);
                }
                else if(r->getYpos()>=HEIGHT){
                     r->updatePosition(r->getXpos(),HEIGHT-1);

                r->setTarget(r->getTarget()->x,-r->getTarget()->y);
                    r->speedDown(1);
                     }
                    } 
}

void doTheRendering(SDL_Renderer*rend,SDL_Texture*texture,VolleyGenerator*gun,Player*player,int* mousex,int* mousey){



        SDL_SetRenderTarget(rend,texture);
        SDL_SetRenderDrawColor(rend,0,0,0,255);
        SDL_RenderClear(rend);
        player->keepPlayerVisible(rend, mousex, mousey);

        ProjectileIterator*it=gun->projectileTracker();

        while(it->hasNext()){

            Projectile *r=it->next();

            r->drawProjectile(rend);
        }
        SDL_SetRenderTarget(rend,NULL);
        SDL_RenderCopy(rend,texture,NULL,NULL);
        SDL_RenderPresent(rend);



}

void updateMovements(VolleyGenerator*gun,Player*player){


        gun->updateLaunchPositions(player->getPlayerX(), player->getPlayerY());

        ProjectileIterator*it=gun->projectileTracker();

while(it->hasNext()){

    Projectile*r=it->next();
    r->updateMovingProjectile();
}

        detetarRicochete(gun);


}

bool handleKeyboard(SDL_Event event, const Uint8 *KEYBOARD,Player*player,bool running,VolleyGenerator *gun){


            if (event.type == SDL_KEYDOWN)
            {

                if (KEYBOARD[SDL_SCANCODE_S])
                {
                    player->movePlayerY(STEP);
                }

                if (KEYBOARD[SDL_SCANCODE_W])
                {

                    player->movePlayerY(-STEP);
                }

                if (KEYBOARD[SDL_SCANCODE_A])
                {

                    player->movePlayerX(-STEP);
                }
                if (KEYBOARD[SDL_SCANCODE_D])
                {

                    player->movePlayerX(STEP);
                }

                if (KEYBOARD[SDL_SCANCODE_S] && KEYBOARD[SDL_SCANCODE_A])
                {

                    player->movePlayerY(STEP);
                    player->movePlayerX(-STEP);
                }
                if (KEYBOARD[SDL_SCANCODE_W] && KEYBOARD[SDL_SCANCODE_A])
                {

                    player->movePlayerY(-STEP);
                    player->movePlayerX(-STEP);
                }
                if (KEYBOARD[SDL_SCANCODE_S] && KEYBOARD[SDL_SCANCODE_D])
                {

                    player->movePlayerY(STEP);
                    player->movePlayerX(STEP);
                }
                if (KEYBOARD[SDL_SCANCODE_W] && KEYBOARD[SDL_SCANCODE_A])
                {

                    player->movePlayerY(-STEP);
                    player->movePlayerX(-STEP);
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

                if (KEYBOARD[SDL_SCANCODE_R])
                {
                    gun->regen();
                }
            }
            return running;


}
