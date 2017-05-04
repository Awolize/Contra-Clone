#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity();
    ~Entity();

    void Update(int deltaTime);
    void Draw(sf::RenderWindow& window);
    
    // Var 
    sf::RectangleShape body;
};

#endif
