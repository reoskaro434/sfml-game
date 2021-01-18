#pragma once

#include "Object.h"

namespace MP
{
	class Land:public Object
	{
	private:

	public:

		///Object constructor.
		///@param texturePtr object texture.
		///@param x the x coordinates.
		///@param y the y coordinates.
		Land(sf::Texture* texturePtr, int x,int y);

		//Constructor used in A* algorythm.
		///@param x the x coordinates.
		//@param y the y coordinates.
		Land( int x,int y);

		///Renders land.
		void render(sf::RenderWindow &mainWindow);
	};
}
