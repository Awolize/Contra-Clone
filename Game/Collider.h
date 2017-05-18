#ifndef COLLIDER_H
#define COLLIDER_H
#include <SFML/Graphics.hpp>

class Collider
{
public:
    Collider(sf::RectangleShape & body);

    void Move(float dx, float dy) { body.move(dx, dy); }
    bool CheckCollision(Collider & other, sf::Vector2f & direction);

    sf::Vector2f GetPosition() { return body.getPosition(); } 
    sf::Vector2f GetSize() { return body.getSize(); }

private:
    sf::RectangleShape & body;
};

#endif
