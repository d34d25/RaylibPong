#include "Ball.h"

Ball::Ball(float b_X, float b_Y, float b_R)
	:ballObject(b_X, b_Y, b_R, 0, {0.0f,0.0f}, 16)
{
	startPressed = false;
}

bool Ball::StartBall()
{
	int randomChance = rand() % 4;
	if (IsKeyPressed(KEY_SPACE) && !startPressed)
	{
		switch (randomChance)
		{
		case 1:
			ballObject.SetVel({3.0f,3.0f});
			startPressed = true;
			return true;
			break;
		case 2:
			ballObject.SetVel({-3.0f,3.0f});
			startPressed = true;
			return true;
			break;
		case 3:
			ballObject.SetVel({ 3.0f,-3.0f });
			startPressed = true;
			return true;
			break;
		case 4:
			ballObject.SetVel({- 3.0f,-3.0f });
			startPressed = true;
			return true;
			break;
		default:
			ballObject.SetVel({3.0f,3.0f });
			startPressed = true;
			return true;
			break;
		}
	}	
}

void Ball::CheckCollisions()
{
	CheckCollisions_Y();
	CheckCollisions_X();
}

void Ball::CheckCollisions_X()
{
	if (ballObject.GetX() + ballObject.GetWidth() <= 0 || ballObject.GetX() + ballObject.GetWidth() >= screen_p.screenWidth)
	{
		ballObject.SetVel({ 0,0 });
		ballObject.SetX(screen_p.screenWidth / 2);
		ballObject.SetY(screen_p.screenHeight / 2);
		startPressed = false;
	}
}

void Ball::CheckCollisions_Y()
{
	if (ballObject.GetY() + ballObject.GetWidth() <= 0)
	{
		ballObject.SetVel({ ballObject.GetVel().x, ballObject.GetVel().y * -1});
	}

	if (ballObject.GetY() + ballObject.GetWidth() >= screen_p.screenHeight)
	{
		ballObject.SetVel({ ballObject.GetVel().x, ballObject.GetVel().y * -1 });
	}
}

void Ball::CheckCollisions_WPlayer(Vector2 playerPos, Vector2 playerSize, Vector2 playerVel)
{
	float speedIncreaseFactor = 0.4f;

	//Collisions on X
	if (ballObject.GetX() + ballObject.GetWidth() + ballObject.GetVel().x > playerPos.x && 
		ballObject.GetX() + ballObject.GetVel().x < playerPos.x + playerSize.x &&
		ballObject.GetY() + ballObject.GetWidth() + ballObject.GetVel().y > playerPos.y &&
		ballObject.GetY() + ballObject.GetVel().y < playerPos.y + playerSize.y) 
	{	
		float newVelX = ballObject.GetVel().x + ballObject.GetVel().x * speedIncreaseFactor;
		float bounceVel_X = -newVelX;

		ballObject.SetVel({ bounceVel_X, ballObject.GetVel().y });
	}

	//Collisions on Y
	if (ballObject.GetX() + ballObject.GetWidth() > playerPos.x &&
		ballObject.GetX() < playerPos.x + playerSize.x &&
		ballObject.GetY() + ballObject.GetWidth() + ballObject.GetVel().y > playerPos.y &&
		ballObject.GetY() + ballObject.GetVel().y < playerPos.y + playerSize.y &&
		playerVel.y < 0)//player moving up
	{
		float newVelY = ballObject.GetVel().y + ballObject.GetVel().y * speedIncreaseFactor;
		float bounceVel_Y = -newVelY;

		ballObject.SetY(playerPos.y - ballObject.GetWidth());
		ballObject.SetVel({ ballObject.GetVel().x , bounceVel_Y });
	}
	else if (ballObject.GetX() + ballObject.GetWidth() > playerPos.x &&
		ballObject.GetX() < playerPos.x + playerSize.x &&
		ballObject.GetY() + ballObject.GetWidth() + ballObject.GetVel().y > playerPos.y &&
		ballObject.GetY() + ballObject.GetVel().y < playerPos.y + playerSize.y &&
		playerVel.y > 0)// player moving down
	{
		float newVelY = ballObject.GetVel().y + ballObject.GetVel().y * speedIncreaseFactor;
        float bounceVel_Y = -newVelY;

        ballObject.SetY(playerPos.y + playerSize.y);
        ballObject.SetVel({ ballObject.GetVel().x , bounceVel_Y });
	}
}



GameObject& Ball::GetBallObject()
{
	return ballObject;
}

