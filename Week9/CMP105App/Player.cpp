#include "Player.h"

Player::Player()
{
}

Player::Player(sf::Vector2f spawn)
{
	texture.loadFromFile("gfx/Mushroom.png");

	setPosition(spawn);
	setSize(sf::Vector2f(150, 150));
	setOrigin(75, 75);
	setFillColor(sf::Color::White);
	setTexture(&texture);
}

Player::~Player()
{
}

void Player::Move(float dt, Input* inp)
{
	input = inp;
	if (input->isKeyDown(sf::Keyboard::A))
	{
		move(-0.1, 0);
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		move(0.1, 0);
	}
	if (input->isKeyDown(sf::Keyboard::W))
	{
		move(0, -0.1);
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		move(0, 0.1);
	}
}

void Player::render(sf::RenderWindow* window)
{
	setTexture(&texture);
	window->draw(*this);
}

void Player::Update()
{
	currentPos = getPosition();
	mousePos.x = input->getMouseX();
	mousePos.y = input->getMouseY();
}

sf::Vector2f Player::GetCurrentPos()
{
	return currentPos;
}

sf::Vector2f Player::GetMousePos()
{
	return mousePos;
}
