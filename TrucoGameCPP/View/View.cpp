#include "View.h"

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
}

void MainPage::CloseMainPage()
{
    mainWindow.close();
}

void MainPage::DrawComponents()
{
    WriteImages();

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

void MainPage::WriteImages()
{
    card1P1Image.loadFromFile("./Assets/3_paus.png");
    card1P1Image.setSmooth(true);

    card2P1Image.loadFromFile("./Assets/A_ouro.png");
    card2P1Image.setSmooth(true);

    card3P1Image.loadFromFile("./Assets/K_espadas.png");
    card3P1Image.setSmooth(true);
}
