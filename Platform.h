#ifndef PLATFORM_H
#define PLATFORM_H
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Collider.h"

class Platform : public Entity
{
public:
	Platform(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position);
	~Platform();

	void Draw(sf::RenderWindow & window);
	Collider GetCollider() { return Collider(body); };

private:

};

#endif
