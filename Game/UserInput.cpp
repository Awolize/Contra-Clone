#include "UserInput.h"


void input::moveDirection(sf::RectangleShape & Body)
{wd
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	moveRight(Body);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	moveLeft(Body);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	moveJump(Body);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	moveDrop(Body);

}

void input::moveRight(sf::RectangleShape & Body)
{
    upperBody.move(1, 0);
}

void input::moveLeft(sf::RectangleShape & Body)
{
    Body.move(-1, 0);
}

void input::moveJump(sf::RectangleShape & Body)
{
    Body.move(0, -1);
}

void input::moveDrop(sf::RectangleShape & Body)
{
    Body.move(0, 1);
}



sf::Vector2f UserInput::direction() const 
{ 
    sf::Vector2f dir; 
    if (up) 	
	dir.y -= 1.0f; 	
    if (down) 	
	dir.y += 1.0f; 
    if (left) 
	dir.x -= 1.0f; 	
    if (right) 
	dir.x += 1.0f; 	
    return (dir);
} 
