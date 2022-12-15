#pragma once
#include "Collider.h"

struct Bounds
{
	Vector2 bounds;
	Vector2 position;
	Bounds();
	Bounds(Vector2 bounds, Vector2 position);
	bool ColliderFits(Collider* other);
};