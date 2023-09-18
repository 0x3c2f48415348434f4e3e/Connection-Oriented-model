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

/*
Number of bytes in int is based on platform, since int is normally 4 bytes, unsigned int is used
Now convert from IP address to intger is not so hard, just take each octect and multiply it by
256 to the octect placevalue (This should be fairly simple to understand)
*/


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
//reason main is here is only for testing, will have to move main to another file, to ensure code is readable
