#include <string>
#include <random>

#include <SFML/Graphics.hpp>

int main()
{
    auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        // Process Input
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            switch (event.type) 
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    window.close();
                    break;
                case sf::Keyboard::Backspace:
                    window.setSize(sf::Vector2u{window.getSize().x - 100, window.getSize().y});
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
        }

        // Process Logic
        

        // Draw to Screen
        window.clear();
        window.display();
    }
}