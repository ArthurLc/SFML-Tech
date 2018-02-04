#include "stdafx.h"

sf::Sprite LoadSprite(string _sFile, bool _bIsCentered)
{
	// Déclaration des variables nécessaires a charger un sprite
	sf::Sprite tempSprite;
	sf::Texture* tempTex = new sf::Texture;

	tempTex->loadFromFile(_sFile); // On utilise le nom de fichier passé en paramètre
	tempSprite.setTexture(*tempTex);

	// Si on veut centrer le sprite...
	if (_bIsCentered == true)
	{
		// On charge la taille en pixel de la texture
		sf::Vector2u tempTaille = tempTex->getSize();
		// On décalera ensuite la texture de la moitié de sa taille (pour atteindre le centre)
		sf::Vector2f tempDecalage = { tempTaille.x / 2.f, tempTaille.y / 2.f };
		// Application du décalage
		tempSprite.setOrigin(tempDecalage);
	}

	return tempSprite;
}

int BlitSprite(sf::Sprite& _sprite, sf::Vector2f _pos, sf::RenderWindow& _window)
{
	_sprite.setPosition(_pos);
	_window.draw(_sprite);

	return 0;
}
