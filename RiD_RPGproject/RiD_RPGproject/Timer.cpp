#include "Timer.h"

void MP::Timer::setTimer(sf::Clock& gameClock, sf::Time breakTime)
{
	_is_timer_rdy = true;
	_next_active=_last_active= gameClock.getElapsedTime();
	_next_active += breakTime;
}

MP::Timer::Timer()
{
	_is_timer_rdy = false;
}

bool MP::Timer::timeControl(sf::Clock& gameClock, sf::Time breakTime)
{
	if (!_is_timer_rdy)
		setTimer(gameClock, breakTime);
	
		if (gameClock.getElapsedTime() >= _next_active)
		{
			_is_timer_rdy = false;
			return true;
		}
	return false;
}
