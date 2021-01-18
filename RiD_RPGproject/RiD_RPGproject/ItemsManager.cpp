#include "ItemsManager.h"
#include "Gold.h"
#include "Iron.h"
#include "Food.h"
#include "Archer.h"
#include "Wood.h"
#include "Swordsman.h"
#include "Spearman.h"




void MP::ItemsManager::setItems(sf::Font &aFont,unsigned int gold, sf::Texture* goldTextures, unsigned int iron, sf::Texture* ironTextures,
	unsigned int wood, sf::Texture* woodTextures, unsigned int food, sf::Texture* foodTextures, unsigned int spearman,
	sf::Texture* spearmanTextures, unsigned int archer, sf::Texture* archerTextures, unsigned int swordsman, sf::Texture* swordsmanTextures)
{
	_gold = std::make_shared<Gold>(goldTextures,aFont);
	_gold->setItemAmount(gold);

	_iron = std::make_shared<Iron>(ironTextures,aFont);
	_iron->setItemAmount(iron);

	_food = std::make_shared<Food>(foodTextures,aFont);
	_food->setItemAmount(food);

	_spearman = std::make_shared<Spearman>(spearmanTextures,aFont);
	_spearman->setItemAmount(spearman);

	_archer= std::make_shared<Archer>(archerTextures,aFont);
	_archer->setItemAmount(archer);

	_wood= std::make_shared<Wood>(woodTextures,aFont);
	_wood->setItemAmount(wood);

	_swordsman = std::make_shared<Swordsman>(swordsmanTextures,aFont);
	_swordsman->setItemAmount(swordsman);
}

std::shared_ptr<MP::Item>& MP::ItemsManager::getGold()
{
	return _gold;
}

std::shared_ptr<MP::Item>& MP::ItemsManager::getIron()
{
	return _iron;
}

std::shared_ptr<MP::Item>& MP::ItemsManager::getWood()
{
	return _wood;
}

std::shared_ptr<MP::Item>& MP::ItemsManager::getFood()
{
	return _food;
}

std::shared_ptr<MP::Item>& MP::ItemsManager::getSpearman()
{
	return _spearman;
}

std::shared_ptr<MP::Item>& MP::ItemsManager::getArcher()
{
	return _archer;
}

std::shared_ptr<MP::Item>& MP::ItemsManager::getSwordsman()
{
	return _swordsman;
}


bool MP::ItemsManager::addItem(std::shared_ptr <Item>& aItem, int amount)
{
	if (_gold->getItemAmount() - (amount * aItem->getItemCost()) >= 0)
	{
		aItem->setItemAmount(aItem->getItemAmount() + amount);
		_gold->setItemAmount(_gold->getItemAmount() - (amount * aItem->getItemCost()));
		return true;
	}
	else
		return false;
}

bool MP::ItemsManager::subtractItem(std::shared_ptr <Item>& aItem, int amount, int buyerGold)
{
	if ((aItem->getItemAmount() - amount) >= 0 and aItem->getItemCost()*amount <= buyerGold)
	{
		aItem->setItemAmount(aItem->getItemAmount() - amount);
		_gold->setItemAmount(_gold->getItemAmount() + (amount * aItem->getItemCost()));
		return true;
	}
	else
		return false;
}