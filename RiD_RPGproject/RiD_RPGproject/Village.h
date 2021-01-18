#pragma once
#include <SFML/Graphics.hpp>
#include "Places.h" 

namespace MP
{
	class Village :public Places
	{
	public:

		///Village's constructor.
		///@param aAssetManager contains textures.
		///@param coord object coord.
		Village(RiD::AssetManager& aAssetManager, sf::Vector2f coord);
	};
}