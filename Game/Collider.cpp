#include "Collider.h"

Collider::Collider(sf::RectangleShape & body) :
    body(body)
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(Collider & otherBody, sf::Vector2f & direction)
{
    float otherBodyTopY = otherBody.GetPosition().y - otherBody.GetSize().y / 2;
    float otherBodyBottomY = otherBody.GetPosition().y + otherBody.GetSize().y / 2;
    float otherBodyRightX = otherBody.GetPosition().x + otherBody.GetSize().x / 2;
    float otherBodyLeftX = otherBody.GetPosition().x - otherBody.GetSize().x / 2;

    float bodyTopY = body.getPosition().y - body.getSize().y / 2;
    float bodyBottomY = body.getPosition().y + body.getSize().y / 2;
    float bodyRightX = body.getPosition().x + body.getSize().x / 2;
    float bodyLeftX = body.getPosition().x - body.getSize().x / 2;

    float moveX = abs(otherBody.GetPosition().x - body.getPosition().x) - 
	(otherBody.GetSize().x / 2 + body.getSize().x / 2);
    float moveY = abs(otherBody.GetPosition().y - body.getPosition().y) - 
	(otherBody.GetSize().y / 2 + body.getSize().y / 2);
	
					      
    if ((otherBody.GetPosition().x + (otherBody.GetSize().x / 2) >
	 body.getPosition().x - ( body.getSize().x / 2) &&

	 otherBody.GetPosition().x - (otherBody.GetSize().x / 2) <
	 body.getPosition().x + (body.getSize().x / 2)) &&


	(otherBody.GetPosition().y + (otherBody.GetSize().y / 2) >
	 body.getPosition().y - (body.getSize().y / 2) &&

	 otherBody.GetPosition().y - (otherBody.GetSize().y / 2) <
	 body.getPosition().y + (body.getSize().y / 2)))
    {
	/*
	            XXX    
		    XP_  
		    XXX 
	       XXX
               _PX
	       XXX  
	 */
	if (bodyTopY < otherBodyBottomY) // Collision on the bottom
	{
	    otherBody.Move(0.0f, +(moveY));
	    direction.x = 0.0f;
	    direction.y = -1.0f;		
	}
        else if (bodyBottomY > otherBodyTopY) // Collision on the top
	{
	    otherBody.Move(0.0f, -(moveY));
	    direction.x = 0.0f;
	    direction.y = 1.0f;		
	}
	else if (bodyLeftX < otherBodyRightX) // Collision on the left
	{
	    otherBody.Move(+(moveX), 0.0f);
	    direction.x = -1.0f;
	    direction.y = 0.0f;		
	}
	else if (bodyRightX > otherBodyLeftX) // Collision on the right
	{
	    otherBody.Move(-(moveX), 0.0f);;
	    direction.x = 1.0f;
	    direction.y = 0.0f;		
	}

	return true;
    }
    return false;
}
