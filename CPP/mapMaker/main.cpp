#include "ImportsAndDefines.hpp"

void handleEvents(SDL_Event event, const Uint8 *KEYBOARD,double*fps,GameState &state);

void listOperations(Pen*pen,Level* currentLevel,std::vector<Throwable*> &army,Jumper*jumper,GameState &currentState,int thickness,SDL_Renderer*renderer);

void settingsLoader(int argc,char* arg1,GameVariables& vars);
int main(int argc, char* argv[]){

        GameVariables currentConstants;
        settingsLoader(argc,argv[1],currentConstants);

        GameState currentState=(GameState){0,0,0,0,0,0,0,0b0000000000010000};

            int nPresses=0,
                x,
                y,
                desiredDelta=1000/currentConstants.fps;

        SDL_Color floorColor=(SDL_Color){0,220,0,255},
                    obstacleColor=(SDL_Color){0,0,0,255};



        const char* fontPath="/usr/share/fonts/truetype/freefont/FreeSans.ttf";

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
        SDL_Texture* obstacleLayer = SDL_CreateTexture(renderer,  SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, mode.w,mode.h); //Creating a texture
        if(obstacleLayer==NULL){

            std::cout<<"Could not create obstacle layer\n";
            return 1;
        }
        std::cout<<"sucesso\n";

        Obstacle *added=new Obstacle(renderer,0,0,1,1,1,1,obstacleColor,"");
        textBox * txt= new textBox(renderer,40,0,0,fontPath,255,0,255,255," ");
        FadingTexture* notification= new FadingTexture(txt->getXPos(),txt->getYPos(),mode.w,40,txt->getTexture(),100,0,0,0);
        LTexture* txtr= new LTexture(renderer,mode.w-300,-100,400,400,SUN_IMAGE_PATH);
        Level*level=new Level(renderer,mode.w,mode.h,DEFAULT_MAP_PATH);

        textBox * text=new textBox(renderer,currentConstants.fontSize,0,0,fontPath,255,255,255,255,"OLA!");
        textBox * text1=new textBox(renderer,currentConstants.fontSize,0,text->getYPos()+text->getHeight(),fontPath,255,255,255,255,"BOM DIA!");
        textBox * text2=new textBox(renderer,currentConstants.fontSize,0,text1->getYPos()+text1->getHeight(),fontPath,255,255,255,255,"TESTES");
        const Uint8* KEYBOARD=SDL_GetKeyboardState(NULL);
        SDL_Event e;

        SDL_Rect floor=(SDL_Rect){0,currentConstants.floorLevel+30,mode.w,mode.h-30-currentConstants.floorLevel};


        while(aux::OnesAreContained(currentState.mask,RUN_MASK)){

                int initFrame=SDL_GetTicks();

                Uint32 button=SDL_GetMouseState(&currentState.mouseX1,&currentState.mouseY1);





            textBox * objTelemetryBox=new textBox(renderer,currentConstants.fontSize*0.5,currentState.mouseX1+3,currentState.mouseY1+3,fontPath,255,255,255,255," ");



            std::string pos="("+std::to_string(currentState.mouseX1)+","+std::to_string(currentState.mouseY1)+")";
            textBox * mousePositionMeter=new textBox(renderer,currentConstants.fontSize,0,text2->getYPos()+text2->getHeight(),fontPath,255,255,255,255,pos.std::string::c_str());





                if (KEYBOARD[SDL_SCANCODE_LEFT])
                {
                }
                if (KEYBOARD[SDL_SCANCODE_N])
                {
                    currentState.mask|=NEW_OBSTACLE_MASK;
                    nPresses++;


                }
                else
                {
                if(nPresses>0){
                    currentState.mask&=N_NEW_OBSTACLE_MASK;
                    nPresses=0;

                    level->addBox(added);
                    }


                }

                if (KEYBOARD[SDL_SCANCODE_RIGHT])
                {

                }


                if (KEYBOARD[SDL_SCANCODE_D])
                {
                    currentState.mask|=DRAW_MASK;
                }
                else
                {
                    currentState.mask&=N_DRAW_MASK;
                }










            while(SDL_PollEvent(&e)){
                handleEvents(e,KEYBOARD,&currentConstants.fps,currentState);
            }


                listOperations(pen,level,army,jumper,currentState,currentConstants.hitBoxThickness,renderer);

                if(aux::OnesAreContained(currentState.mask,LOAD_LEVEL_MASK)){
                level->~Level();

                    std::string name;
                    std::cerr<<"Escreve o nome do level\n";

                    while (!(std::cin>>name))
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// discard input
                    std::cerr<<"falhou\n";
                    }

                        level=new Level(renderer,mode.w,mode.h,MAPS_FOLDER_PATH+name+".map");

                        std::string  loadedText=MAPS_FOLDER_PATH+name;
                        txt->updateText(renderer,loadedText.std::string::c_str());
                        notification= new FadingTexture(txt->getXPos(),txt->getYPos(),mode.w-mode.w*0.3,mode.w*0.025,txt->getTexture(),200,100,200,255);


                    }

                if(aux::OnesAreContained(currentState.mask,NEW_OBSTACLE_MASK)){
                    if(nPresses==1){
                        x=currentState.mouseX1;
                        y=currentState.mouseY1;

                    added=new Obstacle(renderer,x-currentConstants.hitBoxThickness,y-currentConstants.hitBoxThickness,1,1,currentConstants.hitBoxThickness,1,obstacleColor,OBSTACLE_IMAGE_PATH);
                        added->setPos(x-currentConstants.hitBoxThickness,y-currentConstants.hitBoxThickness);

                    }
                    else if(nPresses>1){

                            added->setInnerWidth(currentState.mouseX1-x);
                            added->setInnerHeight(currentState.mouseY1-y);



                    }

            }






            int delta= SDL_GetTicks()- initFrame;

            if(delta<desiredDelta){

                SDL_Delay(desiredDelta);
            }





                SDL_SetRenderTarget(renderer,map);

                    level->renderSky(renderer);
                    txtr->render(renderer);

                SDL_SetRenderTarget(renderer,obstacleLayer);
                SDL_RenderCopy(renderer,map,NULL,NULL);

                        level->renderObstacles(renderer);

                if(nPresses>0){
                added->renderObstacle(renderer);
                }


                SDL_SetRenderTarget(renderer,NULL);
                SDL_RenderCopy(renderer,obstacleLayer,NULL,NULL);

                SDL_SetRenderDrawColor(renderer,floorColor.r,floorColor.g,floorColor.b,floorColor.a);
                SDL_RenderFillRect(renderer,&floor);


                text->render(renderer);

                text1->render(renderer);

                text2->render(renderer);

                mousePositionMeter->render(renderer);

                notification->render(renderer);
            SDL_RenderPresent(renderer);
            currentState.mask&=N_LOAD_LEVEL_MASK;
            delete(objTelemetryBox);
            delete(mousePositionMeter);
        }
//        free((void*)KEYBOARD);
        delete(text);
        delete(text1);
        delete(text2);
        delete(txtr);
        delete(notification);
        delete(txt);
        delete(fading);

        std::cout<<"Tamanho de obstacles: "<<level->getObstacleCount()<<"\n";

        level->~Level();

        std::cout<<"Tamanho de obstacles: "<<level->getObstacleCount()<<"\n";

        SDL_DestroyTexture(map);
        SDL_DestroyTexture(obstacleLayer);

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);

        TTF_Quit();
        IMG_Quit();
        SDL_Quit();

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



void listOperations(Level* currentLevel,GameState &currentState,SDL_Renderer*renderer){


            if(aux::OnesAreContained(currentState.mask,REMOVE_ENTITIES_MASK)){

                currentLevel->removeBoxesOnly();
                currentState.mask&=N_REMOVE_ENTITIES_MASK;
                }

            if(aux::OnesAreContained(currentState.mask,N_REMOVE_OBSTACLE_MASK)){

                ObstacleIterator* it=currentLevel.obstacleIterator();
                while(!it.isOver()){
                    if()


                }
                currentState.mask&=N_REMOVE_OBSTACLE_MASK;
                }

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

                        fileOut<<currentLevel->getSkyImagePath()<<" "<<currentLevel->getObjectImagePath()<<" "<<currentLevel->getObstacleCount()<<" "<<thickness<<"\n";

                        ObstacleIterator* it=currentLevel->obstacleIterator();
                        while(!it->isOver()){
                            Obstacle*obj=it->getCurrent();
                            std::string tmp=obj->getPath2Img()+" "+std::to_string(obj->getCorePos().x)+ " " +std::to_string(obj->getCorePos().y)+ " " +std::to_string(obj->getInnerWidth())+ " " +std::to_string(obj->getInnerHeight())+"\n";
                            fileOut<<tmp;
                            it->increment();

                        }
                        fileOut.close();
                        std::cout<<"SAVED TO "<<filePath<<"\n";


                    }
                    }
                }



void handleEvents(SDL_Event event, const Uint8 *KEYBOARD,double*fps,GameState &state){

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

                if (KEYBOARD[SDL_SCANCODE_S])
                {
                        state.mask|=SAVE_LEVEL_MASK;


                }
                if (KEYBOARD[SDL_SCANCODE_D])
                {
                        state.mask|=REMOVE_OBSTACLE_MASK;


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


                }
                if (KEYBOARD[SDL_SCANCODE_R])
                {
                        state.mask|=REMOVE_ENTITIES_MASK;

                        state.mask|=COLLISIONS_MASK;

                        state.mask&=N_ARMY_MASK;

            }
            }


}
