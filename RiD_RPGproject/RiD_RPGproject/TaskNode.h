#pragma once
#include <vector>
namespace MP
{
	
	class TaskNode
	{
	public:

		enum class taskType///Stores task's type.
		{
			W_PRESSED,
			A_PRESSED,
			S_PRESSED,
			D_PRESSED,
			E_PRESSED,
			ESC_PRESSED,
			MOUSE_SCROLL_UP,
			MOUSE_SCROLL_DOWN,
			LEFT_MOUSE_BUTTON,

			TASK_IDLE,

			//Move basic tasks
			TASK_MOVE,
			TASK_MOVE_UP,
			TASK_MOVE_DOWN,
			TASK_MOVE_RIGHT,
			TASK_MOVE_LEFT,

			//Auto move tasks
			TASK_AUTO_MOVE,
			TASK_BREAK_AUTO_MOVE,
			TASK_EXECUTE_AUTO_MOVE,
			TASK_CREATE_PATH,

			//Mouse tasks
			TASK_LEFT_DOUBLE_CLICK,
			TASK_WAIT_FOR_LEFT_DOUBLE_CLICK,
			LEFT_MOUSE_RELEASED,

			//Mission
			taskMission,
			taskMissionGoToDestination,
			taskMissionGetReward,
			taskMissionReturn

		};
	private:

		taskType _task;///Task type.

	public:

		///Creates new task.
		///@param newTask new game's task.
		TaskNode(taskType newTask);

		///Returns task.
		///@return task.
		TaskNode::taskType getTask();

	};
}