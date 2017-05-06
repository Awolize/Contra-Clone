#ifndef USERINPUT_H
#define USERINPUT_H
#include <SFML/Graphics.hpp>
#include "speed.h"

class UserInput
{
public:
    bool up, down, left, right;
    UserInput() : up(false), down(false), left(false), right(false) {} 
    void pressedKey(bool, sf::Keyboard::Key);
    sf::Vector2f direction() const;
};


#endif
