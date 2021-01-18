#include "GuiPanel.h"

MP::GuiPanel::GuiPanel(sf::Texture* texturePtr, sf::Font& aFont)
{
	aAnimation.loadObjectTextures(texturePtr, 1, 1, 785);
	_panel_title.setFont(aFont);
	_panel_title.setLetterSpacing(1);
	_panel_title.setCharacterSize(37);
	_panel_title.setFillColor(sf::Color(224, 224, 224));
}

void MP::GuiPanel::update(sf::Vector2f panelPosition, std::string panelName)
{
	_panel_title.setString(panelName);
	_panel_title.setPosition(panelPosition+sf::Vector2f(268,57));
	setObjectCoord(panelPosition);
}

void MP::GuiPanel::render(sf::RenderWindow& mainWindow)
{
	mainWindow.draw(aAnimation.getObjectSprite());
	mainWindow.draw(_panel_title);
}
