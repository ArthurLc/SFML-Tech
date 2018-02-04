#include "stdafx.h"
#include "Menu.h"

Menu::Menu()
{
	sprite = LoadSprite("../Datas/PhoneBGLock.png", 0);

	credits = CreateNewText("'Event'\n===\n'ProjetSFML' by Arthur Lacour", arial, 24, sf::Color::Black, sf::Color::Red, 0.5f);

	play_Button = new sfButton("PLAY", { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 });
	credits_Button = new sfButton("CREDITS", { SCREEN_WIDTH / 2, (SCREEN_HEIGHT / 2) + 100 });

	isCreditsActive = false;
}


Menu::~Menu()
{
}



void Menu::EventLoop(sfCursor* _cursor, GAME_STATE* gameState, sf::RenderWindow& _window)
{
	if (play_Button->OnMouseUp(_cursor, _window)) {
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
	play_Button->Draw(_window);
	credits_Button->Draw(_window);
	if(isCreditsActive)
		BlitText(credits, { credits_Button->GetPos().x, credits_Button->GetPos().y + 125 }, 1, _window);
}
