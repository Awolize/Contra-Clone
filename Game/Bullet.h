#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet();
	Bullet(float velocity);
	~Bullet();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow & window);

	float getRight() { return body.getPosition().x + body.getSize().x; }
	float getLeft() { return body.getPosition().x; }
	float getTop() { return body.getPosition().y; }
	float getBottom() { return body.getPosition().y + body.getSize().y; }
	void setBulletHit(bool tmp) { bulletHit = tmp; }
	void setPosition(sf::Vector2f newPosition) { body.setPosition(newPosition); };

private:
	sf::RectangleShape body;
	float velocity{ 20 };
	bool bulletHit{ false };
};

