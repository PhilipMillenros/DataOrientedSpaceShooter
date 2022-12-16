#pragma once
#include "Math\Vector2.h"
struct Projectile
{
	Vector2 shootDirection;
	float speed;
	Projectile()
	{

	}
	Projectile(float speed, Vector2 shootDirection) : speed(speed), shootDirection(shootDirection)
	{

	}
};