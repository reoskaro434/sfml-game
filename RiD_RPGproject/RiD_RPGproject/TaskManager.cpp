#include "TaskManager.h"

MP::TaskManager::TaskManager()
{
	_game_state = stateType::stateMainMenu;
}


void MP::TaskManager::setState(stateType aNewStateType)
{
	_game_state = aNewStateType;
}

MP::TaskManager::stateType MP::TaskManager::getCurrentState()
{
	return _game_state;
}


bool MP::TaskManager::findTask(TaskNode::taskType aTaskType, bool erase)
{
	if (!_task_list.empty())
	{
		std::set<std::shared_ptr<MP::TaskNode>>::iterator findTask;
		findTask = _task_list.begin();
		for (findTask; findTask != _task_list.end(); findTask++)
		{
			if ((*findTask)->getTask() == aTaskType)
			{
				if (erase)
					_task_list.erase(*findTask);

					return true;
			}
		}
	}
	return false;
}

void MP::TaskManager::addTask(TaskNode::taskType newTask)
{
	if (!findTask(newTask, false))
	{
		std::shared_ptr<TaskNode> tmp = std::make_shared<TaskNode>(newTask);
		_task_list.insert(tmp);
	}
}

void MP::TaskManager::deleteTaskList()
{
	_task_list.clear();
}

std::set<std::shared_ptr<MP::TaskNode>>& MP::TaskManager::getTaskList()
{
	return _task_list;
}

bool MP::TaskManager::isTaskListEmpty()
{
	return _task_list.empty();
}

void MP::TaskManager::updateState()
{
	switch (getCurrentState())
	{
	case(TaskManager::stateType::stateGame):
	{
		if (findTask(TaskNode::taskType::ESC_PRESSED, false))
			setState(TaskManager::stateType::stateMainMenu);
	}break;
	case(TaskManager::stateType::stateMainMenu):
	{
	
	}break;
	case(TaskManager::stateType::stateMarketPlace):
	{
		if (findTask(TaskNode::taskType::ESC_PRESSED, false))
			setState(TaskManager::stateType::statePlacesMenu);
	}break;
	case(TaskManager::stateType::statePlacesMenu):
	{
		
	}break;
	}
}


void MP::TaskManager::keyboardHandling()
{
	if (findTask(TaskNode::taskType::W_PRESSED, false))
		addTask(TaskNode::taskType::TASK_MOVE_UP);
	else if(findTask(TaskNode::taskType::A_PRESSED, false))
		addTask(TaskNode::taskType::TASK_MOVE_LEFT);
	else if(findTask(TaskNode::taskType::S_PRESSED, false))
		addTask(TaskNode::taskType::TASK_MOVE_DOWN);
	else if(findTask(TaskNode::taskType::D_PRESSED, false))
		addTask(TaskNode::taskType::TASK_MOVE_RIGHT);
}

void MP::TaskManager::resetInput()
{
	findTask(MP::TaskNode::taskType::LEFT_MOUSE_BUTTON, true);
	findTask(MP::TaskNode::taskType::MOUSE_SCROLL_DOWN, true);
	findTask(MP::TaskNode::taskType::MOUSE_SCROLL_UP, true);
	findTask(MP::TaskNode::taskType::W_PRESSED, true);
	findTask(MP::TaskNode::taskType::A_PRESSED, true);
	findTask(MP::TaskNode::taskType::S_PRESSED, true);
	findTask(MP::TaskNode::taskType::D_PRESSED, true);
	findTask(MP::TaskNode::taskType::ESC_PRESSED, true);
	findTask(MP::TaskNode::taskType::E_PRESSED, true);
}

