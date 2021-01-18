#include "Town.h"

MP::Town::Town(RiD::AssetManager& aAssetManager, sf::Vector2f coord)
{
	aAnimation.loadObjectTextures(&aAssetManager.getTexture("town"), 1, 1, 64);
	setObjectCoord(coord);
	_place_mark = RiD::ConfigurationLoader::getStringData("town", "mark")[0];
}
