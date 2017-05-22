#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Entity.h"
#include "Collider.h"

class PowerUp : Entity 
{
public: 
  PowerUp(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position, std::string name); 
  void Update(float deltaTime) override;
  void Draw(sf::RenderWindow& window) override;
  std::string name;
  Collider GetCollider() { return Collider(body); };
  void Move(float dx, float dy) { body.move(dx, dy); };
  sf::RectangleShape body;
 private:
  //  sf::Sprite Power;
};


