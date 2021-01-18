#pragma once
#include "ActiveObject.h"
#include "Map.h"
#include "TaskManager.h"

namespace MP 
{
	class PawnObject:public ActiveObject
	{
	protected:

		MapElement* _current_land;///Stores ptr to current land, where pawn stands.

		bool _whinney_once;///Stores if horse can makes sound.

	public:

		TaskManager aPawnObjectTaskManager;///Special task manager for pawns.
		
		///Pawn's constructor.
		PawnObject();


		///Checks if up map element is walkable.
		///@param gameMap game's map.
		///@return true if element is walkable.
		bool checkGoUp(Map& gameMap);

		///Checks if up map element is walkable.
		///@param gameMap game's map.
		///@return true if element is walkable.
		bool checkGoDown(Map& gameMap);

		///Checks if up map element is walkable.
		///@param gameMap game's map.
		///@return true if element is walkable.
		bool checkGoLeft(Map& gameMap);

		///Checks if up map element is walkable.
		///@param gameMap game's map.
		///@return true if element is walkable.
		bool checkGoRight(Map& gameMap);

		///Returns current land, where pawn stands.
		///@return current land.
		MapElement* getCurrentLand();
	};
}
