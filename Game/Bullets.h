#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"

class Bullets
{
public:
	Bullets();
	~Bullets();

	void createBullet(bool faceRight, sf::Vector2f bodyPosition);

	std::vector<Bullet> bulletArray;
	Bullet bullet;
};

