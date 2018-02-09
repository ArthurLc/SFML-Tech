#include "stdafx.h"


sfNetworkButton::sfNetworkButton()
{
	text = CreateNewText("NewNetworkButton");
	sprite = LoadSprite("../Datas/ContactButton.png", 1);

	SetPos({ 0,0 });
	SetRot({ 0,0 });
	SetScale({ 1,1 });

	isMouseOnButton = false;
	isMouseDown = false;

	updateMode = NetworkUpdateMode::OnChange;

	m_MsgLoopThread = new std::thread(&sfNetworkButton::ThreadMsgLoop, this);
	m_MsgLoopThread->detach();
}

sfNetworkButton::sfNetworkButton(std::string _sText, NetworkUpdateMode _updateMode, sf::Vector2f _pos, sf::Vector2f _rot, sf::Vector2f _scale, std::string _sSpriteFile)
{
	text = CreateNewText(_sText);
	sprite = LoadSprite(_sSpriteFile, 1);

	SetPos(_pos);
	SetRot(_rot);
	SetScale(_scale);

	isMouseOnButton = false;
	isMouseDown = false;

	updateMode = _updateMode;

	m_MsgLoopThread = new std::thread(&sfNetworkButton::ThreadMsgLoop, this);
	m_MsgLoopThread->detach();
}

sfNetworkButton::~sfNetworkButton()
{
}


void sfNetworkButton::SetPos(sf::Vector2f _pos)
{
	switch (updateMode)
	{
	case NetworkUpdateMode::OnChange:
		if (GetPos() != _pos)
		{
			sfTransform::SetPos(_pos);

			if (ClientLC::Instance != nullptr)
			{
				char datas[1 + 6 * sizeof(float)];
				NetworkButtonToBytes(datas, *this);
				ClientLC::Instance->SendMsg(datas);
			}
		}
		break;
	case NetworkUpdateMode::Continuous:
		sfTransform::SetPos(_pos);

		if (ClientLC::Instance != nullptr)
		{
			char datas[1 + 6 * sizeof(float)];
			NetworkButtonToBytes(datas, *this);
			ClientLC::Instance->SendMsg(datas);
		}
		break;
	default:
		break;
	}
}


/*###THREADS###*/
int sfNetworkButton::ThreadMsgLoop()
{
	while (true)
	{
		NetworkLC::Datas_mtx->lock();
		DATAS_LIST tempDatas = NetworkLC::GetDataList();
		printf("NumDatas: %d\n", tempDatas.size());
		DATAS_LIST::iterator ii;
		for (ii = tempDatas.begin(); ii != tempDatas.end(); ++ii)
		{
			//TODO: Pourquoi faire se test fait crash ???
			if ((char)(*ii).second[0] == GetNetworkID()) {
				BytesToNetworkButton(this, (*ii).second);
				break;
			}
		}
		if (ii != tempDatas.end()) {
			tempDatas.erase(ii);
		}
		NetworkLC::Datas_mtx->unlock();
	}
	return 0;
}
/*#############*/ 
