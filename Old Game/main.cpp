#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Player.h"
#include "Platform.h"
#include "Projectile.h"
#include "Enemy.h"

using namespace std;


static const float VIEW_HEIGHT = 1024.0f;

void ResizedView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML", sf::Style::Close | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f,0.0f), sf::Vector2f(512.0f, 512.0f));
    sf::Texture playerTexture;
    playerTexture.loadFromFile("playerTexture.png");
    //			  texture,	   imageCount,  switchTime,	speed, jumpHeight);
    Player player(&playerTexture, sf::Vector2u(5, 2), 0.2f, 350.0f, 400.0f);

    Enemy enemy(&playerTexture, sf::Vector2u(5, 2), 0.2f, 350.0f, 400.0f);

    // Platform Vector Array
    std::vector<Platform> platformArray;
    platformArray.push_back(Platform(&playerTexture, sf::Vector2f(400.0f, 20.0f), sf::Vector2f(1550.0f, 400.0f)));
    platformArray.push_back(Platform(nullptr, sf::Vector2f(400.0f, 20.0f), sf::Vector2f(650.0f, 700.0f)));
    platformArray.push_back(Platform(nullptr, sf::Vector2f(10000.0f, 20.0f), sf::Vector2f(450.0f, 1000.0f)));
	
    // Platform Vector Array

    float deltaTime = 0.0f;
    sf::Clock clock;

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
	    case sf::Event::TextEntered:
		if (evnt.text.unicode < 128)
		    printf("%c", evnt.text.unicode);
		break;
	    case sf::Event::Resized:
		ResizedView(window, view);
		break;
	    }
	}

	player.Update(deltaTime);
	enemy.Update(deltaTime);

	sf::Vector2f direction;

	for (Platform& platform : platformArray)
	{
	    Collider temp1 = player.GetCollider();
	    if (platform.GetCollider().CheckCollision(temp1, direction, 1.0f))
	    {
		player.OnCollision(direction);
	    }
	    Collider temp2 = enemy.GetCollider();
	    if (platform.GetCollider().CheckCollision(temp2, direction, 1.0f))
	    {
		enemy.OnCollision(direction);
	    }
	}

	view.setCenter(player.getPosition());

	window.clear(sf::Color(150, 150, 150));
	//window.draw(background);
	window.setView(view);
	player.Draw(window);
	enemy.Draw(window);

	for (Platform& platform : platformArray)
	    platform.Draw(window);
	window.display();
    }
    return 0;
}
