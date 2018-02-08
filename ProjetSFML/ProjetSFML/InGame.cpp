#include "stdafx.h"
#include "InGame.h"


InGame::InGame()
{
	m_pNetButton = new sfNetworkButton("ONLINE", { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
}

InGame::~InGame()
{

}



void InGame::EventLoop(sfCursor* _cursor, GAME_STATE* gameState, sf::Event& _event, sf::RenderWindow& _window)
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
	
}

void InGame::BlitLoop(sf::RenderWindow& _window)
{
	m_pNetButton->Draw(_window);
}
