#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>
#include "Entity.h"


class Projectile : public Entity
{
public:
	Projectile();
	~Projectile();

	void Draw(sf::RenderWindow& window);
	void Update(float deltaTime);

	sf::Vector2f bulletVelocity{ 3.0f, 0.0f };
	int attackDamage = 50;
	bool faceRight;

private:

};

#endif
