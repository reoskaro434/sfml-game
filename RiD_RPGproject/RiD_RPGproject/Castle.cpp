#include "Castle.h"

MP::Castle::Castle(RiD::AssetManager& aAssetManager, sf::Vector2f coord)
{
	aAnimation.loadObjectTextures(&aAssetManager.getTexture("castle"), 1, 1, 64);
	setObjectCoord(coord);
	_place_mark = RiD::ConfigurationLoader::getStringData("castle", "mark")[0];
}
