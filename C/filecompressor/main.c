#include "Includes/preprocessor.h"

char * menu="---------------------------------------------------------\nOpçoes para usares o programa:\nc -> Comprimir\nd -> Descomprimir\ns -> Sair\n----------------------------------------\n";
int main(int argc, char ** argv){
	
	if(argc<2){

		perror("O numero de argumentos e invalido. Precisas de uma path source e de uma path destino\n");
		exit(-1);
	}
	
	char c;
	do{

	//system("clear");
	printf("%s",menu);
	if(scanf("%c",&c)<1){
                int ch;
                while((ch=getc(stdin))!=EOF && ch != '\n');
                continue;
        }
	
	switch(c){
		case 'c':
			compress(argv[1],argv[2]);
			break;
		case 'd':
			decompress(argv[1],argv[2]);
			break;
		case 's':
			exit(0);
		default:
			break;

	}

	}while(c!='s');
	
}
