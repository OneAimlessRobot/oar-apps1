#include "../Includes/preprocessor.h"
#include "Includes/maestro.h"


int main(int argc, char ** argv){
	SDL_Init(SDL_INIT_AUDIO);
        Mix_Init(MIX_INIT_MP3);
        Mix_OpenAudio(48000,MIX_DEFAULT_FORMAT,2,1024);


	if(argc<2){

		perror("File not found\n");
		printf("%s\n",argv[1]);
		exit(-1);

	}
	
	metadata* meta=parseheader(argv[1]);
	printheader(meta);
	int fd=open(argv[1],O_RDWR,0777);

	musicPlayingMaestro(meta,fd);
	close(fd);
	Mix_CloseAudio();
        Mix_Quit();
        SDL_Quit();
	free(meta->pairs);
	free(meta);


	return 0;
}

