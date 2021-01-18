#pragma once
#include <map>
#include <SFML/Audio.hpp>
#include "TaskManager.h"

namespace MP
{
	class Music
	{
	private:

		std::map<std::string, std::string> _music;///Stores music's path.

		std::string _current_music_name;///Music name.

		sf::Music _current_playing_music;///Current playing music.

		///Sets music.
		///@param music_name name of the music.
		///@param file_name name of the file from which it will be taken.
		void _set_music(std::string music_name, std::string file_name);

		///Plays music.
		///@param musicName name of music.
		///@param playLoop if true music will play in loop.
		void _play(std::string musicName, bool playLoop);

	public:

		///Music's constructor.
		Music();

		///Updates music, changes it ect.
		void update(TaskManager &mainTaskManager);
	};

}