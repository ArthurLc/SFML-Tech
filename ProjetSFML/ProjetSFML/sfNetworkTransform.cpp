#include "stdafx.h"
#include "sfNetworkTransform.h"



sfNetworkTransform::sfNetworkTransform()
{
	m_MsgLoopThread = new std::thread(&sfNetworkTransform::ThreadMsgLoop, this);
	m_MsgLoopThread->detach();
}


sfNetworkTransform::~sfNetworkTransform()
{
}

/*###THREADS###*/
int sfNetworkTransform::ThreadMsgLoop()
{
	while (true)
	{
		DATAS_LIST tempDatas = NetworkLC::GetDataList();
		for (DATAS_LIST::iterator ii = tempDatas.begin(); ii != tempDatas.end(); ++ii) {
			cout << (*ii).first << ": " << (*ii).second << endl;
		}

		//TODO: Check la liste des MSG du NetworkLC
		// -> Le NetworkID()
		// -> L'ID de l'objet
	}
	return 0;
}
/*#############*/
