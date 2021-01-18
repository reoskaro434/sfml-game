#include "Grass.h"

MP::Grass::Grass(sf::Texture* texturePtr, sf::Vector2f coord, float grassScale)
{
	aAnimation.loadObjectTextures(texturePtr, 1, 1, 18);
	setObjectCoord(coord);
	aAnimation.setOrigin(8, 8);
	aAnimation.setScale(grassScale, grassScale);
}

void MP::Grass::update(sf::Clock& globalClock)
{
}

void MP::Grass::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObjectSprite());
}
