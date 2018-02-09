#include "stdafx.h"

//Initialization static members
bool NetworkLC::IsServer = false;
PCSTR NetworkLC::AdressServer = "127.0.0.1";
std::mutex* NetworkLC::Datas_mtx = new mutex();
DATAS_LIST NetworkLC::dataList;
GO_LIST NetworkLC::goList;

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

	m_MsgLoopThread = new std::thread(&NetworkLC::ThreadMsgLoop, this);
	m_MsgLoopThread->detach();
}


NetworkLC::~NetworkLC()
{
}


/*###THREADS###*/
int NetworkLC::ThreadMsgLoop()
{
	while (true)
	{
		NetworkLC::Datas_mtx->lock();
		DATAS_LIST tempDatas = NetworkLC::GetDataList();
		GO_LIST tempGo = NetworkLC::GetGOList();
		printf("NumDatas: %d\n", tempDatas.size());
		//printf("ObjOnList: %d\n", tempGo.size());

		for (GO_LIST::iterator go = tempGo.begin(); go != tempGo.end(); ++go) //Je parcours tous les objets Network de la scène
		{
			DATAS_LIST::iterator ii;
			for (ii = tempDatas.begin(); ii != tempDatas.end(); ++ii)
			{
				if ((*ii).second[0] == (*go).second->GetNetworkID()) //Si le type du message est le miens (Exemple: "sfNetworkButton")
				{
					//void* objType = (*go).second.GetObj();
					BytesToNetworkButton((sfNetworkButton*)((*go).second->GetObj()), (*ii).second);
					break; //Break de la boucle des messages pour cet objet !
				}
			}
			if (tempDatas.size() > 0 && ii != tempDatas.end()) {
				//tempDatas.erase(ii);
			}
		}
		NetworkLC::Datas_mtx->unlock();
	}
	return 0;
}
/*#############*/

