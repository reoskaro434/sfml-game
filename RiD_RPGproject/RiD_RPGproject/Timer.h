#pragma once
#include <SFML/Graphics.hpp>

namespace MP
{
	class Timer
	{	
	private:

		sf::Time _next_active;///Next time, when time control returns true.

		sf::Time _last_active;///Last time, when time control return true.

		bool _is_timer_rdy;///Stores if timer return true.

	public:

		///Timer constructor.
		Timer();

		///Measures time and return true if timer is ready.
		///@param gameClock game's clock.
		///@breakTime time when timer returns false.
		///@return if timer is ready.
		bool timeControl(sf::Clock & gameClock,sf::Time breakTime);
		
		///Sets timer.
		///@param gameClock game's clock.
		///@breakTime time when timer returns false.
		void setTimer(sf::Clock& gameClock, sf::Time breakTime);
	
	};
}