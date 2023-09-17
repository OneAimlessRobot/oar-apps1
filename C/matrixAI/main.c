
#include "Includes/preprocessorStuff.h"


void printResultOfMatrix(Matrix*mat);


int main(int argc,char** argv){

	srand(time(NULL));
	if(argc<3){
		
		printf("Erro n meteste o nome do ficheiro da matrix. (path)\nOu o tamanho da matrix identidade a ser computada\nOu o ficheiro de destino da matrix identidade criada\n");
		return 2;

}
	FILE*file=fopen(argv[1],"rw+");
	if(!file){
		printf("ficheiro não existe!!!\n");
		return 1;
	}
	fclose(file);
//	Matrix*mat1=generateWordMatrix("Cerebro");
	Matrix*mat1=loadMatrix(argv[1]);
	
	for(int i=0;i<NUM_OF_CYCLES;i++){
	applyRowCombs(mat1,genRandTransformations(mat1));
	}
	
	printf("\n\n\n\nMATRIZ BARALHADA!!!!!!\n\n\n\n\n");
	
	printMatrix(mat1);
	Matrix*mat2=matrixCopy(mat1);
	writeMatrix(mat1,argv[2]);

	printf("\n\n\n\nMATRIZ RESOLVIDA!!!!!!\n\n\n\n\n");
		
	putInRRF(mat1);
	printMatrix(mat1);

	printResultOfMatrix(mat2);
	destroyMatrix(mat1);
	destroyMatrix(mat2);
	return 0;



}


void printResultOfMatrix(Matrix*mat){


	if(mat->w!=mat->h+1){

		return;
	}
	Matrix* copy=matrixCopy(mat);
	if(!isRRF(copy)){
	putInRRF(copy);
	}	
	char* buff= malloc(mat->h+1);
	memset(buff,0,mat->h+1);
	for(int i=0;i<copy->h;i++){

		buff[i]= (char)(round(copy->table[i][copy->w-1]));
	

	}

	printf("%s\n",buff);
	destroyMatrix(copy);
	free(buff);

	
}
