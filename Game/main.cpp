#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Characters.h"
#include "Enemy.h"
#include "Entity.h"
#include "Player.h"
#include "Collision.h"




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

    sf::Texture background;
    background.loadFromFile("images/7680.png");

<<<<<<< HEAD
=======
    sf::Texture bullet;
    bullet.loadFromFile("images/bullet.png");

    sf::Sprite projectile;
    projectile.setTexture(bullet);

    sf::Vector2f bulletpos;
    projectile.setPosition(bulletpos);

    projectile.setScale(sf::Vector2f(0.2f, 0.2f));
    //projectile.scale(sf::Vector2f(1.5f, 3.f));


>>>>>>> master
    sf::Sprite level1;
    level1.setTexture(background);
    level1.setOrigin(500.0f, 300.0f);

    // Objects	
<<<<<<< HEAD
    sf::RectangleShape rec(sf::Vector2f(40.0f, 40.0f)); 
    rec.setOrigin(10.0f, 20.0f); 
    rec.setFillColor(sf::Color::Red);
    
    sf::RectangleShape ground(sf::Vector2f(2000.0f, 40.0f));
    ground.setOrigin(200, -290);
    ground.setFillColor(sf::Color::Green);

    Enemy enemy(sf::Vector2f(400, 400), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 2), 0.2f);
=======
    Enemy enemy(sf::Vector2f(400, 400), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f);
    Player player(sf::Vector2f(200, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f);
>>>>>>> origin/aleer778


    sf::RectangleShape rec(sf::Vector2f(40.0f, 40.0f)); 
    rec.setOrigin(10.0f, 20.0f); 
    rec.setFillColor(sf::Color::Red);

    
    sf::RectangleShape ground(sf::Vector2f(20000.0f, 40.0f));
    ground.setOrigin(200, -50);
    ground.setFillColor(sf::Color::Transparent);

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
	checkCollision(player, ground, deltaTime);
//-----------------------------
<<<<<<< HEAD
<<<<<<< HEAD
	window.draw(level1);
	window.draw(ground);
	window.draw(rec);
=======
>>>>>>> origin/aleer778
=======
	window.draw(level1);
	window.draw(ground);
//	window.draw(rec);

	//projectile.setPosition(bulletpos);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
	  projectile.setPosition(bulletpos);
	  window.draw(projectile);
	  bulletpos.x += 20;
	}
	if (!(sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
	  bulletpos.x = player.getPosition().x;
	  bulletpos.y = player.getPosition().y - 60;
	}


>>>>>>> master
	enemy.Draw(window);
	player.Draw(window);

	window.setView(view);
	window.display();

	
    }
	
    window.close();

    return 0;
}
