#include "Collision.h"
#include <SFML/Graphics.hpp>
//#include "Player.h"

bool ifCollision(sf::FloatRect & firstBox,sf::FloatRect & secondBox)
{
    if (firstBox.intersects(secondBox))
	return false;
    else
	return true;    

}

void checkCollision(Player & firstBox, sf::RectangleShape & secondBox, float & deltatime)
{
    sf::FloatRect tempBox1 = firstBox.body.getGlobalBounds();
    sf::FloatRect tempBox2 = secondBox.getGlobalBounds();
    if(ifCollision(tempBox1, tempBox2))
	firstBox.body.move(0 ,0);
    else
    {
	firstBox.body.move(0, -31*deltatime);
	firstBox.velocity.y = 0;
    }
}
