#include "Ball.h"

Ball::Ball(sf::RenderWindow* hwnd)
{
	window = hwnd;
	scale = 200.0f;
	Direction = true;
	Collided = false;
}

void Ball::update(float dt)
{

	if (Collided == false)
	{
		if (Direction == true)
		{
			stepVelocity.x = 200;
		}
		if (Direction == false)
		{
			stepVelocity.x = -200;
		}
	}

		if (getPosition().x > window->getSize().x - 101)
		{
			Collided = false;
			Direction = false;
		}
		if (getPosition().x < 0)
		{
			Collided = false;
			Direction = true;
		}
	
	
	if (Collided == true)
	{
		if (Direction == true)
		{
			stepVelocity.x = -200;
		}
		if (Direction == false)
		{
			stepVelocity.x = 200;
		}
	}


	setPosition(getPosition() + (stepVelocity * dt));
}

void Ball::collisionResponse(GameObject* collider)
{
	
	Collided = true;
	
}