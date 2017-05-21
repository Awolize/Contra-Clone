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
	
    // Collision with solid object (platforms..)
    Collider GetCollider() { return Collider(body); };
    void OnCollision(sf::Vector2f direction);

    // Hit / Bullets
    void CheckIfHit(Bullet & bullet);
    std::vector<Bullet> bulletArray;
    int lives{ 3 };

    bool end{ false };
private:
    int row{ 0 };
    Animation animation;
    bool faceRight{ true };
    bool isFiring{ false };
	
    // Gun
    Bullet bullet;
    float gunPlacementX{ body.getPosition().x + 60 };
    float reloadTime{ 0 };

    // Jump / movement
    sf::Vector2f velocity;
    bool canJump;
};

#endif
