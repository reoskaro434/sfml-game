#include "Move.h"



void MP::Move::moveBlockDown(PawnObject& object, sf::Clock& currentTime)
{
	if (object.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= object.getReadyTime())
	{
		_move_pixel_down(object);
		object.decreaseBlockLengthCopy();
		object.setLastActive(currentTime);
	}
	else if (object.getBlockLenghtCopy() <= 0)
	{
		object.resetBlockLenghtCopy();
		object.aPawnObjectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockUp(PawnObject& object, sf::Clock& currentTime)
{
	if (object.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= object.getReadyTime())
	{
		_move_pixel_up(object);
		object.decreaseBlockLengthCopy();
		object.setLastActive(currentTime);
	}
	else if (object.getBlockLenghtCopy() <= 0) // Arrived
	{
		object.resetBlockLenghtCopy();
		object.aPawnObjectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockRight(PawnObject& object, sf::Clock& currentTime)
{
	if (object.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() > object.getReadyTime())
	{
		_move_pixel_right(object);
		object.decreaseBlockLengthCopy();
		object.setLastActive(currentTime);
	}
	else if (object.getBlockLenghtCopy() <= 0) // Arrived
	{
		object.resetBlockLenghtCopy();
		object.aPawnObjectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockLeft(PawnObject& object, sf::Clock& currentTime)
{
	if (object.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= object.getReadyTime())
	{
		_move_pixel_left(object);
		object.decreaseBlockLengthCopy();
		object.setLastActive(currentTime);
	}
	else if (object.getBlockLenghtCopy() <= 0) // Arrived
	{
		object.resetBlockLenghtCopy();
		object.aPawnObjectTaskManager.deleteTaskList();
	}
}

void MP::Move::moveBlockDown(Player& player, sf::Clock& currentTime, TaskManager& mainTaskManager)
{
	if (player.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= player.getReadyTime())
	{
		_move_pixel_down(player);
		player.decreaseBlockLengthCopy();
		player.setLastActive(currentTime);
	}
	else if (player.getBlockLenghtCopy() <= 0)
	{
		player.resetBlockLenghtCopy();
		mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, true);
		mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE_DOWN, true);

	}
}

void MP::Move::moveBlockUp(Player& player, sf::Clock& currentTime, TaskManager& mainTaskManager)
{
	if (player.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= player.getReadyTime())
	{
		_move_pixel_up(player);
		player.decreaseBlockLengthCopy();
		player.setLastActive(currentTime);
	}
	else if (player.getBlockLenghtCopy() <= 0) // Arrived
	{
		player.resetBlockLenghtCopy();
		mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, true);
		mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE_UP, true);
	}
}

void MP::Move::moveBlockRight(Player& player, sf::Clock& currentTime, TaskManager& mainTaskManager)
{
	if (player.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() > player.getReadyTime())
	{
		_move_pixel_right(player);
		player.decreaseBlockLengthCopy();
		player.setLastActive(currentTime);
	}
	else if (player.getBlockLenghtCopy() <= 0) // Arrived
	{
		player.resetBlockLenghtCopy();
		mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, true);
		mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE_RIGHT, true);
	}
}

void MP::Move::moveBlockLeft(Player& player, sf::Clock& currentTime, TaskManager& mainTaskManager)
{
	if (player.getBlockLenghtCopy() > 0 && currentTime.getElapsedTime() >= player.getReadyTime())
	{
		_move_pixel_left(player);
		player.decreaseBlockLengthCopy();
		player.setLastActive(currentTime);
	}
	else if (player.getBlockLenghtCopy() <= 0) // Arrived
	{
		player.resetBlockLenghtCopy();
		mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, true);
		mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE_LEFT, true);
	}
}

void MP::Move::_move_pixel_down(ActiveObject& object)
{
	object.setObjectCoord(int(object.getObjectCoord().x), int(object.getObjectCoord().y + object.getVelocity()));
}

void MP::Move::_move_pixel_up(ActiveObject& object)
{
	object.setObjectCoord(int(object.getObjectCoord().x), int(object.getObjectCoord().y - object.getVelocity()));
}

void MP::Move::_move_pixel_right(ActiveObject& object)
{
	object.setObjectCoord(int(object.getObjectCoord().x + object.getVelocity()), int(object.getObjectCoord().y));
}

void MP::Move::_move_pixel_left(ActiveObject& object)
{
	object.setObjectCoord(int(object.getObjectCoord().x - object.getVelocity()), int(object.getObjectCoord().y));
}

void MP::Move::tryToMoveUp(PawnObject &pawn ,Map& gameMap, TaskManager& mainTaskManager)
{
	if (pawn.checkGoUp(gameMap) and !mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false) and !mainTaskManager.findTask(TaskNode::taskType::TASK_AUTO_MOVE, false))
	{
		mainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_UP);
		mainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
	}
}

void MP::Move::tryToMoveDown(PawnObject& pawn, Map& gameMap, TaskManager& mainTaskManager)
{
	if (pawn.checkGoDown(gameMap) and !mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false) and !mainTaskManager.findTask(TaskNode::taskType::TASK_AUTO_MOVE, false))
	{
		mainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_DOWN);
		mainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
	}
}

void MP::Move::tryToMoveLeft(PawnObject& pawn, Map& gameMap, TaskManager& mainTaskManager)
{
	if (pawn.checkGoLeft(gameMap) and !mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false) and !mainTaskManager.findTask(TaskNode::taskType::TASK_AUTO_MOVE, false))
	{
		mainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_LEFT);
		mainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
	}
}

void MP::Move::tryToMoveRight(PawnObject& pawn, Map& gameMap, TaskManager& mainTaskManager)
{
	if (pawn.checkGoRight(gameMap) and !mainTaskManager.findTask(TaskNode::taskType::TASK_MOVE, false) and !mainTaskManager.findTask(TaskNode::taskType::TASK_AUTO_MOVE, false))
	{
		mainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_RIGHT);
		mainTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE);
	}
}