#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
	credits = CreateNewText("'Event'\n===\n'ProjetSFML' by Arthur Lacour", arial, 24, sf::Color::Black, sf::Color::Red, 0.5f);

	host_Button = new sfButton("HOST", { (SCREEN_WIDTH / 2) - 100, (SCREEN_HEIGHT / 2) - 100 });
	join_Button = new sfButton("JOIN", { (SCREEN_WIDTH / 2) - 100, SCREEN_HEIGHT / 2 });
	credits_Button = new sfButton("CREDITS", { (SCREEN_WIDTH / 2) - 100, (SCREEN_HEIGHT / 2) + 100 });

	isCreditsActive = false;
}


Menu::~Menu()
{
}



void Menu::EventLoop(sfCursor* _cursor, GAME_STATE* gameState, sf::RenderWindow& _window)
{
	if (host_Button->OnMouseUp(_cursor, _window)) {
		ServerLC::Instance = new ServerLC(IPPROTO_TCP);
		ServerLC::Instance->CreateServer();
		*gameState = GAME_STATE::E_Game;
	}
	else if (join_Button->OnMouseDown(_cursor, _window)) {
		ClientLC::Instance = new ClientLC(IPPROTO_TCP);
		ClientLC::Instance->ConnectToServer(NetworkLC::AdressServer);
		*gameState = GAME_STATE::E_Game;
	}
	else if (credits_Button->OnMouseDown(_cursor, _window)) {
		isCreditsActive = true;
	}
}

void Menu::FixedUpdateLoop()
{
	/*
	time_t timev = time(0);
	struct tm* now = localtime(&timev);

	hour_Text.setString((now->tm_hour < 10 ? "0" + to_string(now->tm_hour) : to_string(now->tm_hour)) + ":" + (now->tm_min < 10 ? "0" + to_string(now->tm_min) : to_string(now->tm_min)));
	date_Text.setString(tabDays[now->tm_wday] + ", " + tabMonths[now->tm_mon] + " " + to_string(now->tm_mday));
	*/


}

void Menu::BlitLoop(sf::RenderWindow& _window)
{
	BlitSprite(sprite, { 0,0 }, _window);
	host_Button->Draw(_window);
	join_Button->Draw(_window);
	credits_Button->Draw(_window);
	if(isCreditsActive)
		BlitText(credits, { credits_Button->GetPos().x, credits_Button->GetPos().y + 125 }, 1, _window);
}
