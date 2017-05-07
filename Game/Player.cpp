#include "Player.h"
#include <iostream>
#include <vector>
#include <cmath>

Player::Player(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	sf::Texture* texture, sf::Vector2i imageCount, float switchTime)
	: Characters(position, health, attackDamage, movementSpeed, jumpHeight),
	animation(texture, imageCount, switchTime)
{
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	velocity.x = 0.0f;
	isFiring = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		// collision = false;;
		std::cout << "";
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;

		velocity.y = -sqrtf(2.0f * 982.0f * jumpHeight);
	}
	//    velocity.y += 982.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::L))
	{
		isFiring = true;
	}
	

	if (velocity.x == 0.0f)
		if (faceRight == true)
			row = 0;
		else
			row = 1;
	else
	{
		if (velocity.x > 0.0f)
		{
			row = 2;
			faceRight = true;
		}
		else
		{
			row = 3;
			faceRight = false;
		}
	}

	if (isFiring == true)
	{
		bullet.setPosition(sf::Vector2f(body.getPosition().x + 10.0f, body.getPosition().y));
		BulletArray.push_back(bullet);
	}


	for (Bullet& projectile : BulletArray)
		bullet.Update(deltaTime);

	animation.Update(row, deltaTime);
	body.setTextureRect(animation.xyRect);
	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow & window)
{
	for (Bullet& projectile : BulletArray)
		bullet.Draw(window);

	window.draw(body);
}

void Player::CheckCollision(Bullet bullet)
{
	if (bullet.getRight() > body.getPosition().x &&
		bullet.getTop() < body.getPosition().y + body.getSize().y &&
		bullet.getBottom() > body.getPosition().y)
	{
		bullet.setBulletHit(true);
		body.setPosition(sf::Vector2f(0, 10000));
	}
}
