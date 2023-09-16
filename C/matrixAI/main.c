
#include "Includes/preprocessorStuff.h"




int main(int argc,char** argv){

	/*if(argc<3){
		
		printf("Erro n meteste o nome do ficheiro da matrix. (path)\nOu o tamanho da matrix identidade a ser computada\nOu o ficheiro de destino da matrix identidade criada");
		return 2;

}*/

	Matrix*mat=createIdentityMatrix(4);
	printMatrix(mat);
	switchLines(mat,1,2);
	switchLines(mat,0,3);
	printMatrix(mat);
	sortLines(mat);
	printMatrix(mat);
	destroyMatrix(mat);


	return 0;



}
