#include "Characters.h"



Characters::Characters(float health, float attackDamage, float movementSpeed, float jumpHeight,
	sf::Texture* texture, sf::Vector2i imageCount, float switchTime)
	: Entity(texture, imageCount, switchTime)
{
}

Characters::~Characters()
{
}
