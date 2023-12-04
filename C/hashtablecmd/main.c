#include "Includes/preprocessor.h"
hashtablecomp* cmdLine=NULL;
int main(int argc, char ** argv){

cmdLine=initCmdLine();

runCmdLine(cmdLine);


	return 0;
}
