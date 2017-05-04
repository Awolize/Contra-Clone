#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Characters : public Entity
{
public:
    Characters(float health, float attackDamage, float movementSpeed, float jumpHeight,
		sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
    ~Characters();

// Var
	float health{ 100.0f };
    float attackDamage{ 100.0f };
    float movementSpeed{ 100.0f };
    float jumpHeight{ 10.0f };
};

#endif
