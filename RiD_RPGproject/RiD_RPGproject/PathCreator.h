#pragma once
#include "PathNode.h"
#include "Map.h"
#include "MapElement.h"

namespace MP
{
	class PathCreator// :public MP::Map
	{
	private:

		/************************************************* PRIVATE ATTRIBUTES *************************************************/

		MP::Map* _map_copy;///Stores original map ptr.

		sf::Vector2f _start;///Starting coordinates.

		sf::Vector2f _stop;///End coordinates.

		MP::MapElement* _path_map_element_for_export; ///Head list which goes to script player.Deleting in "scriptPlayer" class.

		PathNode* _path;///Path created from parent pointers.

		PathNode* _open_list;///Head list of non-visited place.

		PathNode* _closed_list;///Head list of visited place.

		/************************************************* PRIVATE METHODS *************************************************/

		///Adds element to pathMapElementForExport.
		///@param aNode Node which contains map element for export.
		PathCreator& operator^(PathNode*& aNode);
		
		/// Adds to open list.
		///@param aNode New node.
		PathCreator& operator+(PathNode*& aNode);

		///Deletes from open list and adds to close list.
		///@param aNode new node in close list
		PathCreator& operator-(PathNode* aNode);

		///Searches element in open and close list.
		///@param elementFromNode element from node
		///@return finded element address
		PathNode* _find_path_node(MP::MapElement* elementFromNode);

		///Search node from pathNode class, which contain "mapElement" address.
		///@param elementFromNode element from node
		///@return element which contain element from node
		PathNode* _find_in_closed_list(MP::MapElement* elementFromNode);

		///Search node from pathNode class, which contain "mapElement" address.
		///@param elementFromNode element from node
		///@return element which contain element from node
		PathNode* _find_in_open_list(MP::MapElement* elementFromNode);

		///Deletes node, which contain mapElement address.
		///@param elementFromNode element from node
		void _closed_list_delete_node(MP::MapElement* elementFromNode);

		///Unpluges from open list node, which contain mapElement address. It is used, when node is moving to closed list.
		///@param elementFromNode element from node
		void _disconnect_from_open_list(MP::MapElement* elementFromNode);

		///Sets parent for all elements.
		void _set_parent_for_elements();

		///Searches walkable element, using closed list.
		void _find_walkable_elements();

		///Finding elements by coord and gives it for overload operator.
		///@param aCoord element coordinates
		void _add(sf::Vector2f aCoord);

		///Findes through parents path from start to stop coordinates. If path is complite it makes stop A* algorythm.
		void _try_to_create_path();

		///Findes pathNode's element in close list using coord.
		///@param stop stop coordinates.
		///@return pathNode's element.
		PathNode* _find_in_closed_list_by_coords(sf::Vector2f stop);

		///Creates path for script player, using parent's pointer.
		void _create_path_for_export();

		///Visites all parent pointer from stop to start coordinates.
		///@param aPathNode Head element list
		void _go_through_parents_and_create_export_list(PathNode* aPathNode);

		///Creates mapElement list for script player.
		///@param additiveElement new export list's element/
		void _add_map_element_to_export_list(MP::MapElement*& additiveElement);

		///Deletes list, which head is in function argument.
		///@param listHead first list's element
		void _delete_list(PathNode* listHead);

	public:
	
		///Sets all pointers to nullptr.
		///@param aMap map used for copy
		PathCreator(Map& aMap);

		///Copies element's head, last coord and last line number, for pathCreator.
		///@param aMap map used for copy
		PathCreator& operator=(Map& aMap);

		///Findes path from start to stop. Returns mapElement list.
		///@param start starting coordinates
		///@param stop end of path
		///@return path from start to stop.
		MapElement*& findPath(sf::Vector2f start, sf::Vector2f stop);

	};
}