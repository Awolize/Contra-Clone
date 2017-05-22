#ifndef LAVA_H
#define LAVA_H
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "Entity.h"
#include "Characters.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"


class Lava
{
public:

    void entitySpawn()
    {
	enemyTexture.loadFromFile("images/Enemy.png");

	bullet.loadFromFile("images/bullet.png");

	enemyArray.push_back(Enemy(sf::Vector2f(700, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
	enemyArray.push_back(Enemy(sf::Vector2f(1200, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
	enemyArray.push_back(Enemy(sf::Vector2f(1500, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
	enemyArray.push_back(Enemy(sf::Vector2f(2500, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
	enemyArray.push_back(Enemy(sf::Vector2f(2900, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
	enemyArray.push_back(Enemy(sf::Vector2f(3500, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
	enemyArray.push_back(Enemy(sf::Vector2f(3900, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
	enemyArray.push_back(Enemy(sf::Vector2f(4500, 0), 100, 100, 10, 10, &enemyTexture, sf::Vector2i(3, 4), 0.2f, &bullet));
	

    }
/*
    void playerSpawn()
    {
	
    }
*/

// Platform Vector Array
    void levelLavaSpawn()
    {   
	background.loadFromFile("images/1.png");
	level1.setTexture(background);
	level1.setOrigin(500.0f, 300.0f);
	ground1.loadFromFile("images/level1ground.jpg");
	lava.loadFromFile("images/lava.png");
    
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(500, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(600, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(800, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1000, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1300, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1400, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1600, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1700, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(1800, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(2700, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(3200, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(3300, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(3400, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(3000, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(4000, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(4100, 400)));
	lavaArray.push_back(Platform(&lava, sf::Vector2f(100.0f, 250.0f), sf::Vector2f(4200, 400)));

    
//	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(100, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(200, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(300, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(400, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(700, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(900, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(1100, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(1200, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(1500, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(1900, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(2000, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(2500, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(2600, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(2800, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(2900, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3100, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3500, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3600, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3700, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3800, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(3900, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(4300, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(4400, 400)));
	platformArray.push_back(Platform(&ground1, sf::Vector2f(100.0f, 300.0f), sf::Vector2f(4500, 400)));
    }

    sf::Sprite getLevel1() { return level1;}
    std::vector<Platform> getLavaArray() { return lavaArray; }
    std::vector<Platform> getPlatformArray() { return platformArray; }
    std::vector<Enemy> getEnemyArray() { return enemyArray; }
    // Player getPlayer() { return player; }

private:
    std::vector<Platform> lavaArray;
    std::vector<Platform> platformArray;
    sf::Texture lava;
    sf::Texture ground1;
    sf::Sprite level1;
    sf::Texture background;
    sf::Texture enemyTexture;
    sf::Texture playerTexture;
    sf::Texture bullet;
    std::vector<Enemy> enemyArray;
    std::vector<Bullet> bulletVector;
    //   playerTexture.loadFromFile("images/playerTexture.png");
    //Player player(sf::Vector2f(200, -0), 100, 100, 400, 200, &playerTexture, sf::Vector2i(3, 4), 0.2f, &bullet);
};

#endif
