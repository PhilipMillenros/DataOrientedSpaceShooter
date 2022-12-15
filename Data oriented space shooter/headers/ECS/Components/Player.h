#pragma once
#include <Math\Vector2.h>

struct Player
{
	int hitPoints = 3;
	float speed = 20.f;
	Player(int hitPoints, float speed);
	Player();
};