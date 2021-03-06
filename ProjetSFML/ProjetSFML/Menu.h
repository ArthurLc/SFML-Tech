#ifndef MENU_H
#define MENU_H

class Menu
{
private:
	sf::Sprite sprite;

	sf::Text credits;

	sfButton* host_Button;
	sfButton* join_Button;
	sfButton* credits_Button;
	sfInputField* adress_InputField;

	bool isCreditsActive;

public:
	Menu();
	~Menu();

	void EventLoop(sfCursor* _cursor, GAME_STATE* gameState, sf::Event& _event, sf::RenderWindow& _window);
	void FixedUpdateLoop();
	void BlitLoop(sf::RenderWindow& _window);
};



#endif
