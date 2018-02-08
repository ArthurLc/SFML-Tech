#include "stdafx.h"
#include "InGame.h"


InGame::InGame()
{
	/*server = new ServerLC(IPPROTO_TCP);
	server->CreateServer();*/
	
	client = new ClientLC(IPPROTO_TCP);
	client->ConnectToServer("133.133.3.182");

	m_pNetButton = new sfNetworkButton("ONLINE", { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
}

InGame::~InGame()
{
	//server->ShutdownServer();
	client->ShutdownConnection();
}



void InGame::EventLoop(sfCursor* _cursor, GAME_STATE* gameState, sf::RenderWindow& _window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		m_pNetButton->SetPos({ m_pNetButton->GetPos().x + 1,m_pNetButton->GetPos().y });
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		m_pNetButton->SetPos({ m_pNetButton->GetPos().x - 1,m_pNetButton->GetPos().y });
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		m_pNetButton->SetPos({ m_pNetButton->GetPos().x,m_pNetButton->GetPos().y - 1 });
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		m_pNetButton->SetPos({ m_pNetButton->GetPos().x,m_pNetButton->GetPos().y + 1 });
}


void InGame::FixedUpdateLoop()
{
	char datas[1 + 6 * sizeof(float)];
	NetworkButtonToBytes(datas, *m_pNetButton);
	client->SendMsg(datas);
}

void InGame::BlitLoop(sf::RenderWindow& _window)
{
	m_pNetButton->Draw(_window);
}
