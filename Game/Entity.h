#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Entity
{
public:
    Entity(sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
    ~Entity();

    virtual void Update(int deltaTime) const = 0;
	virtual void Draw(sf::RenderWindow& window) const = 0;
    
	sf::RectangleShape body;
	Animation animation;
};

#endif

/*

class Base {
public:
	int publicMember;	Everything that is aware of Base is also aware that Base contains publicMember.
protected:
	int protectedMember;	Only the children (and their children) are aware that Base contains protectedMember.
private:
	int privateMember;	No one but Base is aware of privateMember.
};

*/
