#pragma once
#include <set>
#include <iostream>
#include "TaskNode.h"

namespace MP
{
	class TaskManager
	{
	public:

		enum class stateType/// Contains game's states.
		{
			stateGame,
			stateMainMenu,
			statePlacesMenu,
			stateMarketPlace
		};

	private:

		stateType _game_state;///Current game state,

		std::set<std::shared_ptr<TaskNode>> _task_list;///Game's task list.

	public:

		///Sets task manager.
		TaskManager();

		///Sets new state.
		///@param aNewStateType new state.
		void setState(stateType aNewStateType);

		///Returns state type.
		///@return state type.
		stateType getCurrentState();

		///Findes task in task list.
		///@param aTaskType task to find.
		///@param erase if true method deletes task.
		///@return true if task was detected.
		bool findTask(TaskNode::taskType aTaskType, bool erase);

		///Adds new task.
		///@param newTask new task.
		void addTask(TaskNode::taskType newTask);
		
		///Deletes task list.
		void deleteTaskList();

		///Returns task's list.
		///@return task's list.
		std::set<std::shared_ptr<TaskNode>>& getTaskList();

		///Returns true if tasl list is empty.
		///@return true if tasl list is empty.
		bool isTaskListEmpty();

		///Updates state.
		void updateState();

		///Handles keyboard.
		void keyboardHandling();

		///Reset all tasks from keyboard and mouse.
		void resetInput();
	};
}