#include "Boss.h"
#include <random>
#include <iostream>

Boss::Boss(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	   sf::Texture* enemyTexture, sf::Vector2i imageCount, float switchTime, sf::Texture* bulletTexture)
    : Characters(position, health, attackDamage, movementSpeed, jumpHeight),
      animation(enemyTexture, imageCount, switchTime)
{
    body.setSize(sf::Vector2f(200, 200));
    body.setTexture(enemyTexture);
    bullet.setTexture(bulletTexture);
    body.setOrigin(sf::Vector2f(body.getSize() / 2.0f));
}

Boss::~Boss()
{
}

void Boss::bossIntelligence(sf::Vector2f distance)
{


    if(bossActivated)
    {

	if (distance.x < 200 && distance.x > 0)
	{
	    isFiring = true;

	    passiveMode = true;
	}

	if((distance.x < 50 && body.getPosition().y > -100) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && body.getPosition().y > -100))  
	{
	    canJump = true;
	    movementSpeed = 500;

	    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	    {
		canJump = false;
	    }
	}
	else
	{
	    if (distance.x > 150 && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	    {
		movementSpeed = -300;
		passiveMode = false;
	    }
	    else if(distance.x > 150 && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	    {
		movementSpeed = 300;
	    }
	}

	if(body.getPosition().x > 7600)
	{
	    movementSpeed = 300;
	}
	else if(body.getPosition().x < 7000)
	{
	    movementSpeed = -300;
	}

	if (canJump)
	{
	    velocity.y = -sqrtf(2.0f * 982.0f * 100);
	    canJump = false;
	}

    }
}



void Boss::Update(float deltaTime)
{
    if (lives > 0)
    {
	velocity.x = 0.0f;
	//	isFiring = true;
	velocity.x -= movementSpeed;

	velocity.y += 982.0f * deltaTime;

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
	    reloadTime *= deltaTime;
	if (reloadTime > 20)
	    reloadTime = 0;

	if (isFiring == true && reloadTime == 0)
	{
	    if (faceRight)
	    {
		gunPlacementX = body.getPosition().x + 55;
		bullet.faceRight = true;
	    }
	    else
	    {
		gunPlacementX = body.getPosition().x - 55;
		bullet.faceRight = false;
	    }
	    bullet.setPosition(sf::Vector2f(gunPlacementX, body.getPosition().y + -15));
	    bulletArray.push_back(bullet);
	    reloadTime++;
	}

	animation.Update(row, deltaTime);
	body.setTextureRect(animation.xyRect);
	body.move(velocity * deltaTime);
    }
    for (Bullet& bullet : bulletArray)
	bullet.Update(deltaTime);
}

void Boss::Draw(sf::RenderWindow & window)
{
    if (lives > 0)
	window.draw(body);
    for (Bullet& bullet : bulletArray)
	bullet.Draw(window);
}

void Boss::onCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f || direction.x > 0.0f) // Collision on the left and right.
    {

    }
    else if (direction.y < 0.0f || direction.y > 0.0f) 
    {
	velocity.y = 0.0f;
	if (direction.y < 0.0f) // Collision on the bottom.
	{ }
    }
}


void Boss::CheckIfHit(Bullet & bullet)
{
    if (((bullet.getGravityPositionX() + (bullet.getSizeX() / 2) > body.getPosition().x - (body.getSize().x / 2) &&
	  bullet.getGravityPositionX() - (bullet.getSizeX() / 2) < body.getPosition().x + (body.getSize().x / 2))
	 &&
	 (bullet.getGravityPositionY() + (bullet.getSizeY() / 2) > body.getPosition().y - (body.getSize().y / 2) &&
	  bullet.getGravityPositionY() - (bullet.getSizeY() / 2) < body.getPosition().y + (body.getSize().y / 2))))
    {
	bullet.setBulletHit(true);
	lives--;
	if(lives == 0)
	{
	    body.setPosition(sf::Vector2f(5000, 5000));
	}
    }

}

