#include "Iron.h"

MP::Iron::Iron()
{
}

MP::Iron::Iron(sf::Texture* texturePtr, sf::Font& aFont)
{
	aAnimation.loadObjectTextures(texturePtr, 1, 1, 64);
	_item_amount_text.setFont(aFont);
	setItemAmount(0);
	_item_amount_text.setLetterSpacing(1);
	_item_amount_text.setCharacterSize(25);
	_item_amount_text.setFillColor(sf::Color(224, 224, 224));
	_item_cost = 9;
}

void MP::Iron::setItemPosition(sf::Vector2f itemPosition)
{
	setObjectCoord(itemPosition);
	itemPosition.x += 68;
	itemPosition.y += 30;

	_item_amount_text.setPosition(itemPosition);
}

void MP::Iron::drawItem(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObjectSprite());
	mainWindow.draw(_item_amount_text);
}
