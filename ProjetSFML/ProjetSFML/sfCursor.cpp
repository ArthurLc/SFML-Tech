#include "stdafx.h"

sfCursor::sfCursor()
{
	basicCursor = LoadSprite("../Datas/basicCursor.png", 0);
	interactibleCursor = LoadSprite("../Datas/interactibleCursor.png", 1);

	currentCursor = &basicCursor;
}

sfCursor::~sfCursor()
{
}

void sfCursor::BlitCursor(sf::RenderWindow& _window)
{
	BlitSprite(*currentCursor, (sf::Vector2f)sf::Mouse::getPosition(_window), _window);
}
