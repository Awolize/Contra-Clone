#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	     sf::Texture* texture, sf::Vector2i imageCount, float switchTime)
    : Characters(position, health, attackDamage, movementSpeed, jumpHeight),
      animation(texture, imageCount, switchTime)
{
    body.setTexture(texture);
    body.setOrigin(sf::Vector2f(body.getSize() / 2.0f));
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

void Enemy::CheckIfHit(Bullet & bullet)
{
    if ((bullet.getGravityPositionX() + (bullet.getSizeX() / 2) > body.getPosition().x - (body.getSize().x / 2) &&
	 bullet.getGravityPositionX() - (bullet.getSizeX() / 2) < body.getPosition().x + (body.getSize().x / 2))
	&&
	(bullet.getGravityPositionY() + (bullet.getSizeY() / 2) > body.getPosition().y - (body.getSize().y / 2) &&
	 bullet.getGravityPositionY() - (bullet.getSizeY() / 2) < body.getPosition().y + (body.getSize().y / 2)))
    {
	bullet.setBulletHit(true);
	hit = true;
	body.setPosition(sf::Vector2f(5000, 5000));
    }
}
