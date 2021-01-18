#include "GuiMenu.h"

void MP::GuiMenu::_create_buttons(RiD::AssetManager& aAssetManager)
{

}

MP::GuiMenu::GuiMenu()
{
}

MP::GuiMenu::GuiMenu(RiD::AssetManager& aAssetManager)
{
}

void MP::GuiMenu::_draw_menu(sf::RenderWindow& aMainWindow)
{
	aMainWindow.draw(aAnimation.getObjectSprite());

	for (unsigned int i = 0; i < _button_array.size(); i++)
	{
		_button_array[i]->render(aMainWindow);
	}
}

void MP::GuiMenu::_select_button(SoundManager& aSoundManager, TaskManager& mainTaskManager, sf::Vector2f mouseCoord)
{
	for (unsigned int i = 0; i < _button_array.size(); i++)
	{
		if (mouseCoord.x >= _button_array[i]->getObjectCoord().x and mouseCoord.x <= _button_array[i]->getObjectCoord().x + 275
			and mouseCoord.y >= _button_array[i]->getObjectCoord().y + 112 and mouseCoord.y <= _button_array[i]->getObjectCoord().y + 163)
			_button_array[i]->update(aSoundManager, mainTaskManager, true);
		else
			_button_array[i]->update(aSoundManager,  mainTaskManager, false);
	}
}

void MP::GuiMenu::_press_button(TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow)
{

}

void MP::GuiMenu::update(SoundManager& aSoundManager, TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f mouseCoord)
{
}

void MP::GuiMenu::render(TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow)
{
}
