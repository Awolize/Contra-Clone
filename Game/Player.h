#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Characters.h"
#include "Animation.h"
#include "Characters.h"
#include "Bullet.h"
#include <iostream>
#include <vector>
#include <cmath>
#include "Entity.h"
#include "Enemy.h"

class Player : public Characters
{
public:
    Player(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	   sf::Texture* playerTexture, sf::Vector2i imageCount, float switchTime, sf::Texture* bulletTexture);
    ~Player();

    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;

<<<<<<< HEAD
    sf::Vector2f getPosition() { return body.getPosition(); }
    sf::Vector2f velocity;
=======
    sf::Vector2f getPosition() { return body.getPosition(); };
    void CheckIfHit(Bullet & bullet);
    void CheckHitEnemy(Enemy & enemy);
>>>>>>> aleer778

    
private:
    int row{ 0 };
    Animation animation;
<<<<<<< HEAD
   
    bool canJump{ true };
=======
    bool hit{ false };
>>>>>>> aleer778
    bool faceRight{ true };
    bool isFiring{ false };

    // Gun
    std::vector<Bullet> bulletArray;
    Bullet bullet;
    float gunPlacementX{ body.getPosition().x + 60 };
    int reloadTime{ 0 };

    // Jump
    sf::Vector2f velocity;
    bool canJump;
};

#endif
