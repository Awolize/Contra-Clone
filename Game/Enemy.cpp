#include "Enemy.h"



Enemy::Enemy(float health, float attackDamage, float movementSpeed, float jumpHeight,
	sf::Texture* texture, sf::Vector2i imageCount, float switchTime)
	: Characters(health, attackDamage, movementSpeed,  jumpHeight,
		texture, imageCount, switchTime)
{
}

Enemy::~Enemy()
{
}

void Enemy::Update(int deltaTime) const
{
}

void Enemy::Draw(sf::RenderWindow & window) const
{
	window.draw(body);
}
