#pragma once
#include "NetworkLC.h"

/*
* @ArthurLacour
* @ServerLC.h
* @19/12/2017
* @Server system.
*/
class ServerLC : public NetworkLC
{
	typedef std::map<int, SOCKET> SOCKET_LIST;
	typedef std::pair<int, SOCKET> SOCKET_PAIR;

private:
	SOCKET serverSock = INVALID_SOCKET;
	SOCKET_LIST clientSockList;
	std::list<int> freeSockID;
	int iTestSend; //Seconde variable de test FB

	std::thread* m_serverThread;

	// THREADS
	int TCP_ClientRecepter();
	int TCP_Protocol(int _sockListID);
	int UDP_Protocol();

public:
	ServerLC(IPPROTO _protocol) : NetworkLC(_protocol) { };
	~ServerLC();

	int CreateServer();

	int ShutdownServer();

	//Informations
	inline int GetNumClients() { return clientSockList.size(); }

	static ServerLC* Instance;
};

