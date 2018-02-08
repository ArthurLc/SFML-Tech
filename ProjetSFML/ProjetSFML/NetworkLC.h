#pragma once
#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <iomanip>
#include <map>
#include <list>
#include <thread>
#include <mutex>

#define DEFAULT_PORT "48563"
#define DEFAULT_BUFLEN 25

typedef public std::multimap<int, char*> DATAS_LIST;
typedef public std::pair<int, char*> DATAS_PAIR;

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
	// Messages
	int recvbuflen = DEFAULT_BUFLEN;
	char msg[DEFAULT_BUFLEN]; //Msg de confirmation
	char recvbuf[DEFAULT_BUFLEN];
	// Other
	int iTest; //Variable de test FB
	struct sockaddr sockaddr;
	int server_length;
	time_t current_time;
	static DATAS_LIST dataList;
	/*================*/

	int StartupWin();

public:
	NetworkLC(IPPROTO _protocol);
	~NetworkLC();

	//Informations
	static bool IsServer;
	static PCSTR AdressServer; //Adresse avec laquelle je vais essayer de me connecter
	static std::mutex* Datas_mtx;           // mutex for critical section
	inline static DATAS_LIST GetDataList() { return dataList; }
};

