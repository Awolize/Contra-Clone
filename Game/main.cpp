#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Characters.h"
#include "Enemy.h"
#include "Entity.h"
#include "Player.h"
// #include "Collider.h"
#include "Platform.h"

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
	float setview;
	std::vector<Enemy> enemyArray;
	enemyArray.push_back(Enemy(sf::Vector2f(400, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f));
	enemyArray.push_back(Enemy(sf::Vector2f(600, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f));
	enemyArray.push_back(Enemy(sf::Vector2f(800, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f));
	enemyArray.push_back(Enemy(sf::Vector2f(1000, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f));
	enemyArray.push_back(Enemy(sf::Vector2f(1200, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f));
	enemyArray.push_back(Enemy(sf::Vector2f(1400, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f));
	enemyArray.push_back(Enemy(sf::Vector2f(1600, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f));
	enemyArray.push_back(Enemy(sf::Vector2f(1800, 0), 100, 100, 10, 10, &playerTexture, sf::Vector2i(3, 4), 0.2f));

	Player player(sf::Vector2f(200, -500), 100, 100, 400, 200, &playerTexture, sf::Vector2i(3, 4), 0.2f, &bullet);
	std::vector<Bullet> bulletVector;

	// Platform Vector Array
	std::vector<Platform> platformArray;
	//	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	platformArray.push_back(Platform(nullptr, sf::Vector2f(2000.0f, 3.0f), sf::Vector2f(570, 57)));
	platformArray.push_back(Platform(nullptr, sf::Vector2f(100.0f, 3.0f), sf::Vector2f(700, -50)));
	platformArray.push_back(Platform(nullptr, sf::Vector2f(100.0f, 3.0f), sf::Vector2f(400, -100)));

	float deltaTime = 0.0f;
	sf::Clock clock;

	// Main Game
	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 60.0f)
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
		//-------------Update---------------
		player.Update(deltaTime);
		sf::Vector2f direction;
		for (Enemy & enemy : enemyArray)
		{
			enemy.Update(deltaTime);
			player.CheckHitEnemy(enemy);
			for (Platform & platform : platformArray)
			{
				Collider temp = enemy.GetCollider();
				if (platform.GetCollider().CheckCollision(temp, direction, 1.0f))
					enemy.OnCollision(direction);
			}
		}
		for (Platform & platform : platformArray)
		{
			Collider temp = player.GetCollider();
			if (platform.GetCollider().CheckCollision(temp, direction, 1.0f))
				player.OnCollision(direction);
		}

		//-------------View-----------------
		setview = player.getPosition().x;
		if (player.getPosition().x < 15)
			setview = 15;
		view.setCenter(setview, 85);
		//-------------Clear----------------
		window.clear(sf::Color(200, 0, 0));
		//-------------Draw-----------------
		window.draw(level1);
		for (Enemy& enemy : enemyArray)
			enemy.Draw(window);
		player.Draw(window);
		for (Platform& platform : platformArray)
			platform.Draw(window);
		window.setView(view);
		window.display();
	}

	window.close();

	return 0;
}
