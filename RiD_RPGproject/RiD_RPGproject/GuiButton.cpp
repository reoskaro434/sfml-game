#include "GuiButton.h"


MP::GuiButton::GuiButton(RiD::AssetManager& aAssetManager, sf::Vector2f buttonPosition,sf::Vector2f relativelyTextPosition, std::string buttonName)
{

	aAnimation.loadObjectTextures(&aAssetManager.getTexture("button"), 2, 1, 275);
	setObjectCoord(buttonPosition);
	_a_text.setFont(aAssetManager.getFont("font"));
	sf::Vector2f realTextPostion = buttonPosition;
	realTextPostion.x += 70;
	realTextPostion.y += 115;

	realTextPostion.x += relativelyTextPosition.x;
	realTextPostion.y += relativelyTextPosition.y;
	_a_text.setPosition(realTextPostion);
	_a_text.setString(buttonName);
	_a_text.setLetterSpacing(1.5);
	_a_text.setCharacterSize(30);
	_is_active = false;
	_was_played = false;

}

sf::Text & MP::GuiButton::getText()
{
	return _a_text;
}

void MP::GuiButton::set_button_active(bool isActive)
{
	if (isActive == true)
		aAnimation.changeSprite(0);
	else
		aAnimation.changeSprite(1);

	_is_active = isActive;
	if (!isActive)
		_was_played=isActive;
}

void MP::GuiButton::_song_procedure(MP::SoundManager& aSoundManager, MP::TaskManager& aMainTaskManager)
{
	if (_is_active)
	{	
		if (!_was_played)
		{
			_sound_player.playSound(aSoundManager.getSound("activeButtonSound"));
			_was_played = true;
		}
		if(aMainTaskManager.findTask(TaskNode::taskType::LEFT_MOUSE_BUTTON,false))
		_sound_player.playSound(aSoundManager.getSound("pressedButtonSound"));
	}
}

bool MP::GuiButton::getButtonIsActive()
{
	return _is_active;
}

void MP::GuiButton::draw_button(sf::RenderWindow& mainWindow)
{

	mainWindow.draw(aAnimation.getObjectSprite());
	mainWindow.draw(_a_text);
}

void MP::GuiButton::setButtonPosition(sf::Vector2f newPostion)
{	
	sf::Vector2f oldTextPosition =_a_text.getPosition();
	sf::Vector2f oldObjCoord = getObjectCoord();

	setObjectCoord(newPostion);

	newPostion.x+= oldTextPosition.x - oldObjCoord.x;
	newPostion.y+= oldTextPosition.y - oldObjCoord.y;

	_a_text.setPosition(newPostion);
}

void MP::GuiButton::update(SoundManager &aSoundManager,TaskManager &aTaskManager,bool isActive)
{
	_song_procedure(aSoundManager, aTaskManager);
	set_button_active(isActive);
}

void MP::GuiButton::render(sf::RenderWindow& mainWindow)
{
	draw_button(mainWindow);
}
