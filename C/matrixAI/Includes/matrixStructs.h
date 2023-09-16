
#define EPSILON (0.0001f)
typedef struct Matrix{

	int h,w;
	float ** table;


}Matrix;
typedef struct pivot{

	int x,y;
	float value;

}pivot;

typedef struct rowSwitch{

	int row1,row2;

}rowSwitch;

typedef struct rowMult{

	int row;
	float coeff;
}rowMult;

typedef struct rowComb{
	
	int first,sec;
	float secCoeff;

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
