#include "Cursor.h"
#include <iostream>
void MP::Cursor::setGameCoord(sf::Vector2f gameCoord)
{
	_game_coord = gameCoord;
}

sf::Vector2f MP::Cursor::getGameCoord()
{
	return _game_coord;
}

void MP::Cursor::setGuiCoord(sf::Vector2f guiCoord)
{
	_gui_coord = guiCoord;
}

sf::Vector2f MP::Cursor::getGuiCoord()
{
	return _gui_coord;
}

MP::Cursor::Cursor(sf::Texture* texturePtr)
{
	aAnimation.loadObjectTextures(texturePtr, 1, 1, 60);
	aAnimation.setOrigin(18, 15);
}

void MP::Cursor::_update_cursor(TaskManager& mainTaskManager, Camera& gameCamera)
{
	//saving gui cursor coord for drawing 
	gameCamera.changeViewToGui();
	sf::Vector2f guiMouseCoord = gameCamera.getWindow().mapPixelToCoords(sf::Mouse::getPosition(gameCamera.getWindow()));
	setObjectCoord(guiMouseCoord);

	//Maping to pixel from gui view
	sf::Vector2i screenMouseCoord = sf::Mouse::getPosition(gameCamera.getWindow());

	//Mapin from pixel to game view
	gameCamera.changeViewToGame();
	sf::Vector2f gameMouseCoord = gameCamera.getWindow().mapPixelToCoords(screenMouseCoord);

	setGameCoord(gameMouseCoord);
	setGuiCoord(guiMouseCoord);

}

void MP::Cursor::_check_if_player_clicked(TaskManager& mainTaskManager, Camera& gameCamera)
{
	if (mainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON,false)) //instructions below managing cursor behaviour
	{
		if (mainTaskManager.getCurrentState() == TaskManager::stateType::stateGame)
		{
			if (_gui_coord.x < 1040 and _gui_coord.x>-460) //map
			{
				if (mainTaskManager.findTask(TaskNode::taskType::TASK_EXECUTE_AUTO_MOVE, false))//for break auto move
					mainTaskManager.addTask(TaskNode::taskType::TASK_BREAK_AUTO_MOVE);
				else if (mainTaskManager.findTask(TaskNode::taskType::TASK_WAIT_FOR_LEFT_DOUBLE_CLICK, true))//for start auto move after path marking
					mainTaskManager.addTask(TaskNode::taskType::TASK_LEFT_DOUBLE_CLICK);
				else
				{
					mainTaskManager.addTask(TaskNode::taskType::TASK_CREATE_PATH);//for start auto move procedure
					mainTaskManager.addTask(TaskNode::taskType::TASK_AUTO_MOVE);
				}
			}
			else //gui
			{
				mainTaskManager.addTask(TaskNode::taskType::TASK_BREAK_AUTO_MOVE);
			}
		}
	}
}

void MP::Cursor::update(TaskManager& mainTaskManager, Camera& gameCamera)
{
	_update_cursor(mainTaskManager, gameCamera);
	_check_if_player_clicked(mainTaskManager, gameCamera);
}

void MP::Cursor::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObjectSprite());
}
