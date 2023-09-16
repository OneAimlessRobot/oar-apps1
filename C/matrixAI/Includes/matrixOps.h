
Matrix* createNullMatrix(int h,int w);


Matrix* createIdentityMatrix(int n);
void linearSumRow(Matrix*matrix,int firstRow,int secRow,float coefficient);
void multLine(Matrix*matrix, int row,float coefficient);
void switchLines(Matrix*matrix,int firstRow,int secRow);
int cmpLines(Matrix*matrix,int index1,int index2);
void sortLines(Matrix*matrix);
Matrix* loadMatrix(char *fileName);
void destroyMatrix(Matrix* matrix);
void testOP1(Matrix*matrix,int index1);
void testOP2(Matrix*matrix,int index1,int index2,int var);

Matrix* getInverseAndPutInRRF(Matrix*matrix);

Matrix* matrixMult(Matrix*m1,Matrix*m2);

void matrixPower(Matrix**m1,int k);
void scaleMatrix(Matrix* matrix, float coeff);
void printMatrix(Matrix* matrix);
void writeMatrix(Matrix* matrix,char* fileName);
Matrix* matrixCopy(Matrix* matrix);
void matrixOverwrite(Matrix* matrix1,Matrix*matrix2);
