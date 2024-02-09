#include "View.h"
#include "../ViewModel/MainPageViewModel.h"
#include "../Model/CardEnums.h"
#include <iostream>

MainPage::MainPage()
{
    PageConfiguration();
    InitializingPlayers();

    while (mainWindow.isOpen())
    {
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                CloseMainPage();
        }

        mainWindow.clear();
        DrawComponents();
        mainWindow.display();
    }
}

void MainPage::PageConfiguration()
{
    mainWindow.create(sf::VideoMode(1200, 800), "Jogo de Truco - Curso C++ Unicamp");

    backgroundImage.loadFromFile("./Assets/main_bg.jpg");
    spriteBackground.setTexture(backgroundImage);
    spriteBackground.setScale(sf::Vector2f(1, 1));
}

void MainPage::InitializingPlayers()
{
    viewModel.InitializeDeck();
    viewModel.InitializePlayers();

    std::list<CardModel>::iterator it;
    std::vector<std::string> cardsImagesList;
    std::list<CardModel> hand = viewModel.GetP1().GetHand();

    for (auto const& i : hand)
    {
        cardsImagesList.insert(cardsImagesList.begin(), viewModel.TranslateCardIntoImageName(i));
    }

    WriteImages(cardsImagesList);
    //WriteSprites();
}

void MainPage::CloseMainPage()
{
    viewModel.Dispose();
    mainWindow.close();
}

void MainPage::DrawComponents()
{
    mainWindow.draw(spriteBackground);

    WriteSprites();
}

void MainPage::WriteImages(std::vector<std::string> cardsImagesList)
{
    for (std::string assetName : cardsImagesList) 
    {
        sf::Texture card;
        card.loadFromFile(assetName);
        card.setSmooth(true);
        cardsImages.push_back(card);
    }
}

void MainPage::WriteSprites()
{
    int x_position = 310;
    int y_position = 640;

    for (sf::Texture texture : cardsImages)
    {
        x_position += NEXT_POSITION;

        sf::Sprite sprite;
        sprite.setTexture(texture);
        sprite.setScale(sf::Vector2f(0.2, 0.2));
        sprite.setPosition(sf::Vector2f(x_position, y_position));

        mainWindow.draw(sprite);
    }

    //cardsImages.clear();
}
