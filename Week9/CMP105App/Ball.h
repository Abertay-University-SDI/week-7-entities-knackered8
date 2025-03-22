#pragma once
#include "Framework/GameObject.h"
#include "Framework//Collision.h"

class Ball : public GameObject
{
public:
	Ball();
	~Ball();
	void collision(GameObject other);

	void update(float dt) override;
};
