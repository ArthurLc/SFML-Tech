#include "stdafx.h"

sf::Music* LoadMusic(char* _sName, float _fVolume, bool _isLoop)
{
	sf::Music* tempMusic = new sf::Music();

	tempMusic->openFromFile(_sName); //Chargement � partir du fichier
	tempMusic->setVolume(_fVolume); //Volume r�duit (_fVolume%)
	tempMusic->setLoop(_isLoop); //Lecture en boucle

	return tempMusic;
}

sf::Sound* LoadSound(char* _sName, float _fVolume)
{
	sf::Sound* tempSound = new sf::Sound;
	sf::SoundBuffer tempBuffer;

	tempBuffer.loadFromFile(_sName); //Chargement des donn�es du son
	tempSound->setBuffer(tempBuffer); //Assignation des donn�es du fichier au son
	tempSound->setVolume(_fVolume); //Volume r�duit (_fVolume%)

	return tempSound;
}
