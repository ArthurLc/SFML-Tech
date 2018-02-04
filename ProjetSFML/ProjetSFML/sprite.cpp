#include "stdafx.h"

sf::Sprite LoadSprite(string _sFile, bool _bIsCentered)
{
	// D�claration des variables n�cessaires a charger un sprite
	sf::Sprite tempSprite;
	sf::Texture* tempTex = new sf::Texture;

	tempTex->loadFromFile(_sFile); // On utilise le nom de fichier pass� en param�tre
	tempSprite.setTexture(*tempTex);

	// Si on veut centrer le sprite...
	if (_bIsCentered == true)
	{
		// On charge la taille en pixel de la texture
		sf::Vector2u tempTaille = tempTex->getSize();
		// On d�calera ensuite la texture de la moiti� de sa taille (pour atteindre le centre)
		sf::Vector2f tempDecalage = { tempTaille.x / 2.f, tempTaille.y / 2.f };
		// Application du d�calage
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
