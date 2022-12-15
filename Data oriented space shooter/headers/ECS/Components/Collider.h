#pragma once
#include "Math\Vector2.h"
#include "ECS\Core\ECS.h"
struct Collider
{
	Vector2 position;
	Vector2 bounds;
	Entity entity;
	Collider();
	Collider(Vector2 position, Vector2 bounds, Entity entity);
	void Collision();
};