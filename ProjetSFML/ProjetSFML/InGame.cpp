#include "stdafx.h"
#include "InGame.h"

InGame::InGame()
{
	/*server = new ServerLC(IPPROTO_TCP);
	server->CreateServer();*/
	
	client = new ClientLC(IPPROTO_TCP);
	client->ConnectToServer("127.0.0.1");
}

InGame::~InGame()
{
	server->ShutdownServer();
	//client->ShutdownConnection();
}



void InGame::EventLoop(sfCursor* _cursor, GAME_STATE* gameState, sf::RenderWindow& _window)
{
	
}


void InGame::FixedUpdateLoop()
{
	client->SendMsg("Salut !");
}

void InGame::BlitLoop(sf::RenderWindow& _window)
{
	BlitSprite(sprite, { 0,0 }, _window);
}
