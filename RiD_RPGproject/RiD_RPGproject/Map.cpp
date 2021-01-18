#include "Map.h"
#include <fstream>


void MP::Map::_delete_map()
{
	std::vector<std::vector<MapElement*>>::iterator it;
	std::vector<MapElement*>::iterator it2;

	unsigned int counter = 0;

	for (it = _map_array.begin(); it != _map_array.end(); it++)
	{
		for (it2 = _map_array[counter].begin(); it2 != _map_array[counter].end(); it2++)
			delete* it2;
		counter++;
	}
}

void MP::Map::createPlacesList()
{
	std::vector<std::vector<MapElement*>>::iterator it;
	std::vector<MapElement*>::iterator it2;

	unsigned int counter = 0;

	for (it = _map_array.begin(); it != _map_array.end(); it++)
	{
		for (it2 = _map_array[counter].begin(); it2 != _map_array[counter].end(); it2++)
			if ((*it2)->getPlace() != nullptr)
				_places_list.push_back((*it2)->getPlace());
		counter++;
	}
}


MP::Map::Map()
{
	_random_value.seed(unsigned int(time(0)));
	_block_length = RiD::ConfigurationLoader::getIntData("game settings", "blockLength");
	_block_length_neg_one = float(pow(_block_length, -1));
}

MP::Map::~Map()
{
	_delete_map();
}


MP::MapElement * MP::Map::findElementAddress(sf::Vector2f coordinates)
{
	return _map_array[unsigned int(coordinates.y * _block_length_neg_one)][unsigned int(coordinates.x * _block_length_neg_one)];
}

MP::MapElement* MP::Map::findElementAddress(float x, float y)
{
	return _map_array[unsigned int(y * _block_length_neg_one)][unsigned int(x * _block_length_neg_one)];
}

MP::MapElement* MP::Map::findElementAddressSquareRange(sf::Vector2f coordinates)
{
	return _map_array[unsigned int(coordinates.y * _block_length_neg_one)][unsigned int(coordinates.x * _block_length_neg_one)];
}

void MP::Map::copyMapArrayAndBlockSize(std::vector<std::vector<MapElement*>> &mapElementArray, int blockSize)
{
	_map_array = mapElementArray;
	_block_length = blockSize;
	_block_length_neg_one = float(pow(_block_length, -1));
}

MP::MapElement* MP::Map::returnRandomWalkableElement()
{

	MapElement* tmp=nullptr;
	sf::Vector2f randVector;
	randVector.x = float(_random_value() % _last_element_coord.x);
	randVector.y = float(_random_value() % _last_element_coord.y);

	tmp = findElementAddressSquareRange(randVector);

	while (tmp->isWalkable() ==false)
	{
		randVector.x = float(_random_value() % _last_element_coord.x);
		randVector.y = float(_random_value() % _last_element_coord.y);
	tmp=findElementAddressSquareRange(randVector);
	if (tmp == nullptr)
		tmp = nullptr;
	}
	return tmp;
}

void MP::Map::setLastElementCoord(sf::Vector2f aVector)
{
	_last_element_coord.x = int(aVector.x);
	_last_element_coord.y = int(aVector.y);
}

std::vector<std::vector<MP::MapElement*>>& MP::Map::getMapArray()
{
	return	_map_array;
}

int MP::Map::getBlockSize()
{
	return _block_length;
}

std::shared_ptr<MP::Places> MP::Map::getRandomPlace(char mark)
{
	while (true)
	{	
		int counter = _random_value() % (_places_list.size());

		if(_places_list[counter]->getPlaceMark()==mark)
		return _places_list[counter];
	}
}
