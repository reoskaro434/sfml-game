#include "SFML/Graphics.hpp"
#include "Engine/ConfigurationLoader.h"
#include "RiDmain.h"


int main()
{
 
    RiD::RiDmain window(RiD::ConfigurationLoader::getIntData("video settings", "screenWidth"), RiD::ConfigurationLoader::getIntData("video settings", "screenHeight"), RiD::ConfigurationLoader::getStringData("video settings", "screenTitle"));

       return 0;
}