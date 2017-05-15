#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Characters.h"
#include "Collider.h"
#include "Bullet.h"
#include <iostream>
#include <vector>
#include <cmath>


class Enemy : public Characters
{
public:
    Enemy(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	  sf::Texture* enemyTexture, sf::Vector2i imageCount, float switchTime, sf::Texture* bulletTexture);
    ~Enemy();

    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;


    sf::Vector2f getPosition() { return body.getPosition(); };

	// Collision with solid object (platforms..)
	Collider GetCollider() { return Collider(body); };
	void OnCollision(sf::Vector2f direction);

	// Hit / Bullets
	void CheckIfHit(Bullet & bullet);
	std::vector<Bullet> bulletArray;

private:
	int row{ 0 };
	Animation animation;
	bool faceRight{ true };
	bool isFiring{ false };
	int lives{ 3 };

	// Gun
	Bullet bullet;
	float gunPlacementX{ body.getPosition().x + 60 };
	float reloadTime{ 0 };

	// Movement
	sf::Vector2f velocity;
	bool canJump;
};

#endif