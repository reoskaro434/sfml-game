#pragma once
#include <SFML/Graphics.hpp>
#include "ActiveObject.h"
#include "Engine/AssetManager.h"

namespace MP
{
	class Places:public ActiveObject
	{
	private:

		ItemsManager _items_for_trade;///Manages items.

	protected:

		char _place_mark;///Stores place's mark.

	public:

		///Place's constructor.
		Places();

		///Returns place's items.
		///@return return items.
		ItemsManager & getItemsForTrade();

		///Updates place.
		void update();

		///Draws object on screen.
		///@param mainWindow game window.
		void render(sf::RenderWindow& mainWindow);

		///Returns place's mark.
		///@return place's mark.
		char getPlaceMark();

		///Sets new place's color.
		void markPlace();
		
		///Sets default color.
		void unmarkPlace();
	};
}
