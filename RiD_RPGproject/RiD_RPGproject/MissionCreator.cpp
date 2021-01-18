#include "MissionCreator.h"
#include "Time.h"
#include "Engine/ConfigurationLoader.h"

void MP::MissionCreator::_set_mission(const char* missionPath, std::string missionName)
{
	std::shared_ptr<Mission> tmp = std::make_shared<Mission>(missionPath);

	_missions[missionName] = tmp;
}

MP::MissionCreator::MissionCreator()
{
	_random_number.seed(time(0));
	_set_mission("missions/town_medicine.ini", "townmedicine");
	_set_mission("missions/castle_supply.ini", "castlesupply");
}

std::shared_ptr<MP::Mission> MP::MissionCreator::getMission(char placeMark)
{
	std::string missionName;

	if (placeMark == RiD::ConfigurationLoader::getStringData("castle", "mark")[0])
	{
		missionName = "castlesupply";
	}
	else if (placeMark == RiD::ConfigurationLoader::getStringData("town", "mark")[0])
	{
		missionName = "townmedicine";
	}
	else if (placeMark == RiD::ConfigurationLoader::getStringData("village", "mark")[0])
	{
		return nullptr;
	}
	return _missions.at(missionName);
}
