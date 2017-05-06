#include "Player.h"


Player::Player(float health, float attackDamage, float movementSpeed, float jumpHeight,
	sf::Texture* texture, sf::Vector2i imageCount, float switchTime)
	: Characters(health, attackDamage, movementSpeed,  jumpHeight,
		texture, imageCount, switchTime)
{
}

Player::~Player()
{
}

void Player::Update(int deltaTime) const
{
}

void Player::Draw(sf::RenderWindow & window) const
{
	window.draw(body);
}
