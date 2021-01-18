#include "PathIcon.h"

MP::PathIcon::PathIcon(sf::Texture* texturePtr, sf::Vector2f spawnCoord)
{
	aAnimation.loadObjectTextures(texturePtr, 1, 1, 60);
	setObjectCoord(spawnCoord);
	aAnimation.setScale(float(0.6), float(0.6));
	aAnimation.setOrigin(-29,-29);
}

void MP::PathIcon::update()
{
}

void MP::PathIcon::render(sf::RenderWindow& mainWindow)
{
}
