#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Characters.h"
#include "Enemy.h"
#include "Entity.h"
#include "Player.h"


using namespace std;

int main()
{
    // Init
    sf::RenderWindow window(sf::VideoMode(1024, 581), "Contra", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1024.0f, 768.0f));

    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);

    // Define Textures
	sf::Texture bullet;
	bullet.loadFromFile("images/bullet.png");

    sf::Texture playerTexture;
    playerTexture.loadFromFile("images/playerTexture.png");

    sf::Texture background;
    background.loadFromFile("images/7680.png");

    sf::Sprite level1;
    level1.setTexture(background);
    level1.setOrigin(500.0f, 300.0f);

    // Define Objects	
    Enemy enemy(sf::Vector2f(400, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f);
    Player player(sf::Vector2f(200, 0), 100, 100, 400, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f, &bullet);
	std::vector<Bullet> bulletVector;
    
    sf::RectangleShape ground(sf::Vector2f(2000.0f, 40.0f));
	ground.setPosition(0, 70);
    ground.setOrigin(1000, 20);
    ground.setFillColor(sf::Color::Green);

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

	player.CheckCollision(enemy);

	view.setCenter(player.getPosition().x, 85);
// Objects rendered before clear will not be visible
	window.clear(sf::Color(200, 0, 0));
//-----------------------------
	window.draw(level1);
	window.draw(ground);

	enemy.Draw(window);
	player.Draw(window);

	window.setView(view);
	window.display();
    }
	
    window.close();

    return 0;
}
