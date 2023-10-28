#include "Includes/preprocessor.h"

int main(int argc, char ** argv){
	
	char buff[1024],buff2[1024],buff3[1024],buff4[1024];
	memset(buff ,0 ,1024);
	memset(buff2 ,0 ,1024);
	char* tmpfilepathsfile=" $(echo $(pwd))/filepaths ";
	strcpy(buff,"find ");
	strcpy(buff4,"rm ");
	strcat(buff,argv[1]);
	strcat(buff," -maxdepth 1 -type f > ");
	strcat(buff,tmpfilepathsfile);
	system(buff);
	strcpy(buff2," $(echo $(pwd))/editor/editor ");
	strcpy(buff3,argv[2]);
	strcat(buff2,tmpfilepathsfile);
	strcat(buff2,buff3);
	system(buff2);
	strcat(buff4,tmpfilepathsfile);
	system(buff4);
	

	return 0;
}
