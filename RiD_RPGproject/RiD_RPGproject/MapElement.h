#pragma once
#include "Land.h"
#include "Places.h"
#include "Engine/AssetManager.h"

namespace MP
{
	class MapElement
	{
	private:

		MapElement* _next_element;///Next element's address.

		std::shared_ptr<Land> _land_tile;///Stores land tile.

		std::shared_ptr<Places> _a_place;///Stores place if exist.

		char _mark;///Places mark.

		bool _walkable;///true if element is walkable.

		///Creates village.
		///@param aAssetManager stores textures.
		///@param coord place's coordinates.
		void _create_village(RiD::AssetManager& aAssetManager, sf::Vector2f coord);

		///Creates town.
		///@param aAssetManager stores textures.
		///@param coord place's coordinates.
		void _create_town(RiD::AssetManager& aAssetManager, sf::Vector2f coord);

		///Creates castle.
		///@param aAssetManager stores textures.
		///@param coord place's coordinates.
		void _create_castle(RiD::AssetManager& aAssetManager,  sf::Vector2f coord);

	public:

		///Map element constructor.
		///@param aAssetManager stores textures.
		///@param cordX x coordinates.
		///@param cordY y coordinates.
		///@param mark place's mark if exist.
		MapElement(RiD::AssetManager &aAssetManager,int cordX,int cordY,char mark);
		
		///Returns land tile.
		///@return land tile.
		Land & getLandTile();
		
		///Returns place otherwise nullptr.
		///@return place.
		std::shared_ptr<Places> getPlace();

		///Returns next element address.
		///@return next element address.
		MapElement *& getNextElement();

		///Returns places mark.
		///@return places mark.
		char getMark();

		///Sets next element's ptr.
		///@param aMapElement next element's ptr.
		void setNextPtr(MapElement* aMapElement);
		
		///Returns if element is walkable or no.
		///@return true if walkable.
		bool isWalkable();

		///Returns map element's address.
		///@return map element's address.
		MapElement* returnAddress();
	};
}