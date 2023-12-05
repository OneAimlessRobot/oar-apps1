#ifndef HASHTABLECMD_H
#define HASHTABLECMD_H

#define ARGVMAX 100
#define LINESIZE 1024
hashtablecomp* initCmdLine(cmdstruct commands[]);

void runCmdLine(hashtablecomp* cmdLookupTable);

#endif
