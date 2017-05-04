#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Characters.h"
//#include "Animation.h"

class Enemy : public Characters
{
public:
    Enemy(float health, float attackDamage, float movementSpeed, float jumpHeight,
	  sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
    ~Enemy();

private:
//    Animation animation
};

#endif
