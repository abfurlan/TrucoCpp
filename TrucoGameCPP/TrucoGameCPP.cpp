#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1600, 1200), "Jogo de Truco - Curso C++ Unicamp");
    sf::Texture background;
    background.loadFromFile("./Assets/bg.jpg");
    sf::Sprite sprite(background);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}