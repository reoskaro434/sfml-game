#include <SFML/Graphics.hpp>
#include "ObjectManager.h"

bool MP::ObjectManager::access()
{
	if (1 == _random_number() % _mod_number)
		return true;
	else
		return false;
}

std::list<MP::ComputerPlayerBandit>* MP::ObjectManager::getComputerPlayerList()
{
	return &_computer_player_list;
}

std::shared_ptr<MP::Cursor>& MP::ObjectManager::getCursor()
{
	return _a_cursor;
}

void MP::ObjectManager::setCursor(std::shared_ptr<Cursor> &aCursor)
{
	_a_cursor = aCursor;
}

MP::GuiManager& MP::ObjectManager::getGuiManager()
{
	return _a_gui_manager;
}

MP::ObjectManager::ObjectManager()
{ 
	_mod_number = RiD::ConfigurationLoader::getIntData("game settings", "randModulo");
	_player = nullptr;
}

MP::ObjectManager::~ObjectManager()
{
	_tree_list.clear();

	_computer_player_list.clear();
}

void MP::ObjectManager::addObiect(std::shared_ptr<Player> &newPlayer)
{
	_player = newPlayer;
}   

void MP::ObjectManager::addObiect(ComputerPlayerBandit& newComputerPlayer)
{
	_computer_player_list.push_back(newComputerPlayer);
}

std::shared_ptr<MP::Player> & MP::ObjectManager::getPlayer()
{
	return _player;
}

MP::Map& MP::ObjectManager::getMap()
{
	return _a_map;
}

std::list<MP::Tree> * MP::ObjectManager::getTreeList()
{
	return &_tree_list;
}

std::vector<MP::Grass>* MP::ObjectManager::getGrassVector()
{
	return &_grass_list;
}
