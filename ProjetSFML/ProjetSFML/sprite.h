#ifndef SPRITE_H
#define SPRITE_H

sf::Sprite LoadSprite(std::string _sFile, bool _bIsCentered);
int BlitSprite(sf::Sprite& _sprite, sf::Vector2f _pos, sf::RenderWindow& _window);

#endif
