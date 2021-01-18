#include "TaskNode.h"


MP::TaskNode::TaskNode(taskType newTask)
{
	_task = newTask;
}

MP::TaskNode::taskType MP::TaskNode::getTask()
{
	return _task;
}