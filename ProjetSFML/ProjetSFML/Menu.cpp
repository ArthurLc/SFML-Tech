#include "stdafx.h"
#include "Menu.h"


Menu::Menu()
{
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

	///#######sfNetworkTransform#######///
	///################################///
	/*char data[1 + 6 * sizeof(float)];
	sfNetworkTransform nTr;
	nTr.SetPos({ 1.234f, 4.321f });
	sfNetworkTransform nTr2;

	NetworkTransformToBytes(data, nTr);
	BytesToNetworkTransform(&nTr2, data);

	printf("nTr:\n");
	printf("NetID: %c\t", nTr.GetNetworkID());
	printf("x: %f\ty: %f | ", nTr.GetPos().x, nTr.GetPos().y);
	printf("x: %f\ty: %f | ", nTr.GetRot().x, nTr.GetRot().y);
	printf("x: %f\ty: %f\n", nTr.GetScale().x, nTr.GetScale().y);
	printf("nTr2:\n");
	printf("NetID: %c\t", nTr2.GetNetworkID());
	printf("x: %f\ty: %f | ", nTr2.GetPos().x, nTr2.GetPos().y);
	printf("x: %f\ty: %f | ", nTr2.GetRot().x, nTr2.GetRot().y);
	printf("x: %f\ty: %f\n\n", nTr2.GetScale().x, nTr2.GetScale().y);*/
}

void Menu::BlitLoop(sf::RenderWindow& _window)
{
	BlitSprite(sprite, { 0,0 }, _window);
	play_Button->Draw(_window);
	credits_Button->Draw(_window);
	if(isCreditsActive)
		BlitText(credits, { credits_Button->GetPos().x, credits_Button->GetPos().y + 125 }, 1, _window);
}
