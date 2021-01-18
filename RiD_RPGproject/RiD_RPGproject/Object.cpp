#include "Object.h"
#include "Engine/ConfigurationLoader.h"

MP::Object::Object()
{
	_objCoord.x = 0;
	_objCoord.y = 0;
	_ready_animation_time = sf::milliseconds(0);
	_last_animation_active = sf::milliseconds(0);
}

void MP::Object::setObjectCoord(int x, int y)
{
	aAnimation.setObjectSpritePosition(x, y);

	_objCoord.x = float(x);
	_objCoord.y = float(y);
}

void MP::Object::setObjectCoord(sf::Vector2f coord)
{
	aAnimation.setObjectSpritePosition(coord);
	_objCoord = coord;
}

sf::Vector2f  MP::Object::getObjectCoord()
{
	return _objCoord;
}

void MP::Object::setLastActiveAnimation(sf::Clock currentTime)
{
	_ready_animation_time = _last_animation_active = currentTime.getElapsedTime();
	_ready_animation_time += _obj_animation_sleep_time;
}