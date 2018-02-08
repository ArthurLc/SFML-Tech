#include "stdafx.h"


sfNetworkButton::sfNetworkButton(std::string _sText, sf::Vector2f _pos, sf::Vector2f _rot, sf::Vector2f _scale, std::string _sSpriteFile)
{
	text = CreateNewText(_sText);
	sprite = LoadSprite(_sSpriteFile, 1);

	SetPos(_pos);
	SetRot(_rot);
	SetScale(_scale);

	isMouseOnButton = false;
	isMouseDown = false;

	m_MsgLoopThread = new std::thread(&sfNetworkButton::ThreadMsgLoop, this);
	m_MsgLoopThread->detach();
}


sfNetworkButton::~sfNetworkButton()
{
}

/*###THREADS###*/
int sfNetworkButton::ThreadMsgLoop()
{
	while (true)
	{
		NetworkLC::mtx_Datas->lock();
		DATAS_LIST tempDatas = NetworkLC::GetDataList();
		for (DATAS_LIST::iterator ii = tempDatas.begin(); ii != tempDatas.end(); ++ii)
		{
			//TODO: Pourquoi faire se test fait crash ???
			if ((char)(*ii).second[0] == GetNetworkID()) {
				BytesToNetworkButton(this, (*ii).second);
				tempDatas.erase(ii);
				break;
			}
		}
		NetworkLC::mtx_Datas->unlock();
	}
	return 0;
}
/*#############*/ 
