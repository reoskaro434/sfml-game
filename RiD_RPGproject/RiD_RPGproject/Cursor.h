#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Camera.h"
#include "TaskManager.h"

namespace MP
{
	class Cursor: public Object
	{
	private:
			
		sf::Vector2f _game_coord;///Stores mouse's coord from game view.

		sf::Vector2f _gui_coord;///Stores mouse's coord from gui view.

		///Updates cursor.
		///@param mainTaskManager main game's task manager.
		///@param gameCamera game's camera.
		void _update_cursor(TaskManager& mainTaskManager, Camera& gameCamera);

		///Checks if player clicked.
		///@param mainTaskManager main game's task manager.
		///@param gameCamera game's camera.
		void _check_if_player_clicked(TaskManager& mainTaskManager, Camera& gameCamera);

	public:

		///Cursor's constructor.
		///@param texturePtr cursor's texture.
		Cursor(sf::Texture* texturePtr);

		///Sets mouse's coord in game.
		///@param game's coord.
		void setGameCoord(sf::Vector2f gameCoord);
		
		///Returns game coordinates.
		///@return game coordinates.
		sf::Vector2f getGameCoord();

		///Sets GUI coordinates.
		///@param guiCoord coordinates.
		void setGuiCoord(sf::Vector2f guiCoord);

		///Returns gui's coord.
		///@return gui's coord.
		sf::Vector2f getGuiCoord();

		///Updates cursor.
		///@param mainTaskManager main game's task manager.
		///@param gameCamera game's camera.
		void update(TaskManager& mainTaskManager, Camera& gameCamera);

		///Draws cursor.
		///@param mainWindow game's window.
		void render(sf::RenderWindow &mainWindow);
	};
}