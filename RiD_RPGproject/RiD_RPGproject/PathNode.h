#pragma once
#include "MapElement.h"

namespace MP
{
	class PathNode
	{
	private:

		MP::MapElement* _a_map_element;///Stores map element address.

		PathNode* _next_node;///Stores next element address.

		PathNode* _parent;///Stores parent address.

		float _cost_F;///costG + costH.

		float _cost_G;///Startpoint distance.

		float _cost_H;///Destination distance.

	public:

		///Sets ptrs to nullptr.
		PathNode();

		///Sets map's element.
		///@param anElement map element.
		///@return Path node which contains map element.
		PathNode& operator=(MP::MapElement*& anElement);

		////Returns F value.
		float getCostF();

		///Calculates F G H value for element using coordinates below.
		///@param start start coordinates.
		///@param stop stop coordinates
		void calculate(sf::Vector2f start, sf::Vector2f stop);

		///Calculates H value using coordinates in arguments.
		///@param meta stop coordinates.
		void calculateHValue(sf::Vector2f meta);

		///Calculates G value using coordinates in arguments.
		///@param start start coordinates.
		void calculateGValue(sf::Vector2f start);

		///Sets parents for each node in function arguments.
		///@param up up node.
		///@param down down node.
		///@param left left node.
		///@param right right node.
		void setParentForElement(PathNode* up, PathNode* down, PathNode* left, PathNode* right);

		///Returns map element's address.
		///@return map element's address.
		MP::MapElement*& getMapElementAddress();

		///Returns next node's address.
		///@return next address.
		PathNode*& getNextNode();

		///Returns next node's address coopy ptr.
		///@return next address.
		PathNode* getNextNodeCopy();

		///Sets parent for element using argument below.
		///@param aNode path node which parents are setted.
		void setParent(PathNode* aNode);

		///Returns parent's address.
		///@return parent's address
		PathNode*& getParent();

		///Sets next node.
		///aNextNode next node.
		void setNextNode(PathNode* aNextNode);

	};
}