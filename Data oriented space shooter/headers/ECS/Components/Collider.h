#pragma once
#include "Math\Vector2.h"
#include "ECS\Core\ECS.h"
struct Collider
{
	std::bitset<8> collisionMask;
	int collisionIndex;
	Vector2 position;
	Vector2 bounds;
	Entity entity;
	bool collision = false;
	Collider();
	Collider(Vector2 position, Vector2 bounds, Entity entity, int collisionIndex, std::bitset<8> mask);
	void Collision(Collider& colliderA, Collider& colliderB);
};