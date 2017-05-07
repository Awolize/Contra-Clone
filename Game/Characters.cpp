#include "Characters.h"



Characters::Characters(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight)
    : Entity(position), health{ health }, attackDamage{ attackDamage }, movementSpeed{ movementSpeed }, jumpHeight {jumpHeight}
{
}

Characters::~Characters()
{
}
