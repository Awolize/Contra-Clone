#include "Bullet.h"

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

void Bullet::Draw(sf::RenderWindow & window)
{
	spriteExplosion.setPosition(body.getPosition().x - 12.5, body.getPosition().y - 12.5);
	if (bulletHit == false)
		window.draw(body);
	if (animationExplosion == true && bulletHit == true)
		window.draw(spriteExplosion);
}

void Bullet::Update(float deltaTime)
{
	if (bulletHit == false)
		if (faceRight)
			body.move(velocity * deltaTime, 0);
		else
			body.move(-velocity * deltaTime, 0);
	else
	{		
		explosionTime++;
		if (explosionTime == 20)
			animationExplosion = false;
	}
}

