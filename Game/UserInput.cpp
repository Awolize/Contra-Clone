#include "UserInput.h"


void UserInput::pressedKey(bool pressed, sf::Keyboard::Key key)
{
	switch (key)
	{ 	
	case sf::Keyboard::W: 	
	    up = pressed; 	
	    break; 	
	case ::sf::Keyboard::S: 
	    down = pressed; 
	    break; 	
	case sf::Keyboard::A: 
	    left = pressed; 
	    break; 	
	case sf::Keyboard::D:
		right = pressed;
		break; 
	default: 	
	    break; 	
	} 
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
