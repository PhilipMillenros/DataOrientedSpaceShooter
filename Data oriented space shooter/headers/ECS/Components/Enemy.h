#pragma once
#include "Math\Vector2.h"

struct Enemy
{
	float hitpoints;
	Vector2 movementSpeed;
	Enemy() : hitpoints(1), movementSpeed(0, 0)
	{

	}
	Enemy(float hitpoints, Vector2 movementSpeed) : hitpoints(hitpoints), movementSpeed(movementSpeed)
	{

	}
};