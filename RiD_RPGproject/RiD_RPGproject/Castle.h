#pragma once
#include "Places.h" 

namespace MP
{
	class Castle:public Places
	{
	public:

		///Castle's constructor.
		///@param aAssetManager contains textures.
		///@param coord object coord.
		Castle(RiD::AssetManager &aAssetManager, sf::Vector2f coord);
	};
}