#include "ImportsAndDefines.hpp"

extern const char* fontPath;

//                                FEDCBA9876543210
#define TRAILS_MASK            (0b0000000000000001)
#define COLLISIONS_MASK        (0b0000000000000010)
#define NEW_OBSTACLE_MASK      (0b0000000000000100)
#define ARMY_MASK              (0b0000000000001000)
#define RUN_MASK               (0b0000000000010000)
#define IS_JUMPING_MASK        (0b0000000000100000)
#define REMOVE_ENTITIES_MASK   (0b0000000001000000)
#define THROWABLE_ADD_MASK     (0b0000000010000000)
#define DRAW_MASK              (0b0000000100000000)
//    #define UNDEFINED_MASK         (0b0000001000000000)
//    #define UNDEFINED_MASK         (0b0000010000000000)
//    #define UNDEFINED_MASK         (0b0000100000000000)
//    #define UNDEFINED_MASK         (0b0001000000000000)
//    #define UNDEFINED_MASK         (0b0010000000000000)
//    #define UNDEFINED_MASK         (0b0100000000000000)
//    #define UNDEFINED_MASK         (0b1000000000000000)



#define N_TRAILS_MASK          (0b1111111111111110)
#define N_COLLISIONS_MASK      (0b1111111111111101)
#define N_NEW_OBSTACLE_MASK    (0b1111111111111011)
#define N_ARMY_MASK            (0b1111111111110111)
#define N_RUN_MASK             (0b1111111111101111)
#define N_IS_JUMPING_MASK      (0b1111111111011111)
#define N_REMOVE_ENTITIES_MASK (0b1111111110111111)
#define N_THROWABLE_ADD_MASK   (0b1111111101111111)
#define N_DRAW_MASK            (0b1111111011111111)
//    #define N_UNDEFINED_MASK       (0b1111110111111111)
//    #define N_UNDEFINED_MASK       (0b1111101111111111)
//    #define N_UNDEFINED_MASK       (0b1111011111111111)
//    #define N_UNDEFINED_MASK       (0b1110111111111111)
//    #define N_UNDEFINED_MASK       (0b1101111111111111)
//    #define N_UNDEFINED_MASK       (0b1011111111111111)
//    #define N_UNDEFINED_MASK       (0b0111111111111111)


class Game{

private:
        
        GameVariables currentConstants;
        GameState currentState;
	SDL_Window* win;
	SDL_Renderer* renderer;
		SDL_Texture* S_H_A_P_E_S,*obstacleLayer,*map,*effects;
            int nPresses,
                x,
                y,
                desiredDelta;
	
        SDL_DisplayMode mode;


        SDL_Color sunColor,
                    skyColor,
                    jumperTrailColor,
                    floorColor,
                    penColor,
                    obstacleColor,
                    jumperColor;

	 Jumper*jumper;
      Obstacle *added;
        Pen* pen;
        textBox * txt,* text,* text1,* text2,*objTelemetryBox,*mousePositionMeter;
	FadingTexture* notification;
	 LTexture* txtr;
	 Sprite*spr;
	Level*level;
	ForceField*field;
	//ODESolver*solver=new ODESolver(0, 0, mode.w,mode.h,10,10,yFunc);

        const Uint8* KEYBOARD;
        SDL_FRect floor;
	
	
        clockCounter*counter;
	SDL_Event e;

        
		
	std::vector<Throwable*> army;
        std::vector<Sprite*> shockwaves;
public:
	Game(int argc,char* argv1);
	void handleKeyCont(void);
	void settingsLoader(int argc,char* arg1,GameVariables& vars);
	~Game();
	void renderText();
	void handleEvents(SDL_Event event, const Uint8 *KEYBOARD,Jumper* jumper,float*fps,GameState &state);
	void renderEverything();
	void updateMovements(int delta,SDL_FPoint* startPos);
	void misc();
	void listOperations(Pen*pen,Level* currentLevel,ForceField* field,std::vector<Throwable*> &army,Jumper*jumper,GameState &currentState,int thickness,SDL_Renderer*renderer);
	void handleMouse(Uint32 button);
	void gameLoop();

};
