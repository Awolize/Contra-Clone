#ifndef CHARACTERS_H
#define CHARACTERS_H
#include <SFML/Graphics.hpp>
#include "Entity.h"

class Characters : public Entity
{
public:
    Characters();
    ~Characters();

// Var
    float health;
    float attackDamage;
    float movementSpeed;
    float jumpHeight;
};

#endif
