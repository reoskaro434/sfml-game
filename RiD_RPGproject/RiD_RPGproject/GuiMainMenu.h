#pragma once
#include "GuiMenu.h"



namespace MP
{
	class GuiMainMenu :public GuiMenu
	{
	private:

		///Creates buttons.
		///@param aAssetManager contains textures and fonts.
		void _create_buttons(RiD::AssetManager& aAssetManager);

		///Checks mouse coordinates and makes button active.
		///@param aSoundManager stores sounds buffers.
		///@param mouseCoord mouse's coordinates.
		///@param mainTaskManager game's task manager.
		void _select_button(SoundManager& aSoundManager, TaskManager& mainTaskManager, sf::Vector2f mouseCoord);

		///Starts procedures relative to pressed button.
		///@param mainTaskManager main task manager.
		///@param mainWindow game's main window.
		void _press_button(TaskManager &mainTaskManager, sf::RenderWindow & mainWindow);

	public:

		///GUI's constructor.
		GuiMainMenu();

		///GUI's constructor.
		///@param aAssetManager contains textures and fonts.
		GuiMainMenu(RiD::AssetManager& aAssetManager);
	
		///Updates GUI.
		///@param aSoundManager plays songs.
		///@param mainTaskManager main task manager.
		///@param mainWindow game's main window.
		///@param guiMouseCoord mouse's coord from gui view.
		void update(SoundManager& aSoundManager, TaskManager& mainTaskManager, sf::RenderWindow& mainWindow, sf::Vector2f guiMouseCoord);

		///Draws GUI.
		///@param mainTaskManager main task manager.
		///@param mainWindow game's main window.
		void render(TaskManager& mainTaskManager, sf::RenderWindow& mainWindow);
	};
}