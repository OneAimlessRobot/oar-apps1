#include "Includes/preprocessor.h"
static const char* ping= "gimmemore!";

static int alive=1;
#define MAXNUMBEROFTRIES 10

#define MAXTIMEOUTSECS 1
#define MAXTIMEOUTUSECS 0

#define MAXTIMEOUTCMD (60*5)
#define MAXTIMEOUTUCMD 0

#define MAXTIMEOUTCONS (60*5)
#define MAXTIMEOUTUCONS 0

#define MAXTIMEOUTPING (60*5)
#define MAXTIMEOUTUPING 0

#define LINESIZE 1024
#define DATASIZE 64
#define PINGSIZE 64

static pthread_mutex_t varMtx= PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t readyCond= PTHREAD_COND_INITIALIZER;
static pthread_mutex_t readyMtx= PTHREAD_MUTEX_INITIALIZER;
static pthread_t connectionChecker;
static pthread_t outputPrinter;
static pthread_t errPrinter;

int goPlease=0; 
int client_socket,lifeline_socket, output_socket,err_socket;
static char outbuff[DATASIZE]={0};
static char errbuff[DATASIZE]={0};
static struct sockaddr_in server_address;

static void sigint_handler(int signal){

	acessVarMtx(&varMtx,&alive,0,0);
	acessVarMtx(&varMtx,&goPlease,0,1);
	pthread_cond_signal(&readyCond);
	pthread_join(connectionChecker,NULL);
	pthread_join(outputPrinter,NULL);
	pthread_join(errPrinter,NULL);
	close(client_socket);
	close(lifeline_socket);
	close(output_socket);
	close(err_socket);
	printf("cliente a fechar!!!\n");
	exit(-1);

}
static int64_t receiveServerOutput(int socket,char buff[],u_int64_t size,int secwait,int usecwait){
                int iResult;
                struct timeval tv;
                fd_set rfds;
                FD_ZERO(&rfds);
                FD_SET(socket,&rfds);
                tv.tv_sec=secwait;
                tv.tv_usec=usecwait;
                iResult=select(socket+1,&rfds,(fd_set*)0,(fd_set*)0,&tv);
                if(iResult>0){
                return recv(socket,buff,size,0);
                }
                return -1;
}

static void* getOutput(void* args){

	char buff[strlen(ping)];
	while(acessVarMtx(&varMtx,&alive,0,-1)){
	
	while(receiveServerOutput(output_socket,outbuff,DATASIZE,MAXTIMEOUTSECS,MAXTIMEOUTUSECS)>0){
		printf("%s",outbuff);
		send(output_socket,ping,strlen(ping),0);
		memset(outbuff,0,DATASIZE);
	}
	
	}
	

}
static void* getErr(void* args){
	acessVarMtx(&varMtx,&goPlease,1,0);
	pthread_cond_signal(&readyCond);
       	char buff[strlen(ping)];
	while(acessVarMtx(&varMtx,&alive,0,-1)){
	int numread=1;
	while((numread=receiveServerOutput(err_socket,errbuff,DATASIZE,MAXTIMEOUTSECS,MAXTIMEOUTUSECS))>0){
				fprintf(stderr,"%s",errbuff);
				send(err_socket,ping,strlen(ping),0);
				memset(errbuff,0,DATASIZE);
			
	}
	
	}
	

}
static void initClient(int port, char* addr){

	client_socket= socket(AF_INET,SOCK_STREAM,0);
	if(client_socket==-1){
		raise(SIGINT);
	}
	lifeline_socket= socket(AF_INET,SOCK_STREAM,0);
	if(lifeline_socket==-1){
		raise(SIGINT);
	}
	output_socket= socket(AF_INET,SOCK_STREAM,0);
	if(output_socket==-1){
		raise(SIGINT);
	}
	err_socket= socket(AF_INET,SOCK_STREAM,0);
	if(err_socket==-1){
		raise(SIGINT);
	}
	
       long flags= fcntl(client_socket,F_GETFL);
        flags |= O_NONBLOCK;
        fcntl(client_socket,F_SETFD,flags);
        
	flags= fcntl(lifeline_socket,F_GETFL);
        flags |= O_NONBLOCK;
        fcntl(lifeline_socket,F_SETFD,flags);
	
	flags= fcntl(output_socket,F_GETFL);
        flags |= O_NONBLOCK;
        fcntl(output_socket,F_SETFD,flags);
	
	flags= fcntl(err_socket,F_GETFL);
        flags |= O_NONBLOCK;
        fcntl(err_socket,F_SETFD,flags);
	
	signal(SIGINT,sigint_handler);
	server_address.sin_family=AF_INET;
	server_address.sin_addr.s_addr = inet_addr(addr);	
	server_address.sin_port= htons(port);
	

}

static void tryConnect(int* socket){
	int success=-1;
	int numOfTries=MAXNUMBEROFTRIES;
	
	
        while(success==-1&& numOfTries){
                success=connect(*socket,(struct sockaddr*)&server_address,sizeof(server_address));
                if(errno!=EINPROGRESS){
			
			break;
		}
		numOfTries--;
		fd_set wfds;
		FD_ZERO(&wfds);
		FD_SET(*socket,&wfds);

                struct timeval t;
		t.tv_sec=MAXTIMEOUTCONS;
		t.tv_usec=MAXTIMEOUTUCONS;
		int iResult=select((*socket)+1,0,&wfds,0,&t);
		
		if(iResult>0){
		
			break;
			
		}
		fprintf(stderr,"Não foi possivel: %s\n",strerror(errno));
        }
        if(!numOfTries){
        printf("Não foi possivel conectar. Numero limite de tentativas (%d) atingido!!!\n",MAXNUMBEROFTRIES);
        raise(SIGINT);
        }
	else{
	
 	       printf("Coneccao de %s!!!!!!\n",inet_ntoa(server_address.sin_addr));

	
	}

}

static void* areYouStillThere(void* args){
	int pingLength=strlen(ping);
	char buff[pingLength];
	memset(buff,0,pingLength);
	
	while(acessVarMtx(&varMtx,&alive,0,-1)){

                send(lifeline_socket,ping,pingLength,0);
		int status=receiveServerOutput(lifeline_socket,buff,pingLength,MAXTIMEOUTPING,MAXTIMEOUTUPING);
		if(status<0){
			printf("Ops! You timed out.... Goodbye!\n");
			raise(SIGINT);
		}
		
		memset(buff,0,pingLength);

        }

}



int main(int argc, char ** argv){

	if(argc!=3){

		printf("Utilizacao correta: arg1: ip do server.\narg2: porta\n");
		exit(-1);
	}
	initClient(atoi(argv[1]),argv[2]);
	tryConnect(&client_socket);
	tryConnect(&lifeline_socket);
	tryConnect(&output_socket);
	tryConnect(&err_socket);
	//especificar socket;

	
	pthread_create(&connectionChecker,NULL,areYouStillThere,NULL);
	pthread_create(&outputPrinter,NULL,getOutput,NULL);
	pthread_create(&errPrinter,NULL,getErr,NULL);
		pthread_mutex_lock(&readyMtx);
		while(!acessVarMtx(&varMtx,&goPlease,0,-1)&&acessVarMtx(&varMtx,&alive,0,-1)){
			pthread_cond_wait(&readyCond,&readyMtx);

		}
		
		pthread_mutex_unlock(&readyMtx);
		while(1){
				char line[LINESIZE];
				memset(line,0,LINESIZE);
				printf("RemoteShell:> ");
				fgets(line,LINESIZE,stdin);
				line[strlen(line)-1]=0;
				char buff[strlen(ping)+1];
				int sent=send(client_socket,line,LINESIZE,0);
				receiveServerOutput(client_socket,buff,sizeof(buff),MAXTIMEOUTCMD,MAXTIMEOUTUCMD);
			
			}
		        raise(SIGINT);
	
}

