#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Characters.h"
#include "Animation.h"
#include "Characters.h"

class Player : public Characters
{
public:
Player(float health, float attackDamage, float movementSpeed, float jumpHeight,
	 sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
~Player();

void Update(int deltaTime) const override;
void Draw(sf::RenderWindow& window) const override;

};

#endif
