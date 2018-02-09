#include "stdafx.h"
#include "InGame.h"


InGame::InGame()
{
	m_pNetButton = new sfNetworkButton("ONLINE", NetworkUpdateMode::OnChange, { SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) - 50 });
	m_pNetButton2 = new sfNetworkButton("ONLINE_2", NetworkUpdateMode::OnChange, { SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 50 });
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		m_pNetButton2->SetPos({ m_pNetButton2->GetPos().x + 1,m_pNetButton2->GetPos().y });
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		m_pNetButton2->SetPos({ m_pNetButton2->GetPos().x - 1,m_pNetButton2->GetPos().y });
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
		m_pNetButton2->SetPos({ m_pNetButton2->GetPos().x,m_pNetButton2->GetPos().y - 1 });
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		m_pNetButton2->SetPos({ m_pNetButton2->GetPos().x,m_pNetButton2->GetPos().y + 1 });
}


void InGame::FixedUpdateLoop()
{
	
}

void InGame::BlitLoop(sf::RenderWindow& _window)
{
	m_pNetButton->Draw(_window);
	m_pNetButton2->Draw(_window);
}
