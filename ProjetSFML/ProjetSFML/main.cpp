/*
* @Arthur Lacour
* @main.cpp
* @02/12/2017
* @Main loop for the game.
*/

#include "stdafx.h"
#include "Menu.h"
#include "InGame.h"
#include <Windows.h>

void HideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

int main()
{
	HideConsole();
	GAME_STATE gameState = GAME_STATE::E_Menu;
	Menu* menu = new Menu();
	InGame* game = new InGame();

	sf::RenderWindow window;
	sfCursor* cursor = new sfCursor();

	sf::Sprite mainSprite = LoadSprite("../Datas/NotifCircle.png", 0);

	initializeWindow(window, "ProjetSFML", sf::Vector2u(SCREEN_WIDTH, SCREEN_HEIGHT), false, false, 60);

	sf::Event event;
	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen())
	{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
				event.type = sf::Event::Closed;
			}

			switch (gameState)
			{
			case E_Menu:
				menu->EventLoop(cursor, &gameState, window);
				break;
			case E_Game:
				game->EventLoop(cursor, &gameState, window);
				break;
			default:
				break;
			}

			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == sf::Event::Closed)
				window.close();
		}


		switch (gameState)
		{
		case E_Menu:
			menu->FixedUpdateLoop();
			break;
		case E_Game:
			game->FixedUpdateLoop();
			break;
		default:
			break;
		}


		window.clear();
		BlitSprite(mainSprite, { 0,0 }, window);

		switch (gameState)
		{
		case E_Menu:
			menu->BlitLoop(window);
			break;
		case E_Game:
			game->BlitLoop(window);
			break;
		default:
			break;
		}

		cursor->BlitCursor(window); // Affichage de la souris en dernier !
		window.display();
	}

	return 0;
}

