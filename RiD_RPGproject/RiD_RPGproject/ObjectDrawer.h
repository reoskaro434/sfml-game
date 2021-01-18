#pragma once
#include "ObjectManager.h"
#include "Camera.h"
#include "MapElement.h"

namespace MP
{
	class ObjectDrawer
	{
	private:

		///Draws land, and places (if exists).
		///@param mainWindow  game's window.
		///@param aObjectManager stores objects.
		void _draw_land(sf::RenderWindow& mainWindow, ObjectManager& aObjectManager);

		///Draws trees.
		///@param mainTaskManger manage's tasks.
		///@param mainWindow  game's window.
		///@param aObjectManager stores objects.
		void _draw_trees(TaskManager& mainTaskManager, sf::RenderWindow& mainWindow, ObjectManager& aObjectManager);

		///Draws grass.
		///@param mainWindow  game's window.
		///@param aObjectManager stores objects.
		void _draw_grass(sf::RenderWindow& mainWindow, ObjectManager& aObjectManager);
		
		///Draws active obiects like player, computer player.
		///@param mainTaskManger manage's tasks.
		///@param mainWindow  game's window.
		///@param aObjectManager stores objects.
		void _draw_active_obiects(TaskManager& mainTaskManger, sf::RenderWindow& mainWindow, ObjectManager& aObjectManager);
		
	public:

		///Draws game's objects.
		///@param mainTaskManger manage's tasks.
		///@param aGameCamera game's window.
		///@param aObjectManager stores objects.
		void drawGame(TaskManager& mainTaskManager, Camera &aGameCamera, ObjectManager & aObjectManager);

	};

}