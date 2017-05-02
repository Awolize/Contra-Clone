#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
public:
	Entity();
	~Entity();

	sf::RectangleShape body;
	sf::Sprite sprite;
	sf::Text text;
};

