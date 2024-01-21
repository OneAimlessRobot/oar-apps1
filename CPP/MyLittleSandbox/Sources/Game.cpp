#include "ImportsAndDefines.hpp"
      const char* fontPath="/usr/share/fonts/truetype/freefont/FreeSans.ttf";

	Game::Game(int argc, char *argv1){

        this->settingsLoader(argc,argv1,this->currentConstants);

        this->currentState=(GameState){0,0,0,0,0,0,0b0000000000010000};

                this->desiredDelta=1000/currentConstants.fps;

        this->sunColor=(SDL_Color){200,200,0,255};
                    this->skyColor=(SDL_Color){0,100,200,255};
                    this->jumperTrailColor=(SDL_Color){0, 255, 0, 255};
                    this->floorColor=(SDL_Color){0,220,0,255};
                    this->penColor=(SDL_Color){0,255,0,255};
                    this->obstacleColor=(SDL_Color){0,0,0,255};
                    this->jumperColor=(SDL_Color){40,40,40,120};

	
	this->nPresses=0;
  	
		
	this->army={};
        this->shockwaves={};

        TTF_Init();
        IMG_Init(IMG_INIT_PNG);
        SDL_Init(SDL_INIT_EVERYTHING);
        this->mode.w=this->currentConstants.winWidth;
        this->mode.h=this->currentConstants.winHeight;
        this->win=SDL_CreateWindow("OLA",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,this->currentConstants.winWidth,this->currentConstants.winHeight,(SDL_WINDOW_RESIZABLE));
        if(this->win==NULL){
            std::cout<<"Could not create window\n";
            return;
        }
        std::cout<<"sucesso\n";
        this->renderer=SDL_CreateRenderer(this->win,-1,SDL_RENDERER_ACCELERATED);
        if(this->renderer==NULL){
            std::cout<<"Could not create renderer\n";
            return;
        }
        std::cout<<"sucesso\n";
        this->map = SDL_CreateTexture(this->renderer,  SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, this->mode.w,this->mode.h); //Creating a texture
        if(this->map==NULL){
            std::cout<<"Could not create map\n";
            return;
        }
        std::cout<<"sucesso\n";
        this->effects = SDL_CreateTexture(this->renderer,  SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, this->mode.w,this->mode.h); //Creating a texture
        if(this->effects==NULL){
            std::cout<<"Could not create effects layer\n";
            return;
        }
        std::cout<<"sucesso\n";
        this->S_H_A_P_E_S = SDL_CreateTexture(this->renderer,  SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, this->mode.w,this->mode.h); //Creating a texture
        if(this->S_H_A_P_E_S==NULL){
            std::cout<<"Could not create the shape\n";
            return;
        }
        std::cout<<"sucesso\n";
        this->obstacleLayer = SDL_CreateTexture(this->renderer,  SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, this->mode.w,this->mode.h); //Creating a texture
        if(this->obstacleLayer==NULL){

            std::cout<<"Could not create obstacle layer\n";
            return;
        }
        std::cout<<"sucesso\n";

	 this->jumper= new Jumper(this->renderer,200,500,50,10,20,this->jumperColor,this->currentConstants.floorLevel,100,2,OBSTACLE_IMAGE_PATH,1);
   this->added=new Obstacle(this->renderer,0,0,1,1,1,1,this->obstacleColor,"");
        this->pen=new Pen(10,this->penColor);
        this->txt= new textBox(this->renderer,40,0,0,fontPath,255,0,255,255," ");
        this->notification= new FadingTexture(this->txt->getXPos(),this->txt->getYPos(),this->mode.w,40,this->txt->getTexture(),100,0,0,0);
        this->txtr= new LTexture(this->renderer,this->mode.w-300,-100,400,400,SUN_IMAGE_PATH);
        this->spr=new Sprite(this->renderer,300,300,TEST_SPRITE_PATH,0,3);
        this->level=new Level(this->renderer,this->mode.w,this->mode.h,DEFAULT_MAP_PATH);
        //this->field=new ForceField(this->renderer,150,150,600,1,1,(SDL_Color){0,0,0,255},FFIELD_IMAGE_PATH,1,1,1,20);
        //ODESolver*solver=new ODESolver(0, 0, mode.w,mode.h,10,10,yFunc);

	
        this->text=new textBox(this->renderer,this->currentConstants.fontSize,0,0,fontPath,255,255,255,255,"OLA!");
        this->text1=new textBox(this->renderer,this->currentConstants.fontSize,0,this->text->getYPos()+this->text->getHeight(),fontPath,255,255,255,255,"BOM DIA!");
        this->text2=new textBox(this->renderer,this->currentConstants.fontSize,0,this->text1->getYPos()+this->text1->getHeight(),fontPath,255,255,255,255,"TESTES");
	 this->KEYBOARD=SDL_GetKeyboardState(NULL);


        this->floor=(SDL_FRect){0,(float)this->currentConstants.floorLevel+30,(float)this->mode.w,(float)this->mode.h-30-(float)this->currentConstants.floorLevel};


        this->counter=new clockCounter(0,1,0);



}

	void Game::handleMouse(Uint32 button){


		

            if(aux::OnesAreContained(this->currentState.mask,ARMY_MASK)){
                    if(button & SDL_BUTTON_LMASK){
                      for(std::vector<Throwable*>::iterator it=this->army.begin();it<this->army.end();it++){
			Throwable* curr= (*it);
                
		          SDL_FPoint point=(SDL_FPoint){(float)this->currentState.mouseX1,(float)this->currentState.mouseY1};
                            SDL_bool detect1=SDL_PointInFRect(&point,curr->getBody());
                    if(detect1){
                            curr->setValue(1);
                    }
                }
		}
                else{
			for(std::vector<Throwable*>::iterator it=this->army.begin();it<this->army.end();it++){
				Throwable* curr= (*it);
            		        curr->setValue(0);
                    }
		}
	    

	}
	}


	void Game::gameLoop(){
	 while(aux::OnesAreContained(this->currentState.mask,RUN_MASK)){
	 int initFrame=SDL_GetTicks();

                this->counter->setModulus(this->army.size());

                Uint32 button=SDL_GetMouseState(&this->currentState.mouseX1,&this->currentState.mouseY1);

                SDL_FPoint startPos={this->jumper->getPos().x,this->jumper->getPos().y};


	renderText();
	handleMouse(button);
	handleKeyCont();
	misc();

	
            int delta= SDL_GetTicks()- initFrame;

            if(delta<this->desiredDelta){

                SDL_Delay(this->desiredDelta-delta);
            }

	updateMovements(delta,&startPos);
	renderEverything();
	delete(this->objTelemetryBox);
       	delete(this->mousePositionMeter);

	}
	}

	void Game::renderText(){



            this->objTelemetryBox=new textBox(this->renderer,this->currentConstants.fontSize*0.5,this->currentState.mouseX1+3,this->currentState.mouseY1+3,fontPath,255,255,255,255," ");



            std::string pos="("+std::to_string(this->currentState.mouseX1)+","+std::to_string(this->currentState.mouseY1)+")";
            this->mousePositionMeter=new textBox(this->renderer,this->currentConstants.fontSize,0,this->text2->getYPos()+this->text2->getHeight(),fontPath,255,255,255,255,pos.std::string::c_str());


		

	}

	void Game::listOperations(Pen*pen,Level* currentLevel,ForceField* field,std::vector<Throwable*> &army,Jumper*jumper,GameState &currentState,int thickness,SDL_Renderer*renderer){


            if(aux::OnesAreContained(currentState.mask,REMOVE_ENTITIES_MASK)){
                pen->clearDrawing();
                for(Throwable* thing:army){
                            delete(thing);
                            army.pop_back();
                }
                //field->removeBodies();
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
                        //field->addBody(added);

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

                        fileOut<<currentLevel->getSkyImagePath()<<" "<<currentLevel->getAirDensity()<<" "<<currentLevel->getObjectImagePath()<<" "<<currentLevel->getObstacleCount()<<" "<<thickness<<"\n";//
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
	void Game::misc(){

	while(SDL_PollEvent(&this->e)){
                handleEvents(this->e,this->KEYBOARD,this->jumper,&this->currentConstants.fps,this->currentState);
            }



                listOperations(this->pen,this->level,this->field,this->army,this->jumper,this->currentState,this->currentConstants.hitBoxThickness,this->renderer);

                if(aux::OnesAreContained(currentState.mask,LOAD_LEVEL_MASK)){
                    this->level->~Level();
                    std::string name;
                    std::cerr<<"Escreve o nome do level\n";

                    while (!(std::cin>>name))
                    {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');// discard input
                    std::cerr<<"falhou\n";
                    }

                            this->level=new Level(this->renderer,this->mode.w,this->mode.h,MAPS_FOLDER_PATH+name+".map");
                            std::string  loadedText=MAPS_FOLDER_PATH+name;
                            this->txt->updateText(this->renderer,loadedText.std::string::c_str());
                            this->notification= new FadingTexture(this->txt->getXPos(),this->txt->getYPos(),this->mode.w-this->mode.w*0.3,this->mode.w*0.025,this->txt->getTexture(),200,100,200,255);


                        }

                if(aux::OnesAreContained(this->currentState.mask,NEW_OBSTACLE_MASK)){
                    if(this->nPresses==1){
                        this->x=currentState.mouseX1;
                        this->y=currentState.mouseY1;
                    this->added=new Obstacle(renderer,x-currentConstants.hitBoxThickness,y-currentConstants.hitBoxThickness,1,1,this->currentConstants.hitBoxThickness,1,obstacleColor,OBSTACLE_IMAGE_PATH);

                        this->added->setPos(this->x-this->currentConstants.hitBoxThickness,this->y-this->currentConstants.hitBoxThickness);

                    }
                    else if(this->nPresses>1){

                            this->added->setInnerWidth(this->currentState.mouseX1-this->x);
                            this->added->setInnerHeight(this->currentState.mouseY1-this->y);



                    }

            }



	}
	void Game::updateMovements(int delta,SDL_FPoint* startPos){

	 SDL_GetMouseState(&this->currentState.mouseX2,&this->currentState.mouseY2);

            SDL_FPoint endPos=(SDL_FPoint){this->jumper->getPos().x,this->jumper->getPos().y};
            SDL_FPoint mousePos=(SDL_FPoint){(float)this->currentState.mouseX1,(float)this->currentState.mouseY1};

            float mDist=aux::distBetPointsFloats((float)currentState.mouseX1,(float)currentState.mouseY1,(float)currentState.mouseX2,(float)currentState.mouseY2);

            float jDist=aux::distBetPoints(startPos,&endPos);
            currentState.mSpeed=(int)(((float)mDist*0.5)/(float)(delta*0.05));

            currentState.jSpeed=(int)(((float)jDist*0.5)/(float)(delta*0.05));

                    if(aux::OnesAreContained(currentState.mask,ARMY_MASK)){
                    for(std::vector<Throwable*>::iterator it=this->army.begin();it<this->army.end();it++){
			Throwable* curr= (*it);
                        SDL_FPoint throwablePos=curr->getCenter();
                        if(curr->getValue()){
                        float speed=aux::distBetPoints(&mousePos,&throwablePos)*0.01*currentConstants.throwingSpeed,
                            deltaX=currentState.mouseX1-throwablePos.x,
                            deltaY=currentState.mouseY1-throwablePos.y;
                             GeometricVector<float>*updatedVec=new GeometricVector<float>(throwablePos.x,throwablePos.y,deltaX,deltaY,positive,speed);
                           curr->setVector(updatedVec);


                        }
                        else{
                            curr->shoot();
                            }
                            if(curr->ricochete()){

                            shockwaves.push_back(new Sprite(renderer,curr->getCenter().x,curr->getCenter().y,TEST_SPRITE_PATH,0,1));


                        }
                    }
                }
                    jumper->trajectoryCalculation(currentConstants.gravity);
//                    std::cout<<jumper->getCenter().x<<" , "<<jumper->getCenter().y<<"\n";
                    //field->updateVectors();
                    level->updateMovements();




	}
	void Game::renderEverything(){



	SDL_SetRenderTarget(renderer,map);

                    this->level->renderSky(this->renderer);
                    this->txtr->render(this->renderer);
                SDL_SetRenderTarget(this->renderer,this->effects);
                SDL_RenderCopy(this->renderer,this->map,NULL,NULL);

                    for(Sprite* sprite:this->shockwaves){
                            sprite->render(this->renderer);
                    }

                SDL_SetRenderTarget(this->renderer,this->S_H_A_P_E_S);
                SDL_RenderCopy(this->renderer,this->effects,NULL,NULL);



                    SDL_SetRenderTarget(this->renderer,this->obstacleLayer);
                    SDL_RenderCopy(this->renderer,this->S_H_A_P_E_S,NULL,NULL);

                        //this->field->render(this->renderer);

                        this->level->renderObstacles(this->renderer);
                        this->level->renderPlanets(this->renderer);

                if(this->nPresses>0){
                this->added->renderBodyOnly(this->renderer);
                }


                SDL_SetRenderTarget(this->renderer,NULL);
                SDL_RenderCopyF(this->renderer,this->obstacleLayer,NULL,NULL);

                SDL_SetRenderDrawColor(this->renderer,this->floorColor.r,this->floorColor.g,this->floorColor.b,this->obstacleColor.a);
                SDL_RenderFillRectF(this->renderer,&this->floor);


                this->text->render(this->renderer);

                this->text1->render(this->renderer);

                this->text2->render(this->renderer);

                this->mousePositionMeter->render(this->renderer);



                        this->pen->renderDrawing(this->renderer);

                        for(Throwable *obj:this->army){
                       	obj->render(this->renderer);
                        }

                this->objTelemetryBox->render(this->renderer);
                this->jumper->render(this->renderer);
//                solver->drawSlopeField(renderer,skyColor);
                SDL_SetRenderDrawColor(this->renderer,this->penColor.r,this->penColor.g,this->penColor.b,255);
//                solver->drawCurve(renderer,(SDL_FPoint){(float)currentState.mouseX1,(float)currentState.mouseY1},0.1,6000);
                this->notification->render(this->renderer);

            SDL_RenderPresent(this->renderer);
            this->currentState.mask&=N_LOAD_LEVEL_MASK;


	}
	void Game::settingsLoader(int argc,char* arg1,GameVariables& vars){


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
	
	Game::~Game(){


	delete(counter);
        delete(added);
	delete(jumper);
        delete(text);
        delete(text1);
        delete(text2);
        delete(txtr);
        delete(notification);
        delete(txt);
        delete(pen);
        delete(spr);
        //delete(field);

        std::cout<<"Tamanho de obstacles: "<<this->level->getObstacleCount()<<"\n";
        std::cout<<"Tamanho de army: "<<this->army.size()<<"\n";
        std::cout<<"Tamanho de shockwaves: "<<this->shockwaves.size()<<"\n";
        std::cout<<"Tamanho de planets: "<<this->level->getPlanetCount()<<"\n";

        level->~Level();

        std::cout<<"Tamanho de obstacles: "<<this->level->getObstacleCount()<<"\n";
        for(Throwable* thing:this->army){
                    delete(thing);
                    this->army.pop_back();
        }
        std::cout<<"Tamanho de army: "<<this->army.size()<<"\n";
        for(Sprite*sprite:this->shockwaves){


            delete(sprite);

            this->shockwaves.pop_back();


        }
        std::cout<<"Tamanho de shockwaves: "<<this->shockwaves.size()<<"\n";

        std::cout<<"Tamanho de planets: "<<this->level->getPlanetCount()<<"\n";

        SDL_DestroyTexture(this->map);
        SDL_DestroyTexture(this->effects);
        SDL_DestroyTexture(this->S_H_A_P_E_S);
        SDL_DestroyTexture(this->obstacleLayer);

        SDL_DestroyRenderer(this->renderer);
        SDL_DestroyWindow(this->win);

        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        std::cout<<"Cheguei aqui\n";
        
	
	
	}
	void Game::handleKeyCont(void){

	if (KEYBOARD[SDL_SCANCODE_LEFT])
                {
                    this->jumper->movePos(-15,0);
                }
                if (KEYBOARD[SDL_SCANCODE_N])
                {
                    this->currentState.mask|=NEW_OBSTACLE_MASK;
                    this->nPresses++;


                }
                else
                {
                if(nPresses>0){
                    this->currentState.mask&=N_NEW_OBSTACLE_MASK;
                    this->nPresses=0;

                    this->level->addBox(added);
                    }


                }

                if (KEYBOARD[SDL_SCANCODE_RIGHT])
                {

                    this->jumper->movePos(15,0);
                }

                if (KEYBOARD[SDL_SCANCODE_DOWN])
                {
                }


                if (KEYBOARD[SDL_SCANCODE_D])
                {
                    this->currentState.mask|=DRAW_MASK;
                }
                else
                {
                    this->currentState.mask&=N_DRAW_MASK;
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
