#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	     sf::Texture* enemyTexture, sf::Vector2i imageCount, float switchTime, sf::Texture* bulletTexture)
    : Characters(position, health, attackDamage, movementSpeed, jumpHeight),
      animation(enemyTexture, imageCount, switchTime)
{
    body.setTexture(enemyTexture);
    bullet.setTexture(bulletTexture);
    body.setOrigin(sf::Vector2f(body.getSize() / 2.0f));
}

Enemy::~Enemy()
{
}

void Enemy::Intelligence(sf::Vector2f distance)
{
  
  if(distance.x < 200 && distance.x > 0)
  {
    isFiring = true;
   
    if(distance.x < 100)
      movementSpeed = -40;
    // velocity.x += 100;
    fireMode = false;
  }
  else if(distance.x > 200 && distance.x < 300)
  {
    isFiring = false;
    movementSpeed = 100;
    fireMode = false;
  }
  else if(distance.x > 300)
  {
    movementSpeed = 0;
    fireMode = true;
  }

  if(distance.x < 50)
  {
    canJump = true;
  }

  if(canJump)
  {
    // std::cout << "HEJ" << std::endl;
    velocity.y = -sqrtf(2.0f * 982.0f * 100);
    canJump = false;
  }
}

void Enemy::Update(float deltaTime)
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

	for (Bullet& bullet : bulletArray)
	{
	    bullet.Update(deltaTime);
	}

		
	animation.Update(row, deltaTime);
	body.setTextureRect(animation.xyRect);
	body.move(velocity * deltaTime);
    }
}

void Enemy::Draw(sf::RenderWindow & window)
{
    if (lives > 0)
    {
	window.draw(body);

	for (Bullet& bullet : bulletArray)
	    bullet.Draw(window);
    }
}

void Enemy::OnCollision(sf::Vector2f direction)
{
    if (direction.x < 0.0f) // Collision on the left.
    {
	velocity.x = 0.0f;
    }
    else if (direction.x > 0.0f) // Collision on the right.
    {
	velocity.x = 0.0f;
    }
    else if (direction.y < 0.0f) // Collision on the bottom.
    {
	velocity.y = 0.0f;
    }
    else if (direction.y > 0.0f) // Collision on the top.
    {
	velocity.x = 0.0f;
    }
}

void Enemy::CheckIfHit(Bullet & bullet)
{
  if(fireMode == false)
  {
    if ((bullet.getGravityPositionX() + (bullet.getSizeX() / 2) > body.getPosition().x - (body.getSize().x / 2) &&
	 bullet.getGravityPositionX() - (bullet.getSizeX() / 2) < body.getPosition().x + (body.getSize().x / 2))
	&&
	(bullet.getGravityPositionY() + (bullet.getSizeY() / 2) > body.getPosition().y - (body.getSize().y / 2) &&
	 bullet.getGravityPositionY() - (bullet.getSizeY() / 2) < body.getPosition().y + (body.getSize().y / 2)))
    {

      bullet.setBulletHit(true);
      lives = 0;
      body.setPosition(sf::Vector2f(5000, 5000));
    
    }
  }
}



