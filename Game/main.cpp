#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Characters.h"
#include "Enemy.h"
#include "Entity.h"
#include "Player.h"
#include "UserInput.h"

using namespace std;

int main()
{
    // Init
    sf::RenderWindow window(sf::VideoMode(1024, 768), "Contra", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f, 512.0f));
    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);
    // Textures
    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/playerTexture.png");

    // Objects	
    sf::CircleShape circle(40); 
    circle.setOrigin(0, 0); 
    circle.setFillColor(sf::Color::Red);

    Enemy enemy(sf::Vector2f(400, 400), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 2), 0.2f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    // Main Game
    while (window.isOpen())
    {
	deltaTime = clock.restart().asSeconds();
	if(deltaTime > 1.0f / 60.0f)
	    deltaTime = 1.0f / 60.0f;

	sf::Event evnt;
	while (window.pollEvent(evnt))
	{
	    switch (evnt.type)
	    {
	    case sf::Event::Closed:
		window.close();
		break;
	    deafult:
		cout << "Event: " << evnt.type << endl;
	    }
	}
	// Update objects
	enemy.Update(deltaTime);
	

// Objects rendered before clear will not be visible
	window.clear();
//-----------------------------
	window.draw(circle);
	enemy.Draw(window);


	window.display();
    }
	
    window.close();

    return 0;
}
