#pragma once

#include <SFML/Graphics.hpp>

class MainPage
{
public:
	MainPage();

private:
	sf::RenderWindow mainWindow;
	sf::Texture backgroundImage;
	sf::Sprite spriteBackground;
	sf::Texture card1P1Image;
	sf::Sprite card1P1Sprite;
	sf::Texture card2P1Image;
	sf::Sprite card2P1Sprite;
	sf::Texture card3P1Image;
	sf::Sprite card3P1Sprite;

	void PageConfiguration();
	void CloseMainPage();
	void DrawComponents();
	void WriteImages();
};