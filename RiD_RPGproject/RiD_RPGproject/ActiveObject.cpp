#include "ActiveObject.h"
#include "Engine/ConfigurationLoader.h"

MP::ActiveObject::ActiveObject()
{
	_last_active = sf::milliseconds(0);
	_ready_time = sf::milliseconds(0);
	active_obj_sleep_time = sf::milliseconds(0);
	_obj_animation_sleep_time = sf::milliseconds(0);

	_block_length_copy=_block_length  = RiD::ConfigurationLoader::getIntData("game settings", "blockLength");

	_distance_traveled = 0;
	_velocity = 0;
}

void MP::ActiveObject::setLastActive(sf::Clock currentTime)
{
	_ready_time = _last_active = currentTime.getElapsedTime();
	_ready_time += active_obj_sleep_time;
}

sf::Time MP::ActiveObject::getLastActiveTime()
{
	return _last_active;
}

sf::Time MP::ActiveObject::getReadyTime()
{
	return _ready_time;
}

int MP::ActiveObject::getBlockLenghtCopy()
{
	return _block_length_copy;
}

void MP::ActiveObject::resetBlockLenghtCopy()
{
	_block_length_copy = _block_length;
	_distance_traveled = 0;
}

void MP::ActiveObject::decreaseBlockLengthCopy()
{
	_block_length_copy-=_velocity;
	_distance_traveled += _velocity;
}

int MP::ActiveObject::getTraveledDistance()
{
	return _distance_traveled;
}

int MP::ActiveObject::getVelocity()
{
	return _velocity;
}
