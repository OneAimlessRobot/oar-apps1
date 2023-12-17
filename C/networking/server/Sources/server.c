#include "../Includes/preprocessor.h"
#include "../Includes/hud.h"

static const char* pingCorrect= "queroja";
serverState* state=NULL;

const char* logFile="./logs.log";
extern int fd;
int logfd,logging=1;

u_int64_t dataSize;
u_int16_t pingSize,maxNumOfClients;
static pthread_mutex_t acceptingMtx= PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t kickingMtx= PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t sendingMtx= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t varMtx= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t listMtx= PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t stackMtx= PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t exitingMtx= PTHREAD_MUTEX_INITIALIZER;
static pthread_mutex_t graphicsMtx= PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t graphicsWait= PTHREAD_COND_INITIALIZER;
static pthread_cond_t acceptingCond= PTHREAD_COND_INITIALIZER;
static pthread_cond_t kickingCond= PTHREAD_COND_INITIALIZER;
static pthread_cond_t exitingCond= PTHREAD_COND_INITIALIZER;
static pthread_cond_t sendingCond= PTHREAD_COND_INITIALIZER;
static pthread_t connectionAccepter,dataSender,graphics,rateInfoUpdater,clientKicker,serverLogWritter;

void cleanup(void){
	
	pthread_join(rateInfoUpdater,NULL);
	if(logging){
	pthread_join(serverLogWritter,NULL);
	}
	pthread_join(clientKicker,NULL);
	pthread_join(graphics,NULL);
	pthread_join(connectionAccepter,NULL);
	pthread_join(dataSender,NULL);
	acessListMtx(&listMtx,state->listOfClients,NULL,0,3);
	acessStackMtx(&listMtx,state->logs,NULL,2);
	acessStackMtx(&listMtx,state->kickedClientPtrs,NULL,2);
	close(state->server_socket);
	close(fd);
	free(state);
	nocbreak();
	endwin();
	printf("server a fechar!!!\n");
	

}

static void sigint_handler(int signal){


	acessVarMtx(&varMtx,&state->serverRunning,0,0);
	pthread_cond_broadcast(&exitingCond);
	acessVarMtx(&varMtx,&state->idle,0,0);
	pthread_cond_broadcast(&sendingCond);
	pthread_cond_broadcast(&acceptingCond);
	pthread_cond_signal(&kickingCond);
	
}


static void* graphicsLoop(void* params){


while(acessVarMtx(&varMtx,&state->serverRunning,0,-1)){

	printServerState();
}

return NULL;
}

static void* serverLogWritting(void* params){


while(acessVarMtx(&varMtx,&state->serverRunning,0,-1)){

	printServerLogs();
}

return NULL;
}
static void pushLog(char* log){
	
	char buff[LOGMSGLENGTH]={0};
	strncpy(buff,log,LOGMSGLENGTH);
	acessStackMtx(&stackMtx,state->logs,buff,0);


}




static void receiveClientPing(clientStruct* nextClient,char buff[]){
	
		int iResult;
		struct timeval tv;
		fd_set rfds;
		FD_ZERO(&rfds);
		FD_SET(nextClient->client_socket,&rfds);
		tv.tv_sec=MAXTIMEOUTPING;
		tv.tv_usec=0;
		iResult=select(nextClient->client_socket+1,&rfds,(fd_set*)0,(fd_set*)0,&tv);
		if(iResult>0){
		recv(nextClient->client_socket,buff,pingSize,0);
		
		}

}
static void* connectionAccepting(void* argStruct){
	while(acessVarMtx(&varMtx,&state->serverRunning,0,-1)){
	

		
	pthread_mutex_lock(&acceptingMtx);
	while(*(u_int64_t*)acessListMtx(&listMtx,state->listOfClients,0,0,4)>=maxNumOfClients&&acessVarMtx(&varMtx,&state->serverRunning,0,-1)){

		pthread_cond_wait(&acceptingCond,&acceptingMtx);
	}
	pthread_mutex_unlock(&acceptingMtx);
	if(!acessVarMtx(&varMtx,&state->serverRunning,0,-1)){


		return NULL;
	}
	
		while(*(u_int64_t*)acessListMtx(&listMtx,state->listOfClients,0,0,4)<maxNumOfClients&&acessVarMtx(&varMtx,&state->serverRunning,0,-1)){
		
		int iResult;
		struct timeval tv;
		fd_set rfds;
		FD_ZERO(&rfds);
			char buff2[LOGMSGLENGTH]={0};
                        snprintf(buff2,LOGMSGLENGTH,"Soca do server: %d\n", state->server_socket);
                        pushLog(buff2);
		FD_SET(state->server_socket,&rfds);
		tv.tv_sec=MAXTIMEOUTSECS;
		tv.tv_usec=MAXTIMEOUTUSECS;
		pushLog("A espera de conexoes!!!");
		iResult=select(state->server_socket+1,&rfds,(fd_set*)0,(fd_set*)0,&tv);
		if(iResult>0){
		clientStruct currClient;
		
		currClient.numOfBytesSent=0;

		currClient.client_socket=accept(state->server_socket,(struct sockaddr*)&(currClient.clientAddress),&(currClient.addrLength));
		
			char buff[LOGMSGLENGTH]={0};
			snprintf(buff,LOGMSGLENGTH,"Accepted connection from %s",inet_ntoa(currClient.clientAddress.sin_addr));
			pushLog(buff);
		
		char ping1[pingSize];
		
		receiveClientPing(&currClient,ping1);
		if(!strcmp(ping1,pingCorrect)){
	
			char buff3[LOGMSGLENGTH]={0};
			snprintf(buff3,LOGMSGLENGTH,"Sending sizes to client!!!!");
			pushLog(buff3);
			char buff4[pingSize];
			snprintf(buff4,pingSize,"%u %lu",pingSize, dataSize);
		send(currClient.client_socket,buff4,strlen(buff4),0);
			
		char ping2[pingSize];
		
		receiveClientPing(&currClient,ping2);
		if(!strncmp(ping2,pingCorrect,strlen(pingCorrect))){
	
			char buff3[LOGMSGLENGTH]={0};
			snprintf(buff3,LOGMSGLENGTH,"client got the sizes!!!!!!!");
			pushLog(buff3);
		
			acessVarMtx(&varMtx,&state->idle,0,0);
			acessListMtx(&listMtx,state->listOfClients,&currClient,0,0);
			pthread_cond_signal(&acceptingCond);
			pthread_cond_signal(&sendingCond);
			pthread_cond_signal(&kickingCond);
	
		}
		else {
			char buff3[LOGMSGLENGTH]={0};
			snprintf(buff3,LOGMSGLENGTH,"client did not get the sizes. Dropping connection");
			pushLog(buff3);
			close(currClient.client_socket);
		
		}
		}
		}
		else{
			char buff[LOGMSGLENGTH]={0};
			snprintf(buff,LOGMSGLENGTH,"Timed out!!!!!( more that %ds waiting). Trying again...",MAXTIMEOUTSECS);
			pushLog(buff);
		}
	}
	
	pushLog("Fechou a loja!!!!");
	}
	return NULL;


}

static void* dataSending(void* argStruct){
	pthread_mutex_lock(&acceptingMtx);
	dliterator* it=NULL;
	while(acessVarMtx(&varMtx,&state->idle,0,-1)&&acessVarMtx(&varMtx,&state->serverRunning,0,-1)){
		
		pthread_cond_wait(&acceptingCond,&acceptingMtx);
	
	}
	pthread_mutex_unlock(&acceptingMtx);
	
	while(acessVarMtx(&varMtx,&state->serverRunning,0,-1)){
	
	pthread_mutex_lock(&sendingMtx);
	while(acessVarMtx(&varMtx,&state->idle,0,-1)&&acessVarMtx(&varMtx,&state->serverRunning,0,-1)){

		pthread_cond_wait(&sendingCond,&sendingMtx);
	}
	pthread_mutex_unlock(&sendingMtx);
	u_int64_t fileSizeBytes=lseek(fd,0,SEEK_END);
	lseek(fd,0,SEEK_SET);
	
	if(!acessVarMtx(&varMtx,&state->serverRunning,0,-1)){


		return NULL;
	}
	
	int64_t numRead=1;
	char message[dataSize];
	while((numRead=read(fd,message,dataSize))>0&&!acessVarMtx(&varMtx,&state->idle,0,-1)&&acessVarMtx(&varMtx,&state->serverRunning,0,-1)){
	it=initIt((DListW*)acessListMtx(&listMtx,state->listOfClients,NULL,0,5));
	while(hasNextIt(it)){
	clientStruct* nextClient=(clientStruct*)acessItMtx(&listMtx,it);
	char buff[pingSize];
	receiveClientPing(nextClient,buff);
	if(!strcmp(buff,pingCorrect)){
	
			char buff3[LOGMSGLENGTH]={0};
			snprintf(buff3,LOGMSGLENGTH,"Sending chunk of data to %s!!!!",inet_ntoa(nextClient->clientAddress.sin_addr));
			pushLog(buff3);
		u_int64_t numSent=send(nextClient->client_socket,message,numRead,0);
		acessVarMtx(&varMtx,&state->totalSent,numSent,3);
		acessVarMtx(&varMtx,&nextClient->numOfBytesSent,numSent,3);
		
		if(acessVarMtx(&varMtx,&nextClient->numOfBytesSent,0,-1)>=fileSizeBytes){
			acessStackMtx(&stackMtx,state->kickedClientPtrs,nextClient,0);
			pthread_cond_signal(&kickingCond);
		}
		
	}
	else {
		acessStackMtx(&stackMtx,state->kickedClientPtrs,nextClient,0);
		pthread_cond_signal(&kickingCond);
	}
	usleep(DELAYUSECS);
	}
	free(it);
	it=NULL;
	char buff[LOGMSGLENGTH]={0};
	snprintf(buff,LOGMSGLENGTH,"Terminei uma vaga!!!!");
	pushLog(buff);
			
	}
	
	char buff5[LOGMSGLENGTH]={0};
	snprintf(buff5,LOGMSGLENGTH,"Tudo enviado!!!!");
	pushLog(buff5);
	
}	
	if(it){
		free(it);
	}
	pushLog("Sender a sair!!!");
	return NULL;

}
static void* clientKicking(void*arg){
	
	while(acessVarMtx(&varMtx,&state->serverRunning,0,-1)){
		
	pthread_mutex_lock(&kickingMtx);
	while(!(*(u_int64_t*)acessStackMtx(&stackMtx,state->kickedClientPtrs,0,3))&&acessVarMtx(&varMtx,&state->serverRunning,0,-1)){

		pthread_cond_wait(&kickingCond,&kickingMtx);
	}
	pthread_mutex_unlock(&kickingMtx);
	u_int64_t sizeOfList;
	while((*(u_int64_t*)acessStackMtx(&stackMtx,state->kickedClientPtrs,0,3))&&acessVarMtx(&varMtx,&state->serverRunning,0,-1)){

	clientStruct* nextClient=(clientStruct*)acessStackMtx(&stackMtx,state->kickedClientPtrs,0,1);
		
		
		close(nextClient->client_socket);

		acessListMtx(&listMtx,state->listOfClients,nextClient,0,1);
		
		sizeOfList=*(u_int64_t*)acessListMtx(&listMtx,state->listOfClients,0,0,4);
			char buff2[LOGMSGLENGTH]={0};
			snprintf(buff2,LOGMSGLENGTH,"Este cliente nao estava ativo logo foi removido!!");
			pushLog(buff2);
			
		if(!sizeOfList){
			
			memset(buff2,0,LOGMSGLENGTH);
			snprintf(buff2,LOGMSGLENGTH,"Nao ha mais clientes a remover!!!!A hibernar...");
			pushLog(buff2);
			acessVarMtx(&varMtx,&state->idle,1,0);
		}
		free(nextClient);
		pthread_cond_signal(&acceptingCond);
		
		}	
	}
	pushLog("Kicker a sair!!!");
	return NULL;
}
static void* updateRates(void* arg){

	while(acessVarMtx(&varMtx,&state->serverRunning,0,-1)){
		u_int64_t currSent=acessVarMtx(&varMtx,&state->totalSent,0,-1);
		struct timeval start, end;
		gettimeofday(&start,NULL);
		usleep(1000000);
		gettimeofday(&end,NULL);
		u_int64_t afterSent=acessVarMtx(&varMtx,&state->totalSent,0,-1);
		double byteSendingRate=((double)afterSent-(double)currSent)/((double)end.tv_sec-(double)start.tv_sec);
		acessVarMtx(&varMtx,(u_int64_t*)&state->trafficRate,(u_int64_t)byteSendingRate,0);

	}
	
	pushLog("Updater de info a sair!!!");
	return NULL;

}

void initEverything(u_int16_t port,char* ipaddr,u_int16_t startPingSize,u_int64_t startDataSize,u_int16_t startMaxNumOfClients){
	
	logfd=creat(logFile,0777);
	if(logfd<0){

		perror("Nao foi possivel abrir o ficheiro de logs!!!!( Nao vais ver logs!!!)");
		logging=0;
	}	
	state=malloc(sizeof(serverState));
	
	state->server_socket= socket(AF_INET,SOCK_STREAM,0);
	if(state->server_socket==-1){
		free(state);
		return;

	}
	
	//especificar socket;
	fcntl(state->server_socket,F_SETFD,O_ASYNC);
	signal(SIGINT,sigint_handler);
	
	state->server_address.sin_family=AF_INET;
	state->server_address.sin_port= htons(port);
		
	state->server_address.sin_addr.s_addr = inet_addr(ipaddr);
	bind(state->server_socket,(struct sockaddr*) &state->server_address,sizeof(state->server_address));
	
	maxNumOfClients=startMaxNumOfClients;
	
	listen(state->server_socket,maxNumOfClients+1);
	
	struct sockaddr_in* pV4Addr = (struct sockaddr_in*)&state->server_address;
	struct in_addr ipAddr = pV4Addr->sin_addr;
	inet_ntop( AF_INET, &ipAddr, state->addressContainer, INET_ADDRSTRLEN );
	
	
        state->totalSent=state->timeActive=0;
        state->trafficRate=0.0;

	state->serverRunning=1;
	state->idle=1;
	state->listOfClients=initDList(sizeof(clientStruct));
	state->logs=initDLStack(LOGMSGLENGTH);
	state->kickedClientPtrs=initDLStack(sizeof(clientStruct));
	pingSize=startPingSize;
	dataSize=startDataSize;
	initscr();
	start_color();
	timeout(10);
	noecho();
	curs_set(0);
	pthread_create(&connectionAccepter,NULL,connectionAccepting,NULL);
	pthread_create(&dataSender,NULL,dataSending,NULL);
	pthread_create(&graphics,NULL,graphicsLoop,NULL);
	pthread_create(&rateInfoUpdater,NULL,updateRates,NULL);
	pthread_create(&clientKicker,NULL,clientKicking,NULL);
	if(logging){
	pthread_create(&serverLogWritter,NULL,serverLogWritting,NULL);
	}
}
