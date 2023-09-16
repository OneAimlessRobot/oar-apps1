
Matrix* createNullMatrix(int h,int w);


Matrix* createIdentityMatrix(int n);
void linearSumRow(Matrix*matrix,int firstRow,int secRow,float coefficient);
void multLine(Matrix*matrix, int row,float coefficient);
void switchLines(Matrix*matrix,int firstRow,int secRow);
int cmpLines(Matrix*matrix,int index1,int index2);

rowSwitchArr* sortLines(Matrix*matrix);


rowCombArr* rowsWar(Matrix* matrix);

rowCombArr* reverseRowsWar(Matrix* matrix);

rowMultArr* makeAllPivotsEqualOne(Matrix*mat);

void applyRowCombs(Matrix*matrix,rowCombArr* rcArr);

void applyRowSwitches(Matrix*matrix,rowSwitchArr* rsArr);

void applyRowMults(Matrix*matrix,rowMultArr* rmArr);

pivotArr* getPivotArray(Matrix*matrix);

int factorial(int n);
int isSorted(Matrix*matrix);
int isRRF(Matrix*matrix);


Matrix* loadMatrix(char *fileName);
void destroyMatrix(Matrix* matrix);
void testOP1(Matrix*matrix,int index1);
void testOP2(Matrix*matrix,int index1,int index2,int var);

Matrix* getInverseAndPutInRRF(Matrix*matrix);

Matrix* matrixMult(Matrix*m1,Matrix*m2);
Matrix* matrixCopy(Matrix*src);
void matrixPower(Matrix**m1,int k);
void scaleMatrix(Matrix* matrix, float coeff);
void printMatrix(Matrix* matrix);
void writeMatrix(Matrix* matrix,char* fileName);
Matrix* matrixCopy(Matrix* matrix);
void matrixOverwrite(Matrix* matrix1,Matrix*matrix2);
