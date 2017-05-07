#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Characters.h"
#include "Animation.h"
#include "Characters.h"

class Player : public Characters
{
public:
    Player(sf::Vector2f position, float health, float attackDamage, float movementSpeed, float jumpHeight,
	   sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
    ~Player();

    void Update(float deltaTime) override;
    void Draw(sf::RenderWindow& window) override;

    sf::Vector2f getPosition() { return body.getPosition(); }

private:
    int row{ 0 };
    Animation animation;
    sf::Vector2f velocity;
    bool canJump{ true };
    
};

#endif
