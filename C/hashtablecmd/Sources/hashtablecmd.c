#include  "../Includes/preprocessor.h"
#include "../Includes/hashtablecomp.h"
#include "../Includes/hashtablecmd.h"
#include "../Includes/auxFuncs.h"
#include "../Includes/cmdstruct.h"
#include "../Includes/globals.h"

extern cmdstruct commands[NOFCOMMANDS];
extern comparator cmdcomparator;
extern hasher cmdhasher;
hashtablecomp* initCmdLine(){

	
	hashtablecomp* result= initHashTableComp(sizeof(cmdstruct),&cmdcomparator,&cmdhasher);

	for(int i=0;i<NOFCOMMANDS;i++){

		cmdstruct* newcmd= spawnCmdStruct(commands[i].cmdname,commands[i].numOfArgs,commands[i].cmd,commands[i].helpdesc);
		addToHTComp(&result,newcmd);

	}

	return result;


}

static char** buildArgv(int numOfAllowedArgs){
	if(!numOfAllowedArgs){

		return NULL;

	}
	int numOfArgs=0;
	char** args= malloc(sizeof(char*)*( numOfAllowedArgs));
	
	memset(args,0,sizeof(char*)*( numOfAllowedArgs));
	
	char cmdBuff[CMDMAXLENGTH+1]={0};
	
	while(numOfArgs<numOfAllowedArgs){
		scanf("%s",&cmdBuff);
                args[numOfArgs]=malloc(CMDMAXLENGTH+1);
                memset(args[numOfArgs],0,CMDMAXLENGTH+1);
                memcpy(args[numOfArgs],cmdBuff,CMDMAXLENGTH);
		memset(cmdBuff,0,CMDMAXLENGTH+1);
		numOfArgs++;
	
	}
	
	return args;



}

int runCmdLine(hashtablecomp* cmdLookupTable){
	
	do{
		printf("HashShell (input goes here): ");
		char var[CMDMAXLENGTH+1]={0};
		scanf("%s",&var);
        	char cmdBuff[CMDMAXLENGTH+1]={0};
                memcpy(cmdBuff,var,CMDMAXLENGTH);
		cmdstruct* cmd =spawnCmdStruct(cmdBuff,0,NULL,NULL);
		cmdstruct* result= getHTElemComp(cmdLookupTable,(void*)cmd);
		free(cmd);
		if(!result){
		continue;
		}
		char** argv= buildArgv(result->numOfArgs);
		result->cmd(result->numOfArgs,(void**)argv);
		freeStrArr(argv,result->numOfArgs);
	}while(1);



}
