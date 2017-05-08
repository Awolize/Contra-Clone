#include "Enemy.h"
#include <iostream>
#include <set>

Enemy::Enemy(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	sf::Texture* texture, sf::Vector2i imageCount, float switchTime)
	: Characters(position, health, attackDamage, movementSpeed, jumpHeight),
	animation(texture, imageCount, switchTime)
{
	body.setTexture(texture);
}

Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime)
{
	if (hit == false)
	{
		animation.Update(row, deltaTime);
		body.setTextureRect(animation.xyRect);
	}
}

void Enemy::Draw(sf::RenderWindow & window)
{
	if (hit == false)
		window.draw(body);
}

void Enemy::CheckCollision(Bullet & bullet)
{
	if (bullet.getRight() > body.getPosition().x &&
		bullet.getTop() < body.getPosition().y + body.getSize().y &&
		bullet.getBottom() > body.getPosition().y &&
		bullet.getLeft() < body.getPosition().x + body.getSize().x)
	{
		bullet.setBulletHit(true);
		hit = true;
		body.setPosition(sf::Vector2f(5000, 5000));
	}
}
