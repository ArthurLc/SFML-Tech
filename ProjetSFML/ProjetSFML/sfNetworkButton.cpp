#include "stdafx.h"


sfNetworkButton::sfNetworkButton()
{
	text = CreateNewText("NewNetworkButton");
	sprite = LoadSprite("../Datas/ContactButton.png", 1);

	sfTransform::SetPos({ 0,0 });
	sfTransform::SetRot({ 0,0 });
	sfTransform::SetScale({ 1,1 });

	isMouseOnButton = false;
	isMouseDown = false;

	obj = this;
	updateMode = NetworkUpdateMode::OnChange;
}

sfNetworkButton::sfNetworkButton(std::string _sText, NetworkUpdateMode _updateMode, sf::Vector2f _pos, sf::Vector2f _rot, sf::Vector2f _scale, std::string _sSpriteFile)
{
	text = CreateNewText(_sText);
	sprite = LoadSprite(_sSpriteFile, 1);

	sfTransform::SetPos(_pos);
	sfTransform::SetRot(_rot);
	sfTransform::SetScale(_scale);

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
			if (ClientLC::Instance != nullptr) {
				sf::Vector2f previousPos = GetPos();
				NetworkIdentity::Obj_mtx->lock();
				sfTransform::SetPos(_pos);
				ClientLC::Instance->SendMsg(NetworkButtonToBytes(*this));
				sfTransform::SetPos(previousPos);
				NetworkIdentity::Obj_mtx->unlock();
			}
			else if (ServerLC::Instance != nullptr) {
				NetworkIdentity::Obj_mtx->unlock();
				sfTransform::SetPos(_pos);
				ServerLC::Instance->SendMsg(NetworkButtonToBytes(*this));
				NetworkIdentity::Obj_mtx->lock();
			}
		}
		break;
	case NetworkUpdateMode::Continuous:
		if (ClientLC::Instance != nullptr) {
			sf::Vector2f previousPos = GetPos();
			sfTransform::SetPos(_pos);
			ClientLC::Instance->SendMsg(NetworkButtonToBytes(*this));
			sfTransform::SetPos(previousPos);
		}
		else if (ServerLC::Instance != nullptr) {
			sfTransform::SetPos(_pos);
			ServerLC::Instance->SendMsg(NetworkButtonToBytes(*this));
		}
		break;
	default:
		break;
	}
}


void sfNetworkButton::Draw(sf::RenderWindow& _window)
{
	Obj_mtx->lock();
	sfButton::Draw(_window);
	Obj_mtx->unlock();
}
