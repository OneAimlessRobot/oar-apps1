#include "Includes/ImportsAndDefines.hpp"

void handleEvents(SDL_Event event, const Uint8 *KEYBOARD,Jumper* jumper,float*fps,GameState &state);
//void gameLoop();
void listOperations(Pen*pen,Level* currentLevel,ForceField* field,std::vector<Throwable*> &army,Jumper*jumper,GameState &currentState,int thickness,SDL_Renderer*renderer);

void settingsLoader(int argc,char* arg1,GameVariables& vars);
int main(int argc, char* argv[]){

        GameVariables currentConstants;
        settingsLoader(argc,argv[1],currentConstants);

        GameState currentState=(GameState){0,0,0,0,0,0,0b0000000000010000};

            int nPresses=0,
                x,
                y,
                desiredDelta=1000/currentConstants.fps;

        SDL_Color sunColor=(SDL_Color){200,200,0,255},
                    skyColor=(SDL_Color){0,100,200,255},
                    jumperTrailColor=(SDL_Color){0, 255, 0, 255},
                    floorColor=(SDL_Color){0,220,0,255},
                    penColor=(SDL_Color){0,255,0,255},
                    obstacleColor=(SDL_Color){0,0,0,255},
                    jumperColor=(SDL_Color){40,40,40,120};



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
}

void settingsLoader(int argc,char* arg1,GameVariables& vars){



                if(argc==2&&!strcmp(arg1,"default")){
                    vars.winWidth=DEFAULT_WIN_WIDTH;
                    vars.winHeight=DEFAULT_WIN_WIDTH*0.5625;
                    vars.fps=DEFAULT_FRAMERATE;
                    vars.fontSize=DEFAULT_FONTSIZE;
                    vars.throwingSpeed=DEFAULT_THROWINGSPEED;
                    vars.floorLevel=DEFAULT_FLOOR_LEVEL;
                    vars.hitBoxThickness=DEFAULT_HITBOX_THICKNESS;
                    vars.gravity=DEFAULT_GRAVITY_CONST;

                }
                else{
                    std::fstream settingsReader;
                    settingsReader.open("/home/oneaimlessrobot/speed/settings.txt");
                    if(settingsReader.is_open()){
                    settingsReader>>vars.floorLevel>>vars.fontSize>>vars.throwingSpeed>>vars.gravity>>vars.hitBoxThickness>>vars.fps>>vars.winWidth;
                    vars.winHeight=vars.winWidth*0.5625;
                    settingsReader.close();
                    }
                    else{
                        std::cout<<"No settings file was found!\n";
                    }
                }





}



void listOperations(Pen*pen,Level* currentLevel,ForceField* field,std::vector<Throwable*> &army,Jumper*jumper,GameState &currentState,int thickness,SDL_Renderer*renderer){

                if(aux::OnesAreContained(currentState.mask,SAVE_LEVEL_MASK)){
                currentState.mask&=N_SAVE_LEVEL_MASK;
                    std::string name;
                    std::cout<<"Escreve o nome do level\n";
                    while (!(std::cin>>name))
                    {
                    std::cout<<"falhou\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
                    }
                    std::string filePath=MAPS_FOLDER_PATH+name+".map";
                    std::fstream fileOut;
                    fileOut.open(filePath.std::string::c_str(),std::ios_base::out);
                    if(fileOut.is_open()){

                        fileOut<<currentLevel->getSkyImagePath()<<" "<<currentLevel->getAirDensity()<<" "<<currentLevel->getObjectImagePath()<<" "<<currentLevel->getObstacleCount()<<" "<<thickness<<"\n";
//" "<<currentLevel->getFluidDx()<<" "<<currentLevel->getFluidDy()<<" "<<currentLevel->getFluidSpeed()<<
                        Iterator<Obstacle*>* it=currentLevel->obstacleIterator();
                        while(!it->isOver()){
                            Obstacle*obj=it->getCurrent();
                            std::string tmp=std::to_string(obj->getCorePos().x)+ " " +std::to_string(obj->getCorePos().y)+ " " +std::to_string(obj->getInnerWidth())+ " " +std::to_string(obj->getInnerHeight())+"\n";
                            fileOut<<tmp;
                            it->increment();

                        }
                        fileOut<<currentLevel->getPlanetImagePath()<<" "<<currentLevel->getPlanetCount()<<"\n";
                        Iterator<Planet*>* it2=currentLevel->planetIterator();
                        while(!it2->isOver()){
                            Planet*p=it2->getCurrent();
                            std::string tmp=std::to_string(p->getPos().x)+ " " +std::to_string(p->getPos().y)+ " " +std::to_string(p->getSize())+" " +std::to_string(p->getConstant())+"\n";
                            fileOut<<tmp;
                            it2->increment();


                        }
                        fileOut.close();
                        std::cout<<"SAVED TO "<<filePath<<"\n";


                    }
                    }
                }



void handleEvents(SDL_Event event, const Uint8 *KEYBOARD,Jumper* jumper,float*fps,GameState &state){

            if(event.type==SDL_QUIT){
                state.mask&=N_RUN_MASK;
            }

            if (event.type == SDL_KEYDOWN)
            {


                if (KEYBOARD[SDL_SCANCODE_A])
                {
                        state.mask|=ARMY_MASK;


                        state.mask|=THROWABLE_ADD_MASK;


                }

                if (KEYBOARD[SDL_SCANCODE_P])
                {


                        state.mask|=PLANET_MASK;


                }

                if (KEYBOARD[SDL_SCANCODE_S])
                {
                        state.mask|=SAVE_LEVEL_MASK;


                }
                if (KEYBOARD[SDL_SCANCODE_L])
                {
                        state.mask|=LOAD_LEVEL_MASK;


                }
                if (KEYBOARD[SDL_SCANCODE_U])
                {
                        state.mask|=COLLISIONS_MASK;
                }
                if (KEYBOARD[SDL_SCANCODE_SPACE])
                {
                    if(!jumper->bouncing()){
                        jumper->bounce();
                    }
                }
                if (KEYBOARD[SDL_SCANCODE_R])
                {
                        state.mask|=REMOVE_ENTITIES_MASK;

                        state.mask|=COLLISIONS_MASK;

                        state.mask&=N_ARMY_MASK;

            }
            }


}
