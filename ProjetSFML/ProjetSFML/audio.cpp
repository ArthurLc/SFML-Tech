#include "stdafx.h"

sf::Music* LoadMusic(char* _sName, float _fVolume, bool _isLoop)
{
	sf::Music* tempMusic = new sf::Music();

	tempMusic->openFromFile(_sName); //Chargement à partir du fichier
	tempMusic->setVolume(_fVolume); //Volume réduit (_fVolume%)
	tempMusic->setLoop(_isLoop); //Lecture en boucle

	return tempMusic;
}

sf::Sound* LoadSound(char* _sName, float _fVolume)
{
	sf::Sound* tempSound = new sf::Sound;
	sf::SoundBuffer tempBuffer;

	tempBuffer.loadFromFile(_sName); //Chargement des données du son
	tempSound->setBuffer(tempBuffer); //Assignation des données du fichier au son
	tempSound->setVolume(_fVolume); //Volume réduit (_fVolume%)

	return tempSound;
}
