#include "Sound.h"
#include "Engine/ConfigurationLoader.h"

MP::Sound::Sound()
{
	_volume = 0;
	_sound.setVolume(float(RiD::ConfigurationLoader::getIntData("game settings", "soundVolume")));
}

void MP::Sound::playSound(sf::SoundBuffer& aSoundBuffer)
{
	
	_sound.setBuffer(aSoundBuffer);

	_sound.play();

}

bool MP::Sound::isPlaying()
{
	if (_sound.getStatus() == sf::Sound::SoundSource::Paused or _sound.getStatus() == sf::Sound::SoundSource::Stopped)
		return false;
	else
		return true;
}

void MP::Sound::setSpeed(float speed)
{
	_sound.setPitch(speed);
}

void MP::Sound::stopSound()
{
	_sound.stop();
}
