#include "Archer.h"

MP::Archer::Archer()
{
}

MP::Archer::Archer(sf::Texture* texturePtr, sf::Font& aFont)
{

	aAnimation.loadObjectTextures(texturePtr, 1, 1, 202);
	_item_amount_text.setFont(aFont);
	setItemAmount(0);
	_item_amount_text.setLetterSpacing(1);
	_item_amount_text.setCharacterSize(25);
	_item_amount_text.setFillColor(sf::Color(224,224,224));
	_item_cost = 25;
}

void MP::Archer::setItemPosition(sf::Vector2f itemPosition)
{
	setObjectCoord(itemPosition);
	itemPosition.x += 70;
	itemPosition.y += 197;

	_item_amount_text.setPosition(itemPosition);
}

void MP::Archer::drawItem(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObjectSprite());
	mainWindow.draw(_item_amount_text);
}
