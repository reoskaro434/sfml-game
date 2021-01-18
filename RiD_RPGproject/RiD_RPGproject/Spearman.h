#pragma once
#include <SFML/Graphics.hpp>
#include "Item.h"


namespace MP
{
	class Spearman :public Item
	{
	private:

	public:

		///Item's constructor.
		Spearman();

		///Item's constructor.
		///@param texturePtr object's texture.
		///@param aFont text's font.
		Spearman(sf::Texture* texturePtr, sf::Font& aFont);

		///Sets item position.
		///@param itemPosition obiect's position.
		void setItemPosition(sf::Vector2f itemPosition);

		///Draws item.
		///@param mainWindow game's window.
		void drawItem(sf::RenderWindow& mainWindow);
	};
}