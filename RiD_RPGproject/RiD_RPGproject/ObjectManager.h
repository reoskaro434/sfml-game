#pragma once

#include <random>
#include <list>
#include "Player.h"
#include "Land.h"
#include "Map.h"
#include "Tree.h"
#include "ComputerPlayerBandit.h"
#include "Cursor.h"
#include "GuiManager.h"
#include "Grass.h"

namespace MP
{
	class ObjectManager
	{
	private:

		int _mod_number;///Used to generate proper random number.

		std::mt19937 _random_number;///Generates random number.

		std::shared_ptr<Player> _player;///Stores player.

		std::list<ComputerPlayerBandit> _computer_player_list;///Stores computer player list's

		std::list<Tree> _tree_list;///Stores tree's list.

		std::vector<Grass> _grass_list;///Store's grass vector.
		
		std::shared_ptr<Cursor> _a_cursor;///Store's cursor.
	
		Map _a_map;///game's map.

		GuiManager _a_gui_manager;///Stores gui.

	public:
		
		///Object manager's constructor.
		ObjectManager();

		///Object manager's destructor.
		~ObjectManager();

		///Sets player.
		///@param newPlayer player.
		void addObiect(std::shared_ptr<Player> &newPlayer);
		
		///Sets computer players.
		///@param newComputerPlayer new computer players.
		void addObiect(ComputerPlayerBandit &newComputerPlayer);

		///Return player.
		///@return player.
		std::shared_ptr<Player> & getPlayer();
		
		///Returns oryginal map.
		///@return map.
		Map& getMap();

		//return tree list ptr.
		//@return tree list.
		std::list<Tree> * getTreeList();

		///Returns grass's vector.
		///@return grass's vector.
		std::vector<Grass>* getGrassVector();

		///If returns true, tree's animation is allowed.
		///@return tree's animation permission.
		bool access();

		///Returns computer plaer list.
		///@return computer player list.
		std::list<MP::ComputerPlayerBandit>* getComputerPlayerList();

		//Returns cursor.
		//@return cursor.
		std::shared_ptr<Cursor>& getCursor();

		///Sets cursor.
		///@param aCursor cursor.
		void setCursor(std::shared_ptr<Cursor> &aCursor);

		///Return gui manager.
		///@return gui manager.
		GuiManager& getGuiManager();
	};

}