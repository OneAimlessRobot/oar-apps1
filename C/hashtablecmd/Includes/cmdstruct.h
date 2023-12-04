#ifndef CMDSTRUCT_H
#define CMDSTRUCT_H
#define CMDMAXLENGTH 127
typedef struct cmdstruct{

char cmdname[CMDMAXLENGTH+1];
u_int64_t numOfArgs;
void (*cmd)(u_int64_t,int*,void**);
char* helpdesc;

}cmdstruct;

int compareCmds(void* cmd1,void*cmd2);

int64_t hashCmd(char* cmd);

cmdstruct* spawnCmdStruct(char* name,u_int64_t numOfArgs, void(*cmd)(u_int64_t,int*, void**),char* helpdesc);

void destroyCmdStruct(cmdstruct* cmd);

extern hasher cmdhasher;
extern comparator cmdcomparator;

#endif
