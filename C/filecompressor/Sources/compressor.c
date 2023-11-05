#include "../Includes/preprocessor.h"


pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condC=PTHREAD_COND_INITIALIZER;
pthread_cond_t condP=PTHREAD_COND_INITIALIZER;
#define N_CHARS 5
#define N_SIZE 10000

char buff[N_SIZE];
int finput,dstfd;

void compress(char* srcfilepath,char* dstfilepath){

if((finput=open(srcfilepath,O_RDWR,0777))<0){

	perror("Erro a abrir ficheiro em compress em compress.c\n");
	exit(-1);

}
memset(buff,0,N_SIZE);

dstfd= creat(dstfilepath,0777);
u_int64_t currN=1,currCursor,nread,i=1,currentSeen=0;
char currC;
nread=read(finput,buff,N_SIZE);
currC=buff[0];
while(nread>0){



for(;i<=nread;i++){
if(currC==buff[i]){
	currN++;

}

else{
	char buff2[1024];
	memset(buff2,0,1024);
	//int num=0;
	//num=snprintf(buff2,1024,"%c%lx ",currC,currN);
	//write(dstfd,buff2,num);
	int num=0,num2=0;
	num=snprintf(buff2,1024,"%c",currC);
	if(currN>1){
	
	num2=snprintf(buff2+num,1024," %lx ",currN);
	
	}
	write(dstfd,buff2,num+num2);
	
	currC=buff[i];
	//printf("Curr Seen: %d\n",currentSeen+currN);
	currentSeen+=currN;
	currN=1;
}
}
nread=read(finput,buff,N_SIZE);
//printf("Nread: %d\n",nread);
i=1;
}

close(dstfd);
close(finput);	

}

void decompress(char* srcfilepath,char* dstfilepath){

if((finput=open(srcfilepath,O_RDWR,0777))<0){

	perror("Erro a abrir ficheiro em compress em compress.c\n");
	exit(-1);

}
memset(buff,0,N_SIZE);

dstfd= creat(dstfilepath,0777);

FILE* finbuff,*dstbuff;
if(!(finbuff= fdopen(finput,"r+"))){


	perror("Erro a abrir ficheiro fonte em compresssor.c\n");
	exit(-1);
}



if(!(dstbuff=fdopen(dstfd,"w"))){

	perror("Erro a abrir ficheiro de destino em compresssor.c\n");
	exit(-1);

}
u_int64_t i=0,currwriten=0;
fseek(finbuff,0,SEEK_END);

int64_t fsize=ftell(finbuff);
//printf("%ld\n",fsize);
fseek(finbuff,0,SEEK_SET);
do{
//printf("%ld\n",ftell(finbuff));
/*int status;
char c,dump;
fscanf(finbuff,"%c",&c);
status=(fscanf(finbuff,"%lx",&i)>=1);
fscanf(finbuff,"%c",&dump);
*/
int status;
char c,dump1,dump2;
fscanf(finbuff,"%c",&c);
int pos2=ftell(finbuff);
status=fscanf(finbuff,"%c%lx%c",&dump1,&i,&dump2);
int diff= ftell(finbuff)-pos2;
char* buff3;
if(!(dump1==' '&&dump2==' '&&(status==3))){

fseek(finbuff,-diff,SEEK_CUR);
i=1;
buff3= malloc(i);
buff3[0]=c;
}
else{
buff3=malloc(i);
memset(buff3,c,i);
}

//printf("String to add:\n%s\nCurr written: %ld\n",buff3,(currwriten+=i));
fwrite(buff3, 1, i,dstbuff);
free(buff3);
}while(ftell(finbuff)<fsize);
fclose(finbuff);
fclose(dstbuff);
close(dstfd);
close(finput);	
}
