#include "PowerUp.h"
#include <iostream>

PowerUp::PowerUp(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, std::string name)
  : name{ name }
{
  body.setSize(size);
  body.setTexture(texture);
  body.setPosition(position);
  body.setOrigin(size/2.0f);
}
void PowerUp::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void PowerUp::Update(float deltaTime)
{
	
}



