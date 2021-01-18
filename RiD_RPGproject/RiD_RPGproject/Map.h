#pragma once

#include <random>
#include "MapElement.h"

namespace MP
{

	class Map
	{
	private:

		sf::Vector2i _last_element_coord;///Last element's coordinates loaded to map.

		std::mt19937 _random_value;///Generates random number.

		int _block_length;///Map element's block length/

		float _block_length_neg_one;///Calculated 1/_block_length.

		std::vector<std::vector<MapElement*>> _map_array;///Stores map elements.

		std::vector<std::shared_ptr<Places>> _places_list;///Stores places.

		///Delets map.
		void _delete_map();

	public:

		///Map's constructor.
		Map();

		///Map's destructor.
		~Map();

		///Findes element's address.
		///@param coordinates element's coordinates.
		///@return element addres.
		MapElement* findElementAddress(sf::Vector2f coordinates);

		///Findes element's address.
		///@param x x element's coordinates.
		///@param y y element's coordinates.
		///@return element addres.
		MapElement* findElementAddress(float x,float y);

		///Findes nearest element's address.
		///@param coordinates nearest coordinates.
		///@return element addres.
		MapElement* findElementAddressSquareRange(sf::Vector2f coordinates);

		///Used in path creator. Copies map array and block size.
		///@param mapElementArray stores map's elements.
		///@param blockSize block's size.
		void copyMapArrayAndBlockSize(std::vector<std::vector<MapElement*>> & mapElementArray,int blockSize);

		///Returns random walkable element.
		///@return map element address.
		MapElement* returnRandomWalkableElement();

		///Sets last element coord.
		///@param aVector last element coordinates.
		void  setLastElementCoord(sf::Vector2f aVector);

		///Resturns map element array.
		///@returns elements' array.
		std::vector<std::vector<MapElement*>>& getMapArray();
		
		///Returns block's size.
		int getBlockSize();

		///Returns random place based on mark.
		///@param mark place's mark.
		///@return random place.
		std::shared_ptr<Places> getRandomPlace(char mark);
		
		///Creates places' list.
		void createPlacesList();
	};
}