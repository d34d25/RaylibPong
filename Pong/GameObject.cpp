#include "GameObject.h"

GameObject::GameObject(float init_x, float init_y, float init_width, float init_height, Vector2 init_vel, float max_spd)
	:x(init_x), y(init_y), width(init_width), height(init_height), velocity(init_vel), maxSpeed(max_spd)
{
}

void GameObject::DrawObject(int type)
{
	switch (type)
	{
	case 1:
		DrawRectangle(x, y, width, height, RAYWHITE);
		break;
	case 2:
		DrawCircle(x, y, width, RAYWHITE);
		break;
	default:
		break;
	}
}

void GameObject::UpdateObject()
{
	x += velocity.x;
	y += velocity.y;
}


//Setters
void GameObject::SetX(float newX)
{
	x = newX;
}

void GameObject::SetY(float newY)
{
	y = newY;
}

void GameObject::SetWidth(float newWidth)
{
	width = newWidth;
}

void GameObject::SetHeight(float newHeight)
{
	height = newHeight;
}

void GameObject::SetVel(Vector2 newVel)
{
	velocity = newVel;
}


//Getters

float GameObject::GetX()
{
	return x;
}

float GameObject::GetY()
{
	return y;
}

float GameObject::GetWidth()
{
	return width;
}

float GameObject::GetHeight()
{
	return height;
}

Vector2 GameObject::GetVel()
{
	return velocity;
}

float GameObject::GetMaxSpeed()
{
	return maxSpeed;
}

