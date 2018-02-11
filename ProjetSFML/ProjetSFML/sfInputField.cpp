#include "stdafx.h"

sfInputField::sfInputField()
{
	text = CreateNewText("NewInputField");
	sprite = LoadSprite("../Datas/ContactButton.png", 1);

	SetPos({ 0,0 });
	SetRot({ 0,0 });
	SetScale({ 1,1 });

	isMouseOnButton = false;
	isMouseDown = false;
	isSelect = false;
	isKeyPressed = false;

	playerInput = "NewInputField";
}
sfInputField::sfInputField(std::string _sText, sf::Vector2f _pos, sf::Vector2f _rot, sf::Vector2f _scale, std::string _sSpriteFile)
{
	text = CreateNewText(_sText);
	sprite = LoadSprite(_sSpriteFile, 1);

	SetPos(_pos);
	SetRot(_rot);
	SetScale(_scale);

	isMouseOnButton = false;
	isMouseDown = false;
	isSelect = false;
	isKeyPressed = false;

	playerInput = _sText;
}

sfInputField::~sfInputField()
{
	inputThread->~thread();
}



int sfInputField::Thread_UpdateField()
{
	while (isSelect)
	{
		if (stockEvent->type == sf::Event::TextEntered)
		{
			sf::Uint32 input = stockEvent->text.unicode;
			if (input == (sf::Uint32)13) {
				isSelect = false;
			}
			else if (input == (sf::Uint32)8) {
				isKeyPressed = true;

				playerInput.erase(0);
				SetText(playerInput);
			}
			else if(isKeyPressed == false)
			{
				isKeyPressed = true;

				playerInput += input;
				SetText(playerInput);
			}
		}
		else
		{
			isKeyPressed = false;
		}
	}

	return 0;
}


void sfInputField::SelectField(sf::Event& _event)
{
	if (isSelect == false)
	{
		isSelect = true;
		stockEvent = &_event;

		inputThread = new std::thread(&sfInputField::Thread_UpdateField, this);
		inputThread->detach();
	}
}
