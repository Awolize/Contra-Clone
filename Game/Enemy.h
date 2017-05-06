#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include "Characters.h"
#include "Animation.h"

class Enemy : public Characters
{
public:
    Enemy(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	  sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
    ~Enemy();

    void Update(int deltaTime) override;
    void Draw(sf::RenderWindow& window) override;

private:
    Animation animation;
};

#endif
