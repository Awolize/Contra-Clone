#include "Projectile.h"



Projectile::Projectile()
{
	body.setSize(sf::Vector2f(10, 10));
	body.setFillColor(sf::Color::Black);
	//	body.setTexture();
}

Projectile::~Projectile()
{
}

void Projectile::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Projectile::Update(float deltaTime)
{
	if (faceRight)
	{
		body.move(bulletVelocity);
	}
	else
	{
		body.move(-bulletVelocity);
//		body.move(-abs(velocity.x * deltaTime), body.getPosition.y);
	}
	
}

