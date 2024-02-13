#pragma once

#include "../Model/CardModel.h"
#include "../ViewModel/MainPageViewModel.h"
#include <SFML/Graphics.hpp>
#include <list>

class MainPage
{
public:
	MainPage();

private:
	MainPageViewModel viewModel;

	const int SCREEN_WIDTH = 1200;
	const int SCREEN_HEIGHT = 800;
	const int NEXT_POSITION = 120;
	sf::RenderWindow mainWindow;
	sf::Texture backgroundImage;
	sf::Sprite spriteBackground;
	sf::Texture cardPileImage;
	sf::Sprite spriteCardPile;
	sf::Texture manillaImage;
	sf::Sprite spriteManilla;
	std::list<sf::Texture> cardsImages;
	std::list<sf::Sprite> cardsSprites;
	CardModel manilla;

	void PageConfiguration();
	void InitializingPlayers();
	void CloseMainPage();
	void DrawComponents();
	void WriteImages(std::list<std::string> cardsImagesList);
	void WritePlayerSprites();
	std::string TranslateCardIntoImageName(CardModel card);
};