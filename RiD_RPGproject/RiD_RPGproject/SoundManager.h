#pragma once
#include <SFML/Audio.hpp>
#include <map>

namespace MP
{
	class SoundManager
	{
	private:

		std::map<std::string,sf::SoundBuffer> _sound;///Contains sound buffers.

	public:
		
		///Sound manager's constructor.
		SoundManager();
		
		///Sets sound.
		///@param sound_name name of the sound.
		///@param file_name name of the file from which it will be taken.
		void setSound(std::string sound_name, std::string file_name);
		
		///Returns sound.
		///@param sound_name name of the sound.
		///@returns sound.
		sf::SoundBuffer& getSound(std::string sound_name);
	};

}