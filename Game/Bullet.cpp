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
		velocity = 0;
		explosionTime++;
		if (explosionTime == 20)
		{
			animationExplosion = false;
			body.setPosition(sf::Vector2f(6000, 6000));
		}
	}
}

void Bullet::Draw(sf::RenderWindow & window)
{
	spriteExplosion.setPosition(body.getPosition().x - 12.5, body.getPosition().y - 12.5);
	if (bulletHit == false)
		window.draw(body);
	if (animationExplosion == true && bulletHit == true)
		window.draw(spriteExplosion);
}

