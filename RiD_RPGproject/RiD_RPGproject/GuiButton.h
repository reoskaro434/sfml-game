#pragma once
#include "Object.h"
#include "SoundManager.h"
#include "Sound.h"
#include "Engine/AssetManager.h"
#include "TaskManager.h"

namespace MP
{
	class GuiButton:public Object
	{
	private:

		sf::Text _a_text;///Stores button's text.

		bool _is_active;///Tells if button is active.

		bool _was_played;///Tells if sound was played.

		///Draws button.
		///@param mainWindow game's window.
		void draw_button(sf::RenderWindow& mainWindow);

		///Sets button state.
		///@param isActive new button's state.
		void set_button_active(bool isActive);

		MP::Sound _sound_player; //Plays songs.

		///Starts song procedure.
		///@param aSoundManager plays song.
		///@param mainTaskManager manages task.
		void _song_procedure(MP::SoundManager& aSoundManager,MP::TaskManager &mainTaskManager);

	public:

		///Button's constructor.
		///@param aAssetManager contains textures and fonts.
		///@param buttonPositon button's coordinates.
		///@param relativelyTextPosition button's text position, relatively to button.
		///@param buttonName button's name.
		GuiButton(RiD::AssetManager& aAssetManager,sf::Vector2f buttonPosition, sf::Vector2f relativelyTextPosition, std::string buttonName);

		///Returns button's text.
		///@return button's text.
		sf::Text& getText();

		///Return button's state.
		///@return button's state.
		bool getButtonIsActive();

		///Sets button's position.
		///@param newPosition new button's position.
		void setButtonPosition(sf::Vector2f newPostion);

		///Updates button.
		///@param aSoundManager plays sounds.
		///@param mainTaskManager manages tasks.
		///@param isActive button's state.
		void update(SoundManager& aSoundManager, TaskManager& mainTaskManager,bool isActive);

		///Draws button.
		///@param mainWindow game's main window.
		void render(sf::RenderWindow& mainWindow);
	};
}