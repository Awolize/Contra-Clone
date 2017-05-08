#include "Bullet.h"

Bullet::Bullet()
{
	body.setSize(sf::Vector2f(25, 25));
//	body.setFillColor(sf::Color::Magenta);
	//	body.setTexture();
}

Bullet::~Bullet()
{
}

void Bullet::Draw(sf::RenderWindow & window)
{
	if (bulletHit == false)
		window.draw(body);
}

void Bullet::Update(float deltaTime)
{
	if (bulletHit == false)
		if (faceRight)
			body.move(velocity * deltaTime, 0);
		else
			body.move(-velocity * deltaTime, 0);
}

