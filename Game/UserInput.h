#ifndef USERINPUT_H
#define USERINPUT_H
#include <SFML/Graphics.hpp>



class UserInput
{
public:
    bool up, down, left, right;
    
    UserInput() : up(false), down(false), left(false), right(false) {}

    void onKey(bool pressed, sf::Keyboard::Key key) {
	switch (key) { 	
	case sf::Keyboard::Up: || sf::Keyboard::W: 	
	    up = pressed; 		
	    break; 	
	case sf::Keyboard::Down: 
	case ::sf::Keyboard::S: 
	    down = pressed; 
	    break; 	
	case sf::Keyboard::Left: 
	case sf::Keyboard::A: 	
	    left = pressed; 	
	    break; 		case sf::Keyboard::Right: 
	case sf::Keyboard::D: 		
	    right = pressed; 		
	    break; 	
	default: 
	    break; 	
	} 
    }



private:

}

#endif
