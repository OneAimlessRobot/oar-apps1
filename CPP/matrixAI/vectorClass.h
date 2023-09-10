


typedef struct arrayWithCounter
{

    int* array,counter,initSize;

} arrayWithCounter;


int getArraySize(arrayWithCounter* vector);

void addElement(arrayWithCounter*vector,int value);

void arrayInit(arrayWithCounter*vector,int sizeInit);

void getElement(arrayWithCounter*vector,int index);

