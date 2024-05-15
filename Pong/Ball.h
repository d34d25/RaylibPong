#pragma once
#include "raylib.h"
#include "GameObject.h"
#include <cstdlib> // for rand()
#include "Screen.h"

class Ball
{
private:

	GameObject ballObject;

	Screen screen_p;

	bool startPressed;

	void CheckCollisions_X();

	void CheckCollisions_Y();

	
public:

	Ball(float b_X, float b_Y, float b_R);

	bool StartBall();

	void CheckCollisions();

	void CheckCollisions_WPlayer(Vector2 playerPos, Vector2 playerSize, Vector2 playerVel);

	GameObject& GetBallObject();
};

