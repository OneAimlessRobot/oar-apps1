

class ThrowableGame{


GameState currentState=(GameState){0,0,0,0,0,0,0,0b0000000000010000};


    ThrowableGame(SDL_Window* win, SDL_Renderer* renderer);

void handleEvents(SDL_Event event, const Uint8 *KEYBOARD,Jumper* jumper,float*fps,GameState &state);

void listOperations(Level* currentLevel,ForceField* field,std::vector<Throwable*> &army,SDL_Renderer*renderer);

void settingsLoader(int argc,char* arg1,GameVariables& vars);

    void gameLoop();

    ThrowableGame();
};