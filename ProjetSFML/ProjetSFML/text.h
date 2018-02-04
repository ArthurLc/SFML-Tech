#ifndef TEXT_H
#define TEXT_H

#define arial "../Datas/Fonts/Arial/arial.ttf"

sf::Text CreateNewText(std::string _sText, std::string _sFont = arial, int _iCharacterSize = 24, sf::Color _fillColor = sf::Color::White, sf::Color _outlineColor = sf::Color::Black, float _outlineThickness = 0.0f);
int BlitText(sf::Text& _text, sf::Vector2f _pos, bool _bIsCentered, sf::RenderWindow& _window);
int BlitInvertText(sf::Text& _text, sf::Vector2f _pos, sf::RenderWindow& _window);

#endif
