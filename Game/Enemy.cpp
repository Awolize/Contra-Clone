#include "Enemy.h"



Enemy::Enemy(float health, float attackDamage, float movementSpeed, float jumpHeight, 
	     sf::Texture* texture, sf::Vector2u imageCount, float switchTime) 
// : animation(texture, imageCount, switchTime)
{
}

Enemy::~Enemy()
{
}

void Entity::Update(int deltaTime)
{
    
}

void Entity::Draw(sf::RenderWindow& window)
{
    window.draw(body);
}
