#include "FallingBallManager.h"

FallingBallManager::FallingBallManager()
{
	spawnPoint = sf::Vector2f(rand() % 1200 , -100);
	texture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&texture);
		balls[i].setSize(sf::Vector2f(100, 100));
		balls[i].setCollisionBox(0, 0, 100, 100);
	}
}

FallingBallManager::~FallingBallManager()
{
}

void FallingBallManager::spawn(sf::Vector2f playerPos, sf::Vector2f mousePos)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			spawnPoint = sf::Vector2f(rand() % 1200, -100);
			balls[i].setAlive(true);
			balls[i].setVelocity(mousePos- playerPos);
			balls[i].setPosition(playerPos);
			return;
		}
	}
	balls.push_back(Ball());
	std::cout << balls.size() << "\n";
}

void FallingBallManager::update(float dt,GameObject wall)
{
	// call update on all ALIVE balls
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setTexture(&texture);
			balls[i].setSize(sf::Vector2f(100, 100));
		}


		if (balls[i].isAlive())
		{
			balls[i].update(dt);
			balls[i].collision(wall);
		}
	}
	deathCheck();
}

void FallingBallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			
			if (balls[i].getPosition().x > 1200)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void FallingBallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].setTexture(&texture);
			window->draw(balls[i]);
		}
	}
}
