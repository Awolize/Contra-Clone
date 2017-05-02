#include "Player.h"


Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float movementSpeed, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->movementSpeed = movementSpeed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(sf::Vector2f(36.0f * 2.5f, 38.0f * 2.5f));
	body.setPosition(0.0f, 900.0f);
	body.setOrigin(body.getSize() / 2.0f);
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	velocity.x *= 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += movementSpeed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;

		velocity.y = -sqrtf(2.0f * 982.0f * jumpHeight);
	}

	velocity.y += 982.0f * deltaTime;

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
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
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

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(body);
	for (Projectile& projectile : projectileArray)
		projectile.Draw(window);

/*	int i{ 0 };
	for (iter = projectileArray.begin(); iter != projectileArray.end(); iter++)
	{
		window.draw(projectileArray[i].body);
		i++;
	}
	*/
}

void Player::OnCollision(sf::Vector2f direction)
{

	if (direction.x < 0.0f) // Collision on the left.
	{
		velocity.x = 0.0f;
		canJump = false;
	}
	else if (direction.x > 0.0f) // Collision on the right.
	{
		velocity.x = 0.0f;
		canJump = false;
	}
	else if (direction.y < 0.0f) // Collision on the bottom.
	{
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f) // Collision on the top.
	{
		velocity.x = 0.0f;
		canJump = false;
	}
}
