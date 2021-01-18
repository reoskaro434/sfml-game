#pragma once
#include "GuiMenu.h"

namespace MP
{

	class GuiPlacesMenu:public GuiMenu
	{
	private:

		///Creates buttons.
		///@param aAssetManager contains textures and fonts.
		void _create_buttons(RiD::AssetManager& aAssetManager);
	
		///Checks mouse coordinates and makes button active.
		///@param aSoundManager stores sound's buffers.
		///@param mainTaskManager main task manager.
		///@param mouseCoord mouse's coordinates.
		void _select_button(SoundManager& aSoundManager, TaskManager& mainTaskManager, sf::Vector2f mouseCoord);

		///Starts procedures relative to pressed button.
		///@param aMainTaskManager main task manager.
		///@param aMainWindow game's main window.
		void _press_button(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow);

		

	public:

		///GUI's constructor.
		GuiPlacesMenu();

		///GUI's constructor.
		///@param aAssetManager contains textures and fonts.
		GuiPlacesMenu(RiD::AssetManager& aAssetManager);

		///Updates GUI.
		///@param aSoundManager stores sound's buffers.
		///@param mainTaskManager main task manager.
		///@param aMainWindow game's main window.
		///@param guiMouseCoord mouse's coord from gui view.
		///@param aSoundManager stores sounds.
		void update(SoundManager& aSoundManager, TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f guiMouseCoord);
		
		///Draws GUI.
		///@param mainTaskManager main task manager.
		///@param aMainWindow game's main window.
		void render(TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow);

	};
}
