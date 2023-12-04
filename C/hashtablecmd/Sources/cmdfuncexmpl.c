#include "../Includes/preprocessor.h"
#include "../Includes/cmdfuncexmpl.h"
#include "../Includes/cmdstruct.h"



cmdstruct commands[]={
			{"add",2,addNums,"printa a soma dos dois numeros que deres."},
			{"mult",2,multNums,"printa o produto dos dois numeros que deres."},
			{"whoami",1,myname,"Faz echo da string fornecida"},
			{"sair",0,sair,"Sair do programa"},
			{"myiq",0,myiq,"Mostra o teu qi"},
			{"showall",0,showall,"Mostra este menu"},
			{"",0,0,0}
		};


extern hashtablecomp* cmdLine;
void addNums(u_int64_t argc,int* toExit, void** argv){

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

void multNums(u_int64_t argc,int* toExit, void** argv){


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
void myname(u_int64_t argc,int* toExit, void** argv){

	if(argc!=1){

	printf("Numero de argumentos errado!!");
	}
	else{
	
	printf("%s\n",(char*)argv[0]);
	}

}

void myiq(u_int64_t argc,int* toExit, void** argv){

	
	printf("O teu qi neste momento e: %d\n",genRandInt(0,10000));


}

void sair(u_int64_t argc,int* toExit, void** argv){
	*toExit=1;
}


void showall(u_int64_t argc,int* toExit, void** argv){


			int j=0;
			while(commands[j].cmdname[0]){
			printf("%s- %s\n",(char*)commands[j].cmdname,(char*)commands[j].helpdesc);
			j++;
			
			}
			printf("\n");
}
