#pragma once
#include <SFML/Audio.hpp>


namespace MP
{
	class Sound
	{
	private:

		sf::Sound _sound;///Stores sound.

		float _volume;///Stores sound volume.

	public:

		///Sound's constructor.
		Sound();

		///Plays sound.
		///@param aSoundBuffer sound's buffer,
		void playSound(sf::SoundBuffer& aSoundBuffer);

		///Returns true if sound is playing.
		///@return true if sound is playing.
		bool isPlaying();

		///Sets sound's speed.
		///@param speed current sound's speed.
		void setSpeed(float speed);

		///stops sound.
		void stopSound();
	};
}
