#include "ImportsAndDefines.hpp"
Game*game=NULL;
void sigint_handler(int signal){
	
	if(game){
		
	delete(game);
	}
	exit(-1);

}
int main(int argc, char** argv){

	game= new Game(argc,argv[1]);
	game->gameLoop();
	if(game){
	delete(game);
	}

return 0;
}



