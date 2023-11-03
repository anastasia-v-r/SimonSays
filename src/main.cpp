#include <string>
#include <random>
#include <vector>
#include <iostream>

#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    std::vector<sf::RectangleShape> buttons(4, sf::RectangleShape{ sf::Vector2f{200.0f, 200.0f} });
    buttons[0].setPosition(sf::Vector2f(1920.0f / 4.0f, 1080.0f / 4.0f));
    buttons[1].setPosition(sf::Vector2f(1920.0f / 4.0f, (1080.0f / 4.0f) * 3));
    buttons[2].setPosition(sf::Vector2f((1920.0f / 4.0f) * 3, 1080.0f / 4.0f));
    buttons[3].setPosition(sf::Vector2f((1920.0f / 4.0f) * 3, (1080.0f / 4.0f) * 3));

    while (window.isOpen())
    {
        // Process Input
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            switch (event.type) 
            {
            case sf::Event::Closed:
            {
                window.close();
                break;
            }
            case sf::Event::KeyPressed:
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Backspace:
                    window.setSize(sf::Vector2u{ window.getSize().x - 100, window.getSize().y });
                    break;
                case sf::Keyboard::Space:
                    window.setSize(sf::Vector2u{ window.getSize().x + 100, window.getSize().y });
                    break;
                default:
                    window.setTitle(std::to_string([]() {std::random_device rd; std::mt19937 mt(rd()); std::uniform_real_distribution<double> dist(1.0, 100000.0); return dist(mt); }()));
                    break;
                }
                break;
            }
            case sf::Event::MouseButtonPressed:
            {
                bool objFound = false;
                for (auto& button : buttons)
                {
                    if (button.getGlobalBounds().contains(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y))
                    {
                        objFound = true;
                        button.setFillColor((button.getFillColor() != sf::Color::Blue) ? sf::Color::Blue : sf::Color::Red);
                    }
                }
                if (!objFound)
                    for (auto& button : buttons) { button.setFillColor(sf::Color::White); };
                break;
            }
            default:
                //std::cout << "Unrecognized command : " << event.type << std::endl;
                break;
            }
        }

        // Process Logic


        // Draw to Screen
        window.clear();
        for (const auto& button : buttons)
        {
            window.draw(button);
        }
        window.display();
    }
}