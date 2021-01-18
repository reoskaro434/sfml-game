#include "Music.h"
#include "Engine/ConfigurationLoader.h"


void MP::Music::_set_music(std::string music_name, std::string file_name)
{
	_music[music_name] = file_name;
}

void MP::Music::_play(std::string musicName, bool playLoop)
{
	_current_music_name = musicName;
	try
	{
		if (_current_playing_music.openFromFile(_music[musicName]))
		{
			_current_playing_music.setLoop(playLoop);
			_current_playing_music.play();
		}
		else
		{
			throw std::runtime_error("Filed to open music");
		}
	}
	catch (std::runtime_error& error)
	{
		std::cout << "Sound error.\n sound name: " << musicName << " " << error.what() << std::endl;
	}
}

MP::Music::Music()
{
	_set_music("robinHood", "music/robin_hood_savant.ogg");
	_set_music("tickle", "music/tickle_savant.ogg");
	_current_playing_music.setVolume(float(RiD::ConfigurationLoader::getIntData("game settings","musicVolume")));
}

void MP::Music::update(TaskManager& mainTaskManager)
{
	switch (mainTaskManager.getCurrentState())
	{
	case TaskManager::stateType::stateMainMenu:
	{
		if (_current_music_name != "robinHood")
			_play("robinHood",true);
			
	}break;
	case TaskManager::stateType::stateGame:
	{
		if (_current_music_name != "tickle")
			_play("tickle",true);
	}break;
	case TaskManager::stateType::statePlacesMenu:
	{

	}break;
	case TaskManager::stateType::stateMarketPlace:
	{

	}break;
	}
}
