#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <utility>
#include <map>

#include <cmath>

const uint32_t BOUND_POINTS = 10;

class Point
{
public:
    sf::CircleShape shape_handle;

    std::pair<float,float> position;

    Point(float distance): shape_handle(1.f) {}

    void reposition(float angle, float new_distance)
    {
        position.first  = new_distance * sin(angle);
        position.second = new_distance * cos(angle);

        shape_handle.setPosition({position.first, position.second});
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "LiDAR");

    // Initial point
    sf::CircleShape point(10.f, 3);
    point.setFillColor(sf::Color::Green);
    point.setPosition({400,400});

    std::map<float, Point> boundaries;

    boundaries.insert({30,4});

    // temp
    sf::CircleShape shape1(1.f);
    float i = 5;

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