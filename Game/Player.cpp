#include "Player.h"

Player::Player(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	       sf::Texture* playerTexture, sf::Vector2i imageCount, float switchTime, sf::Texture* bulletTexture)
    : Characters(position, health, attackDamage, movementSpeed, jumpHeight),
      animation(playerTexture, imageCount, switchTime)
{
    body.setTexture(playerTexture);
    bullet.setTexture(bulletTexture);
    std::cout << "Player Body Origin (x, y): " << body.getOrigin().x << " " << body.getOrigin().y << std::endl;
    std::cout << "Player Body Size   (x, y): " << body.getSize().x << " " << body.getSize().y << std::endl;
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

    velocity.y += 982.0f * deltaTime;

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

	// Map Border (x-axis)
	if (body.getPosition().x < -440)
		body.setPosition(-440, body.getPosition().y);
}

void Player::Draw(sf::RenderWindow & window)
{
	if (lives > 0)
	{
		window.draw(body);
	}
	for (Bullet& bullet : bulletArray)
		bullet.Draw(window);
}

// velocity = 0 in the collision direction 
void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f || direction.x > 0.0f) // Collision on the left.
	{
		velocity.x = 0.0f;
		canJump = false;
	}
	else if (direction.y < 0.0f || direction.y > 0.0f) // Collision on the bottom.
	{
		velocity.y = 0.0f;
		canJump = false;
		if (direction.y < 0.0f)
			canJump = true;
	}
}

void Player::CheckIfHit(Bullet & bullet)
{
	if (// X-Axis 
		(bullet.getGravityPositionX() + (bullet.getSizeX() / 2) > body.getPosition().x - (body.getSize().x / 2) &&
			bullet.getGravityPositionX() - (bullet.getSizeX() / 2) < body.getPosition().x + (body.getSize().x / 2))
		&&
		// Y-Axis
		(bullet.getGravityPositionY() + (bullet.getSizeY() / 2) > body.getPosition().y - (body.getSize().y / 2) &&
			bullet.getGravityPositionY() - (bullet.getSizeY() / 2) < body.getPosition().y + (body.getSize().y / 2))
		)
	{
		bullet.setBulletHit(true);
		body.setPosition(sf::Vector2f(200, -500));
		lives--;
		velocity.x = 0.0f;
		velocity.y = 0.0f;
		canJump = true;
	}
}

