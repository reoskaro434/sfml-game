#pragma once
#include "Object.h"
#include "TaskManager.h"

namespace MP
{
	class Tree :public Object
	{
	private:

		///Changes object sprite relative to global clock.
		///@param globalClock measures game time.
		void _tree_animation(sf::Clock& globalClock);

	public:

		///Tree object constructor.
		///@param texturePtr object texture.
		///@param coord object coord.
		///@param treeScale changes size of tree.
		Tree(sf::Texture* texturePtr, sf::Vector2f coord, float treeScale);

		///Updates object.
		///@param mainTaskManager stores tasks.
		///@param globalClock measure game time.
		void update(TaskManager& mainTaskManager, sf::Clock& globalClock);

		///Draws object on screen.
		///@param mainTaskManager stores tasks.
		///@param mainWindow game window.
		void render(TaskManager& mainTaskManager, sf::RenderWindow &mainWindow);

	};
}