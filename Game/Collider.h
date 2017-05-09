#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
    Collider(sf::RectangleShape& body);
    ~Collider();

    sf::Vector2f GetPosition() { return body.getPosition(); }
    sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

    bool CheckCollision(sf::RectangleShape & otherBody)

private:
    sf::RectangleShape& body;
};
