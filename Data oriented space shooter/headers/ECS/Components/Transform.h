#pragma once
#include "Math/Vector2.h"
struct Transform
{
	
public:
	Vector2 position;
	Transform()
	{
		position = { 0.f, 0.f };
	}
	Transform(Vector2 position)
	{
		this->position = position;
	}
};