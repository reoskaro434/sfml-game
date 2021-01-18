#pragma once
#include <vector>
#include "PawnObject.h"
#include "Map.h"
#include "PathIcon.h"
#include "TaskManager.h"
#include "SoundManager.h"
#include "MissionCreator.h"

namespace MP
{
	class Player :public PawnObject
	{
	private:

		sf::Vector2f checkingVector;///Saved postion of first clicked block.

		MapElement* _path;///Player's path, generated from auto move procedure.

		sf::Texture * _a_path_icon_texture;///Stores path's texture.

		std::vector<PathIcon> _a_path_icon;///Stores path's icon.

	 	MissionCreator _a_mission_creator;///Creates mission.

		std::shared_ptr<Places> _current_place;///Stores current place which interact witch player.

		std::shared_ptr<Places> _destination_place; ///Destination place.

		std::shared_ptr<Places> _employer_place;///Player's emplyer.

		std::shared_ptr<Mission> _current_mision;///Current mission.

		std::string message[12];/// Message which updates gui message.

		///Changes player's sprite.
		///@param globalClock games'clock.
		void _player_animation_right(sf::Clock& globalClock);

		///Changes player's sprite.
		///@param globalClock games'clock.
		void _player_animation_left(sf::Clock& globalClock);

		///Changes player's sprite.
		///@param globalClock games'clock.
		void _player_animation_up(sf::Clock& globalClock);

		///Changes player's sprite.
		///@param globalClock games'clock.
		void _player_animation_down(sf::Clock& globalClock);

		///Changes player's sprite.
		///@param globalClock games'clock.
		void _player_animation_idle(sf::Clock& globalClock);

		///Starts player's animation. 
		///@param globalClock game's clock.
		///@param mainTaskManger game's task manager.
		void _player_animation(sf::Clock& globalClock, TaskManager& mainTaskManger);

		///Starts player's move. 
		///@param globalClock game's clock.
		///@param mainTaskManger game's task manager.
		void _player_move(sf::Clock& globalClock, TaskManager& mainTaskManger);

		///Starts player's auto move. 
		///@param aMap game's map.
		///@param mainTaskManger game's task manager.
		void _player_automatic_move(Map& aMap, TaskManager& mainTaskManger);

		///Sets new path.
		///@param newPath new path head.
		void _set_path(MapElement*& newPath);

		///Delets player's path.
		void _delete_player_path();

		///Creates path icon.
		void _mark_path();

		///Delets path icon.
		void _unmark_path();

		///Starts procedure auto move.
		///@param mainTaskManger manages tasks.
		////@param gameClock game's clock.
		///@param aMap game's map.
		///@param mouseGameCoord stores mouse game coord.
		void _procedure_player_auto_move(TaskManager& mainTaskManger, sf::Clock& gameClock, MP::Map& aMap, sf::Vector2f &mouseGameCoord);

		///Starts song procedure
		///@param gameClock game's clock.
		///@param aSoundManager stores sounds' buffers.
		///@param mainTaskManger manages tasks.
		void _song_procedure(sf::Clock& gameClock, MP::SoundManager& aSoundManager, TaskManager& mainTaskManger);

		///Starts mission procedure.
		///@param mainTaskManger manages tasks.
		///@param gameMap game's map.
		///@param aSoundManager plays sounds.
		void _mission_procedure(TaskManager& mainTaskManger, Map& gameMap, SoundManager& aSoundManager);

		///Handles keyboard.
		///@param mainTaskManger manage's task.
		///@param gameMap game's map.
		void _keyboard_handling(TaskManager& mainTaskManger, Map& gameMap);

	public:

		///Player's constructor.
		///@param texturePtr player's texture.
		///@param pathIconTexturePtr path's texture.
		Player(sf::Texture *texturePtr,sf::Texture *pathIconTexturePtr);

		///Opens place's menu.
		///@param gameMap game's map.
		///@param aMainTaskManager game's task manager.
		void goToPlace(Map& gameMap, TaskManager& aMainTaskManger);

		///Returns current place.
		///return current place.
		std::shared_ptr<Places> & getCurrentPlace();

		///Returns message.
		///@return message.
		std::string* getMessage();

		///Updates player.
		///@param aSoundManager stores sounds' buffers.
		///@param mainTaskManger game's task manager.
		///@param gameClock game's clock.
		///@param gameMap game's map.
		///@param mouseGameCoord
		void update(SoundManager& aSoundManager, TaskManager& mainTaskManger, sf::Clock& gameClock, MP::Map& gamesMap, sf::Vector2f mouseGameCoord);

		///Draws player.
		///@param mainTaskManger game's task manager.
		///@param mainWindow game's window.
		void render(TaskManager& mainTaskManger, sf::RenderWindow &mainWindow);

	
	};


}