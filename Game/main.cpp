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
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 768.0f));

    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);

    // Textures
    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/playerTexture.png");

    // Objects	
    sf::RectangleShape rec(sf::Vector2f(40.0f, 40.0f)); 
    rec.setOrigin(20.0f, 20.0f); 
    rec.setFillColor(sf::Color::Red);

    Enemy enemy(sf::Vector2f(400, 400), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 2), 0.2f);
    Player player(sf::Vector2f(200, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 2), 0.2f);

    float deltaTime = 0.0f;
    sf::Clock clock;

    // Main Game
    while (window.isOpen())
    {
	deltaTime = clock.restart().asSeconds();
	if(deltaTime > 1.0f / 60.0f)
	    deltaTime = 1.0f / 60.0f;

	sf::Event event;
	while (window.pollEvent(event))
	{
	    switch (event.type)
	    {
	    case sf::Event::Closed:
		window.close();
		break;
	    case sf::Event::KeyPressed:
		if (event.key.code == sf::Keyboard::Escape)
		    window.close();
		break;
	    case sf::Event::Resized:
		cout << "New width:  " << event.size.width << endl;
		cout << "New height: " << event.size.height << endl;
		break;
	    case sf::Event::TextEntered:
		if (event.text.unicode < 128)
		    cout << "ASCII chaaracter typed: " << static_cast<char>(event.text.unicode) << endl;
	    }
	}

	// Update objects
	enemy.Update(deltaTime);
	player.Update(deltaTime);
	
	view.setCenter(player.getPosition().x, 0);
// Objects rendered before clear will not be visible
	window.clear();
//-----------------------------
	window.draw(rec);
	enemy.Draw(window);
	player.Draw(window);

	window.setView(view);
	window.display();
    }
	
    window.close();

    return 0;
}
