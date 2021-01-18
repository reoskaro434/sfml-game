#include "RiDmain.h"
#include "Engine/ConfigurationLoader.h"
#include <iostream>
#include "TaskManager.h"
#include <Windows.h>

void RiD::RiDmain::_create_window()
{	
	
	_a_object_generator.generateObiects(_a_object_manager);
	std::printf("generated successful \n");
	

	while (_a_camera.getWindow().isOpen()) //program main loop
	{
		_event_function();
		_calculate();
		_draw();
	}
}

void RiD::RiDmain::_event_function()
{

	while (_a_camera.getWindow().pollEvent(_event)) //handling events
	{
		if (_event.type == sf::Event::EventType::Closed)
			_a_camera.getWindow().close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			_a_main_task_manager.addTask(MP::TaskNode::taskType::ESC_PRESSED);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			_a_main_task_manager.addTask(MP::TaskNode::taskType::W_PRESSED);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			_a_main_task_manager.addTask(MP::TaskNode::taskType::A_PRESSED);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			_a_main_task_manager.addTask(MP::TaskNode::taskType::S_PRESSED);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			_a_main_task_manager.addTask(MP::TaskNode::taskType::D_PRESSED);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
			_a_main_task_manager.addTask(MP::TaskNode::taskType::E_PRESSED);


		if (_event.type == sf::Event::MouseWheelScrolled)
		{
			if (_event.mouseWheelScroll.delta > 0)
				_a_main_task_manager.addTask(MP::TaskNode::taskType::MOUSE_SCROLL_UP);
			else
				_a_main_task_manager.addTask(MP::TaskNode::taskType::MOUSE_SCROLL_DOWN);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and _a_main_task_manager.findTask(MP::TaskNode::taskType::LEFT_MOUSE_RELEASED, true))
			_a_main_task_manager.addTask(MP::TaskNode::taskType::LEFT_MOUSE_BUTTON);

		if (_event.type == sf::Event::MouseButtonReleased)
			if(!_a_main_task_manager.findTask(MP::TaskNode::taskType::LEFT_MOUSE_RELEASED,false))
			_a_main_task_manager.addTask(MP::TaskNode::taskType::LEFT_MOUSE_RELEASED);
	}
}

void RiD::RiDmain::_calculate()
{	
	_music.update(_a_main_task_manager);

	_a_calculator.updateGame(_a_sound_manager,_a_main_task_manager, _a_object_manager, _clock, _a_camera);

	_a_object_manager.getCursor()->update(_a_main_task_manager, _a_camera);

	_a_camera.update(_a_object_manager.getPlayer()->getObjectCoord(), _a_main_task_manager);

	//Deleting basic task from keyboard, mouse ect.
	_a_main_task_manager.resetInput();
}

void RiD::RiDmain::_draw()
{
	_a_camera.clearCamera();

	_a_object_drawer.drawGame(_a_main_task_manager,_a_camera,_a_object_manager);

	_a_camera.drawFrame(); 
}

RiD::RiDmain::RiDmain(int width, int height, std::string title)
{

	sf::VideoMode mode = sf::VideoMode::getFullscreenModes()[0];
	_a_camera.getWindow().create(mode, title, sf::Style::Close | sf::Style::Fullscreen);
	

	//_a_camera.getWindow().create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	//_a_camera.getWindow().setFramerateLimit(RiD::ConfigurationLoader::getIntData("video settings", "gameFPS"));


	_a_camera.getWindow().setMouseCursorVisible(false);
	this->_create_window();

}
