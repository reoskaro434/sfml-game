#pragma once
#include "PawnObject.h"
#include "TaskManager.h"
#include "Player.h"

namespace MP
{
	class Move
	{
	private:

		///Moves object down.
		///@param object object, whose sprite is moved.
		void _move_pixel_down(ActiveObject& object);

		///Moves object up.
		///@param object object, whose sprite is moved.
		void _move_pixel_up(ActiveObject& object);

		///Moves object right.
		///@param object object, whose sprite is moved.
		void _move_pixel_right(ActiveObject& object);

		///Moves object left.
		///@param object object, whose sprite is moved.
		void _move_pixel_left(ActiveObject& object);

	public:

		///Moves object one block down.
		///@param object object, whose sprite is moved.
		///@param currentTime current game time.
		void moveBlockDown(PawnObject& object, sf::Clock &currentTime);

		///Moves object one block up.
		///@param object object, whose sprite is moved.
		///@param currentTime current game time.
		void moveBlockUp(PawnObject& object, sf::Clock &currentTime);

		///Moves object one block right.
		///@param object object, whose sprite is moved.
		///@param currentTime current game time.
		void moveBlockRight(PawnObject& object, sf::Clock &currentTime);

		///Moves object one block left.
		///@param object object, whose sprite is moved.
		///@param currentTime current game time.
		void moveBlockLeft(PawnObject& object, sf::Clock &currentTime);

		///Moves player one block down.
		///@param player object, whose sprite is moved.
		///@param currentTime current game time.
		///@param mainTaskManager manages tasks.
		void moveBlockDown(Player& player, sf::Clock& currentTime,TaskManager &mainTaskManager);

		///Moves player one block up.
		///@param player object, whose sprite is moved.
		///@param currentTime current game time.
		///@param mainTaskManager manages tasks.
		void moveBlockUp(Player& player, sf::Clock& currentTime, TaskManager& mainTaskManager);

		///Moves player one block right.
		///@param player object, whose sprite is moved.
		///@param currentTime current game time.
		///@param mainTaskManager manages tasks.
		void moveBlockRight(Player& player, sf::Clock& currentTime, TaskManager& mainTaskManager);

		///Moves player one block left.
		///@param player object, whose sprite is moved.
		///@param currentTime current game time.
		///@param mainTaskManager manages tasks.
		void moveBlockLeft(Player& player, sf::Clock& currentTime, TaskManager& mainTaskManager);

		///Checks if main task manager is empty.
		///@param pawn whose sprite is moved.
		///@param gameMap game's map.
		///@param mainTaskManager manages tasks.
		void tryToMoveUp(PawnObject& pawn, Map& gameMap, TaskManager& mainTaskManager);

		///Checks if main task manager is empty.
		///@param pawn whose sprite is moved.
		///@param gameMap game's map.
		///@param mainTaskManager manages tasks.
		void tryToMoveDown(PawnObject& pawn, Map& gameMap, TaskManager& mainTaskManager);

		///Checks if main task manager is empty.
		///@param pawn whose sprite is moved.
		///@param gameMap game's map.
		///@param mainTaskManager manages tasks.
		void tryToMoveLeft(PawnObject& pawn, Map& gameMap, TaskManager& mainTaskManager);

		///Checks if main task manager is empty.
		///@param pawn whose sprite is moved.
		///@param gameMap game's map.
		///@param mainTaskManager manages tasks.
		void tryToMoveRight(PawnObject& pawn, Map& gameMap, TaskManager& mainTaskManager);
	};
}