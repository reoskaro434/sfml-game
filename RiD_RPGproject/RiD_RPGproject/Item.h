#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

namespace MP

{
	class Item:public Object
	{
	protected:

		int _item_amount;///Item's amount.

		int _item_cost;/// Item's cost.

		sf::Text _item_amount_text;///Item's amount text.

	public:

		///Item's constructor.
		Item();

		///Item's constructor.
		///@param texturePtr object's texture.
		///@param aFont text's font.
		Item(sf::Texture* texturePtr, sf::Font& aFont);

		///Sets new item's amount.
		void setItemAmount(unsigned int newItemAmount);

		///Returns amount of item.
		///@return item's amount.
		int getItemAmount();

		///Sets item position.
		///@param itemPosition obiect's position.
		virtual void setItemPosition(sf::Vector2f itemPosition);

		///Draws item.
		///@param mainWindow game's window.
		virtual void drawItem(sf::RenderWindow& mainWindow);

		///Sets text position retlative to object coordination.
		///@param newPosioton new coordinates position.
		void setTextPostion(sf::Vector2f newPosition);

		///Returns item's cost.
		///@return item's cost.
		int getItemCost();

		///Updates object.
		void update();

		///Draws object.
		void render();

	};
}
