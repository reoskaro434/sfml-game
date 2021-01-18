#include "Places.h"

MP::Places::Places()
{
}

MP::ItemsManager& MP::Places::getItemsForTrade()
{
	return _items_for_trade;
}

void MP::Places::update()
{
}

void MP::Places::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObjectSprite());
}

char MP::Places::getPlaceMark()
{
	return	_place_mark;
}

void MP::Places::markPlace()
{
	aAnimation.setColor(sf::Color(143,249,128));
}

void MP::Places::unmarkPlace()
{
	aAnimation.setColor(sf::Color(255, 255, 255));
}
