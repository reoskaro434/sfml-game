#pragma once
#include "Object.h" 

namespace MP
{
	class PathIcon :public Object
	{
	public:
		
		///Object constructor.
		///@param texturePtr object texture.
		///@param spawnCoord object coord.
		PathIcon(sf::Texture* texturePtr,sf::Vector2f spawnCoord);

		///Updates path's icon.
		void update();

		///Draws object on screen.
		///@param mainWindow 
		void render(sf::RenderWindow& mainWindow);
	};
}