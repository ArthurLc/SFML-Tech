#pragma once
#include <thread>

class sfInputField : public sfButton
{
private:
	sf::String playerInput;

	std::thread* inputThread;
	sf::Event* stockEvent;
	bool isSelect;
	bool isKeyPressed;

	int Thread_UpdateField();

public:
	sfInputField();
	sfInputField(std::string _sText, sf::Vector2f _pos = { 0,0 }, sf::Vector2f _rot = { 0,0 }, sf::Vector2f _scale = { 1,1 }, std::string _sSpriteFile = "../Datas/ContactButton.png");
	~sfInputField();
	
	void SelectField(sf::Event& _event);
};

