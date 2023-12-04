#include "../Includes/preprocessor.h"
#include "../Includes/cmdfuncexmpl.h"
#include "../Includes/cmdstruct.h"
#include "../Includes/globals.h"
extern hashtablecomp* cmdLine;
extern cmdstruct commands[NOFCOMMANDS];
void addNums(u_int64_t argc, void** argv){

	if(argc!=2){

	printf("Numero de argumentos errado!!");

	}
	else{
	int64_t arg1,arg2;
	sscanf((char*)argv[0],"%ld",&arg1);
	sscanf((char*)argv[1],"%ld",&arg2);
	printf("%ld\n", arg1+arg2);

	}

}

void multNums(u_int64_t argc, void** argv){


	if(argc!=2){

	printf("Numero de argumentos errado!!");
	}
	else{
	
	double arg1,arg2;
	sscanf((char*)argv[0],"%lf",&arg1);
	sscanf((char*)argv[1],"%lf",&arg2);
	printf("%lf\n", arg1*arg2);
	}

}
void myname(u_int64_t argc, void** argv){

	if(argc!=1){

	printf("Numero de argumentos errado!!");
	}
	else{
	
	printf("%s\n",(char*)argv[0]);
	}

}

void myiq(u_int64_t argc, void** argv){

	
	printf("O teu qi neste momento e: %d\n",genRandInt(0,10000));


}

void sair(u_int64_t argc, void** argv){
	destroyHashTableComp(cmdLine);
	freeStrArr((char**)argv,argc);
	exit(-1);

}


void showall(u_int64_t argc, void** argv){



			for(u_int64_t j=0;j<NOFCOMMANDS;j++){
			
			printf("%s- %s\n",(char*)commands[j].cmdname,(char*)commands[j].helpdesc);
			
			
			}
			printf("\n");
}
