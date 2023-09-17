//Memory and IO related

Matrix* createNullMatrix(int h,int w);
Matrix* createIdentityMatrix(int n);
Matrix* matrixCopy(Matrix*src);
Matrix* loadMatrix(char *fileName);
void printMatrix(Matrix* matrix);
void writeMatrix(Matrix* matrix,char* fileName);
void matrixOverwrite(Matrix* matrix1,Matrix*matrix2);
void destroyMatrix(Matrix* matrix);
void destroyRowCombArr(rowCombArr*arr);
void destroyRowMultArr(rowMultArr*arr);
void destroyRowSwitchArr(rowSwitchArr*arr);


//Basic Transformations
void linearSumRow(Matrix*matrix,int firstRow,int secRow,double coefficient);
void multLine(Matrix*matrix, int row,double coefficient);
void switchLines(Matrix*matrix,int firstRow,int secRow);
int cmpLines(Matrix*matrix,int index1,int index2);



//Aux Functions to invert matrices

//These perform transformations and return them in apropriate arrays to be used...
rowSwitchArr* sortLines(Matrix*matrix);
rowCombArr* rowsWar(Matrix* matrix);
rowCombArr* reverseRowsWar(Matrix* matrix);
rowMultArr* makeAllPivotsEqualOne(Matrix*mat);

//..On other matrices through these functions
void applyRowCombs(Matrix*matrix,rowCombArr* rcArr);
void applyRowSwitches(Matrix*matrix,rowSwitchArr* rsArr);
void applyRowMults(Matrix*matrix,rowMultArr* rmArr);

//Actual operations

//RRF functions
void putInRRF(Matrix*matrix);
Matrix* getInverseAndPutInRRF(Matrix*matrix);

//Matrix getters
Matrix* matrixMult(Matrix*m1,Matrix*m2);
void matrixPower(Matrix**m1,int k);
void scaleMatrix(Matrix* matrix, double coeff);
double getDet(Matrix*matrix);
pivotArr* getPivotArray(Matrix*matrix);


//Boolean functions
int isInvertible(Matrix*matrix);
int isSquareMatrix(Matrix*matrix);
int isSorted(Matrix*matrix);
int isRRF(Matrix*matrix);


//Fun fucntions


rowCombArr* genRandTransformations(Matrix*mat);
Matrix* generateWordMatrix(const char* nullTermedString);
