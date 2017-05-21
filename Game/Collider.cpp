#include "Collider.h"
#include <iostream>


Collider::Collider(sf::RectangleShape & body) :
	body(body)
{
}

bool Collider::CheckCollision(Collider & otherBody, sf::Vector2f & direction)
{
	// Check for collision
		// X-axis
	if (((otherBody.GetPosition().x + (otherBody.GetSize().x / 2) >
		body.getPosition().x - (body.getSize().x / 2)) &&

		(otherBody.GetPosition().x - (otherBody.GetSize().x / 2) <
			body.getPosition().x + (body.getSize().x / 2))) &&
		// Y-axis
			((otherBody.GetPosition().y + (otherBody.GetSize().y / 2) >
				body.getPosition().y - (body.getSize().y / 2)) &&

				(otherBody.GetPosition().y - (otherBody.GetSize().y / 2) <
					body.getPosition().y + (body.getSize().y / 2))))
	{
		if (((abs(otherBody.GetPosition().x - body.getPosition().x) -
			((otherBody.GetSize().x / 2) + (body.getSize().x / 2))) >
			(abs(otherBody.GetPosition().y - body.getPosition().y) -
			((otherBody.GetSize().y / 2) + (body.getSize().y / 2)))))
		{
			direction.x = 0.0f;
			direction.y = 0.0f;
			if ((otherBody.GetPosition().x - body.getPosition().x) > 0)
			{
				otherBody.Move(-(abs(body.getPosition().x - otherBody.GetPosition().x) -
					((otherBody.GetSize().x / 2) + (body.getSize().x / 2))), 0);
				direction.x = 1.0f;
			}
			else
			{
				otherBody.Move((abs(body.getPosition().x - otherBody.GetPosition().x) -
					((otherBody.GetSize().x / 2) + (body.getSize().x / 2))), 0);
				direction.x = -1.0f;
			}
		}
		else
		{
			if ((otherBody.GetPosition().y - body.getPosition().y) > 0)
			{
				otherBody.Move(0, -(abs(body.getPosition().y - otherBody.GetPosition().y) -
					((otherBody.GetSize().y / 2) + (body.getSize().y / 2))));
				direction.y = 1.0f;
			}
			else
			{
				otherBody.Move(0, abs(body.getPosition().y - otherBody.GetPosition().y) -
					((otherBody.GetSize().y / 2) + (body.getSize().y / 2)));
				direction.y = -1.0f;
			}
		}

		return true;
	}
	else
		return false;
}
