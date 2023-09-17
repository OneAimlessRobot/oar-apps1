#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "../Includes/auxFuncs.h"
#include "../Includes/matrixStructs.h"
#include "../Includes/matrixOps.h"
Matrix* createNullMatrix(int h,int w){

	Matrix * matrix= malloc(sizeof(Matrix));
	matrix->table=malloc(sizeof(double*)*h);
	matrix->h=h;
	matrix->w=w;
	for(int i=0;i<h;i++){
		
		matrix->table[i]=malloc(sizeof(double)*w);
		for(int j=0;j<w;j++){

			matrix->table[i][j]= 0.0;	
		}

	}
	return matrix;
	




}
Matrix* createIdentityMatrix(int n){

	Matrix* mat= createNullMatrix(n,n);
	for(int i=0;i<n;i++){


		mat->table[i][i]= 1.0;
	
	}
	return mat;
	



}


double getDet(Matrix*matrix){

	if(matrix->w!=matrix->h){
		
		return 0.0f;

	}

	Matrix*copy=matrixCopy(matrix);
	putInRRF(copy);
	pivotArr*parr=getPivotArray(matrix);
	double result=1.0f;
	for(int i=0;i<parr->count;i++){

		result*=parr->arr[i].value;

	}
	free(parr->arr);
	free(parr);
	destroyMatrix(copy);
	return result;


}


int isSquareMatrix(Matrix*matrix){

	return matrix->w==matrix->h;



}
int isInvertible(Matrix*matrix){


		return isSquareMatrix(matrix)&&!lessThanEpsilon(getDet(matrix));



}
void putInRRF(Matrix*matrix){

	while(!isRRF(matrix)){
		
		destroyRowSwitchArr(sortLines(matrix));
		destroyRowMultArr(makeAllPivotsEqualOne(matrix));
		destroyRowCombArr(rowsWar(matrix));
		destroyRowCombArr(reverseRowsWar(matrix));
	
	}

}



void linearSumRow(Matrix*matrix,int firstRow,int secRow,double coefficient){

	
	if(firstRow < 0 || secRow <0||firstRow >=matrix->h||secRow >=matrix->h){

			return;
		}
	

        if(lessThanEpsilon(coefficient)){


			return;
		}

	for(int i=0;i<matrix->w;i++){

	
		matrix->table[firstRow][i]+=matrix->table[secRow][i]*coefficient;

	}


	






}

int isSorted(Matrix*matrix){
	int result=1;
	for(int i=1;i<matrix->h;i++){
		result=result&&(cmpLines(matrix,i-1,i)<=0);

	}
	return result;



}

void multLine(Matrix*matrix, int row,double coefficient){


	  if(row <0 || row>=matrix->h){


                        return;
                }

    
        if(lessThanEpsilon(coefficient)){
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

		double aux=matrix->table[firstRow][i];
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
		
		if(!lessThanEpsilon(matrix->table[index1][i])){
			pos1=i;
			i=matrix->w;
		}
	}
	for(int i=0;i<matrix->w;i++){
		
		if(!lessThanEpsilon(matrix->table[index2][i])){
			
			pos2=i;
			i=matrix->w;

		}
	}
	if(pos1>pos2){

		return 1;
	}
	else{
		if(pos1<pos2){

			return -1;
		}
		else{
			return 0;
		
		}
	}
}

rowSwitchArr* sortLines(Matrix*matrix){
	rowSwitchArr*rsArr=malloc(sizeof(rowSwitchArr));
	rsArr->arr=malloc(sizeof(rowSwitch)*factorial(matrix->h));
	int cursor=0;
	int h=matrix->h;
		for(int i=0;i<h-1;i++){

			for( int j=i+1;j<h;j++){
				
				if(cmpLines(matrix,i,j)>0){
					
					rsArr->arr[cursor].row1=i;
					rsArr->arr[cursor++].row2=j;
					switchLines(matrix,i,j);
				}
			}
			
		}
	rsArr->count=cursor;
	return rsArr;


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

			fscanf(file,"%lf",&matrix->table[i][j]);
		
		}
		fscanf(stdout,"\n");


	}
	fclose(file);

	return matrix;





}


rowCombArr* rowsWar(Matrix*matrix){
	
	rowCombArr* rcArr= malloc(sizeof(rowCombArr));
	rcArr->arr=malloc(sizeof(rowComb)*factorial(matrix->h));
	int cursor=0;
	for(int i=0;i<matrix->h-1;i++){

		for(int j=i+1;j<matrix->h;j++){

			if(cmpLines(matrix,i,j)==0){
				
				rcArr->arr[cursor].first=j;
				rcArr->arr[cursor].sec=i;
				rcArr->arr[cursor++].secCoeff=1.0;
				linearSumRow(matrix,j,i,-1.0);
				
			}

		}


	}
	rcArr->count=cursor;
	return rcArr;






}


rowCombArr* reverseRowsWar(Matrix*matrix){
	
	rowCombArr* rcArr= malloc(sizeof(rowCombArr));
	rcArr->arr=malloc(sizeof(rowComb)*factorial(matrix->h));
	int cursor=0;
	pivotArr* parr= getPivotArray(matrix);
	for(int i=matrix->h-1;i>-1;i--){
		for(int j=i-1;j>-1;j--){
			double targetNum=matrix->table[j][parr->arr[i].x];
			double currCoeff=-targetNum/parr->arr[i].value;
				rcArr->arr[cursor].first=j;
				rcArr->arr[cursor].sec=i;
				rcArr->arr[cursor++].secCoeff=currCoeff;
			linearSumRow(matrix,j,i,currCoeff);
		}


	}
	free(parr->arr);
	free(parr);
	rcArr->count=cursor;
	return rcArr;
	
}

void applyRowCombs(Matrix*matrix,rowCombArr* rcArr){

	for(int i=0;i<rcArr->count;i++){
		rowComb comb=rcArr->arr[i];
		linearSumRow(matrix,comb.first,comb.sec,comb.secCoeff);

	}

	free(rcArr->arr);
	free(rcArr);




}
void applyRowSwitches(Matrix*matrix,rowSwitchArr* rsArr){


	
	for(int i=0;i<rsArr->count;i++){
		rowSwitch swtch=rsArr->arr[i];
		switchLines(matrix,swtch.row1,swtch.row2);
	}

	free(rsArr->arr);
	free(rsArr);


}
void applyRowMults(Matrix*matrix,rowMultArr* rmArr){
	
	
	for(int i=0;i<rmArr->count;i++){
		rowMult mult=rmArr->arr[i];
		multLine(matrix,mult.row,mult.coeff);
	}

	free(rmArr->arr);
	free(rmArr);
	



}

int isRRF(Matrix*matrix){

	pivotArr* parr=getPivotArray(matrix);
	int result=1;
	for(int i=0;i<parr->count-1;i++){
		
		int pivotsCondition=parr->arr[i].x<parr->arr[i+1].x;
		result=result&&pivotsCondition;
	
	}
	for(int i=0;i<parr->count;i++){
		
		result=result&&lessThanEpsilon(parr->arr[i].value-1.0f);
	
	}
	int*pivotCols=malloc(sizeof(int)*parr->count);
	for(int i=0;i<parr->count;i++){
		pivotCols[i]=parr->arr[i].y;
	
	
	}
	for(int i=0;i<parr->count;i++){
		pivot curr=parr->arr[i];
		for(int j=curr.y-1;j>-1;j--){
			double target=matrix->table[j][curr.x];
			result=result&&(lessThanEpsilon(target));
		
		}
	
	
	}
	free(pivotCols);
	free(parr->arr);
	free(parr);
	return result;

}

Matrix* getInverseAndPutInRRF(Matrix*matrix){

	if(matrix->w!=matrix->h){

		return NULL;
	}
	int n=matrix->w;
	Matrix*image=createIdentityMatrix(n);
	while(!isRRF(matrix)){
		
		applyRowSwitches(image,sortLines(matrix));
		applyRowMults(image,makeAllPivotsEqualOne(matrix));
		applyRowCombs(image,rowsWar(matrix));
		applyRowCombs(image,reverseRowsWar(matrix));
	
	}
		
	return image;

}

rowMultArr* makeAllPivotsEqualOne(Matrix* matrix){
	rowMultArr* rmArr=malloc(sizeof(rowMultArr));
	rmArr->arr=malloc(sizeof(rowMult)*matrix->h);
	rmArr->count=matrix->h;
	int h=matrix->h;
	pivotArr* parr= getPivotArray(matrix);
	
	for(int i=0;i<h;i++){
		
		double currCoeff=1.0f/matrix->table[parr->arr[i].y][parr->arr[i].x];
		rmArr->arr[i].row=i;
		rmArr->arr[i].coeff=currCoeff;
		multLine(matrix,i,currCoeff);

	}
	free(parr->arr);
	free(parr);

	return rmArr;


}


pivotArr* getPivotArray(Matrix*matrix){
	
	pivotArr* parr= malloc(sizeof(pivotArr));
	parr->arr=malloc(sizeof(pivot)*matrix->h);
	pivot*arr=parr->arr;
	parr->count=0;
	for(int j=0;j<matrix->h;j++){
	for(int i=0;i<matrix->w;i++){
		if(!lessThanEpsilon(matrix->table[j][i])){

			parr->count++;
			arr[j].value=matrix->table[j][i];
			arr[j].x=i;
			arr[j].y=j;	
			i=matrix->w;
		}
	}
	}
	return parr;
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
		tmp=matrixMult(result,*m1);
		matrixOverwrite(result,tmp);
		destroyMatrix(tmp);
	}
	
	*m1=result;

}

void printMatrix(Matrix* matrix){

	for(int i=0;i<matrix->h;i++){
		for(int j=0;j<matrix->w;j++){
	
			printf("%.0lf  ",matrix->table[i][j]);		

		}
		printf("\n\n");
		



	}
	
	
	
	

}

void scaleMatrix(Matrix* matrix, double coeff){

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

			fprintf(file,"%.20lf ",matrix->table[i][j]);
		
		}
		fprintf(file,"\n");

	}



	fclose(file);

}

rowCombArr* genRandTransformations(Matrix*mat){
	int numOfOps=NUM_OF_TRANSFORMATIONS;
	rowCombArr* rcArr=malloc(sizeof(rowCombArr));
	rcArr->arr=malloc(sizeof(rowComb)*numOfOps);
	rcArr->count=numOfOps;
	int minRow=0,maxRow=mat->h-1;
	double minVal=-5.0,maxVal=5.0;
	for(int i=0;i<rcArr->count;i++){


		rcArr->arr[i].first=genRandInt(minRow,maxRow);
		
		int first=rcArr->arr[i].first;
		
		do{
		rcArr->arr[i].sec=genRandInt(minRow,maxRow);
		
		}while(rcArr->arr[i].sec==first);
		
		rcArr->arr[i].secCoeff=genRanddouble(minVal,maxVal);
		

	}
	return rcArr;

}
void destroyRowCombArr(rowCombArr*arr){


	free(arr->arr);
	free(arr);





}


void destroyRowMultArr(rowMultArr*arr){


	free(arr->arr);
	free(arr);





}
void destroyRowSwitchArr(rowSwitchArr*arr){


	free(arr->arr);
	free(arr);





}

Matrix* generateWordMatrix(const char* nullTermedString){

	int matrixHeight= strlen(nullTermedString);
	
	Matrix* mat=createNullMatrix(matrixHeight,matrixHeight+1);
	
	for(int i=0;i<mat->h;i++){

		mat->table[i][i]=1.0;

	}
	
	for(int i=0;i<mat->h;i++){

		mat->table[i][mat->w-1]= (double)((int)(nullTermedString[i]));
	
	}

	return mat;

}
