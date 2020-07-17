#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "LiDAR");

    sf::CircleShape point(10.f, 3);

    point.setFillColor(sf::Color::Green);
    point.setPosition({400,400});

    sf::CircleShape shape1(1.f);

    float i = 5;
    shape1.setPosition({i,i});

    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                // draw circle
                shape1.move({i+10,i+10});
                std::cout << "something ahppended" << std::endl;
            }
            
        }

        window.clear();
        window.draw(shape1);
        window.draw(point);
        window.display();
    }

    return 0;
}