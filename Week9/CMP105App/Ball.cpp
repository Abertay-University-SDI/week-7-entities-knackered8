#include "Ball.h"

Ball::Ball()
{
	alive = false;
}

Ball::~Ball()
{
}

void Ball::update(float dt)
{
	move(velocity * dt);
}