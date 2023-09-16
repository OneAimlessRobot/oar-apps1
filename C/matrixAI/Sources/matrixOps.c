#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Includes/matrixStructs.h"
#include "../Includes/matrixOps.h"

Matrix* createNullMatrix(int h,int w){

	Matrix * matrix= malloc(sizeof(Matrix));
	matrix->table=malloc(sizeof(float*)*h);
	matrix->h=h;
	matrix->w=w;
	for(int i=0;i<h;i++){
		
		matrix->table[i]=malloc(sizeof(float)*w);
		for(int j=0;j<w;j++){

			matrix->table[i][j]= 0.0f;	
		}

	}
	return matrix;
	




}
Matrix* createIdentityMatrix(int n){

	Matrix* mat= createNullMatrix(n,n);
	for(int i=0;i<n;i++){


		mat->table[i][i]= 1.0f;
	
	}
	return mat;
	



}
void linearSumRow(Matrix*matrix,int firstRow,int secRow,float coefficient){

	
	if(firstRow < 0 || secRow <0||firstRow >=matrix->h||secRow >=matrix->h){

			return;
		}
	

        if(coefficient < EPSILON &&coefficient > 0||coefficient>-EPSILON&&coefficient<0){


			return;
		}

	multLine(matrix,secRow,coefficient);
	for(int i=0;i<matrix->w;i++){

	
		matrix->table[firstRow][i]+=matrix->table[secRow][i];

	}


	






}
void multLine(Matrix*matrix, int row,float coefficient){


	  if(row <0 || row>=matrix->h){


                        return;
                }

    
        if(coefficient < EPSILON &&coefficient > 0||coefficient>-EPSILON&&coefficient<0){

                        return;
                }
	for(int i=0;i<matrix->w;i++){


		matrix->table[row][i]*=coefficient;

	}


}
void switchLines(Matrix*matrix,int firstRow,int secRow){


	 if(firstRow < 0 || secRow <0||firstRow >=matrix->h||secRow >=matrix->h){

                        return;
                }
	
	for(int i=0;i<matrix->w;i++){

		float aux=matrix->table[firstRow][i];
		matrix->table[firstRow][i]=matrix->table[secRow][i];
		matrix->table[secRow][i]=aux;
		


	}



}
int cmpLines(Matrix*matrix,int index1,int index2){

	
         if(index1 < 0 || index2 <0||index1 >=matrix->h||index2 >=matrix->h){

                        return 0;;
                }
	
	int pos1=0,pos2=0;
	for(int i=0;i<matrix->w;i++){
		
		if(matrix->table[index1][i]>EPSILON||matrix->table[index1][i]<-EPSILON){

			pos1=i;
		}	i=matrix->w;

	}
	for(int i=0;i<matrix->w;i++){
		
		if(matrix->table[index2][i]>EPSILON||matrix->table[index2][i]<-EPSILON){

			pos2=i;
		}	i=matrix->w;

	}
	printf("%d %d\n",pos1,pos2);
	if(pos1>pos2){

		return 1;
	}
	else{
		if(pos2<pos1){

			return -1;
		}
		else{
			return 0;
		
		}
	}
}

void sortLines(Matrix*matrix){

	int h=matrix->h;
		for(int i=0;i<h-1;i++){

			for( int j=i;j<h;j++){
				
				if(cmpLines(matrix,i,j)>0){
					switchLines(matrix,i,j);
				}
			}
			
		}


}

void destroyMatrix(Matrix* matrix){
	for(int i=0;i<matrix->h;i++){

		free(matrix->table[i]);
		
	}

	free(matrix->table);
	free(matrix);






}

Matrix * loadMatrix(char* fileName){
	
	int h, w;
	FILE* file= fopen(fileName,"r");
	fscanf(file,"%i %i\n",&h,&w);
	Matrix* matrix=createNullMatrix(h,w);
	for(int i=0;i<matrix->h;i++){


		for(int j=0;j<matrix->w;j++){

			fscanf(file,"%f",&matrix->table[i][j]);
		
		}
		fscanf(stdout,"\n");


	}
	fclose(file);

	return matrix;





}
void testOP1(Matrix*matrix,int index1);
void testOP2(Matrix*matrix,int index1,int index2,int var);

Matrix* getInverseAndPutInRRF(Matrix*matrix){








}
Matrix* matrixMult(Matrix*m1,Matrix*m2){
		
		int h1,h2,w1,w2;
		h1=m1->h;
		w1=m1->w;
		h2=m2->h;
		w2=m2->w;
		if(w1!=h2){

			return createNullMatrix(1,1);
		}
		Matrix *result=createNullMatrix(h1,w2);
		for(int i=0;i<h1;i++){

			for(int j=0;j<w2;j++){
					
				for(int k=0;k<w1;k++){

					result->table[i][j]+=m1->table[i][k]*m2->table[k][j];

				}

			}

		}
		return result;
		





}

Matrix* matrixCopy(Matrix*src){

	Matrix* copy= createNullMatrix(src->h,src->w);
	for(int i=0;i<src->h;i++){

		for(int j=0;j<src->w;j++){

			copy->table[i][j]=src->table[i][j];

		}

	}
	copy->h=src->h;
	copy->w=src->w;
	
	return copy;



}

void matrixOverwrite(Matrix*dest,Matrix*src){
	if(dest->w!=src->w||src->h!=dest->h){

		return;
	}
	for(int i=0;i<src->h;i++){

		for(int j=0;j<src->w;j++){

			dest->table[i][j]=src->table[i][j];

		}

	}
	dest->h=src->h;
	dest->w=src->w;
	


}
void matrixPower(Matrix**m1,int k){
	if(k==0){

		return;
	}

	Matrix* result=matrixCopy(*m1);
	Matrix*tmp;
	for(int i=k;i>0;i--){
		printf("\n\n\nANTES:\n\n\n");
		printMatrix(result);
		tmp=matrixMult(result,*m1);
		matrixOverwrite(result,tmp);
		printf("\n\n\nDEPOIS:\n\n\n");
		printMatrix(result);
		destroyMatrix(tmp);
	}
	
	*m1=result;

}

void printMatrix(Matrix* matrix){

	for(int i=0;i<matrix->h;i++){
		for(int j=0;j<matrix->w;j++){
	
			printf("%.2f  ",matrix->table[i][j]);		

		}
		printf("\n\n");
		



	}
	
	
	
	

}

void scaleMatrix(Matrix* matrix, float coeff){

	
        if(coeff < EPSILON &&coeff > 0||coeff>-EPSILON&&coeff<0){


                        return;
        }	

	for(int i=0;i<matrix->h;i++){


		multLine(matrix,i,coeff);

	}




}


void writeMatrix(Matrix* matrix,char* fileName){
	
	if(!matrix){
			printf("Matrix is null at writeMatrix function");
			return;
		}
	FILE* file= fopen(fileName,"w");

	if(!file){

		printf("File does not exist!!!!!\n%s\n",fileName);
		return;

	}
	fprintf(file,"%d %d\n",matrix->h,matrix->w);
	

	for(int i=0;i<matrix->h;i++){


		for(int j=0;j<matrix->w;j++){

			fprintf(file,"%.2f",matrix->table[i][j]);
		
		}

	}



	fclose(file);

}

