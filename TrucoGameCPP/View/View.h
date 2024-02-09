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

	const int NEXT_POSITION = 120;
	sf::RenderWindow mainWindow;
	sf::Texture backgroundImage;
	sf::Sprite spriteBackground;
	std::list<sf::Texture> cardsImages;
	std::list<sf::Sprite> cardsSprites;

	void PageConfiguration();
	void InitializingPlayers();
	void CloseMainPage();
	void DrawComponents();
	void WriteImages(std::vector<std::string> cardsImagesList);
	void WriteSprites();
	std::string TranslateCardIntoImageName(CardModel card);
};