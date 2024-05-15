#pragma once
#include "raylib.h"

class GameObject
{
private:

	float x, y, width, height;

	Vector2 velocity;

	float maxSpeed;

public:

	GameObject(float init_x, float init_y, float init_width, float init_height, Vector2 init_vel, float max_spd);

	void DrawObject(int type);

	void UpdateObject();


	//Setters
	void SetX(float newX);

	void SetY(float newY);

	void SetWidth(float newWidth);

	void SetHeight(float newHeight);

	void SetVel(Vector2 newVel);

	//Getters
	float GetX();

	float GetY();

	float GetWidth();

	float GetHeight();

	Vector2 GetVel();

	float GetMaxSpeed();
};

