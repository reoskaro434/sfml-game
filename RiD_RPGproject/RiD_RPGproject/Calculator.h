#pragma once
#include <thread>
#include "Move.h"
#include "TaskManager.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Camera.h"


namespace MP
{
	class Calculator
	{
	private:

		///Executes computer players' procedures.
		///@param mainTaskManager manage's tasks.
		///@param aSoundManager stores sound buffer.
		///@param aObjectManager stores objects.
		///@param gameClock game's clock.
		///@param aMap game's map.
		void _computer_players_procedure(TaskManager& mainTaskManger, SoundManager& aSoundManager, ObjectManager& aObjectManager, sf::Clock& gameClock,Map& aMap);

		///Executes trees' procedures.
		///@param mainTaskManager manage's tasks.
		///@param gameClock game's clock.
		///@param aObjectManager stores objects.
		void _trees_procedure(TaskManager& mainTaskManger, sf::Clock& gameClock, ObjectManager& aObjectManager);

	public:

		///Executes games procedures, updates objects, manages tasks.
		///@param aSoundManager stores sound buffer.
		///@param mainTaskManager manage's tasks.
		///@param aObjectManager stores objects.
		///@param gameClock game's clock.
		///@param aCamera game's camera.
		void updateGame(SoundManager& aSoundManager, TaskManager& mainTaskManger, ObjectManager& aObjectManager, sf::Clock& gameClock, Camera& aCamera);

	};
}