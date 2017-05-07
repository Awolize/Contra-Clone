#ifndef USERINPUT_H
#define USERINPUT_H
#include <SFML/Graphics.hpp>

class UserInput
{
public:
    bool up, down, left, right;
    UserInput() : up(false), down(false), left(false), right(false) {}
    void moveDirection(sf::RectangleShape &);
    sf::Vector2f direction() const;
private:
    void moveRight(sf::RectangleShape &);
    void moveLeft(sf::RectangleShape &);
    void moveJump(sf::RectangleShape &);
    void moveDrop(sf::RectangleShape &);
};


#endif
