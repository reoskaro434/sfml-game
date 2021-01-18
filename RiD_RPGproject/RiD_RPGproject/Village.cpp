#include "Village.h"


MP::Village::Village(RiD::AssetManager& aAssetManager, sf::Vector2f coord)
{
	aAnimation.loadObjectTextures(&aAssetManager.getTexture("village"), 1, 1, 64);
	setObjectCoord(coord);
	_place_mark = RiD::ConfigurationLoader::getStringData("village", "mark")[0];
}
