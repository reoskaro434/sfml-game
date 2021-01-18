#include "ObjectDrawer.h"
#include "MapElement.h"


void MP::ObjectDrawer::_draw_land(sf::RenderWindow& mainWindow, ObjectManager& aObjectManager)
{	
	std::vector<std::vector<MapElement*>>::iterator it;
	std::vector<MapElement*>::iterator it2;

	unsigned int counter = 0;

	std::vector<std::vector<MapElement*>> mapArray = aObjectManager.getMap().getMapArray();
	for (it = mapArray.begin(); it != mapArray.end(); it++)
	{
		for (it2 = mapArray[counter].begin(); it2 != mapArray[counter].end(); it2++)
		{
			(*it2)->getLandTile().render(mainWindow); //land drawing

			if ((*it2)->getPlace() != nullptr)
				(*it2)->getPlace()->render(mainWindow);//place drawing
		}
		counter++;
	}
}

void MP::ObjectDrawer::_draw_trees(TaskManager& mainTaskManger, sf::RenderWindow& mainWindow, ObjectManager& aObjectManager)
{
	std::list<Tree> * aTree = aObjectManager.getTreeList();
	std::list<Tree >::iterator iterator;
	iterator = aTree->begin();

	for (iterator; iterator != aTree->end(); iterator++)
		iterator->render(mainTaskManger,mainWindow);
}

void MP::ObjectDrawer::_draw_grass(sf::RenderWindow& mainWindow, ObjectManager& aObjectManager)
{
	std::vector<Grass>* aGrass = aObjectManager.getGrassVector();
	std::vector<Grass >::iterator iterator;
	iterator = aGrass->begin();

	for (iterator; iterator != aGrass->end(); iterator++)
		iterator->render(mainWindow);
}

void MP::ObjectDrawer::_draw_active_obiects(TaskManager& mainTaskManger, sf::RenderWindow& mainWindow, ObjectManager& aObjectManager)
{
	//drawing player and path icon (if exist);
	aObjectManager.getPlayer()->render(mainTaskManger,mainWindow);


	//drawing computer player
	std::list<MP::ComputerPlayerBandit> *computerPlayerList = aObjectManager.getComputerPlayerList();
	std::list<MP::ComputerPlayerBandit>::iterator it;
	it = computerPlayerList->begin();

	for (it; it != computerPlayerList->end(); it++)
		it->render(mainTaskManger,mainWindow);

}
void MP::ObjectDrawer::drawGame(TaskManager& mainTaskManger, Camera& aGameCamera, ObjectManager& aObjectManager)
{
	//GAME DRAWING
	aGameCamera.changeViewToGame();
	_draw_land(aGameCamera.getWindow(), aObjectManager);
	_draw_grass(aGameCamera.getWindow(), aObjectManager);
	_draw_active_obiects(mainTaskManger, aGameCamera.getWindow(), aObjectManager);
	_draw_trees(mainTaskManger, aGameCamera.getWindow(), aObjectManager);

	//GUI DRAWING
	aGameCamera.changeViewToGui();
	//Drawing map gui
	aObjectManager.getGuiManager().getMapGui()->render(mainTaskManger, aGameCamera.getWindow(), aObjectManager.getPlayer()->aItemsManager);
	//Drawing cursor
	aObjectManager.getGuiManager().getGuiMainMenu()->render(mainTaskManger, aGameCamera.getWindow());

	aObjectManager.getGuiManager().getGuiPlacesMenu()->render(mainTaskManger, aGameCamera.getWindow());

	aObjectManager.getGuiManager().getGuiMarketPlace()->render(mainTaskManger, aGameCamera.getWindow(), aObjectManager.getMap().findElementAddressSquareRange(aObjectManager.getPlayer()->getObjectCoord())->getPlace(), aObjectManager.getPlayer());

	aObjectManager.getCursor()->render(aGameCamera.getWindow());
}