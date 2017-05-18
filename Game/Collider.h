#pragma once
#include <SFML/Graphics.hpp>

class Collider
{
public:
    Collider(sf::RectangleShape & body);
    ~Collider();

    void Move(float dx, float dy) { body.move(dx, dy); }
    bool CheckCollision(Collider & other, sf::Vector2f & direction);

    sf::Vector2f GetPosition() { return body.getPosition(); } 
    sf::Vector2f GetSize() { return body.getSize(); }

private:
    sf::RectangleShape & body;
};
