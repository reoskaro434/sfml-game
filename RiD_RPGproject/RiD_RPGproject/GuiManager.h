#pragma once
#include "MapGui.h"
#include "GuiMainMenu.h"
#include "GuiMarketPlace.h"
#include "GuiPlacesMenu.h"

namespace MP
{
	class GuiManager
	{
	private:

		std::unique_ptr<MapGui> _a_map_gui;///Stores gui from game.

		std::unique_ptr<GuiMainMenu> _a_gui_main_menu;///Stores menu's gui.

		std::unique_ptr<GuiPlacesMenu> _a_gui_places_menu;///Stores place menu's gui.

		std::unique_ptr<GuiMarketPlace> _a_gui_market_place;///Stores market place's gui.

	public:

		///Returns map gui.
		///@return map gui.
		std::unique_ptr<MapGui>& getMapGui();

		///Returns gui main menu.
		///@return gui main menu.
		std::unique_ptr<GuiMainMenu>& getGuiMainMenu();

		///Returns place menu.
		///@return place menu.
		std::unique_ptr<GuiPlacesMenu>& getGuiPlacesMenu();

		///Returns market place menu.
		///@return market place menu.
		std::unique_ptr<MP::GuiMarketPlace>& getGuiMarketPlace();

	};
}