#pragma once
#include "Ball.h"
#include <math.h>
#include <vector>
#include <iostream>
#include "Framework/GameObject.h"
class FallingBallManager
{
public:
	FallingBallManager();
	~FallingBallManager();
	void spawn(sf::Vector2f playerPos, sf::Vector2f mousePos);
	void update(float dt, GameObject wall);
	void deathCheck();
	void render(sf::RenderWindow* window);
private:
	std::vector<Ball> balls;
	sf::Vector2f spawnPoint;
	sf::Texture texture;
	//GameObject wall;
};
