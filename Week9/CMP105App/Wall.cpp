#include "Wall.h"

Wall::Wall()
{
	setPosition(500, 300);
	setSize(sf::Vector2f(50, 100));
	setFillColor(sf::Color::Blue);
	setCollisionBox(0, 0, 50, 100);

}

Wall::~Wall()
{
}
