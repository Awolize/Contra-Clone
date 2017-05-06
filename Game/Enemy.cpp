#include "Enemy.h"



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

void Enemy::Update(int deltaTime)
{
    animation.Update(row, deltaTime);
    body.setTextureRect(animation.xyRect);
}

void Enemy::Draw(sf::RenderWindow & window)
{
    window.draw(body);
}
