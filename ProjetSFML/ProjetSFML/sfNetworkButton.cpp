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

	obj = this;
	updateMode = NetworkUpdateMode::OnChange;
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

	obj = this;
	updateMode = _updateMode;
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
