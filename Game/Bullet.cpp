#include "Bullet.h"



Bullet::Bullet()
{
	body.setSize(sf::Vector2f(20, 20));
	body.setFillColor(sf::Color::White);
}

Bullet::Bullet(float velocity) : velocity{ velocity }
{
}


Bullet::~Bullet()
{
}

void Bullet::Update(float deltaTime)
{
	body.move(velocity*deltaTime, 0);
}

void Bullet::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}
