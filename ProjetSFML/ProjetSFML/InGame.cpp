#include "stdafx.h"
#include "InGame.h"

InGame::InGame()
{
	sprite = LoadSprite("../Datas/PhoneHeader.png", 0);
}

InGame::~InGame()
{
}



void InGame::EventLoop(sfCursor* _cursor, GAME_STATE* gameState, sf::RenderWindow& _window)
{
	
}


void InGame::FixedUpdateLoop()
{

}

void InGame::BlitLoop(sf::RenderWindow& _window)
{
	BlitSprite(sprite, { 0,0 }, _window);
}
