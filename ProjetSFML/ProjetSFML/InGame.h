#ifndef INGAME_H
#define INGAME_H

class InGame
{
private:
	ServerLC * server;
	ClientLC* client;

	sfNetworkButton* m_pNetButton;

public:
	InGame();
	~InGame();

	void EventLoop(sfCursor* _cursor, GAME_STATE* gameState, sf::RenderWindow& _window);
	void FixedUpdateLoop();
	void BlitLoop(sf::RenderWindow& _window);
};

#endif
