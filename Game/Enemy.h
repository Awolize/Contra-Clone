#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Characters.h"
#include "Animation.h"
#include "Bullet.h"

class Enemy : public Characters
{
public:
	Enemy(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
		sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
	~Enemy();

	void Update(float deltaTime) override;
	void Draw(sf::RenderWindow& window) override;

	void CheckCollision(Bullet & Bullet);

private:
	int row{ 0 };
	Animation animation;
	bool hit{ false };
};

#endif
