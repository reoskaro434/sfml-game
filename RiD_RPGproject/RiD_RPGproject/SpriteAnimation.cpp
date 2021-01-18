#include "SpriteAnimation.h"

void  MP::SpriteAnimation::_get_rectangle_array(int columns, int rows, int squareLength)
{
	int x = 0, y = 0;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sf::IntRect tmp(y, x, squareLength, squareLength);

			_object_rectangle_array.push_back(tmp);

			y += squareLength;
		}
		x += squareLength;
		y = 0;
	}
}

void MP::SpriteAnimation::setObjectSpritePosition(int x, int y)
{
	_obj_sprite.setPosition(float(x),float(y));
}

void MP::SpriteAnimation::setObjectSpritePosition(sf::Vector2f coord)
{
	_obj_sprite.setPosition(coord.x, coord.y);
}

sf::Sprite& MP::SpriteAnimation::getObjectSprite()
{
	return _obj_sprite;
}

MP::SpriteAnimation::SpriteAnimation()
{
	_obj_texture = nullptr;
	_current_sprite = 0;
}

void MP::SpriteAnimation::loadObjectTextures(sf::Texture *texturePtr, int columns, int rows, int squareLength)
{
	_obj_texture = texturePtr;
	_obj_sprite.setTexture(*texturePtr);
	_get_rectangle_array(columns, rows, squareLength);
	changeSprite(0);
}


void MP::SpriteAnimation::_set_object_texture_rect(sf::IntRect &textureRect)
{
	_obj_sprite.setTextureRect(textureRect);
}

void MP::SpriteAnimation::changeSprite(int spriteNumber)
{
	_set_object_texture_rect(_object_rectangle_array[spriteNumber]);
	_current_sprite = spriteNumber;
}

const std::vector<sf::IntRect>& MP::SpriteAnimation::getOryginalArray()
{
	return _object_rectangle_array;
}

int MP::SpriteAnimation::getCurrentSprite()
{
	return _current_sprite;
}

void MP::SpriteAnimation::setNextSprite(int from, int to)
{
	int currentSpriteNumber = getCurrentSprite();

	if (currentSpriteNumber < to and currentSpriteNumber >=from)
		currentSpriteNumber++;
	else if (currentSpriteNumber == to)
		currentSpriteNumber = from;
	else if (currentSpriteNumber <from or currentSpriteNumber>=to)
		currentSpriteNumber = from;

	changeSprite(currentSpriteNumber);
}

void MP::SpriteAnimation::setScale(float x, float y)
{
	_obj_sprite.setScale(x, y);
}

sf::Vector2f MP::SpriteAnimation::getScale()
{
	return _obj_sprite.getScale();
}

void MP::SpriteAnimation::setOrigin(int x, int y)
{
	_obj_sprite.setOrigin(float(x), float(y));
}

void MP::SpriteAnimation::setColor(sf::Color newColor)
{
	_obj_sprite.setColor(newColor);
}

