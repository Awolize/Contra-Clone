#ifndef COLLISION_H
#define COLLISION_H
#include <SFML/Graphics.hpp>
#include "Player.h"

bool ifCollision(sf::FloatRect &,sf::FloatRect &);
void checkCollision(Player &, sf::RectangleShape &, float &);

#endif