#pragma once
#include <SFML/Graphics.hpp>
#include "Platform.h"
#include "Enemy.h"

float lvl_size{5};
float gap{100};
std::string current_lvl{"1"};
sf::Texture level;
void update_lvl(){ level.loadFromFile("images/"+current_lvl+".png");}
void Build(std::vector<Platform>& platformArray, std::vector<Enemy>& enemyArray);

