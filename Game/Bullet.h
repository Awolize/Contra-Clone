#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow & window);

	float getGravityPositionX() { return body.getPosition().x; }
	float getGravityPositionY() { return body.getPosition().y; }
	float getSizeX() { return body.getSize().y; }
	float getSizeY() { return body.getSize().x; }
	void setTexture(sf::Texture * texture) { body.setTexture(texture); }
	void setBulletHit(bool tmp) { bulletHit = tmp; }

	void setPosition(sf::Vector2f newPosition) { body.setPosition(newPosition); };

	bool faceRight;


private:
	sf::RectangleShape body;
	float velocity{ 500 };
	bool bulletHit{ false };
	bool animationExplosion{ true };
	int explosionTime{ 0 };
	sf::Sprite spriteExplosion;
	sf::Texture explosion;
};

