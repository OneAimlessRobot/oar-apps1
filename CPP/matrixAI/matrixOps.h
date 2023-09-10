

Matrix* createNullMatrix(int h,int w);

Matrix* createIdentityMatrix(int n);

void linearSumRow(Matrix*matrix,int firstRow,int secRow,float coefficient);

void multLine(Matrix*matrix, int row,float coefficient);

void switchLines(Matrix*matrix,int firstRow,int secRow);

int cmpLines(Matrix*matrix,int index1,int index2);

void sortLines(Matrix*matrix);

void destroyMatrix(Matrix* matrix);

void testOP1(Matrix*matrix,int index1);
void testOP2(Matrix*matrix,int index1,int index2,int var);

Matrix* getInverseAndPutInRRF(Matrix*matrix);

Matrix* matrixMult(Matrix*m1,Matrix*m2);

Matrix* matrixPower(Matrix*m1,int k);