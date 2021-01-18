#pragma once
#include <iostream>
#include <map>
#include "Mission.h"
#include <random>

namespace MP
{
	class MissionCreator
	{
	private:

		std::mt19937 _random_number;///Generates random number.

		std::map<std::string,std::shared_ptr<Mission>> _missions;///Stores mission.
		
		///Creates mission.
		///@param missionPath path to .ini file.
		///@param missionName mission's name.
		void _set_mission(const char* missionPath, std::string missionName);


	public:

		///Mission creator constructor.
		MissionCreator();

		///Returns mission.
		///@param placeMark place's mark.
		///@Return mission.
		std::shared_ptr<Mission> getMission(char placeMark);
	};

}