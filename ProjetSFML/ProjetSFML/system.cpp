#include "stdafx.h"

int initializeWindow(sf::RenderWindow& _window, char* _winName, sf::Vector2u _size, bool _bIsFullscreen, bool _bSetMouseCursor, unsigned int _uiFramerateLimit)
{
	_window.create(sf::VideoMode(_size.x, _size.y), _winName, _bIsFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	_window.setMouseCursorVisible(_bSetMouseCursor);
	_window.setFramerateLimit(_uiFramerateLimit);

	return 0;
}
