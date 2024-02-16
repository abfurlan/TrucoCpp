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
            
            if (event.type == sf::Event::MouseButtonPressed) 
            {
                std::cout << "Mouse pressed" << std::endl;
            }
             
        }

        mainWindow.clear();
        DrawComponents();
        mainWindow.display();
    }
}

void MainPage::PageConfiguration()
{
    mainWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Jogo de Truco - Curso C++ Unicamp");

    backgroundImage.loadFromFile("./Assets/main_bg.jpg");
    spriteBackground.setTexture(backgroundImage);
    spriteBackground.setScale(sf::Vector2f(1, 1));

    cardPileImage.loadFromFile("./Assets/Card_pile.png");
    spriteCardPile.setTexture(cardPileImage);
    spriteCardPile.setScale(sf::Vector2f(0.25, 0.25));
    spriteCardPile.setPosition(sf::Vector2f(1020, 310));
}

void MainPage::InitializingPlayers()
{
    viewModel.InitializeDeck();
    viewModel.InitializePlayers();

    std::list<CardModel>::iterator it;
    std::list<std::string> cardsImagesList;
    std::list<CardModel> p1Hand = viewModel.GetP1().GetHand();
    std::list<CardModel> pcHand = viewModel.GetP2().GetHand();
    manilla = viewModel.PickRandomCard();
    viewModel.SetManilla(manilla.GetCardNumber());

    for (auto const& i : p1Hand)
    {
        cardsImagesList.push_back(viewModel.TranslateCardIntoImageName(i));
    }

    for (auto const& i : pcHand)
    {
        cardsImagesList.push_back(viewModel.TranslateCardIntoImageName(i));
    }

    cardsImagesList.push_back(viewModel.TranslateCardIntoImageName(manilla));

    WriteImages(cardsImagesList);
    //viewModel.Player1WonTheRound(viewModel.PickRandomCard(), viewModel.PickRandomCard(), viewModel.PickRandomCard());
    //viewModel.p1PlayedCard = viewModel.PickRandomCard();
    //CardModel botCard = viewModel.BotPlayCard(1, false, 0);
    //viewModel.BotAcceptTruco(2, 1);
}

void MainPage::CloseMainPage()
{
    viewModel.Dispose();
    mainWindow.close();
}

void MainPage::DrawComponents()
{
    mainWindow.draw(spriteBackground);
    mainWindow.draw(spriteCardPile);
    WritePlayerSprites();
}

void MainPage::WriteImages(std::list<std::string> cardsImagesList)
{
    manillaImage.loadFromFile(viewModel.TranslateCardIntoImageName(manilla));

    for (std::string assetName : cardsImagesList) 
    {
        sf::Texture card;
        card.loadFromFile(assetName);
        card.setSmooth(true);
        cardsImages.push_back(card);
    }
}

void MainPage::WritePlayerSprites()
{
    int x_positionP1 = 310;
    int y_positionP1 = 640;
    int x_positionP2 = 310;
    int y_positionP2 = 10;
    int index = 0;

    for (sf::Texture texture : cardsImages)
    {
        if (index <= 2)
        {
            x_positionP1 += NEXT_POSITION;

            sf::Sprite sprite;
            sprite.setTexture(texture);
            sprite.setScale(sf::Vector2f(0.2, 0.2));
            sprite.setPosition(sf::Vector2f(x_positionP1, y_positionP1));

            mainWindow.draw(sprite);

            index++;
        }

        else if (index <= 5)
        {
            x_positionP2 += NEXT_POSITION;

            sf::Texture card;
            card.loadFromFile("./Assets/Back_cards.png");
            card.setSmooth(true);
            cardsImages.push_back(card);

            sf::Sprite sprite;
            sprite.setTexture(card);
            sprite.setScale(sf::Vector2f(0.2, 0.2));
            sprite.setPosition(sf::Vector2f(x_positionP2, y_positionP2));

            mainWindow.draw(sprite);

            index++;
        }
        else
        {
            spriteManilla.setTexture(manillaImage);
            spriteManilla.setScale(sf::Vector2f(0.25, 0.25));
            spriteManilla.setPosition(sf::Vector2f(870, 310));

            mainWindow.draw(spriteManilla);
        }

    }
}
