#include "../Includes/preprocessor.h"
#include "../Includes/globals.h"
#include "../Includes/cmdfuncexmpl.h"
#include "../Includes/cmdstruct.h"
#include "../Includes/comparator.h"
#include "../Includes/hasher.h"

cmdstruct commands[NOFCOMMANDS]={
			{"add",2,addNums,"printa a soma dos dois numeros que deres."},
			{"mult",2,multNums,"printa o produto dos dois numeros que deres."},
			{"whoami",1,myname,"Faz echo da string fornecida"},
			{"sair",0,sair,"Sair do programa"},
			{"myiq",0,myiq,"Mostra o teu qi"},
			{"showall",0,showall,"Mostra este menu"}
		};


comparator cmdcomparator = {compareCmds};
hasher cmdhasher = {hashCmd};
