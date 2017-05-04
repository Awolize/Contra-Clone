#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2i imageCount, float switchTime);
	~Animation();

	void Update(int row, float deltaTime);
	sf::IntRect rect;

private:
	float totalTime;
	float switchTime;
	sf::Vector2i imageCount;
	sf::Vector2i currentImage;
};

/*
 sf::IntRect
- - - - - - -
T 	left
Left coordinate of the rectangle.

T 	top
Top coordinate of the rectangle.

T 	width
Width of the rectangle.

T 	height
Height of the rectangle.
*/

#endif