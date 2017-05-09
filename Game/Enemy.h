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
	  sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
    ~Enemy();

    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;

    sf::Vector2f getPosition() { return body.getPosition(); };
    void CheckIfHit(Bullet & bullet);

private:
    int row{ 0 };
    Animation animation;
    bool hit{ false };
};

#endif
