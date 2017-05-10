#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Characters.h"
#include "Bullet.h"
#include "Collider.h"
#include "Enemy.h"
#include <iostream>
#include <vector>
#include <cmath>


class Player : public Characters
{
public:
    Player(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	   sf::Texture* playerTexture, sf::Vector2i imageCount, float switchTime, sf::Texture* bulletTexture);
    ~Player();

    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;

    sf::Vector2f getPosition() { return body.getPosition(); };
    void CheckIfHit(Bullet & bullet);
    void CheckHitEnemy(Enemy & enemy);

	Collider GetCollider() { return Collider(body); };
	void OnCollision(sf::Vector2f direction);

private:
    int row{ 0 };
    Animation animation;
    bool hit{ false };
    bool faceRight{ true };
    bool isFiring{ false };

    // Gun
    std::vector<Bullet> bulletArray;
    Bullet bullet;
    float gunPlacementX{ body.getPosition().x + 60 };
    float reloadTime{ 0 };

    // Jump
    sf::Vector2f velocity;
    bool canJump;
};

#endif
