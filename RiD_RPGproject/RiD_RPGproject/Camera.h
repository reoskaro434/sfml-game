#pragma once 
#include "TaskManager.h"
#include "GuiManager.h"

namespace MP
{
	class Camera
	{
	private:

		int _max_x_size;///Min resolution zoom.

		int _min_x_size;///Maksimum resolution.

		sf::RenderWindow _window;///Game's window/

		sf::View _game_view;///Game's view.

		sf::View _gui_view;///Gui's view.

		///Changes zoom.
		void _zoom_in();

		///Changes zoom.
		void _zoom_out();

		///Changes zoom realtive to task.
		///@param aTaskManager game's task manager.
		void _change_zoom(MP::TaskManager& aTaskManager);

		///Sets camera centre's point.
		///@param coord camera's centre point.
		void _change_camera(sf::Vector2f coord);

	public:	

		///Camera's constructor.
		Camera();

		///Returns game's window.
		///@return game's window.
		sf::RenderWindow & getWindow();

		///Clears game view.
		void clearCamera();

		///Draws frame.
		void drawFrame();
		
		///Changes view to game.
		void changeViewToGame();

		///Changes view to gui.
		void changeViewToGui();

		///Updates camera.
		///@param newFocusCoord new focus coordinates.
		///@param mainTaskManager games task manager.
		void update(sf::Vector2f newFocusCoord, TaskManager &mainTaskManager);

	};
}