#include "Item.h"

MP::Item::Item()
{
	_item_cost = 0;
	_item_amount = 0;
}

MP::Item::Item(sf::Texture* texturePtr,  sf::Font& aFont)
{
	_item_cost = 0;
	_item_amount = 0;
}

void MP::Item::setItemAmount(unsigned int newItemAmount)
{
	std::string tmp = std::to_string(newItemAmount);
	_item_amount = newItemAmount;
	_item_amount_text.setString(std::string("X") + tmp);
}

 int MP::Item::getItemAmount()
{
	return _item_amount;
}

void MP::Item::setItemPosition(sf::Vector2f itemPosition)
{
	setObjectCoord(itemPosition);
	itemPosition.x += 68;
	itemPosition.y += 30;

	_item_amount_text.setPosition(itemPosition);

}

void MP::Item::drawItem(sf::RenderWindow& mainWindow)
{
}

void MP::Item::setTextPostion(sf::Vector2f newPosition)
{
	newPosition.x += getObjectCoord().x;
	newPosition.y += getObjectCoord().y;
	_item_amount_text.setPosition(newPosition);
}

int MP::Item::getItemCost()
{
	return _item_cost;
}

void MP::Item::update()
{
}

void MP::Item::render()
{
}
