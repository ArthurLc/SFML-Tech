#ifndef AUDIO_H
#define AUDIO_H

sf::Music* LoadMusic(char* _sName, float _fVolume = 100.0f, bool _isLoop = true);
sf::Sound* LoadSound(char* _sName, float _fVolume);

#endif
