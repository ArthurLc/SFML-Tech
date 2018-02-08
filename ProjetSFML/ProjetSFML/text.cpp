#include "stdafx.h"


sf::Text CreateNewText(std::string _sText, std::string _sFont, int _iCharacterSize, sf::Color _fillColor, sf::Color _outlineColor, float _outlineThickness)
{
	// Déclaration des variables nécessaires a charger un sprite
	sf::Text tempText;
	sf::Font* font = new sf::Font;
	
	font->loadFromFile(_sFont);
	tempText.setFont(*font);

	tempText.setString(_sText);
	tempText.setCharacterSize(_iCharacterSize);
	tempText.setFillColor(_fillColor);
	tempText.setOutlineColor(_outlineColor);
	tempText.setOutlineThickness(_outlineThickness);

	return tempText;
}

int BlitText(sf::Text& _text, sf::Vector2f _pos, bool _bIsCentered, sf::RenderWindow& _window)
{
	if (_bIsCentered == true)
	{
		_text.setPosition(_pos - sf::Vector2f((_text.getGlobalBounds().width / 2.0f), (_text.getGlobalBounds().height)));
	}
	else {
		_text.setPosition(_pos);
	}


	_window.draw(_text);

	return 0;
}

int BlitInvertText(sf::Text& _text, sf::Vector2f _pos, sf::RenderWindow& _window)
{
	_text.setPosition(_pos - sf::Vector2f(_text.getGlobalBounds().width, (_text.getGlobalBounds().height)));
	_window.draw(_text);

	return 0;
}
