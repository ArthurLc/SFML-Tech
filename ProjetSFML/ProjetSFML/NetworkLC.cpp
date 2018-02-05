#include "NetworkLC.h"



/// Ouverture de la fenêtre
int NetworkLC::StartupWin()
{	
	int iWSAResult = WSAStartup(wVersionRequested, &wsaData);
	
	// Test adresse serveur et port
	iTest = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
	if (iTest != 0) {
		std::cout << "Error : GetAddrInfo : " << iTest << std::endl;
		WSACleanup();
		return 1;
	}
	return 0;
}


NetworkLC::NetworkLC(IPPROTO _protocol)
{
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	switch (_protocol)
	{
	case IPPROTO_ICMP:
		hints.ai_socktype = SOCK_RAW;
		break;
	case IPPROTO_IGMP:
		hints.ai_socktype = SOCK_RAW;
		break;
	case 3:
		hints.ai_socktype = SOCK_STREAM;
		break;
	case IPPROTO_TCP:
		hints.ai_socktype = SOCK_STREAM;
		break;
	case IPPROTO_UDP:
		hints.ai_socktype = SOCK_DGRAM;
		break;
	case IPPROTO_ICMPV6:
		hints.ai_socktype = SOCK_RAW;
		break;
	case IPPROTO_PGM:
		hints.ai_socktype = SOCK_RDM;
		break;
	default:
		std::cout << "Error: This socktype doesn't exist." << std::endl;
		break;
	}
	hints.ai_protocol = _protocol;
	hints.ai_flags = AI_PASSIVE;

	StartupWin();
}


NetworkLC::~NetworkLC()
{
}
