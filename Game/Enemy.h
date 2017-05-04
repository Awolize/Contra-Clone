#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Characters.h"
#include "Entity.h"

class Enemy : public Entity
{
public:
    Enemy(float health, float attackDamage, float movementSpeed, float jumpHeight,
	  sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
    ~Enemy();

	void Update(int deltaTime) const override;
	void Draw(sf::RenderWindow& window) const override;

};

#endif
