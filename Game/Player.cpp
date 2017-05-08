#include "Player.h"
#include <iostream>
#include <vector>
#include <cmath>

Player::Player(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	sf::Texture* playerTexture, sf::Vector2i imageCount, float switchTime, sf::Texture* bulletTexture)
	: Characters(position, health, attackDamage, movementSpeed, jumpHeight),
	animation(playerTexture, imageCount, switchTime)
{
	body.setTexture(playerTexture);
	bullet.setTexture(bulletTexture);
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
	
	// velocity.y += 982.0f;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
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
	if (reloadTime > 0)
		reloadTime++;
	if (reloadTime > 100)
		reloadTime = 0;


	if ( isFiring == true && reloadTime == 0 )
	{
		if (faceRight)
		{
			gunPlacementX = body.getPosition().x + 45;
			bullet.faceRight = true;
		}
		else
		{
			gunPlacementX = body.getPosition().x - 55;
			bullet.faceRight = false;
		}
		bullet.setPosition(sf::Vector2f(gunPlacementX, body.getPosition().y + 5));
		bulletArray.push_back(bullet);
		reloadTime++;
	}

	for (Bullet& bullet : bulletArray)
		bullet.Update(deltaTime);

	animation.Update(row, deltaTime);
	body.setTextureRect(animation.xyRect);
	body.move(velocity * deltaTime);

	// Map Border (x-axis)
	if (body.getPosition().x < 15)
		body.setPosition(15, getPosition().y);
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(body);

	for (Bullet& bullet : bulletArray)
		bullet.Draw(window);
}

void Player::CheckCollision(Enemy & enemy)
{
	for (Bullet& bullet : bulletArray)
		enemy.CheckCollision(bullet);
}
