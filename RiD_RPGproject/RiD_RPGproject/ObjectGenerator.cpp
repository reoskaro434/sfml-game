#include <fstream>
#include "ObjectGenerator.h"
#include "Player.h"
#include "ActiveObject.h"
#include "SpriteAnimation.h"
#include "Land.h"
#include <vector>
#include "Engine/ConfigurationLoader.h"
#include "ComputerPlayerBandit.h"
#include "GuiPlacesMenu.h"

void MP::ObjectGenerator::_generate_trees(ObjectManager& aObiectManager)
{

	std::cout << "generates trees " << std::endl;

	std::vector<std::vector<MapElement* >> tmpMapArray = aObiectManager.getMap().getMapArray();

	std::vector<std::vector<MapElement* >>::iterator it = tmpMapArray.begin();
	std::vector<MapElement* >::iterator it2;
	unsigned int counter = 0;

	char controlMark = RiD::ConfigurationLoader::getStringData("game settings", "treeWallMark")[0];

	int a = tmpMapArray.size();
	int b = tmpMapArray[0].size();
	a *= b;
	int progresCounter = 0;


	for (it; it != tmpMapArray.end(); it++) 
	{
		it2 = tmpMapArray[counter].begin();
		for (it2; it2 != tmpMapArray[counter].end(); it2++)
		{
			if ((*it2)->getMark() == controlMark)
			{
				int counter = RiD::ConfigurationLoader::getIntData("game settings", "numberOfTrees");
				int spawnRange = RiD::ConfigurationLoader::getIntData("game settings", "blockLength");
				spawnRange -= 10;
				while (counter != 0)
				{
					sf::Vector2f tmpCoord = (*it2)->getLandTile().getObjectCoord();
					tmpCoord.x += _random_number() % spawnRange;
					tmpCoord.y += _random_number() % spawnRange;

					float newScale = ((_random_number() % 50) * float(0.01)) + float(0.8);

					std::shared_ptr<Tree> tmpTree = std::make_shared<Tree>(&_a_asset_manager.getTexture("tree"), tmpCoord, newScale);
					aObiectManager.getTreeList()->push_back(*tmpTree);
					counter--;
				}

			}
		}
		counter++;
	}
}

void MP::ObjectGenerator::_generate_grass(ObjectManager& aObiectManager)
{
	std::cout << "generates grass " << std::endl;

	std::vector<std::vector<MapElement* >> tmpMapArray = aObiectManager.getMap().getMapArray();

	std::vector<std::vector<MapElement* >>::iterator it = tmpMapArray.begin();
	std::vector<MapElement* >::iterator it2;
	unsigned int counter = 0;

	//char controlMark = RiD::ConfigurationLoader::getStringData("game settings", "treeWallMark")[0];

	int a = tmpMapArray.size();
	int b = tmpMapArray[0].size();
	a *= b;
	int progresCounter = 0;


	for (it; it != tmpMapArray.end(); it++)
	{
		it2 = tmpMapArray[counter].begin();
		for (it2; it2 != tmpMapArray[counter].end(); it2++)
		{
				int counter = RiD::ConfigurationLoader::getIntData("game settings", "numberOfGrass");
				int spawnRange = RiD::ConfigurationLoader::getIntData("game settings", "blockLength");
				spawnRange -= 10;
				if((*it2)->getPlace()==nullptr)
				while (counter != 0)
				{
					sf::Vector2f tmpCoord = (*it2)->getLandTile().getObjectCoord();
					tmpCoord.x += _random_number() % spawnRange;
					tmpCoord.y += _random_number() % spawnRange;

					float newScale = ((_random_number() % 50) * float(0.01)) + float(0.8);

					std::unique_ptr<Grass> tmpTree = std::make_unique<Grass>(&_a_asset_manager.getTexture("grass"), tmpCoord, newScale);
					aObiectManager.getGrassVector()->push_back(*tmpTree);
					counter--;
				}
		}
		counter++;
	}
}

void MP::ObjectGenerator::_generate_player(ObjectManager& aObiectManager)
{
	std::cout << "generates player " << std::endl;
	std::shared_ptr<MP::Player> tmp = std::make_shared< Player >(&_a_asset_manager.getTexture("player"), &_a_asset_manager.getTexture("pathicon"));

	tmp->aItemsManager.setItems(_a_asset_manager.getFont("font"),
		RiD::ConfigurationLoader::getIntData("player", "gold"), &_a_asset_manager.getTexture("gold"),
		RiD::ConfigurationLoader::getIntData("player", "iron"), &_a_asset_manager.getTexture("iron"),
		RiD::ConfigurationLoader::getIntData("player", "wood"),&_a_asset_manager.getTexture("wood"),
		RiD::ConfigurationLoader::getIntData("player", "food"),&_a_asset_manager.getTexture("food"),
		RiD::ConfigurationLoader::getIntData("player", "spearman"),&_a_asset_manager.getTexture("spearman"), 
		RiD::ConfigurationLoader::getIntData("player", "archer"),&_a_asset_manager.getTexture("archer"),
		RiD::ConfigurationLoader::getIntData("player", "swordsman"),&_a_asset_manager.getTexture("swordsman"));

	aObiectManager.addObiect(tmp);
}

void MP::ObjectGenerator::_generate_map(ObjectManager& aObiectManager)
{
	std::cout << "generates map " <<std::endl;
	std::fstream mapFile;
	mapFile.open("worldmaps/worldmap1.txt", std::ios::in);

	std::string line;

	int blockLength = RiD::ConfigurationLoader::getIntData("game settings", "blockLength");
	int y = 0;

	std::vector<MapElement*> row;
	unsigned int counter = 0;
	while (mapFile)
	{
		int x = 0;
		std::getline(mapFile, line);

		if (mapFile)
		{
			
			aObiectManager.getMap().getMapArray().push_back(row);

			for (unsigned int i = 0; i < line.length(); i++)
			{
				MapElement* tmpMapElement = new MapElement(_a_asset_manager,x, y, line[i]);
				

				aObiectManager.getMap().getMapArray()[counter].push_back(tmpMapElement);

				x += blockLength;
				aObiectManager.getMap().setLastElementCoord(tmpMapElement->getLandTile().getObjectCoord());

				char placesMark = tmpMapElement->getMark();

				if (tmpMapElement->getPlace() != nullptr)
				{
					tmpMapElement->getPlace()->aItemsManager.setItems(_a_asset_manager.getFont("font"),
						0, &_a_asset_manager.getTexture("gold"),
						0, &_a_asset_manager.getTexture("iron"),
						0, &_a_asset_manager.getTexture("wood"),
					    0, &_a_asset_manager.getTexture("food"),
						0, &_a_asset_manager.getTexture("spearman"),
						0, &_a_asset_manager.getTexture("archer"),
						0, &_a_asset_manager.getTexture("swordsman"));

					tmpMapElement->getPlace()->getItemsForTrade().setItems(_a_asset_manager.getFont("font"),
						0, & _a_asset_manager.getTexture("gold"),
						0, & _a_asset_manager.getTexture("iron"),
						0, & _a_asset_manager.getTexture("wood"),
						0, & _a_asset_manager.getTexture("food"),
						0, & _a_asset_manager.getTexture("spearman"),
						0, & _a_asset_manager.getTexture("archer"),
						0, & _a_asset_manager.getTexture("swordsman"));

					if (placesMark == RiD::ConfigurationLoader::getStringData("village", "mark")[0])
					{
						_generate_items_for_places(tmpMapElement->getPlace()->aItemsManager,tmpMapElement->getPlace()->getItemsForTrade(), RiD::ConfigurationLoader::getIntData("village", "modulo"), RiD::ConfigurationLoader::getIntData("village", "moduloTrade"), placesMark);
					}
					else if (placesMark == RiD::ConfigurationLoader::getStringData("castle", "mark")[0])
					{
						_generate_items_for_places(tmpMapElement->getPlace()->aItemsManager, tmpMapElement->getPlace()->getItemsForTrade(), RiD::ConfigurationLoader::getIntData("castle", "modulo"), RiD::ConfigurationLoader::getIntData("village", "moduloTrade"), placesMark);
					}
					else if (placesMark == RiD::ConfigurationLoader::getStringData("town", "mark")[0])
					{
						_generate_items_for_places(tmpMapElement->getPlace()->aItemsManager, tmpMapElement->getPlace()->getItemsForTrade(), RiD::ConfigurationLoader::getIntData("town", "modulo"), RiD::ConfigurationLoader::getIntData("village", "moduloTrade"), placesMark);
					}
				}
			}
			counter++;
			y += blockLength;
		}
	}
	aObiectManager.getMap().createPlacesList();
}

void MP::ObjectGenerator::_generate_computer_player(ObjectManager& aObiectManager)
{
	std::cout << "generates computer players " << std::endl;
	int computerPlayerAmmount = RiD::ConfigurationLoader::getIntData("computer player", "numberOfPlayers");
	while (computerPlayerAmmount != 0)
	{
		sf::Vector2f computerPlayerCoords = aObiectManager.getMap().returnRandomWalkableElement()->getLandTile().getObjectCoord();
		computerPlayerCoords.x += 10;
		computerPlayerCoords.y += 6;
		std::shared_ptr<ComputerPlayerBandit> tmp= std::make_shared<ComputerPlayerBandit>(&_a_asset_manager.getTexture("bandit"), computerPlayerCoords);
		aObiectManager.addObiect(*tmp);


		computerPlayerAmmount--;
	}

}

void MP::ObjectGenerator::_generate_cursor(ObjectManager& aObiectManager)
{
	std::cout << "generates cursor " << std::endl;
	std::shared_ptr<Cursor> tmp = std::make_shared<Cursor>(&_a_asset_manager.getTexture("cursor"));
	aObiectManager.setCursor(tmp);

}

void MP::ObjectGenerator::_generate_gui(ObjectManager& aObiectManager)
{
	std::cout << "generates GUI" << std::endl;
	//creating map gui
	aObiectManager.getGuiManager().getMapGui() = std::make_unique<MapGui>(_a_asset_manager);


	//creating main menu
	aObiectManager.getGuiManager().getGuiMainMenu() = std::make_unique<GuiMainMenu>(_a_asset_manager);


	//creating places menu
	aObiectManager.getGuiManager().getGuiPlacesMenu() = std::make_unique<GuiPlacesMenu>(_a_asset_manager);
	
	//creating market place menu
	aObiectManager.getGuiManager().getGuiMarketPlace() = std::make_unique<GuiMarketPlace>(_a_asset_manager);

}

void MP::ObjectGenerator::_generate_items_for_places(ItemsManager& itemsFromPlaces,ItemsManager &itemsForTrade,int multiplier,int tradeMultiplier, char placesMark)
{


	if (placesMark == RiD::ConfigurationLoader::getStringData("village", "mark")[0])
	{
		itemsFromPlaces.getWood()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getIron()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getGold()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getFood()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getArcher()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getSwordsman()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getSpearman()->setItemAmount(_random_number() % multiplier);

		itemsForTrade.getWood()->setItemAmount(_random_number() % tradeMultiplier*25);
		itemsForTrade.getIron()->setItemAmount(_random_number() % tradeMultiplier*25);
		itemsForTrade.getGold()->setItemAmount(_random_number() % tradeMultiplier*20);
		itemsForTrade.getFood()->setItemAmount(_random_number() % tradeMultiplier*25);
		itemsForTrade.getArcher()->setItemAmount(0);
		itemsForTrade.getSwordsman()->setItemAmount(0);
		itemsForTrade.getSpearman()->setItemAmount(0);
	}
	if (placesMark == RiD::ConfigurationLoader::getStringData("castle", "mark")[0])
	{
		itemsFromPlaces.getWood()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getIron()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getGold()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getFood()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getArcher()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getSwordsman()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getSpearman()->setItemAmount(_random_number() % multiplier);

		itemsForTrade.getWood()->setItemAmount(0);
		itemsForTrade.getIron()->setItemAmount(0);
		itemsForTrade.getGold()->setItemAmount(_random_number() % tradeMultiplier*100);
		itemsForTrade.getFood()->setItemAmount(_random_number() % tradeMultiplier*5);
		itemsForTrade.getArcher()->setItemAmount(_random_number() % tradeMultiplier*3);
		itemsForTrade.getSwordsman()->setItemAmount(_random_number() % tradeMultiplier * 3);
		itemsForTrade.getSpearman()->setItemAmount(_random_number() % tradeMultiplier * 3);
	}
	if (placesMark == RiD::ConfigurationLoader::getStringData("town", "mark")[0])
	{
		itemsFromPlaces.getWood()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getIron()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getGold()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getFood()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getArcher()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getSwordsman()->setItemAmount(_random_number() % multiplier);
		itemsFromPlaces.getSpearman()->setItemAmount(_random_number() % multiplier);

		itemsForTrade.getWood()->setItemAmount(_random_number() % tradeMultiplier*5);
		itemsForTrade.getIron()->setItemAmount(_random_number() % tradeMultiplier*5);
		itemsForTrade.getGold()->setItemAmount(_random_number() % tradeMultiplier*500);
		itemsForTrade.getFood()->setItemAmount(_random_number() % tradeMultiplier*10);
		itemsForTrade.getArcher()->setItemAmount(0);
		itemsForTrade.getSwordsman()->setItemAmount(0);
		itemsForTrade.getSpearman()->setItemAmount(0);
	}
}

MP::ObjectGenerator::ObjectGenerator()
{
	_random_number.seed((unsigned int)time(NULL));
}

void MP::ObjectGenerator::generateObiects(ObjectManager& aObiectManager)
{
	_a_asset_manager.setTexture("tree", "img/mpimg/mptree.png");
	_a_asset_manager.setTexture("land", "img/mpimg/mpgrass8.png");
	_a_asset_manager.setTexture("grass", "img/mpimg/grass3.png");
	_a_asset_manager.setTexture("player", "img/mpimg/mpcharacter.png");
	_a_asset_manager.setTexture("bandit", "img/mpimg/mpcomputerplayerbandit.png");
	_a_asset_manager.setTexture("village", "img/mpimg/places/mpvillage.png");
	_a_asset_manager.setTexture("town", "img/mpimg/places/mptown.png");
	_a_asset_manager.setTexture("castle", "img/mpimg/places/mpcastle.png");
	_a_asset_manager.setTexture("cursor", "img/mpimg/icons/hand.png");
	_a_asset_manager.setTexture("wood", "img/mpimg/icons/wood.png");
	_a_asset_manager.setTexture("iron", "img/mpimg/icons/iron.png");
	_a_asset_manager.setTexture("food", "img/mpimg/icons/food.png");
	_a_asset_manager.setTexture("gold", "img/mpimg/icons/gold.png");
	_a_asset_manager.setTexture("archer", "img/mpimg/icons/archer2.png");
	_a_asset_manager.setTexture("swordsman", "img/mpimg/icons/swordsman2.png");
	_a_asset_manager.setTexture("spearman", "img/mpimg/icons/spearman2.png");
	_a_asset_manager.setTexture("pathicon", "img/mpimg/icons/move.png");
	_a_asset_manager.setTexture("mapgui", "img/GUI/rid_map_gui_2.png");
	_a_asset_manager.setTexture("menu", "img/GUI/rid_main_menu.png");
	_a_asset_manager.setTexture("placesmenu", "img/GUI/places_menu.png");
	_a_asset_manager.setTexture("button", "img/GUI/button.png");
	_a_asset_manager.setTexture("marketplace", "img/GUI/rid_marketplace_background.png");
	_a_asset_manager.setTexture("panelleft", "img/GUI/rid_panel_bottom_left.png");
	_a_asset_manager.setTexture("panelright", "img/GUI/rid_panel_bottom_right.png");

	_a_asset_manager.setFont("font", "font/MerchantCopy-GOXq.ttf");

	_generate_map(aObiectManager);
	_generate_trees(aObiectManager);
	_generate_grass(aObiectManager);
	_generate_player(aObiectManager);
	_generate_computer_player(aObiectManager);
	_generate_cursor(aObiectManager);
	_generate_gui(aObiectManager);
}
