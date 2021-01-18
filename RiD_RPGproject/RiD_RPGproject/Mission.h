#pragma once
#include <string>
#include "Sound.h"

namespace MP
{
	class Mission
	{

	private:

		char _employer;///Stores employer's mark.
		char _destination;///Stores destination's mark.
		std::string _action;///Responds for mission type.
		unsigned int _fight_lvl;///Responds for enemy's count.

		int _gold_award;///Stores gold award.
		int _wood_award;///Stores wood award.
		int _iron_award;///Stores iron award.
		int _food_award;///Stores food award.
		int _spearman_award;///Stores spearman award.
		int _swordsman_award;///Stores swordsman award.
		int _archer_award;///Stores archer award.

		int _gold_needs;///Stores required gold.
		int _wood_needs;///Stores required wood.
		int _iron_needs;///Stores required iron.
		int _food_needs;///Stores required food.
		int _spearman_needs;///Stores required spearman.
		int _swordsman_needs;///Stores required swordsman.
		int _archer_needs;///Stores required archer.

		std::string _start_message[12];///Message which is shown while mission started.
		std::string _destination_message[12];///Message which is shown while mission got half stage.
		std::string _end_message[12];///Message which is shown while mission ended.

		///Downloads mission from path.
		///@param missionPath path to .ini file.
		void _download_mission(const char* missionPath);

	public:

		MP::Sound missionSoundPlayer;///Stores sound.

		///Sets mission.
		///@param missionPath path to .ini file.
		Mission(const char* missionPath);

		///Returns destination mark.
		///@return destination mark.
		char getDestination();

		///Returns emplyer mark.
		///@return employer mark.
		char getEmployer();

		///Returns action type.
		///@return action type.
		std::string getAction();

		///Returns fight level.
		///@return fight level.
		unsigned int getFightLvl();

		///Returns start message.
		///@return start message.
		std::string* getStartMessage();

		///Returns end message.
		///@return end message.
		std::string* getEndMessage();

		///Returns half stage message.
		///@return half stage message.
		std::string* getDestinationMessage();

		///Get awards.
		///@param itemName item's name from which award is being taken.
		///@return award amount.
		int getAwardAmount(std::string itemName);

		///Get needs.
		///@param itemName item's name from which needs is being taken.
		///@return needs amount.
		int getNeedsAmount(std::string itemName);
	};

}