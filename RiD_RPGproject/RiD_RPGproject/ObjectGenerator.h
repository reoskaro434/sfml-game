#pragma once

#include <random>
#include "SoundManager.h"
#include "ObjectDrawer.h"
#include "ObjectManager.h"
#include "Engine/AssetManager.h"

namespace MP
{
	class ObjectGenerator
	{
	private:

		RiD::AssetManager _a_asset_manager;///Stores textures.

		MP::SoundManager _a_sound_manager;///Stores sounds.

		std::mt19937 _random_number;///Generates random number.

		///Generates trees.
		///@param aObiectManager stores and manages game's obiects.
		void _generate_trees(ObjectManager& aObiectManager);
		
		///Generates grass.
		///@param aObiectManager stores and manages game's obiects.
		void _generate_grass(ObjectManager& aObiectManager);

		///Generates player.
		///@param aObiectManager stores and manages game's obiects.
		void _generate_player(ObjectManager& aObiectManager);

		///Generates map.
		///@param aObiectManager stores and manages game's obiects.
		void _generate_map(ObjectManager& aObiectManager);

		///Generates computer players.
		///@param aObiectManager stores and manages game's obiects.
		void _generate_computer_player(ObjectManager& aObiectManager);

		///Generates cursor.
		///@param aObiectManager stores and manages game's obiects.
		void _generate_cursor(ObjectManager& aObiectManager);

		///Generates gui.
		///@param aObiectManager stores and manages game's obiects.
		void _generate_gui(ObjectManager& aObiectManager);

		///Generates random items for places.
		///@param itemsFromPlaces stores place's items.
		///@param itemsForTrade stores items for trade.
		///@param multiplier multiply items.
		///@param trademultiplier multiply items for trade.
		///@param placesMark stores place's mark.
		void _generate_items_for_places(ItemsManager& itemsFromPlaces, ItemsManager& itemsForTrade, int multiplier, int tradeMultiplier,char placesMark);

	public:

		///Generates all objects.
		ObjectGenerator();

		///Starts generates procedures.
		///@param aObiectManager stores and manages game's obiects.
		void generateObiects(ObjectManager & aObiectManager);

	};
}