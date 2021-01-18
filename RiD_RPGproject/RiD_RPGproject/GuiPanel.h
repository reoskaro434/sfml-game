#pragma once
#include "Object.h"
namespace MP
{
	class GuiPanel :public Object
	{
	private:

		sf::Text _panel_title;///Stores text.

	public:

		///Panel's constructor.
		///@param texturePtr object's texture.
		///@param aFont text's font.
		GuiPanel(sf::Texture* texturePtr, sf::Font& aFont);

		///Updates panel.
		///@param panelPosition panel's coordinates.
		///@param panelName panel's name.
		void update(sf::Vector2f panelPosition, std::string panelName);

		///Draws panel.
		///@param mainWindow game's window.
		void render(sf::RenderWindow &mainWindow);

	};
}
