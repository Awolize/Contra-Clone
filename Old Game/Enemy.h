#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Animation.h"
#include "Collider.h"
#include "Projectile.h"

class Enemy : public Entity
{
public:
	Enemy(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float movementSpeed, float jumpHeight);
	~Enemy();

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

	// Speed + Gravity
	float movementSpeed;
	sf::Vector2f velocity;

	// Gun
	std::vector<Projectile> projectileArray;
	Projectile projectile;
	float gunPlacementX{ body.getPosition().x + 45 };
};

#endif
