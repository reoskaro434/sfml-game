#pragma once

#include "SFML/Graphics.hpp"
#include "ObjectDrawer.h"
#include "Move.h"
#include "ObjectManager.h"
#include "ObjectGenerator.h"
#include "TaskManager.h"
#include "Calculator.h"
#include "Camera.h"
#include "Music.h"

namespace RiD
{
	class RiDmain
	{
	private:

		MP::ObjectDrawer _a_object_drawer;///Draws objects.

		MP::ObjectManager _a_object_manager;///Manages objects.

		MP::ObjectGenerator _a_object_generator;///Generates objects.

		MP::Calculator _a_calculator;///Executes game's objects updates functions.

		MP::TaskManager _a_main_task_manager;///Stores tasks from keyboard ect.

		MP::Camera _a_camera;///Manages game's ang gui view. 

		sf::Event _event;///Handles event.

		sf::Clock _clock;///Game's clock.

		MP::Music _music;///Plays musics.

		MP::SoundManager _a_sound_manager;///Stores sounds.

     	///Executes creation of window.
		void _create_window();
		
		///Manages events function.
		void _event_function();

		///Manages updates functions.
		void _calculate();
		
		///Manages draws funtion.
		void _draw();


	public:

		///Constructor that creates main window.
		///@param width width of the window.
		///@param height height of the window.
		///@param title title on the top bar.
		RiDmain(int width, int height, std::string title);
	};

}