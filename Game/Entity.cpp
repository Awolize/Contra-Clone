#include "Entity.h"



Entity::Entity(sf::Texture* texture, sf::Vector2i imageCount, float switchTime) 
	: animation( texture, imageCount, switchTime )
{
}


Entity::~Entity()
{
}
