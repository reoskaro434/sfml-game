#include <thread>
#include "Calculator.h"
#include <iostream>


void MP::Calculator::_computer_players_procedure(TaskManager& mainTaskManger, SoundManager &aSoundManager,ObjectManager& aObjectManager, sf::Clock& gameClock, Map& aMap)
{
	std::list<ComputerPlayerBandit>* computerPlayerList = aObjectManager.getComputerPlayerList();
	std::list<ComputerPlayerBandit>::iterator it;

	it = computerPlayerList->begin();

	for (it; it != computerPlayerList->end(); it++)
		it->update(mainTaskManger,aSoundManager,aMap, gameClock,aObjectManager.getPlayer());

}

void MP::Calculator::_trees_procedure(TaskManager& mainTaskManger, sf::Clock& globalClock, ObjectManager& aObjectManager)
{

	std::list<Tree>* aTree = aObjectManager.getTreeList();
	std::list<Tree >::iterator iterator;
	iterator = aTree->begin();



	for (iterator; iterator != aTree->end(); iterator++)
		if (aObjectManager.access())
			iterator->update(mainTaskManger,globalClock);

}


void MP::Calculator::updateGame(SoundManager& aSoundManager, TaskManager& mainTaskManger, ObjectManager& aObjectManager, sf::Clock& gameClock, Camera& aCamera)
{
	//state

	mainTaskManger.updateState();

	//game
	aObjectManager.getPlayer()->update(aSoundManager, mainTaskManger, gameClock, aObjectManager.getMap(), aObjectManager.getCursor()->getGameCoord());

	_trees_procedure(mainTaskManger, gameClock, aObjectManager);

	_computer_players_procedure(mainTaskManger, aSoundManager, aObjectManager, gameClock, aObjectManager.getMap());

	//menu
	aObjectManager.getGuiManager().getMapGui()->update(mainTaskManger, aObjectManager.getPlayer()->aItemsManager, aObjectManager.getPlayer()->getMessage());

	aObjectManager.getGuiManager().getGuiMainMenu()->update(aSoundManager, mainTaskManger, aCamera.getWindow(), aObjectManager.getCursor()->getGuiCoord());

	aObjectManager.getGuiManager().getGuiPlacesMenu()->update(aSoundManager, mainTaskManger, aCamera.getWindow(), aObjectManager.getCursor()->getGuiCoord());

	aObjectManager.getGuiManager().getGuiMarketPlace()->update(aSoundManager, mainTaskManger, aCamera.getWindow(), aObjectManager.getCursor()->getGuiCoord(), aObjectManager.getPlayer(), aObjectManager.getPlayer()->getCurrentPlace());
}