#include "View.h"
#include "../ViewModel/MainPageViewModel.h"
#include "../Model/CardEnums.h"

MainPage::MainPage()
{
    PageConfiguration();

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

    viewModel.InitializeDeck();
    viewModel.InitializePlayers();
    std::list<CardModel>::iterator it;
    std::vector<std::string> cardsImagesList;
    std::list<CardModel> hand = viewModel.GetP1().GetHand();
    for (auto const& i : hand)
    {
        cardsImagesList.insert(cardsImagesList.begin(), TranslateCardIntoImageName(i));
    }
    WriteImages(cardsImagesList[0], cardsImagesList[1], cardsImagesList[2]);
}

void MainPage::CloseMainPage()
{
    mainWindow.close();
    viewModel.Dispose();
}

void MainPage::DrawComponents()
{
    card1P1Sprite.setTexture(card1P1Image);
    card1P1Sprite.setScale(sf::Vector2f(0.2, 0.2));
    card1P1Sprite.setPosition(sf::Vector2f(430, 640));

    card2P1Sprite.setTexture(card2P1Image);
    card2P1Sprite.setScale(sf::Vector2f(0.2, 0.2));
    card2P1Sprite.setPosition(sf::Vector2f(550, 640));

    card3P1Sprite.setTexture(card3P1Image);
    card3P1Sprite.setScale(sf::Vector2f(0.2, 0.2));
    card3P1Sprite.setPosition(sf::Vector2f(670, 640));

    mainWindow.draw(spriteBackground);
    mainWindow.draw(card1P1Sprite);
    mainWindow.draw(card2P1Sprite);
    mainWindow.draw(card3P1Sprite);
}

void MainPage::WriteImages(std::string card1, std::string card2, std::string card3)
{
    card1P1Image.loadFromFile(card1);
    card1P1Image.setSmooth(true);

    card2P1Image.loadFromFile(card2);
    card2P1Image.setSmooth(true);

    card3P1Image.loadFromFile(card3);
    card3P1Image.setSmooth(true);
}

std::string MainPage::TranslateCardIntoImageName(CardModel card)
{
    std::string ret = "./Assets/";
    switch (card.GetCardNumber())
    {
    case CardEnums::Four:
        ret += "4";
        break;
    case CardEnums::Five:
        ret += "5";
        break;
    case CardEnums::Six:
        ret += "6";
        break;
    case CardEnums::Seven:
        ret += "7";
        break;
    case CardEnums::Queen:
        ret += "Q";
        break;
    case CardEnums::Jack:
        ret += "J";
        break;
    case CardEnums::King:
        ret += "K";
        break;
    case CardEnums::Ace:
        ret += "A";
        break;
    case CardEnums::Two:
        ret += "2";
        break;
    case CardEnums::Three:
        ret += "3";
        break;
    }

    ret += "_";
    switch (card.GetSuit()) {
    case CardEnums::Diamonds:
        ret += "ouro";
        break;
    case CardEnums::Spades:
        ret += "espadas";
        break;
    case CardEnums::Hearts:
        ret += "copa";
        break;
    case CardEnums::Clubs:
        ret += "paus";
        break;
    }

    ret += ".png";
    return ret;
}
