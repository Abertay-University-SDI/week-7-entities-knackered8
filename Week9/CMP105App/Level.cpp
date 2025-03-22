#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	//ball = Ball();
	//ballManager = BeachBallManager();
	fallingManager = FallingBallManager();
	player = Player(sf::Vector2f(100, 100));



}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Space))
	{
		//ballManager.spawn();
		player.Move(dt, input);
		fallingManager.spawn(player.GetCurrentPos(), player.GetMousePos());
	}
	player.Move(dt, input);
}

// Update game objects
void Level::update(float dt)
{
	//ballManager.update(dt);
	fallingManager.update(dt,wall);
	player.Update();
}

// Render level
void Level::render()
{
	beginDraw();
	//ballManager.render(window);
	fallingManager.render(window);
	player.render(window);
	window->draw(wall);
	endDraw();
}
