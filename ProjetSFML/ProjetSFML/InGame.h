#ifndef INGAME_H
#define INGAME_H

class InGame
{
private:
	sf::Sprite sprite;

public:
	InGame();
	~InGame();

	void EventLoop(sfCursor* _cursor, GAME_STATE* gameState, sf::RenderWindow& _window);
	void FixedUpdateLoop();
	void BlitLoop(sf::RenderWindow& _window);
};

#endif
