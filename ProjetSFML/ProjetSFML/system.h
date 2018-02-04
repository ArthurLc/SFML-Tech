#ifndef SYSTEM_H
#define SYSTEM_H

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int initializeWindow(sf::RenderWindow& _window, char* _winName, sf::Vector2u _size, bool _bIsFullscreen, bool _bSetMouseCursor, unsigned int _uiFramerateLimit);

#endif
