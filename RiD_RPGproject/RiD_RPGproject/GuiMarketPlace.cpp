#include "GuiMarketPlace.h"
#include "Gold.h"
#include "Iron.h"
#include "Food.h"
#include "Archer.h"
#include "Wood.h"
#include "Swordsman.h"
#include "Spearman.h"

void MP::GuiMarketPlace::_create_buttons(RiD::AssetManager& aAssetManager)
{
	std::shared_ptr<GuiButton> tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(365, 25), sf::Vector2f(42, 0), "buy");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(365, 175), sf::Vector2f(40, 0), "sell");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(365, 325), sf::Vector2f(40, 0), "food");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(365, 9000), sf::Vector2f(40, 0), "wood");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(365, 9000), sf::Vector2f(40, 0), "iron");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(365, 9000), sf::Vector2f(20, 0), "spearman");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(365, 9000), sf::Vector2f(20, 0), "swordsman");
	_button_array.push_back(tmp);

	tmp = std::make_shared<GuiButton>(aAssetManager, sf::Vector2f(365, 9000), sf::Vector2f(30, 0), "archer");
	_button_array.push_back(tmp);
}

void MP::GuiMarketPlace::_create_panels(sf::Texture* panelLeftTexture, sf::Texture* panelRightTexture)
{

	_panelA->aAnimation.loadObjectTextures(panelLeftTexture, 1, 1,785);
	_panelB->aAnimation.loadObjectTextures(panelRightTexture, 1, 1,785);
}

void MP::GuiMarketPlace::_buy_item(ItemsManager& seller, ItemsManager& buyer)
{
	Item* itemType = nullptr;

	itemType = dynamic_cast<Food*>(_current_item.get());
	if (itemType != nullptr)
	{
	
			if(seller.subtractItem(seller.getFood(), 1, buyer.getGold()->getItemAmount()))
			buyer.addItem(buyer.getFood(), 1);
		
		itemType = nullptr;
	}

	itemType = dynamic_cast<Wood*>(_current_item.get());
	if (itemType != nullptr)
	{
		
			if(seller.subtractItem(seller.getWood(), 1, buyer.getGold()->getItemAmount()))
			buyer.addItem(buyer.getWood(), 1);
		
		itemType = nullptr;
	}

	itemType = dynamic_cast<Iron*>(_current_item.get());
	if (itemType != nullptr)
	{
	
			if(seller.subtractItem(seller.getIron(), 1, buyer.getGold()->getItemAmount()))
			buyer.addItem(buyer.getIron(), 1);
		
		itemType = nullptr;
	}

	itemType = dynamic_cast<Spearman*>(_current_item.get());
	if (itemType != nullptr)
	{
	
			if(seller.subtractItem(seller.getSpearman(), 1, buyer.getGold()->getItemAmount()))
			buyer.addItem(buyer.getSpearman(), 1);
		
		itemType = nullptr;
	}

	itemType = dynamic_cast<Archer*>(_current_item.get());
	if (itemType != nullptr)
	{
	
			if(seller.subtractItem(seller.getArcher(), 1, buyer.getGold()->getItemAmount()))
			buyer.addItem(buyer.getArcher(), 1);
		
		itemType = nullptr;
	}

	itemType = dynamic_cast<Swordsman*>(_current_item.get());
	if (itemType != nullptr)
	{

			if(seller.subtractItem(seller.getSwordsman(), 1,buyer.getGold()->getItemAmount()))
			buyer.addItem(buyer.getSwordsman(), 1);
		
		itemType = nullptr;
	}
}





MP::GuiMarketPlace::GuiMarketPlace()
{
}

MP::GuiMarketPlace::GuiMarketPlace(RiD::AssetManager& aAssetManager)
{
	aAnimation.loadObjectTextures(&aAssetManager.getTexture("marketplace"), 1, 1, 1920);
	aAnimation.setObjectSpritePosition(0, 0);
	aAnimation.setOrigin(460, 460);

	_create_buttons(aAssetManager);

	_panelA = std::make_unique<GuiPanel>(&aAssetManager.getTexture("panelleft"),aAssetManager.getFont("font"));
	_panelB = std::make_unique<GuiPanel>(&aAssetManager.getTexture("panelright"), aAssetManager.getFont("font"));

	_current_item = std::make_unique<Food>();
}

void MP::GuiMarketPlace::_update_market_place(Places& place, ActiveObject& player)
{
	_panelA->update(sf::Vector2f(-400, 60), "      Trader");
	_panelB->update(sf::Vector2f(620, 60), "       Player");


	place.getItemsForTrade().getWood()->setItemPosition(sf::Vector2f(-80,192));
	place.getItemsForTrade().getIron()->setItemPosition(sf::Vector2f(-80,256));
	place.getItemsForTrade().getGold()->setItemPosition(sf::Vector2f(-80,320));
	place.getItemsForTrade().getFood()->setItemPosition(sf::Vector2f(-80, 384));

	place.getItemsForTrade().getArcher()->setItemPosition(sf::Vector2f(-88, 460));
	place.getItemsForTrade().getArcher()->aAnimation.setScale(0.5, 0.5);
	place.getItemsForTrade().getArcher()->setTextPostion(sf::Vector2f(70,64));


	place.getItemsForTrade().getSwordsman()->setItemPosition(sf::Vector2f(-88, 560));
	place.getItemsForTrade().getSwordsman()->aAnimation.setScale(0.5, 0.5);
	place.getItemsForTrade().getSwordsman()->setTextPostion(sf::Vector2f(72, 64));

	place.getItemsForTrade().getSpearman()->setItemPosition(sf::Vector2f(-100, 660));
	place.getItemsForTrade().getSpearman()->aAnimation.setScale(0.5, 0.5);
	place.getItemsForTrade().getSpearman()->setTextPostion(sf::Vector2f(84, 78));



	player.aItemsManager.getWood()->setItemPosition(sf::Vector2f(935, 192));
	player.aItemsManager.getIron()->setItemPosition(sf::Vector2f(935, 256));
	player.aItemsManager.getGold()->setItemPosition(sf::Vector2f(935, 320));
	player.aItemsManager.getFood()->setItemPosition(sf::Vector2f(935, 384));

	player.aItemsManager.getArcher()->setItemPosition(sf::Vector2f(927, 460));
	player.aItemsManager.getArcher()->aAnimation.setScale(0.5, 0.5);
	player.aItemsManager.getArcher()->setTextPostion(sf::Vector2f(70, 64));

	player.aItemsManager.getSwordsman()->setItemPosition(sf::Vector2f(927, 560));
	player.aItemsManager.getSwordsman()->aAnimation.setScale(0.5, 0.5);
	player.aItemsManager.getSwordsman()->setTextPostion(sf::Vector2f(72, 64));

	player.aItemsManager.getSpearman()->setItemPosition(sf::Vector2f(915, 660));
	player.aItemsManager.getSpearman()->aAnimation.setScale(0.5, 0.5);
	player.aItemsManager.getSpearman()->setTextPostion(sf::Vector2f(84, 78));

}

void MP::GuiMarketPlace::setCurrentPlace(std::shared_ptr<Places>& currentPlace)
{
	_current_place = currentPlace;
}

void MP::GuiMarketPlace::_draw_menu(sf::RenderWindow& mainWindow, Places& place, ActiveObject& player)
{
	mainWindow.draw(aAnimation.getObjectSprite());

	for (unsigned int i = 0; i < _button_array.size(); i++)
		_button_array[i]->render(mainWindow);

	_panelA->render(mainWindow);
	_panelB->render(mainWindow);

	place.getItemsForTrade().getWood()->drawItem(mainWindow);
	place.getItemsForTrade().getIron()->drawItem(mainWindow);
	place.getItemsForTrade().getGold()->drawItem(mainWindow);
	place.getItemsForTrade().getFood()->drawItem(mainWindow);
	place.getItemsForTrade().getArcher()->drawItem(mainWindow);
	place.getItemsForTrade().getSwordsman()->drawItem(mainWindow);
	place.getItemsForTrade().getSpearman()->drawItem(mainWindow);

	player.aItemsManager.getWood()->drawItem(mainWindow);
	player.aItemsManager.getIron()->drawItem(mainWindow);
	player.aItemsManager.getGold()->drawItem(mainWindow);
	player.aItemsManager.getFood()->drawItem(mainWindow);
	player.aItemsManager.getArcher()->drawItem(mainWindow);
	player.aItemsManager.getSwordsman()->drawItem(mainWindow);
	player.aItemsManager.getSpearman()->drawItem(mainWindow);
}

void MP::GuiMarketPlace::_select_button(SoundManager& aSoundManager, TaskManager& aTaskManager, sf::Vector2f mouseCoord)
{
	for (unsigned int i = 0; i < _button_array.size(); i++)
	{
		if (mouseCoord.x >= _button_array[i]->getObjectCoord().x and mouseCoord.x <= _button_array[i]->getObjectCoord().x + 275
			and mouseCoord.y >= _button_array[i]->getObjectCoord().y + 112 and mouseCoord.y <= _button_array[i]->getObjectCoord().y + 163)
			_button_array[i]->update(aSoundManager, aTaskManager, true);
		else
			_button_array[i]->update(aSoundManager, aTaskManager, false);
	}
}

void MP::GuiMarketPlace::_press_button(TaskManager& aMainTaskManager, sf::RenderWindow& mainWindow, std::shared_ptr<Player>& aPlayer, std::shared_ptr<Places>& aPlaces)
{
	if (_button_array[0]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON,true))//buy
	{
		_buy_item(aPlaces->getItemsForTrade(), aPlayer->aItemsManager);
	}
	if (_button_array[1]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true)) //sell
	{
		_buy_item(aPlayer->aItemsManager, aPlaces->getItemsForTrade());
	}
	if (_button_array[2]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		_button_array[3]->setButtonPosition(sf::Vector2f(365, 325));
		_button_array[2]->setButtonPosition(sf::Vector2f(365, 9000));
		_current_item = std::make_unique<Wood>();
	}
	if (_button_array[3]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		_button_array[4]->setButtonPosition(sf::Vector2f(365, 325));
		_button_array[3]->setButtonPosition(sf::Vector2f(365, 9000));
		_current_item = std::make_unique<Iron>();
	}
	if (_button_array[4]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		_button_array[5]->setButtonPosition(sf::Vector2f(365, 325));
		_button_array[4]->setButtonPosition(sf::Vector2f(365, 9000));
		_current_item = std::make_unique<Spearman>();
	}
	if (_button_array[5]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		_button_array[6]->setButtonPosition(sf::Vector2f(365, 325));
		_button_array[5]->setButtonPosition(sf::Vector2f(365, 9000));
		_current_item = std::make_unique<Swordsman>();
	}
	if (_button_array[6]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		_button_array[7]->setButtonPosition(sf::Vector2f(365, 325));
		_button_array[6]->setButtonPosition(sf::Vector2f(365, 9000));
		_current_item = std::make_unique<Archer>();
	}
	if (_button_array[7]->getButtonIsActive() == true and aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON, true))
	{
		_button_array[2]->setButtonPosition(sf::Vector2f(365, 325));
		_button_array[7]->setButtonPosition(sf::Vector2f(365, 9000));
		_current_item = std::make_unique<Food>();
	}
}

void MP::GuiMarketPlace::update(SoundManager & aSoundManager,TaskManager& aMainTaskManager, sf::RenderWindow& mainWindow, sf::Vector2f guiMouseCoord, std::shared_ptr<Player>& aPlayer, std::shared_ptr<Places>& aPlace)
{
	if (aMainTaskManager.getCurrentState() == MP::TaskManager::stateType::stateMarketPlace)
	{
		_update_market_place(*aPlace, *aPlayer);
		_select_button(aSoundManager, aMainTaskManager,guiMouseCoord);
		_press_button(aMainTaskManager, mainWindow, aPlayer, aPlace);
	}
}

void MP::GuiMarketPlace::render(TaskManager& aMainTaskManager, sf::RenderWindow& aMainWindow ,std::shared_ptr<Places> aPlace, std::shared_ptr<Player> aPlayer)
{
	if (aMainTaskManager.getCurrentState() == MP::TaskManager::stateType::stateMarketPlace)
		_draw_menu(aMainWindow, *aPlace, *aPlayer);
}
