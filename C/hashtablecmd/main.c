#include "Includes/preprocessor.h"
hashtablecomp* cmdLine=NULL;
int main(int argc, char ** argv){

cmdLine=initCmdLine(commands);

runCmdLine(cmdLine);

destroyHashTableComp(cmdLine);
	return 0;
}
