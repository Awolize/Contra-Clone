#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>


using namespace std;

Bullet::Bullet()
{
    body.setSize(sf::Vector2f(25, 25));
    body.setOrigin(sf::Vector2f(body.getSize() / 2.0f));

    explosion.loadFromFile("images/explosion.png");
    spriteExplosion.setTexture(explosion);
    spriteExplosion.setScale(sf::Vector2f(3.4, 3.4));
}

Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime)
{
    if (bulletHit == false)
    {
	spriteExplosion.setPosition(body.getPosition().x - 12.5, body.getPosition().y - 12.5);
	float temp = time.asSeconds();
	temp -= deltaTime;
	time = sf::seconds(temp);

	if (time.asSeconds() < 0)
	    bulletHit = true;
	if (faceRight)
	{
	    if (direction == -2)
		body.move(velocity * deltaTime, velocity * deltaTime);
	    else if (direction == -1)
		body.move(velocity * deltaTime, velocity * deltaTime / 2);
	    else if (direction == 0)
		body.move(velocity * deltaTime, 0);
	    else if (direction == 1)
		body.move(velocity * deltaTime, -(velocity * deltaTime / 2));
	    else if (direction == 2)
		body.move(velocity * deltaTime, -(velocity * deltaTime));
	}
	else
	{
	    if (direction == -2)
		body.move(-(velocity * deltaTime), velocity * deltaTime);
	    else if (direction == -1)
		body.move(-(velocity * deltaTime), velocity * deltaTime / 2);
	    else if (direction == 0)
		body.move(-(velocity * deltaTime), 0);
	    else if (direction == 1)
		body.move(-(velocity * deltaTime), -(velocity * deltaTime / 2));
	    else if (direction == 2)
		body.move(-(velocity * deltaTime), -(velocity * deltaTime));
	}
    }
    else
    {
	if(animationExplosion)
	{
	    if(explosionTime.asSeconds() > explosionTime0)
	    {
		body.setPosition(sf::Vector2f(6000, 6000));
	    }
	    velocity = 0;
	    if (explosionTime.asSeconds() < 0.0)
	    {
		animationExplosion = false;
		spriteExplosion.setPosition(sf::Vector2f(6000, 6000));
	    }
	    float temp = explosionTime.asSeconds();
	    temp -= deltaTime;
	    explosionTime = sf::seconds(temp);
	}
    }
}

void Bullet::Draw(sf::RenderWindow & window)
{
    if (bulletHit == false)
	window.draw(body);
    if (animationExplosion == true && bulletHit == true)
	window.draw(spriteExplosion);
}

