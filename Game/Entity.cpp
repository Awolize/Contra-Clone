#include "Entity.h"

Entity::Entity() 
{

}

Entity::Entity(sf::Vector2f position) 
{
    body.setSize(sf::Vector2f(100.0f, 100.0f));
    body.setPosition(position);
    body.setOrigin(body.getSize() / 2.0f);
}


Entity::~Entity()
{
}
