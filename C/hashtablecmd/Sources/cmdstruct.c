#include "../Includes/preprocessor.h"
#include "../Includes/cmdstruct.h"




int compareCmds(void* cmd1,void*cmd2){

	cmdstruct* var1= (cmdstruct*)cmd1;
	cmdstruct* var2= (cmdstruct*)cmd2;

	return strcmp(var1->cmdname,var2->cmdname);
	

}

int64_t hashCmd(char* cmd){

 char* mem= ((cmdstruct*)(cmd))->cmdname;

u_int64_t hash= 5381;

	u_int64_t count=0;

for(;count<CMDMAXLENGTH+1;count++){

hash= ((hash << 5) + hash) +mem[count];
}
return hash;


}
cmdstruct* spawnCmdStruct(char* name, u_int64_t numOfArgs, void(*cmd)(u_int64_t, void**),char* helpdesc){

cmdstruct* result= malloc(sizeof(cmdstruct));

memset(result->cmdname,0,CMDMAXLENGTH+1);
memcpy(result->cmdname,name,CMDMAXLENGTH);

result->numOfArgs=numOfArgs;
result->helpdesc=helpdesc;
result->cmd=cmd;

return result;


}

void destroyCmdStruct(cmdstruct* cmd){

	free(cmd);

}