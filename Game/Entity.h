#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>


class Entity
{
public:
  Entity();
    Entity(sf::Vector2f position);
    ~Entity();

    virtual void Update(float deltaTime) = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
    
    sf::RectangleShape body;
    bool faceRight;
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
