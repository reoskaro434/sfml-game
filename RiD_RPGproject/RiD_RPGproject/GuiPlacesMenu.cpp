#include "GuiPlacesMenu.h"

void MP::GuiPlacesMenu::_create_buttons(RiD::AssetManager& aAssetManager)
{
	std::shared_ptr<GuiButton> tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(400, 50), sf::Vector2f(-45, 0), "go to market place");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(400, 200), sf::Vector2f(-32, 0), "attack the place");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(400, 350), sf::Vector2f(-45, 0), "check notice board");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(400, 500), sf::Vector2f(40, 0), "exit");
	_button_array.push_back(tmp);
}

MP::GuiPlacesMenu::GuiPlacesMenu()
{
}

MP::GuiPlacesMenu::GuiPlacesMenu(RiD::AssetManager& aAssetManager)
{
	aAnimation.loadObjectTextures(&aAssetManager.getTexture("placesmenu"), 1, 1, 1920);
	aAnimation.setObjectSpritePosition(0, 0);
	aAnimation.setOrigin(460, 460);

	_create_buttons(aAssetManager);
}

void MP::GuiPlacesMenu::_select_button(SoundManager& aSoundManager, TaskManager& mainTaskManager, sf::Vector2f mouseCoord)
{
	for (unsigned int i = 0; i < _button_array.size(); i++)
	{
		if (mouseCoord.x >= _button_array[i]->getObjectCoord().x and mouseCoord.x <= _button_array[i]->getObjectCoord().x + 275
			and mouseCoord.y >= _button_array[i]->getObjectCoord().y + 112 and mouseCoord.y <= _button_array[i]->getObjectCoord().y + 163)
			_button_array[i]->update( aSoundManager,mainTaskManager, true);
		else
			_button_array[i]->update( aSoundManager,  mainTaskManager, false);
	}
}

void MP::GuiPlacesMenu::_press_button(TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow)
{
	if (_button_array[0]->getButtonIsActive() == true and mainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		mainTaskManager.setState(TaskManager::stateType::stateMarketPlace);
	}
	if (_button_array[1]->getButtonIsActive() == true and mainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
	}
	if (_button_array[2]->getButtonIsActive() == true and mainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		mainTaskManager.addTask(TaskNode::taskType::taskMission);
		mainTaskManager.setState(TaskManager::stateType::stateGame);
	}
	if (_button_array[3]->getButtonIsActive() == true and mainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		mainTaskManager.setState(TaskManager::stateType::stateGame);
	}
}

void MP::GuiPlacesMenu::update(SoundManager& aSoundManager,TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow, sf::Vector2f GuiMouseCoord)
{
	if (mainTaskManager.getCurrentState() == TaskManager::stateType::statePlacesMenu)
	{
		_select_button(aSoundManager, mainTaskManager, GuiMouseCoord);
		_press_button(mainTaskManager,aMainWindow);
	}
}

void MP::GuiPlacesMenu::render(TaskManager& mainTaskManager, sf::RenderWindow& aMainWindow)
{
	if (mainTaskManager.getCurrentState() == TaskManager::stateType::statePlacesMenu)
		_draw_menu(aMainWindow);
}
