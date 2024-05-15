#pragma once
#include "raylib.h"
#include"raymath.h"
#include "GameObject.h"
#include "Screen.h"

class Player
{
private:

	int playerType;

	int score;

	GameObject playerObject;

	void MovePlayerOne();

	void MovePlayerTwo();

	void IncreasePoints_A(float ball_xPos);

	void IncreasePoints_B(float ball_xPos);

	Screen screen_prop;

	bool scoredRecently = false;

public:

	Player(float p_X, float p_Y, float p_W, float p_H, int p_Type); //p_X = player X

	void Move();

	GameObject& GetPlayerObject();

	void CheckCollisions();

	void ScorePoints(float ball_xPos);

	void resetRecentScore();

	int& GetScore();

};

