#include "ImportsAndDefines.hpp"

void handleEvents(SDL_Event event, const Uint8 *KEYBOARD,Jumper* jumper,float*fps,GameState &state);

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

        Jumper*jumper=  new Jumper(renderer,200,500,50,10,20,jumperColor,currentConstants.floorLevel,100,2,OBSTACLE_IMAGE_PATH,1);
        Obstacle *added=new Obstacle(renderer,0,0,1,1,1,1,obstacleColor,"");
        Pen* pen=new Pen(10,penColor);
        textBox * txt= new textBox(renderer,40,0,0,fontPath,255,0,255,255," ");
        FadingTexture* notification= new FadingTexture(txt->getXPos(),txt->getYPos(),mode.w,40,txt->getTexture(),100,0,0,0);
        LTexture* txtr= new LTexture(renderer,mode.w-300,-100,400,400,SUN_IMAGE_PATH);
        Sprite*spr=new Sprite(renderer,300,300,TEST_SPRITE_PATH,0,3);
        Level*level=new Level(renderer,mode.w,mode.h,DEFAULT_MAP_PATH);
        ForceField*field=new ForceField(renderer,150,150,600,1,1,(SDL_Color){0,0,0,255},FFIELD_IMAGE_PATH,1,1,1,20);
        //ODESolver*solver=new ODESolver(0, 0, mode.w,mode.h,10,10,yFunc);

        textBox * text=new textBox(renderer,currentConstants.fontSize,0,0,fontPath,255,255,255,255,"OLA!");
        textBox * text1=new textBox(renderer,currentConstants.fontSize,0,text->getYPos()+text->getHeight(),fontPath,255,255,255,255,"BOM DIA!");
        textBox * text2=new textBox(renderer,currentConstants.fontSize,0,text1->getYPos()+text1->getHeight(),fontPath,255,255,255,255,"TESTES");
        const Uint8* KEYBOARD=SDL_GetKeyboardState(NULL);
        SDL_Event e;

        SDL_FRect floor=(SDL_FRect){0,(float)currentConstants.floorLevel+30,(float)mode.w,(float)mode.h-30-(float)currentConstants.floorLevel};

        clockCounter*counter=new clockCounter(0,1,0);


        while(aux::OnesAreContained(currentState.mask,RUN_MASK)){
              int initFrame=SDL_GetTicks();

                counter->setModulus(army.size());
  
                Uint32 button=SDL_GetMouseState(&currentState.mouseX1,&currentState.mouseY1);

                SDL_FPoint startPos=(SDL_FPoint){jumper->getPos().x,jumper->getPos().y};




            textBox * objTelemetryBox=new textBox(renderer,currentConstants.fontSize*0.5,currentState.mouseX1+3,currentState.mouseY1+3,fontPath,255,255,255,255," ");



            std::string pos="("+std::to_string(currentState.mouseX1)+","+std::to_string(currentState.mouseY1)+")";
            textBox * mousePositionMeter=new textBox(renderer,currentConstants.fontSize,0,text2->getYPos()+text2->getHeight(),fontPath,255,255,255,255,pos.std::string::c_str());





            if(aux::OnesAreContained(currentState.mask,ARMY_MASK)){
                    if(button & SDL_BUTTON_LMASK){
                            SDL_FPoint point=(SDL_FPoint){(float)currentState.mouseX1,(float)currentState.mouseY1};
                            SDL_bool detect1=SDL_PointInFRect(&point,army[counter->getCurrent()]->getBody());
                    if(detect1){
                            army[counter->getCurrent()]->setValue(1);
                    }
                }
                else{

                            army[counter->getCurrent()]->setValue(0);
                }
            }

                if (KEYBOARD[SDL_SCANCODE_LEFT])
                {
                    jumper->movePos(-15,0);
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

                    jumper->movePos(15,0);
                }

                if (KEYBOARD[SDL_SCANCODE_DOWN])
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
                handleEvents(e,KEYBOARD,jumper,&currentConstants.fps,currentState);
            }


                listOperations(pen,level,field,army,jumper,currentState,currentConstants.hitBoxThickness,renderer);

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

            SDL_GetMouseState(&currentState.mouseX2,&currentState.mouseY2);

            SDL_FPoint endPos=(SDL_FPoint){jumper->getPos().x,jumper->getPos().y};
            SDL_FPoint mousePos=(SDL_FPoint){(float)currentState.mouseX1,(float)currentState.mouseY1};

            float mDist=aux::distBetPointsFloats((float)currentState.mouseX1,(float)currentState.mouseY1,(float)currentState.mouseX2,(float)currentState.mouseY2);

            float jDist=aux::distBetPoints(&startPos,&endPos);
            currentState.mSpeed=(int)(((float)mDist*0.5)/(float)(delta*0.05));

            currentState.jSpeed=(int)(((float)jDist*0.5)/(float)(delta*0.05));

                    if(aux::OnesAreContained(currentState.mask,ARMY_MASK)){

                        SDL_FPoint throwablePos=army[counter->getCurrent()]->getCenter();
                        if(army[counter->getCurrent()]->getValue()){
                        float speed=aux::distBetPoints(&mousePos,&throwablePos)*0.01*currentConstants.throwingSpeed,
                            deltaX=currentState.mouseX1-throwablePos.x,
                            deltaY=currentState.mouseY1-throwablePos.y;
                            GeometricVector<float>*updatedVec=new GeometricVector<float>(throwablePos.x,throwablePos.y,deltaX,deltaY,positive,speed);
                            army[counter->getCurrent()]->setVector(updatedVec);


                        }
                        else{
                            army[counter->getCurrent()]->shoot();
                            }
                            if(army[counter->getCurrent()]->ricochete()){

                            shockwaves.push_back(new Sprite(renderer,army[counter->getCurrent()]->getCenter().x,army[counter->getCurrent()]->getCenter().y,TEST_SPRITE_PATH,0,1));


                        }
                        counter->increment();
                    }
                    else{
                        counter->setCurrent(0);
                        counter->setModulus(army.size());

                    }

                    jumper->trajectoryCalculation(currentConstants.gravity);
//                    std::cout<<jumper->getCenter().x<<" , "<<jumper->getCenter().y<<"\n";
                    field->updateVectors();
                    level->updateMovements();








                SDL_SetRenderTarget(renderer,map);

                    level->renderSky(renderer);
                    txtr->render(renderer);
                SDL_SetRenderTarget(renderer,effects);
                SDL_RenderCopy(renderer,map,NULL,NULL);

                    for(Sprite* sprite:shockwaves){
                            sprite->render(renderer);
                    }

                SDL_SetRenderTarget(renderer,S_H_A_P_E_S);
                SDL_RenderCopy(renderer,effects,NULL,NULL);



                    SDL_SetRenderTarget(renderer,obstacleLayer);
                    SDL_RenderCopy(renderer,S_H_A_P_E_S,NULL,NULL);

                        field->render(renderer);

                        level->renderObstacles(renderer);
                        level->renderPlanets(renderer);

                if(nPresses>0){
                added->renderBodyOnly(renderer);
                }


                SDL_SetRenderTarget(renderer,NULL);
                SDL_RenderCopyF(renderer,obstacleLayer,NULL,NULL);

                SDL_SetRenderDrawColor(renderer,floorColor.r,floorColor.g,floorColor.b,obstacleColor.a);
                SDL_RenderFillRectF(renderer,&floor);


                text->render(renderer);

                text1->render(renderer);

                text2->render(renderer);

                mousePositionMeter->render(renderer);



                        pen->renderDrawing(renderer);

                        for(Throwable *obj:army){
                        obj->render(renderer);
                        }

                objTelemetryBox->render(renderer);
                jumper->render(renderer);
//                solver->drawSlopeField(renderer,skyColor);
                SDL_SetRenderDrawColor(renderer,penColor.r,penColor.g,penColor.b,255);
//                solver->drawCurve(renderer,(SDL_FPoint){(float)currentState.mouseX1,(float)currentState.mouseY1},0.1,6000);
                notification->render(renderer);

            SDL_RenderPresent(renderer);
            currentState.mask&=N_LOAD_LEVEL_MASK;
            delete(objTelemetryBox);
            delete(mousePositionMeter);
        }
//        free((void*)KEYBOARD);
        delete(counter);
        delete(jumper);
        delete(text);
        delete(text1);
        delete(text2);
        delete(txtr);
        delete(notification);
        delete(txt);
        delete(pen);
        delete(spr);
        delete(field);

        std::cout<<"Tamanho de obstacles: "<<level->getObstacleCount()<<"\n";
        std::cout<<"Tamanho de army: "<<army.size()<<"\n";
        std::cout<<"Tamanho de shockwaves: "<<shockwaves.size()<<"\n";
        std::cout<<"Tamanho de planets: "<<level->getPlanetCount()<<"\n";

        level->~Level();

        std::cout<<"Tamanho de obstacles: "<<level->getObstacleCount()<<"\n";
        for(Throwable* thing:army){
                    delete(thing);
                    army.pop_back();
        }
        std::cout<<"Tamanho de army: "<<army.size()<<"\n";
        for(Sprite*sprite:shockwaves){


            delete(sprite);

            shockwaves.pop_back();


        }
        std::cout<<"Tamanho de shockwaves: "<<shockwaves.size()<<"\n";

        std::cout<<"Tamanho de planets: "<<level->getPlanetCount()<<"\n";

        SDL_DestroyTexture(map);
        SDL_DestroyTexture(effects);
        SDL_DestroyTexture(S_H_A_P_E_S);
        SDL_DestroyTexture(obstacleLayer);

        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(win);

        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        std::cout<<"Cheguei aqui\n";
        return 0;

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
                    settingsReader.open(SETTINGS_PATH);
                    if(settingsReader.is_open()){
                    settingsReader>>vars.floorLevel>>vars.fontSize>>vars.throwingSpeed>>vars.gravity>>vars.hitBoxThickness>>vars.fps>>vars.winWidth;
                    vars.winHeight=vars.winWidth*0.5625;
                    settingsReader.close();
                    }
                    else{
                        std::cout<<"No settings file was found!\n"<<" "<<SETTINGS_PATH<<"\n";
                    }
                }





}



void listOperations(Pen*pen,Level* currentLevel,ForceField* field,std::vector<Throwable*> &army,Jumper*jumper,GameState &currentState,int thickness,SDL_Renderer*renderer){

            if(aux::OnesAreContained(currentState.mask,REMOVE_ENTITIES_MASK)){
                pen->clearDrawing();
                for(Throwable* thing:army){
                            delete(thing);
                            army.pop_back();
                }
                field->removeBodies();
                currentLevel->removeBoxes();
                currentLevel->removePlanets();
                currentLevel->removeThrowables();
                currentState.mask&=N_REMOVE_ENTITIES_MASK;
                }
            if(aux::OnesAreContained(currentState.mask,ARMY_MASK)){
                if(aux::OnesAreContained(currentState.mask,THROWABLE_ADD_MASK)){

                            Throwable* added= new Throwable(renderer,currentState.mouseX1,currentState.mouseY1,50,(SDL_Color){255,0,0,120},50,10,THROWABLE_IMAGE_PATH,0,(float)10,0.0625);
                        added->addBox(currentLevel->getAirBox());
                        Iterator<Obstacle*>* it=currentLevel->obstacleIterator();
                        while(!it->isOver()){
                            added->addBox(it->getCurrent());
                            it->increment();
                            }
                        currentLevel->addThrowable(added);
                        field->addBody(added);

                        army.push_back(added);


                        currentState.mask&=N_THROWABLE_ADD_MASK;
                }
                }
            if(aux::OnesAreContained(currentState.mask,COLLISIONS_MASK)){
                    for(Throwable* object:army){

                        Iterator<Obstacle*>* it=currentLevel->obstacleIterator();
                        while(!it->isOver()){
                            object->addBox(it->getCurrent());
                            it->increment();

                        }


                    }
                    currentState.mask&=N_COLLISIONS_MASK;

                }


                if(aux::OnesAreContained(currentState.mask,DRAW_MASK)){

                    pen->draw(currentState.mouseX1,currentState.mouseY1);

                }
                if(aux::OnesAreContained(currentState.mask,PLANET_MASK)){

                currentState.mask&=N_PLANET_MASK;
                    int num;
                    std::cout<<"Escreve a constante:\n";
                    while (!(std::cin>>num))
                    {
                    std::cout<<"falhou\n";
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard input
                    }
                    Planet*added=new Planet(renderer,currentState.mouseX1,currentState.mouseY1,50,THROWABLE_IMAGE_PATH,(SDL_Color){0,0,0,255},num,1);


                        Iterator<Planet*>* it=currentLevel->planetIterator();
                        while(!it->isOver()){
                          ( (Planet*)(it->getCurrent()))->addPlanet(added);
                            it->increment();

                        }

                    currentLevel->addPlanet(added);

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



	void Game::handleEvents(SDL_Event event, const Uint8 *KEYBOARD,Jumper* jumper,float*fps,GameState &state){

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
