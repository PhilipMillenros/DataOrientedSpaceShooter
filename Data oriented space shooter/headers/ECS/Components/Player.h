#pragma once
#include <Math\Vector2.h>

struct Player
{
	Player();
	int hitPoints = 3;
	float speed = 20.f;
	int xVelocity = 0;
	int yVelocity = 0;
	Player(int hitPoints, float speed);
};