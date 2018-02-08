#include "ServerLC.h"



ServerLC::~ServerLC()
{
}


/*###SERVER###*/
int ServerLC::CreateServer()
{
	isServer = true;

	//Création de la socket serveur
	serverSock = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (serverSock == SOCKET_ERROR) {
		std::cout << "Error : " << WSAGetLastError() << std::endl;
		closesocket(serverSock);
		WSACleanup();
		return 1;
	}

	// Mise en place de la socket serveur
	iTest = bind(serverSock, result->ai_addr, (int)result->ai_addrlen);
	if (iTest == SOCKET_ERROR) {
		std::cout << "Error : " << WSAGetLastError() << std::endl;
		closesocket(serverSock);
		WSACleanup();
		return 1;
	}
	freeaddrinfo(result); //Libération de l'addrInfo qui n'a plus d'utilitées

	// Test d'écoute avec la socket
	if (result->ai_socktype == SOCK_STREAM)
	{
		if (listen(serverSock, SOMAXCONN) == SOCKET_ERROR) {
			std::cout << "Error de Listen: " << WSAGetLastError() << std::endl;
			closesocket(serverSock);
			WSACleanup();
			return 1;
		}
	}

	// Lancement du thread de réception de clients
	switch (result->ai_socktype)
	{
	case SOCK_STREAM:
		m_serverThread = new std::thread(&ServerLC::TCP_ClientRecepter, this);
		m_serverThread->detach();
		break;
	case SOCK_DGRAM:
		m_serverThread = new std::thread(&ServerLC::UDP_Protocol, this);
		m_serverThread->detach();
		break;
	default:
		std::cout << "Error: This socktype doesn't taken care of." << std::endl;
		break;
	}

	return 0;
}

int ServerLC::ShutdownServer()
{
	//Shutdown du client
	iTest = shutdown(clientSockList[clientSockList.size() - 1], SD_SEND);
	if (iTest == SOCKET_ERROR) {
		std::cout << "Error : " << WSAGetLastError() << std::endl;
		closesocket(clientSockList[clientSockList.size() - 1]);
		WSACleanup();
		return 1;
	}
	//Cleanup des Familles
	closesocket(clientSockList[clientSockList.size() - 1]);
	WSACleanup();
	return 0;
}
/*############*/


/*###THREADS###*/
int ServerLC::TCP_ClientRecepter()
{
	//Accepter une connexion...
	while (true)
	{
		SOCKET tempSock = accept(serverSock, NULL, NULL);
		SOCKET_LIST::iterator it = clientSockList.find(tempSock);
		int newClientID = clientSockList.size();

		if (freeSockID.size() != 0) {
			newClientID = freeSockID.front();
			freeSockID.remove(freeSockID.front());
		}

		clientSockList.insert(SOCKET_PAIR(newClientID, tempSock));

		if (clientSockList[newClientID] == SOCKET_ERROR) {
			std::cout << "Error : " << WSAGetLastError() << std::endl;
			closesocket(serverSock);
			WSACleanup();
			return 1;
		}

		std::thread* newClient = new std::thread(&ServerLC::TCP_Protocol, this, (int)newClientID);
		newClient->detach();
		//std::cout << "New Client !" << std::endl << "===" << std::endl;

	}
	return 0;
}

int ServerLC::TCP_Protocol(int _sockListID)
{
	do {
		for (int i = 0; i < recvbuflen; i++)
			recvbuf[i] = '\0';
		iTest = recv(clientSockList[_sockListID], recvbuf, recvbuflen, 0);
		if (iTest > 0) {
			//Affichage du message de l'autre
			NetworkLC::mtx_Datas->lock();
			dataList.insert(DATAS_PAIR(0, recvbuf));
			NetworkLC::mtx_Datas->unlock();
			//std::cout << "Client n°" << _sockListID << ": " << recvbuf << std::endl;

			//Envois de la réponse
			memcpy(msg, recvbuf, sizeof(recvbuf));
			for (SOCKET_LIST::iterator it = clientSockList.begin(); it != clientSockList.end(); ++it)
			{
				iTestSend = send(clientSockList[it->first], msg, /*(int)strlen(msg)*/recvbuflen, 0);
				if (iTestSend == SOCKET_ERROR) {
					std::cout << "Echec de l'envois : " << WSAGetLastError() << std::endl;
				}
			}
		}
		else if (iTest == 0)
			std::cout << "===" << std::endl << "Aucun msg Client n°" << _sockListID << std::endl;
		else {
			std::cout << "===" << std::endl << "Client n°" << _sockListID << " ferme." << std::endl;
			closesocket(clientSockList[_sockListID]);
			clientSockList.erase(_sockListID);
			freeSockID.push_back(_sockListID);
			return 1;
		}
	} while (true);

	return 0;
}

int ServerLC::UDP_Protocol()
{
	do {
		//Reception
		int client_length = (int)sizeof(struct sockaddr_in);
		iTest = recvfrom(serverSock, recvbuf, recvbuflen, 0, (struct sockaddr *)&sockaddr, &client_length);

		//Affichage du message de l'autre
		std::cout << "Client n°" << "???" << ": " << recvbuf << std::endl;

		//Envois de la réponse
		/* Check for time request */
		if (strcmp(recvbuf, "GET TIME\r\n") == 0)
		{
			/* Get current time */
			current_time = time(NULL);

			/* Send data back */
			if (sendto(serverSock, (char *)&current_time,
				(int)sizeof(current_time), 0,
				(struct sockaddr *)&sockaddr, client_length) !=
				(int)sizeof(current_time))
			{
				fprintf(stderr, "Error sending datagram.\n");
				closesocket(serverSock);
				WSACleanup();
				return 1;
			}
		}
	} while (true);

	return 0;
}
/*#############*/
