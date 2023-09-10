#include "ImportsAndDefines.hpp"




ThrowableGame::ThrowableGame(){

        GameVariables currentConstants;
        settingsLoader(argc,argv[1],currentConstants);



}

int main(int argc, char* argv[]){

        GameVariables currentConstants;
        settingsLoader(argc,argv[1],currentConstants);

        GameState currentState=(GameState){0,0,0,0,0,0,0,0b0000000000010000};

            int nPresses=0,
                x,
                y,
                desiredDelta=1000/currentConstants.fps;

        SDL_Color   skyColor=(SDL_Color){0,100,200,255},
                    floorColor=(SDL_Color){0,220,0,255},
                    obstacleColor=(SDL_Color){0,0,0,255};



        const char* fontPath="/usr/share/fonts/truetype/freefont/FreeSans.ttf";

        std::vector<Throwable*> army={};
        std::vector<Sprite*> shockwaves={};

        TTF_Init();
        IMG_Init(IMG_INIT_PNG);
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_DisplayMode mode;
        mode.w=currentConstants.winWidth;
        mode.h=currentConstants.winHeight;
        SDL_Window* win=SDL_CreateWindow("OLA",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,currentConstants.winWidth,currentConstants.winHeight,(SDL_WINDOW_RESIZABLE));
        if(win==NULL){
            std::cout<<"Could not create window\n";
            return 1;
        }
        std::cout<<"sucesso\n";
        SDL_Renderer* renderer=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
        if(renderer==NULL){
            std::cout<<"Could not create renderer\n";
            return 1;
        }
        std::cout<<"sucesso\n";
        SDL_Texture* map = SDL_CreateTexture(renderer,  SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, mode.w,mode.h); //Creating a texture
        if(map==NULL){
            std::cout<<"Could not create map\n";
            return 1;
        }
        std::cout<<"sucesso\n";
        SDL_Texture* effects = SDL_CreateTexture(renderer,  SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, mode.w,mode.h); //Creating a texture
        if(effects==NULL){
            std::cout<<"Could not create effects layer\n";
            return 1;
        }
        std::cout<<"sucesso\n";
        SDL_Texture* S_H_A_P_E_S = SDL_CreateTexture(renderer,  SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, mode.w,mode.h); //Creating a texture
        if(S_H_A_P_E_S==NULL){
            std::cout<<"Could not create the shape\n";
            return 1;
        }
        std::cout<<"sucesso\n";
        SDL_Texture* obstacleLayer = SDL_CreateTexture(renderer,  SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, mode.w,mode.h); //Creating a texture
        if(obstacleLayer==NULL){

            std::cout<<"Could not create obstacle layer\n";
            return 1;
        }
        std::cout<<"sucesso\n";
        const Uint8* KEYBOARD=SDL_GetKeyboardState(NULL);
        SDL_Event e;

        SDL_FRect floor=(SDL_FRect){0,(float)currentConstants.floorLevel+30,(float)mode.w,(float)mode.h-30-(float)currentConstants.floorLevel};

        while(aux::OnesAreContained(currentState.mask,RUN_MASK)){


        }
}


void ThrowableGame::settingsLoader(int argc,char* arg1,GameVariables& vars){




void listOperations(Pen*pen,Level* currentLevel,ForceField* field,std::vector<Throwable*> &army,Jumper*jumper,GameState &currentState,int thickness,SDL_Renderer*renderer){

                }



void handleEvents(SDL_Event event, const Uint8 *KEYBOARD,Jumper* jumper,float*fps,GameState &state){


}
