#pragma once
#include "Framework/GameObject.h"
#include "Framework/Input.h"

class Player : public GameObject
{
public:
	Player();
	Player(sf::Vector2f spawn);
	~Player();
	void Move(float dt,Input* inp);
	void render(sf::RenderWindow* window);
	void Update();
	sf::Vector2f GetCurrentPos();
	sf::Vector2f GetMousePos();


protected:
	sf::Vector2f playerSpawn;
	sf::Vector2f currentPos;
	sf::Texture texture;
	sf::Vector2f mousePos;


};
