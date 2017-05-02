#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h"
#include "Collider.h"
#include "Projectile.h"

class Player : public Entity
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float movementSpeed, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);

	sf::Vector2f getPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); };

private:
	Animation animation;
	unsigned int row;
	bool faceRight{};
	int attackDamage = 50;
	int health = 50;
	float movementSpeed;

	// Gun
	std::vector<Projectile> projectileArray;
	Projectile projectile;
	float gunPlacementX{ body.getPosition().x + 45 };

	// Jump
	sf::Vector2f velocity;
	bool canJump;
	float jumpHeight;
};

