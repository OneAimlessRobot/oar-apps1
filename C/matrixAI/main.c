
#include "Includes/preprocessorStuff.h"




int main(int argc,char** argv){

	if(argc<1){
		
		printf("Erro n meteste o nome do ficheiro da matrix. (path)\nOu o tamanho da matrix identidade a ser computada\nOu o ficheiro de destino da matrix identidade criada");
		return 2;

}
	Matrix* mat1=loadMatrix(argv[1]);
	Matrix*mat2= matrixCopy(mat1);
	Matrix*inv=getInverseAndPutInRRF(mat1);
	printf("%d\n",isRRF(mat1));
	printf("\n\n\n\nMatrix Original\n\n\n\n");;
	printMatrix(mat2);
	printf("\n\n\n\nResultado Inversão\n\n\n\n");;
	printMatrix(mat1);
	printf("\n\n\n\n\nMatrix Inversa\n\n\n\n");;
	printMatrix(inv);
	printf("\n\n\n\nProduto entre Inversa e original\n\n\n\n");
	Matrix* prod=matrixMult(inv,mat2);
	printMatrix(prod);;
	destroyMatrix(mat1);
	destroyMatrix(mat2);
	destroyMatrix(inv);
	destroyMatrix(prod);

	return 0;



}
