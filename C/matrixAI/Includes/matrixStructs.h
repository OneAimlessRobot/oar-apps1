
typedef struct Matrix{

	int h,w;
	double ** table;


}Matrix;
typedef struct pivot{

	int x,y;
	double value;

}pivot;

typedef struct rowSwitch{

	int row1,row2;

}rowSwitch;

typedef struct rowMult{

	int row;
	double coeff;
}rowMult;

typedef struct rowComb{
	
	int first,sec;
	double secCoeff;

}rowComb;
typedef struct pivotArr{

	pivot*arr;
	int count;


}pivotArr;
typedef struct rowSwitchArr{

	rowSwitch* arr;
	int count;


}rowSwitchArr;

typedef struct rowMultArr{

	rowMult* arr;
	int count;


}rowMultArr;

typedef struct rowCombArr{

	rowComb* arr;
	int count;


}rowCombArr;
