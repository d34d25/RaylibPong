#include "Player.h"


Player::Player(float p_X, float p_Y, float p_W, float p_H, int p_Type)
	: playerObject(p_X, p_Y, p_W, p_H, {0.0f,0.0f}, 8.0f), playerType(p_Type)
{
	score = 0;
}

void Player::Move()
{
	switch (playerType)
	{
	case 2: 
		MovePlayerOne();
		break;
	case 1:
		MovePlayerTwo();
		break;
	default:
		break;
	}
	
}

void Player::MovePlayerOne()
{
	float desiredMovement = 0.0f;
	bool isMoving = false;

	if (IsKeyDown(KEY_UP))
	{
		desiredMovement = -4.0f;
		isMoving = true;
	}
	else if (IsKeyDown(KEY_DOWN))
	{
		desiredMovement = 4.0f;
		isMoving = true;
	}
	else
	{
		isMoving = false;
	}
	
	if (isMoving)
	{
		playerObject.SetVel({0.0f,Clamp(playerObject.GetVel().y + desiredMovement, -playerObject.GetMaxSpeed(), playerObject.GetMaxSpeed())});
	}
	else
	{
		playerObject.SetVel({ 0.0f,0.0f });
	}
}

void Player::MovePlayerTwo()
{
	float desiredMovement = 0.0f;
	bool isMoving = false;

	if (IsKeyDown(KEY_W))
	{
		desiredMovement = -4.0f;
		isMoving = true;
	}
	else if (IsKeyDown(KEY_S))
	{
		desiredMovement = 4.0f;
		isMoving = true;
	}
	else
	{
		isMoving = false;
	}

	if (isMoving)
	{
		playerObject.SetVel({ 0.0f,Clamp(playerObject.GetVel().y + desiredMovement, -playerObject.GetMaxSpeed(), playerObject.GetMaxSpeed()) });
	}
	else
	{
		playerObject.SetVel({0.0f,0.0f});
	}
}




GameObject& Player::GetPlayerObject()
{
	return playerObject;
}

void Player::CheckCollisions()
{
	if (playerObject.GetY() - playerObject.GetHeight() + playerObject.GetVel().y <= -40) //higher than the top of the screen
	{
		playerObject.SetVel({ 0.0f,0.0f});
	}

	if (playerObject.GetY() + playerObject.GetHeight() + playerObject.GetVel().y >= screen_prop.screenHeight)
	{
		playerObject.SetVel({ 0.0f,0.0f});
	}
}

void Player::ScorePoints(float ball_xPos)
{
	switch (playerType)
	{
	case 1:
		IncreasePoints_B(ball_xPos);
		break;

	case 2:
		IncreasePoints_A(ball_xPos);
		break;
	default:
		break;
	}
	
}

void Player::IncreasePoints_A(float ball_xPos)
{
	if (ball_xPos <= 0 && !scoredRecently)
	{
		score++;
		scoredRecently = true;
	}
}

void Player::IncreasePoints_B(float ball_xPos)
{
	
	if (ball_xPos >= screen_prop.screenWidth - 40 && !scoredRecently)
	{
		score++;
		scoredRecently = true;
	}
}

int& Player::GetScore()
{
	return score;
}


void Player::resetRecentScore()
{
	scoredRecently = false;
}
