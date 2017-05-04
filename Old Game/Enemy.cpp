#include "Enemy.h"



Enemy::Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float movementSpeed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->movementSpeed = movementSpeed;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(36.0f * 2.5f, 38.0f * 2.5f));
	body.setPosition(600.0f, 900.0f);
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
}



Enemy::~Enemy()
{
}

void Enemy::Update(float deltaTime)
{
	velocity.x *= 0.0f;

	if (false) // atm
		velocity.x -= movementSpeed;
	if (false) // atm
		velocity.x += movementSpeed;

	velocity.y += 982.0f * deltaTime;

	// Animation
	if (velocity.x == 0.0f)
		row = 0;
	else
	{
		row = 1;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	// Fire
	if (false) // atm
	{
		if (faceRight)
		{
			gunPlacementX = body.getPosition().x + 45;
			projectile.faceRight = true;
		}
		else
		{
			gunPlacementX = body.getPosition().x - 55;
			projectile.faceRight = false;
		}

		projectile.body.setPosition(gunPlacementX, body.getPosition().y + 5);
		projectileArray.push_back(projectile);
	}

	for (Projectile& projectile : projectileArray)
		projectile.Update(deltaTime);
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Enemy::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	for (Projectile& projectile : projectileArray)
		projectile.Draw(window);
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