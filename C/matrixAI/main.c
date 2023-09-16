
#include "Includes/preprocessorStuff.h"




int main(int argc,char** argv){

	if(argc<1){
		
		printf("Erro n meteste o nome do ficheiro da matrix. (path)\nOu o tamanho da matrix identidade a ser computada\nOu o ficheiro de destino da matrix identidade criada");
		return 2;

}
	Matrix* mat1=loadMatrix(argv[1]);
	Matrix*mat2= matrixCopy(mat1);
	Matrix*inv=getInverseAndPutInRRF(mat1);


	destroyMatrix(mat1);
	destroyMatrix(inv);
	destroyMatrix(mat2);

	return 0;



}
