#include "Player.h"
#include <iostream>
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
    std::cout << row;
    velocity.x = 0.0f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	velocity.x -= movementSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	velocity.x += movementSpeed;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	// collision = false;;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
    {
	canJump = false;

	velocity.y = -sqrtf(2.0f * 982.0f * jumpHeight);
    }
//    velocity.y += 982.0f * deltaTime;
    
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

    animation.Update(row, deltaTime);
    body.setTextureRect(animation.xyRect);
    body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow & window)
{
    window.draw(body);
}
