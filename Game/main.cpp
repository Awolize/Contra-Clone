#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Characters.h"
#include "Enemy.h"
#include "Entity.h"
#include "Player.h"
#include "speed.h"
#include "UserInput.h"


bool pressedKey(bool pressed, sf::Keyboard::Key current, UserInput &keys)
{ 
	switch (current)
	{ 
	case ::sf::Keyboard::Escape: 
		return true; 
	default: 	
	keys.pressedKey(pressed, current); 	
	break; 
	} 
	return false; 
}

int main()
{
	sf::View Box;
	Box.reset(sf::FloatRect(200, 200, 300, 200));
	Box.setCenter(sf::Vector2f(350, 300));	
	sf::Texture texture;
	sf::CircleShape circle(40); 
	circle.setOrigin(0, 0); 
	sf::Vector2f circlePos(0, 0);
	circle.setFillColor(sf::Color::Red);
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Contra",
				sf::Style::Close | sf::Style::Resize);
        window.setKeyRepeatEnabled(false);
	window.setVerticalSyncEnabled(true);
	UserInput keys;
	bool quit = false;

	while (!quit)
	{
	    sf::Event event;
	    while (window.pollEvent(event))
	    {
		switch (event.type) 
		{
		case sf::Event::Closed:
		    quit = true;
		    break;
		case sf::Event::KeyPressed: 
		    quit |= pressedKey(true, event.key.code, keys); 		
		    break; 	
		case sf::Event::KeyReleased: 
		    quit |= pressedKey(false, event.key.code, keys); 
		    break;
		default:		
		    break;
		    std::cout << "Event: " << event.type << std::endl;
		    break;
		}


	    }

	    window.clear();
	    circlePos += keys.direction() * 2.0f;
	    circle.setPosition(circlePos);
	    window.draw(circle);
	    window.display();
	}
	
	window.close();

	return 0;
}
