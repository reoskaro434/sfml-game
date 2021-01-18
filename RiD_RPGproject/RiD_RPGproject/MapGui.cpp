#include "MapGui.h"

MP::MapGui::MapGui(RiD::AssetManager& aAssetManager)
{
	aAnimation.loadObjectTextures(&aAssetManager.getTexture("mapgui"), 1, 1, 1920);
	setObjectCoord(sf::Vector2f(0,0));
	aAnimation.setOrigin(460, 460);
	
	for (int i = 0; i < 12; i++)
	{
		_text_array[i].setFont(aAssetManager.getFont("font"));
		_text_array[i].setFillColor(sf::Color(224, 224, 224));
		_text_array[i].setPosition(sf::Vector2f(float(1070), float(650 + i * 30)));
	}
}

void MP::MapGui::_update_items(ItemsManager& aItemsManager)
{
	aItemsManager.getWood()->setItemPosition(sf::Vector2f(1100, 25));
	aItemsManager.getIron()->setItemPosition(sf::Vector2f(1300, 25));
	aItemsManager.getGold()->setItemPosition(sf::Vector2f(1100, 100));
	aItemsManager.getFood()->setItemPosition(sf::Vector2f(1300, 100));

	aItemsManager.getArcher()->setItemPosition(sf::Vector2f(1040, 310));
	aItemsManager.getArcher()->aAnimation.setScale(1, 1);

	aItemsManager.getSwordsman()->setItemPosition(sf::Vector2f(1155, 310));
	aItemsManager.getSwordsman()->aAnimation.setScale(1, 1);

	aItemsManager.getSpearman()->setItemPosition(sf::Vector2f(1250, 290));
	aItemsManager.getSpearman()->aAnimation.setScale(1, 1);
}

void MP::MapGui::render(TaskManager& mainTaskManager, sf::RenderWindow& mainWindow, ItemsManager& aItemsManager)
{
	if (mainTaskManager.getCurrentState() == TaskManager::stateType::stateGame)
	{
		mainWindow.draw(aAnimation.getObjectSprite());
		_draw_items(mainWindow, aItemsManager);

		for (int i = 0; i < 12; i++)
			mainWindow.draw(_text_array[i]);
	}

}

void MP::MapGui::update(TaskManager& mainTaskManager, ItemsManager& aItemsManager, std::string textArray[12])
{
	if (mainTaskManager.getCurrentState() == TaskManager::stateType::stateGame)
	{
		_update_items(aItemsManager);

		for (int i = 0; i < 12; i++)
			_text_array[i].setString(textArray[i]);
	}
}

void MP::MapGui::_draw_items(sf::RenderWindow& mainWindow, ItemsManager& aItemsManager)
{
	aItemsManager.getWood()->drawItem(mainWindow);
	aItemsManager.getIron()->drawItem(mainWindow);
	aItemsManager.getGold()->drawItem(mainWindow);
	aItemsManager.getFood()->drawItem(mainWindow); 
	aItemsManager.getArcher()->drawItem(mainWindow);
	aItemsManager.getSwordsman()->drawItem(mainWindow);
	aItemsManager.getSpearman()->drawItem(mainWindow);
}
