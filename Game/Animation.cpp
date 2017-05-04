#include "Animation.h"



Animation::Animation(sf::Texture* texture, sf::Vector2i imageCount, float switchTime) :
	imageCount{ imageCount }, switchTime{ switchTime }, totalTime{ 0.0f }, currentImage{ 0, 0 }
{
	rect.width = texture->getSize().x / imageCount.x;
	rect.height = texture->getSize().y / imageCount.y;
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime = totalTime + deltaTime;

	if (totalTime >= switchTime)
	{
		totalTime = totalTime - switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x)
			currentImage.x = 0;
	}

	rect.top = currentImage.y * rect.height;
	rect.left = currentImage.x * rect.width;
}