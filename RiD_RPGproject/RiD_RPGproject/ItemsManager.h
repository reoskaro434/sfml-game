#pragma once
#include "Item.h"

namespace MP
{
	class ItemsManager
	{
	private:

		std::shared_ptr <Item> _gold;///Item gold.
		std::shared_ptr <Item> _iron;///Item iron.
		std::shared_ptr <Item> _wood;///Item wood.
		std::shared_ptr <Item> _food;///Item food.
		std::shared_ptr <Item> _spearman;///Item spearman.
		std::shared_ptr <Item> _archer;///Item archer.
		std::shared_ptr <Item> _swordsman;///Item swordsman.

	public:

		///Sets all items.
		///@param aFont game's font.
		///@param gold amount of gold.
		///@param goldTextures gold texture.
		///@param iron amount of iron.
		///@param ironTextures iron texture.
		///@param wood amount of wood.
		///@param woodTextures wood texture.
		///@param food amount of food.
		///@param foodTextures food texture.
		///@param spearman amount of spearman.
		///@param spearmanTextures spearman texture.
		///@param archer amount of archer.
		///@param archerTextures archer texture.
		///@param swordsman amount of swordsman.
		///@param swordsmanTextures swordsman texture.
		void setItems(sf::Font& aFont,
			unsigned int gold, sf::Texture* goldTextures, 
			unsigned int iron, sf::Texture* ironTextures,
			unsigned int wood, sf::Texture* woodTextures, 
			unsigned int food, sf::Texture* foodTextures, 
			unsigned int spearman, sf::Texture* spearmanTextures,
			unsigned int archer, sf::Texture* archerTextures, 
			unsigned int swordsman, sf::Texture* swordsmanTextures );

		///Returns gold.
		///@return gold.
		std::shared_ptr <Item>& getGold();

		///Returns iron.
		///@return iron.
		std::shared_ptr <Item>& getIron();

		///Returns wood.
		///@return wood.
		std::shared_ptr <Item>& getWood();

		///Returns food.
		///@return food.
		std::shared_ptr <Item>& getFood();

		///Returns spearman.
		///@return spearman.
		std::shared_ptr <Item>& getSpearman();

		///Returns archer.
		///@return archer.
		std::shared_ptr <Item>& getArcher();

		///Returns swordsman.
		///@return swordsman.
		std::shared_ptr <Item>& getSwordsman();

		///Sets new item's amount, delets gold.
		///@param aItem current trading item.
		///@param amount item's amount.
		///@return true if new amount is set.
		bool addItem(std::shared_ptr <Item>& aItem, int amount);

		///Substract amount of item, adds gold.
		///@param aItem current trading item.
		///@param amount item amount.
		///@param buyerGold amount of buyer's gold.
		///@return true if new amount is substract.
		bool subtractItem(std::shared_ptr <Item>& aItem, int amount, int buyerGold);
	};
}
