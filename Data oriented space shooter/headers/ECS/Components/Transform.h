#pragma once
#include "Math/Vector2.h"
struct Transform
{
	
public:
	Vector2 position {0, 0};
	Vector2 size{ 1, 1 };
	Transform()
	{

	}
	Transform(Vector2 position, Vector2 size) : position(position),  size(size) {}
	

};