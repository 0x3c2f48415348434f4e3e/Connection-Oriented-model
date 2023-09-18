#include <stdio.h>
#include <sys/socket.h>
#include <pthread.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <stdlib.h>
// Port and address

void serverSocket(void);

struct sockaddr_in forServerSocket;
int PORT = 443;
unsigned int localMachine = 2130706433;

void serverSocket(void){
	forServerSocket.sin_port = PORT;
	forServerSocket.sin_addr.s_addr = localMachine;
	//Create socket object

	int Server = socket(AF_INET,SOCK_STREAM,0);

	//Ensure server socket was successfully created
	if(Server == -1){
		printf("Server Could not be created");
		exit(EXIT_FAILURE);
	}

	//bind socket to a particular PORT AND ADDR
	//Ensure server socket was succesfuly bound
	int res = bind(Server, (const struct sockaddr *)&forServerSocket,sizeof(forServerSocket));
		if(res == -1){
			printf("Could not bind sever to port %i and address %i",PORT,localMachine);
			exit(EXIT_FAILURE);
		}

	// Listen for connections (lisres is short for listen result)
	int lisres = listen(Server,) //Continue
}

int main(){
	serverSocket();
	return 0;
}
