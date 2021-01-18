#pragma once
#include "Object.h"
#include "ItemsManager.h"
#include "Sound.h"


namespace MP
{
	class ActiveObject :public Object
	{
	protected:
	
		sf::Time _last_active;///Stores time, when object moved.

		sf::Time _ready_time;///Stores time when object is able to move.

		sf::Time active_obj_sleep_time;///Amount of time, when object don't change position.

		int _block_length;///Block length.

		int _block_length_copy;///Copy of block length.

		int _distance_traveled;///Current traveled distance.

		int _velocity; ///Obiect velocity. Use only divisible numbers by block length.

		MP::Sound _sound_player;///Plays songs.

	public:

		ItemsManager aItemsManager;///Manages items.

		///Constructor.
		ActiveObject();

		///Sets last active time.
		///@param currentTime current game's time.
		void setLastActive(sf::Clock currentTime);

		///Returns last active time.
		///@return last active time.
		sf::Time getLastActiveTime();

		///Returns ready time.
		///@return ready time.
		sf::Time getReadyTime();

		///Return copy of block length.
		///@return copy of block length.
		int getBlockLenghtCopy();

		///Returns distance traveled by obiect.
		///@return traveled distance.
		int getTraveledDistance();
		
		///Returns velocity.
		///@return velocity.
		int getVelocity();

		///Resets block length copy.
		void resetBlockLenghtCopy();

		///Decreases block lenth copy.
		void decreaseBlockLengthCopy();
	};
}