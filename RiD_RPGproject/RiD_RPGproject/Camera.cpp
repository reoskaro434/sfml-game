#include "Camera.h"
#include "ActiveObject.h"

void MP::Camera::_zoom_in()
{
	if (_game_view.getSize().x > _min_x_size)
	{
		_game_view = _window.getView();
		_game_view.zoom(float(0.8));
		_window.setView(_game_view);
	}

}

void MP::Camera::_zoom_out()
{
	if (_game_view.getSize().x < _max_x_size)
	{
		_game_view = _window.getView();
		_game_view.zoom(float(1.2));
		_window.setView(_game_view);
	}

}

MP::Camera::Camera()
{
	_min_x_size = RiD::ConfigurationLoader::getIntData("video settings", "minCameraView");
	_max_x_size = RiD::ConfigurationLoader::getIntData("video settings", "maxCameraView");
	_game_view.setSize(float(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth")*0.78125), float(RiD::ConfigurationLoader::getIntData("video settings", "screenHeight")));
	_gui_view.setSize(float(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth")), float(RiD::ConfigurationLoader::getIntData("video settings", "screenHeight")));

	_game_view.setViewport(sf::FloatRect(0, 0, 0.78125, 1)); //Computer will not drawing frames behind gui
	_gui_view.setViewport(sf::FloatRect(0, 0, 1, 1));
}

sf::RenderWindow & MP::Camera::getWindow()
{
	return _window;
}

void MP::Camera::clearCamera()
{
	_window.clear();
}

void MP::Camera::drawFrame()
{
	_window.display();
}

void MP::Camera::_change_zoom(MP::TaskManager& aTaskManager)
{
	changeViewToGame();

	if (aTaskManager.findTask(MP::TaskNode::taskType::MOUSE_SCROLL_DOWN,true))
		_zoom_out();
	if (aTaskManager.findTask(MP::TaskNode::taskType::MOUSE_SCROLL_UP, true))
		_zoom_in();
}

void MP::Camera::_change_camera(sf::Vector2f coord)
{
	//Correcting camera position
	coord.x += 30;
	coord.y += 30;
	
	_game_view.setCenter(coord);
	_window.setView(_game_view);

}

void MP::Camera::changeViewToGame()
{
	_window.setView(_game_view);
}

void MP::Camera::changeViewToGui()
{
	_window.setView(_gui_view);
}

void MP::Camera::update(sf::Vector2f newFocusCoord, TaskManager& mainTaskManager)
{
	if (mainTaskManager.findTask(MP::TaskNode::taskType::MOUSE_SCROLL_UP,false) or mainTaskManager.findTask(MP::TaskNode::taskType::MOUSE_SCROLL_DOWN, false))
		_change_zoom(mainTaskManager);

	_change_camera(newFocusCoord);
}
