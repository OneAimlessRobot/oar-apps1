#include "Includes/preprocessor.h"

static u_int16_t pingSize;
static u_int64_t dataSize;
#define MAXNUMBEROFTRIES 10
int client_socket;
int fd;

void sigint_handler(int signal){

	close(client_socket);
	close(fd);
	printf("cliente a fechar!!!\n");
	exit(-1);

}
int main(int argc, char ** argv){

	if(argc!=5){

		printf("Utilizacao correta: arg1: Ficheiro de destino. arg2: mensagem de ping!!!!. arg3: porta do server.\narg4: ipv4 do server\n");
		exit(-1);
	}
	//especificar socket;
	fd= creat(argv[1],0777);
	if(fd<0){
		perror("Não foi possivel criar destino dos dados recebidos.\n");
		exit(-1);
	}
	client_socket= socket(AF_INET,SOCK_STREAM,0);
	if(client_socket==-1){
		raise(SIGINT);
		return 0;
	}
	signal(SIGINT,sigint_handler);
	struct sockaddr_in server_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port= htons(atoi(argv[3]));
	server_address.sin_addr.s_addr = inet_addr(argv[4]);	
	int success=-1;
	int numOfTries=MAXNUMBEROFTRIES;
	while(success==-1&& numOfTries){
		printf("Tentando conectar a %s: Tentativa %d\n",inet_ntoa(server_address.sin_addr),-numOfTries+MAXNUMBEROFTRIES+1);
		usleep(1000000);
		success=connect(client_socket,(struct sockaddr*)&server_address,sizeof(server_address));
		numOfTries--;
		if(success>=0){
		break;	
		}
		fprintf(stderr,"Não foi possivel: %s\n",strerror(errno));
	}
	if(!numOfTries){
	printf("Não foi possivel conectar. Numero limite de tentativas (%d) atingido!!!\n",MAXNUMBEROFTRIES);
	raise(SIGINT);
	}
	printf("Conectado a %s!!!!!!\n",inet_ntoa(server_address.sin_addr));
	
	//receber e armazenar dados recebidos
        int64_t numRecv=0;
	int pingMsgLen=strlen(argv[2]);
	send(client_socket,argv[2],pingMsgLen,0);
	char buff[pingMsgLen];
	recv(client_socket,buff,pingMsgLen,0);
	sscanf(buff,"%hu %lu",&pingSize,&dataSize);
	
	char message[dataSize];
	printf("Tamanhos:\npings: %hu\ndados: %lu\n",pingSize,dataSize);
	
	send(client_socket,argv[2],pingSize,0);
	send(client_socket,argv[2],pingSize,0);
	while((numRecv=recv(client_socket,message,sizeof(message),0))>0){


		printf("Received chunk of data with size %ld from %s\n\nWritting....to here:%s\n",numRecv,inet_ntoa(server_address.sin_addr),argv[1]);
		int status=write(fd,message,numRecv);
		if(!status){
			printf("No bytes were written!!! End of file...\n");
		}
		else if(status==-1){
			perror("No bytes written!!!! An error happened\n");
		}
		printf("Done!!!!!\n");
		

	send(client_socket,argv[2],pingSize,0);
	printf("GIMMEMORE!!!!!!\n");
        }

	raise(SIGINT);
	return 0;
}
