#pragma once
#include <vector>
#include "Engine/ConfigurationLoader.h"
#include <SFML/Graphics.hpp>

namespace MP
{
	class SpriteAnimation
	{
	private:

		sf::Texture *_obj_texture;///Stores object's texture.

		sf::Sprite _obj_sprite;///Stores object's sprite.

		sf::Color _obj_color;///Object's color.

		std::vector<sf::IntRect> _object_rectangle_array;///Stores object's rectangles.

		int _current_sprite;///Current sprite, relative to obj rectangle.

		///Sets object's texture rectangle.
		///@param textureRect texture's rextangle.
		void _set_object_texture_rect(sf::IntRect& textureRect);

		///Creates rectangle's array.
		///@param columns number of sprite in one column.
		///@param rows number of sprite in one row.
		///@param squareLength one sprite size.
		void _get_rectangle_array(int columns, int rows, int squareLength);

	public:

		///Sprite's animation constructor.
		SpriteAnimation();

		///Loads object textures, sets array of rectangles.
		///@param texturePtr loaded texture.
		///@param columns number of sprite in one column.
		///@param rows number of sprite in one row.
		///@param squareLength one sprite size.
		void loadObjectTextures(sf::Texture* texturePtr, int columns, int rows, int squareLength);

		///Changes object's current sprite.
		///@param spriteNumber number of sprite taken from rectangle array.
		void changeSprite(int spriteNumber);
	
		///Sets object position.
		///@param x x coordinate.
		///@param y y coordinate.
		void setObjectSpritePosition(int x, int y);

		///Sets object position.
		///@param coord contains coordinates x and y.
		void setObjectSpritePosition(sf::Vector2f coord);
		
		///Sets next sprite from sprites loop.
		///@param from sprites loop begin.
		///@param to sprites loop end.
		void setNextSprite(int from, int to);

		///Sets sprite scale.
		///@param x scale x.
		///@param y scale y.
		void setScale(float x, float y);

		///Sets sprite origin coordinates.
		///@param x x coordinate.
		///@param y y coordinate.
		void setOrigin(int x, int y);

		///Sets sprite new color.
		///@param newColor new sprite's color.
		void setColor(sf::Color newColor);
	
		///Returns object's sprite.
		///@return object's sprite.
		sf::Sprite& getObjectSprite();

		///Returns object's scale.
		///@return object's scale.
		sf::Vector2f getScale();

		///Returns current object's sprite.
		///@return current sprite.
		int getCurrentSprite();

		///Gets rectangle array.
		///@return rectangle's array.
		const std::vector<sf::IntRect>& getOryginalArray();
	

	
	};
}