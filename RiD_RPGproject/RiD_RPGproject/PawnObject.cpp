#include "PawnObject.h"
#include "TaskManager.h"

MP::PawnObject::PawnObject()
{
	_current_land = nullptr;
	_whinney_once = false;
	_sound_player.setSpeed(float(1.15));
}

bool MP::PawnObject::checkGoUp(MP::Map& aMap)
{
	sf::Vector2f tmp = getObjectCoord();
	tmp.y -= _block_length;
	MapElement* tmp2= aMap.findElementAddressSquareRange(tmp);
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_current_land = tmp2;
		return true;
	}
	else
		return false;
}

bool MP::PawnObject::checkGoDown(MP::Map& aMap)
{
	sf::Vector2f tmp = getObjectCoord();
	tmp.y += _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp);
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_current_land = tmp2;
		return true;
	}
	else
		return false;
}

bool MP::PawnObject::checkGoLeft(MP::Map& aMap)
{
	sf::Vector2f tmp = getObjectCoord();
	tmp.x -= _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp);
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_current_land = tmp2;
		return true;
	}
	else
		return false;
}

bool MP::PawnObject::checkGoRight(MP::Map& aMap)
{
	sf::Vector2f tmp = getObjectCoord();
	tmp.x += _block_length;
	MapElement* tmp2 = aMap.findElementAddressSquareRange(tmp);
	if (tmp2 != nullptr and tmp2->isWalkable() == true)
	{
		_current_land = tmp2;
		return true;
	}
	else
		return false;
}
//
//void MP::PawnObject::tryToMoveUp(Map& aMap, TaskManager& aMainTaskManager)
//{
//	if (_check_go_up(aMap) and !aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false))
//	{
//		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_UP);
//		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
//	}
//}
//
//void MP::PawnObject::tryToMoveDown(Map& aMap, TaskManager& aMainTaskManager)
//{
//	if (_check_go_down(aMap)and !aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false))
//	{
//		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_DOWN);
//		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
//	}
//}
//
//void MP::PawnObject::tryToMoveLeft(Map& aMap, TaskManager& aMainTaskManager)
//{
//	if (_check_go_left(aMap)and !aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false))
//	{
//		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_LEFT);
//		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
//	}
//}
//
//void MP::PawnObject::tryToMoveRight(Map& aMap, TaskManager& aMainTaskManager)
//{
//	if (_check_go_right(aMap) and !aMainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false))
//	{
//		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_RIGHT);
//		aMainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
//	}
//}

MP::MapElement* MP::PawnObject::getCurrentLand()
{
	return _current_land;
}
