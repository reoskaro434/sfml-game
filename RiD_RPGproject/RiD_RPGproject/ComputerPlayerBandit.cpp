#include "ComputerPlayerBandit.h"
#include "Move.h"

MP::ComputerPlayerBandit::ComputerPlayerBandit(sf::Texture* texturePtr, sf::Vector2f computerPlayerCoordinates)
{

	_path = nullptr;
	_is_enemys_check = false;
	//Loading textures.
	aAnimation.loadObjectTextures(texturePtr, 4, 4, 64);
	aAnimation.changeSprite(6);
	aAnimation.setScale(float(0.8), float(0.8));

	//Getting computer player animation and move sleep time.
	active_obj_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("computer player", "SleepTime"));
	_obj_animation_sleep_time = sf::milliseconds(RiD::ConfigurationLoader::getIntData("computer player", "animationSleepTime"));

	//Loading velocity.
	_velocity = RiD::ConfigurationLoader::getIntData("computer player", "velocity");

	//Getting player coordinates.
	setObjectCoord(computerPlayerCoordinates);

	//Loading radius
	_radius = RiD::ConfigurationLoader::getIntData("computer player", "radius");
}

void MP::ComputerPlayerBandit::_chose_destination(Map &aMap)
{
	MP::PathCreator tmp(aMap);
	sf::Vector2f destinationCoord = aMap.returnRandomWalkableElement()->getLandTile().getObjectCoord();
	MapElement* startingElement = aMap.findElementAddressSquareRange(getObjectCoord());

	while(destinationCoord == startingElement->getLandTile().getObjectCoord())
		destinationCoord = aMap.returnRandomWalkableElement()->getLandTile().getObjectCoord();

	//Chose random destination and calculate path.
	
	_path =  tmp.findPath(startingElement->getLandTile().getObjectCoord(),destinationCoord);
}

void MP::ComputerPlayerBandit::_delete_path()
{
	if (_path == nullptr)
		return;
	else
	{
		while (_path != nullptr)
		{
			MapElement* tmp = _path;

			_path = _path->getNextElement();
			delete tmp;
		}
	}
}

bool MP::ComputerPlayerBandit::_check_enemy(std::shared_ptr<Player>& aPlayer)
{
	sf::Vector2f radiusCoord;
	sf::Vector2f player = aPlayer->getObjectCoord();
	radiusCoord.x = getObjectCoord().x - _radius;
	radiusCoord.y = getObjectCoord().y - _radius;


	if (radiusCoord.x + 2 * _radius > player.x and radiusCoord.x < player.x)
		if (radiusCoord.y + 2 * _radius > player.y and radiusCoord.y < player.y)
		{
			if (!_is_enemys_check)
			{
				aAnimation.setColor(sf::Color(240, 128, 128));
				active_obj_sleep_time = sf::milliseconds(35);
				_is_enemys_check = true;
			}

			return true;
		}

	if (_is_enemys_check)
	{
		aAnimation.setColor(sf::Color(255, 255, 255));
		_is_enemys_check = false;
		active_obj_sleep_time = sf::milliseconds(55);
	}
	return false;
}

void MP::ComputerPlayerBandit::_song_procedure(MP::SoundManager& aSoundManager)
{
	if (!_sound_player.isPlaying())
		if(_is_enemys_check)
		if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_DOWN, false) or
			aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_UP, false) or
			aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_LEFT, false) or
			aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_RIGHT, false))
			_sound_player.playSound(aSoundManager.getSound("pawnSound"));
}

void MP::ComputerPlayerBandit::_attack_player(Map &gameMap,std::shared_ptr<Player>& player)
{
	_delete_path();
	MapElement* playerField = player->getCurrentLand();
	PathCreator tmp(gameMap);

	_path = tmp.findPath(getCurrentLand()->getLandTile().getObjectCoord(),playerField->getLandTile().getObjectCoord());
}

void MP::ComputerPlayerBandit::_get_next_task(Map& aMap, std::shared_ptr<Player>& player)
{
	if (aPawnObjectTaskManager.isTaskListEmpty())
	{
		if (_path == nullptr)//Sets new destination.
		_chose_destination(aMap);

		MapElement* nextDestination = _path;//Takes new destination (new block).
		MapElement* tmp = aMap.findElementAddressSquareRange(getObjectCoord());//Return element where computer player stands.

		_current_land = tmp;
		//_is_enemys_check = false;
		_check_enemy(player);

		if (tmp->getLandTile().getObjectCoord().x == nextDestination->getLandTile().getObjectCoord().x and tmp->getLandTile().getObjectCoord().y + _block_length == nextDestination->getLandTile().getObjectCoord().y)//Goes down
			aPawnObjectTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_DOWN);

		else if (tmp->getLandTile().getObjectCoord().x == nextDestination->getLandTile().getObjectCoord().x and tmp->getLandTile().getObjectCoord().y - _block_length == nextDestination->getLandTile().getObjectCoord().y)//Goes up
			aPawnObjectTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_UP);

		else if (tmp->getLandTile().getObjectCoord().x + _block_length == nextDestination->getLandTile().getObjectCoord().x and tmp->getLandTile().getObjectCoord().y == nextDestination->getLandTile().getObjectCoord().y)
			aPawnObjectTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_RIGHT);

		else if (tmp->getLandTile().getObjectCoord().x - _block_length == nextDestination->getLandTile().getObjectCoord().x and tmp->getLandTile().getObjectCoord().y == nextDestination->getLandTile().getObjectCoord().y)
			aPawnObjectTaskManager.addTask(MP::TaskNode::taskType::TASK_MOVE_LEFT);

		_path = _path->getNextElement();//Deleting usless element
		delete nextDestination;	
	}
}

void MP::ComputerPlayerBandit::_computer_player_move(sf::Clock& globalClock)
{
	MP::Move tmp;

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_UP, false))
		tmp.moveBlockUp(*this, globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_LEFT, false))
		tmp.moveBlockLeft(*this, globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_DOWN, false))
		tmp.moveBlockDown(*this, globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_RIGHT, false))
		tmp.moveBlockRight(*this, globalClock);

	if (aPawnObjectTaskManager.isTaskListEmpty())
		this->resetBlockLenghtCopy();
}

MP::ComputerPlayerBandit::~ComputerPlayerBandit()
{
	_delete_path();
}

void MP::ComputerPlayerBandit::_computer_player_animation(sf::Clock& globalClock)
{
	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_UP, false))
		_computer_player_animation_up(globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_DOWN, false))
		_computer_player_animation_down(globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_LEFT, false))
		_computer_player_animation_left(globalClock);

	if (aPawnObjectTaskManager.findTask(MP::TaskNode::taskType::TASK_MOVE_RIGHT, false))
		_computer_player_animation_right(globalClock);
}

void MP::ComputerPlayerBandit::_computer_player_animation_right(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(8, 11);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::_computer_player_animation_left(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(4, 7);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::_computer_player_animation_up(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(12, 15);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::_computer_player_animation_down(sf::Clock& globalClock)
{
	if (globalClock.getElapsedTime() > _ready_animation_time)
	{
		aAnimation.setNextSprite(0, 3);
		setLastActiveAnimation(globalClock);
	}
}

void MP::ComputerPlayerBandit::update(TaskManager& mainTaskManager, SoundManager& aSoundManager, Map& aMap, sf::Clock& gameClock, std::shared_ptr<Player>& aPlayer)
{
	if (mainTaskManager.getCurrentState() == TaskManager::stateType::stateGame)
	{
		if (_is_enemys_check)
			_attack_player(aMap, aPlayer);
		_song_procedure(aSoundManager);
		_get_next_task(aMap, aPlayer);
		_computer_player_animation(gameClock);
		_computer_player_move(gameClock);
	}
}

void MP::ComputerPlayerBandit::render(TaskManager& mainTaskManager,sf::RenderWindow& mainWindow)
{
	if (mainTaskManager.getCurrentState() == TaskManager::stateType::stateGame)
	mainWindow.draw(aAnimation.getObjectSprite());
}