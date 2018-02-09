#include "ClientLC.h"

//Initialization static members
ClientLC* ClientLC::Instance = nullptr;


ClientLC::~ClientLC()
{
	ShutdownConnection();
}


/*###CLIENT###*/
int ClientLC::ConnectToServer(PCSTR _adress)
{
	Instance = this;
	IsServer = false;

	AdressServer = _adress;
	// Test adresse serveur et port
	iTest = getaddrinfo(AdressServer, DEFAULT_PORT, &hints, &result);
	if (iTest != 0) {
		std::cout << "Error : GetAddrInfo : " << iTest << std::endl;
		WSACleanup();
		return 1;
	}

	//Initialisation de la socket
	mySock = INVALID_SOCKET;
	ptr = result;
	//Initialisation de la socket
	mySock = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
	if (mySock == SOCKET_ERROR) {
		std::cout << "Error : " << WSAGetLastError() << std::endl;
		closesocket(mySock);
		WSACleanup();
		return 1;
	}
	//Connexion au serveur
	iTest = connect(mySock, ptr->ai_addr, (int)ptr->ai_addrlen);
	if (iTest == SOCKET_ERROR) {
		std::cout << "Error : " << WSAGetLastError() << std::endl;
		closesocket(mySock);
		WSACleanup();
		return 1;
	}

	// Lancement du thread de réception de messages du server
	switch (result->ai_socktype)
	{
	case SOCK_STREAM:
		m_serverMsgRecepter = new std::thread(&ClientLC::TCP_ServerMsgRecepter, this);
		m_serverMsgRecepter->detach();
		break;
	case SOCK_DGRAM:
		m_serverMsgRecepter = new std::thread(&ClientLC::UDP_ServerMsgRecepter, this);
		m_serverMsgRecepter->detach();
		break;
	default:
		std::cout << "Error: This socktype doesn't taken care of." << std::endl;
		break;
	}

	return 0;
}

int ClientLC::SendMsg(char _msg[DEFAULT_BUFLEN])
{
	switch (result->ai_socktype)
	{
	case SOCK_STREAM:
		//Envois d'un message
		iTest = send(mySock, _msg, /*(int)strlen(_msg)*/recvbuflen, 0);
		if (iTest == SOCKET_ERROR) {
			std::cout << "Error : " << WSAGetLastError() << std::endl;
			closesocket(mySock);
			WSACleanup();
			return 1;
		}
		break;
	case SOCK_DGRAM:
		/* Tranmsit data to get time */
		server_length = sizeof(struct sockaddr_in);

		if (sendto(mySock, _msg, (int)strlen(_msg) + 1,
			0, (struct sockaddr *)&sockaddr, server_length) == -1)
		{
			fprintf(stderr, "Error transmitting data.\n");
			closesocket(mySock);
			WSACleanup();
			return 1;
		}
		break;
	default:
		std::cout << "Error: This socktype doesn't taken care of." << std::endl;
		break;
	}

	return 0;
}

int ClientLC::ShutdownConnection()
{
	//Libération de l'addrinfo
	freeaddrinfo(result);
	if (mySock == SOCKET_ERROR) {
		std::cout << "Error : " << WSAGetLastError() << std::endl;
		closesocket(mySock);
		WSACleanup();
		return 1;
	}
	//Shutdown socket
	iTest = shutdown(mySock, SD_SEND);
	if (iTest == SOCKET_ERROR) {
		std::cout << "Error : " << WSAGetLastError() << std::endl;
		closesocket(mySock);
		WSACleanup();
		return 1;
	}
	//Cleanup des Familles
	closesocket(mySock);
	WSACleanup();
	return 0;
}
/*############*/


/*###THREADS###*/
int ClientLC::TCP_ServerMsgRecepter()
{
	//Accepter une connexion...
	while (true)
	{
		for (int i = 0; i < recvbuflen; i++)
			recvbuf[i] = '\0';

		iTest = recv(mySock, recvbuf, recvbuflen, 0); //Reception du Msg
		if (iTest > 0) {
			NetworkLC::Datas_mtx->lock();
			dataList.insert(DATAS_PAIR(recvbuf[0], recvbuf));
			NetworkLC::Datas_mtx->unlock();
			//std::cout << "Client : " << recvbuf << std::endl;
		}
		else if (iTest == 0)
			std::cout << "===" << std::endl << "Connexion ferme." << std::endl;
		else
			std::cout << "Echec de reception de confirmation : " << WSAGetLastError() << std::endl;
	}
	return 0;
}

int ClientLC::UDP_ServerMsgRecepter()
{
	server_length = sizeof(struct sockaddr_in);

	/* Receive time */
	if (recvfrom(mySock, (char *)&current_time,
		(int)sizeof(current_time), 0,
		(struct sockaddr *)&sockaddr,
		&server_length) < 0)
	{
		fprintf(stderr, "Error receiving data.\n");
		closesocket(mySock);
		WSACleanup();
		return 1;
	}

	return 0;
}
/*#############*/
