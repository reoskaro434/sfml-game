#include "Land.h"

MP::Land::Land(sf::Texture* texturePtr, int x, int y)
{
	aAnimation.loadObjectTextures(texturePtr, 1, 1, 64);

	setObjectCoord(x, y);
}

MP::Land::Land(int x, int y)
{
	setObjectCoord(x, y);
}

void MP::Land::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObjectSprite());
}
 