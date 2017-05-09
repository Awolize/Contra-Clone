#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Collider.h"

class Platform : public Entity
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow & window);
	Collider GetCollider() { return Collider(body); };

private:

};

