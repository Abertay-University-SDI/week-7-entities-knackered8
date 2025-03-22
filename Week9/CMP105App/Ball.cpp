#include "Ball.h"

Ball::Ball()
{
	setOrigin(50, 50);
	alive = false;
}

Ball::~Ball()
{
}

void Ball::collision(GameObject other)
{
 	if (Collision::checkBoundingBox(this, &other))
	{
		alive = false;
	}
	

	
}

void Ball::update(float dt)
{
	move(velocity * dt);
}