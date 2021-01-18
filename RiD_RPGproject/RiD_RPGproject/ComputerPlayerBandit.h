#pragma once
#include <SFML/Graphics.hpp>
#include "PawnObject.h"
#include "PathCreator.h"
#include "Player.h"

namespace MP
{
	class ComputerPlayerBandit:public PawnObject
	{
	private:

		MapElement* _path;///Stores path.

		int _radius;///Used to calculate detect area.

		///returns true if computer player detects enemy.
		///@return true if computer player detects enemy.
		bool _is_enemys_check;

		///Makes animation.
		///@param globalClock game's clock.
		void _computer_player_animation_right(sf::Clock& globalClock);

		///Makes animation.
		///@param globalClock game's clock.
		void _computer_player_animation_left(sf::Clock& globalClock);

		///Makes animation.
		///@param globalClock game's clock.
		void _computer_player_animation_up(sf::Clock& globalClock);

		///Makes animation.
		///@param globalClock game's clock.
		void _computer_player_animation_down(sf::Clock& globalClock);

		///Makes animation.
		///@param globalClock game's clock.
		void _computer_player_animation(sf::Clock& globalClock);

		///Starts move procedure.
		///@param globalClock game's clock.
		void _computer_player_move(sf::Clock& globalClock);

		///Sets next task.
		///@param aMap game's map.
		///@param player player.
		void _get_next_task(Map& aMap, std::shared_ptr<Player>& player);

		///Choses next destination.
		///@param aMap game's map.
		void _chose_destination(Map& aMap);

		///Deletes path.
		void _delete_path();

		///Returns true if enemy was detected.
		///@param player player.
		///Return true if enemy was detected.
		bool _check_enemy(std::shared_ptr<Player>& aPlayer);

		///Starts song procedure.
		///@param aSoundManager stores sound's buffers.
		void _song_procedure(MP::SoundManager& aSoundManager);

		///Start procedure attack player.
		///@param gameMap game's map.
		///@param player player.
		void _attack_player(Map& gameMap, std::shared_ptr<Player>& player);

	public:

		///Creates computer player.
		///@param texturePtr contains computer player texture.
		///@param computerPlayerCoordinates computer  player's coordinates.
		ComputerPlayerBandit(sf::Texture* texturePtr,sf::Vector2f computerPlayerCoordinates);

		///Delets path.
		~ComputerPlayerBandit();

		///Updates computer player.
		///@param mainTaskManger stores task's.
		///@param aSoundManager stores sound's buffers.
		///@param aMap game's map.
		///@param gameClock game's clock.
		///@param aPlayer player.
		void update(TaskManager& mainTaskManager,SoundManager& aSoundManager, Map& aMap, sf::Clock& gameClock, std::shared_ptr<Player>& aPlayer);

		///Renders computer player.
		///@param mainTaskManger stores task's.
		///@param mainWindow game's window.
		void render(TaskManager& mainTaskManager,sf::RenderWindow &mainWindow);

	};

}