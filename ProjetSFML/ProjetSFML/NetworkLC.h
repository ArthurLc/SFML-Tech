#pragma once
#pragma comment(lib, "Ws2_32.lib")

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <iomanip>
#include <thread>

#define DEFAULT_PORT "50000"
#define DEFAULT_BUFLEN 512

/*
* @ArthurLacour
* @NetworkLC.h
* @19/12/2017
* @Network system.
*/
class NetworkLC
{
	enum NetworkTargets
	{
		All
	};

protected:
	/*===PARAMETERS===*/
	// WSA (Winsock DLL)
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD(2, 2);
	// Socket
	struct addrinfo *result = NULL, *ptr = NULL, hints; //Structure nécessaire à la connexion d'un serveur
	// Casual
	int recvbuflen = DEFAULT_BUFLEN;
	char msg[DEFAULT_BUFLEN]; //Msg de confirmation
	char recvbuf[DEFAULT_BUFLEN];
	// Other
	int iTest; //Variable de test FB
	struct sockaddr sockaddr;
	int server_length;
	time_t current_time;
	/*================*/

	int StartupWin();

public:
	NetworkLC(IPPROTO _protocol);
	~NetworkLC();
};

