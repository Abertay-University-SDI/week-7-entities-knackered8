#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include "BeachBallManager.h"
#include "FallingBallManager.h"
#include "Player.h"
#include "Wall.h"


class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();




private:
	//Ball ball;
	BeachBallManager ballManager;
	FallingBallManager fallingManager;
	Player player;
	Wall wall;

	
};