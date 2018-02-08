#pragma once
#include "NetworkLC.h"

/*
* @ArthurLacour
* @ClientLC.h
* @19/12/2017
* @Client system.
*/
class ClientLC : public NetworkLC
{
private:
	SOCKET mySock;

	std::thread* m_serverMsgRecepter;

	// THREADS
	int TCP_ServerMsgRecepter();
	int UDP_ServerMsgRecepter();

public:
	ClientLC(IPPROTO _protocol) : NetworkLC(_protocol) {};
	~ClientLC();

	int ConnectToServer(PCSTR _adress);

	int SendMsg(char _msg[DEFAULT_BUFLEN]);

	int ShutdownConnection();

	static ClientLC* Instance;
};

