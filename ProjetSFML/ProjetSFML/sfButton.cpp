#include "stdafx.h"
#include "sfCursor.h"



sfButton::sfButton(std::string _sText, sf::Vector2f _pos, sf::Vector2f _rot, sf::Vector2f _scale, std::string _sSpriteFile)
{
	text = CreateNewText(_sText);
	sprite = LoadSprite(_sSpriteFile, 1);

	SetPos(_pos);
	SetRot(_rot);
	SetScale(_scale);

	isMouseOnButton = false;
	isMouseDown = false;
}

sfButton::~sfButton()
{
}


bool sfButton::OnMouseDown(sfCursor* cursor, sf::RenderWindow& _window)
{
	if (OnMousePos(_window))
	{
		cursor->SetCursorToInteractible();
		isMouseOnButton = true;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			if (isMouseDown != true)
			{
				isMouseDown = true;
				cursor->SetCursorToBasic();
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			isMouseDown = false;
			return false;
		}
	}
	else
	{
		if (isMouseOnButton == true)
		{
			cursor->SetCursorToBasic();
			isMouseOnButton = false;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false) {
			isMouseDown = false;
		}

		return false;
	}
}

bool sfButton::OnMouseUp(sfCursor* cursor, sf::RenderWindow& _window)
{
	if (OnMousePos(_window))
	{
		cursor->SetCursorToInteractible();
		isMouseOnButton = true;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
		{
			isMouseDown = true;
			return false;
		}
		else
		{
			if (isMouseDown == true)
			{
				isMouseDown = false;
				cursor->SetCursorToBasic();
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		if (isMouseOnButton == true)
		{
			cursor->SetCursorToBasic();
			isMouseOnButton = false;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) == false) {
			isMouseDown = false;
		}

		return false;
	}
}


bool sfButton::OnMousePos(sf::RenderWindow& _window)
{
	mousePos = (sf::Vector2f)sf::Mouse::getPosition(_window); // Récupération de la position de la souris

	if (mousePos.x <= (GetPos().x + (GetScale().x * (GetSprite().getTexture()->getSize().x / 2.0f))) &&
		mousePos.x >= (GetPos().x - (GetScale().x * (GetSprite().getTexture()->getSize().x / 2.0f))) &&
		mousePos.y <= (GetPos().y + (GetScale().y * (GetSprite().getTexture()->getSize().y / 2.0f))) &&
		mousePos.y >= (GetPos().y - (GetScale().y * (GetSprite().getTexture()->getSize().y / 2.0f))))
	{
		return true;
	}
	
	return false;
}


void sfButton::Draw(sf::RenderWindow& _window)
{
	BlitSprite(sprite, GetPos(), _window);
	BlitText(text, GetPos(), 1, _window);
}
