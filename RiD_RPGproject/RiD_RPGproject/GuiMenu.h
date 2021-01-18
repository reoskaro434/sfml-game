#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Object.h"
#include "GuiButton.h"
#include "TaskManager.h"


namespace MP
{
	class GuiMenu:public Object
	{
	protected:

		

		std::vector< std::shared_ptr<GuiButton>> _button_array;///Stores buttons.

		///Creates buttons.
		///@param aAssetManager contains textures and fonts.
	 	virtual	void _create_buttons(RiD::AssetManager& aAssetManager);

		///Checks mouse coordinates and makes button active.
		///@param aSoundManager stores sound's buffers.
		///@param mainTaskManager main task manager.
		///@param guiMouseCoord mouse's coordinates.
		virtual void _select_button(SoundManager& aSoundManager, TaskManager& mainTaskManager, sf::Vector2f guiMouseCoord);

		///Starts procedures relative to pressed button.
		///@param mainTaskManager main task manager.
		///@param aMainWindow game's main window.
		virtual void _press_button(TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow);

		///Draws menu.
		///@param aMainWindow game's window.
		void _draw_menu(sf::RenderWindow& aMainWindow);

	public:

		///GUI's constructor.
		GuiMenu();

		///GUI's constructor.
		///@param aAssetManager stores textures.
		GuiMenu(RiD::AssetManager& aAssetManager);

		///Updates GUI.
		///@param aSoundManager stores sound's buffers.
		///@param mainTaskManager main task manager.
		///@param aMainWindow game's main window.
		///@param guiMouseCoord mouse's coord from gui view.
		virtual void update(SoundManager& aSoundManager, TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f guiMouseCoord);

		///Draws GUI.
		///@param mainTaskManager main task manager.
		///@param aMainWindow game's main window.
		virtual void render(TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow);
	};
}
