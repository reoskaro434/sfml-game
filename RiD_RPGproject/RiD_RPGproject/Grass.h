#pragma once
#include "Object.h"

namespace MP
{
	class Grass :public Object
	{
	public:

		///Grass object constructor.
		///@param texturePtr object texture.
		///@param coord object coord.
		///@param treeScale changes size of tree.
		Grass(sf::Texture* texturePtr, sf::Vector2f coord, float grassScale);

		///Updates object.
		///@param globalClock measure game time.
		void update(sf::Clock& globalClock);

		///Draws object on screen.
		///@param mainWindow game window.
		void render(sf::RenderWindow& mainWindow);

	};
}