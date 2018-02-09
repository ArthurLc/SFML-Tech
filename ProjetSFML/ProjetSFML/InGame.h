#ifndef INGAME_H
#define INGAME_H

class InGame
{
private:
	ServerLC * server;
	ClientLC* client;

	sfNetworkButton* m_pNetButton;
	sfNetworkButton* m_pNetButton2;

public:
	InGame();
	~InGame();

	void EventLoop(sfCursor* _cursor, GAME_STATE* gameState, sf::Event& _event, sf::RenderWindow& _window);
	void FixedUpdateLoop();
	void BlitLoop(sf::RenderWindow& _window);
};

#endif
