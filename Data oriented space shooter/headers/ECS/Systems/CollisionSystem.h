#pragma once
#include "ECS\Core\System.h"
#include "ECS\Systems\QuadTreeCollision.h"

#include <ECS\Core\Coordinator.h>

extern QuadTreeCollision quadTreeCollision;
extern Coordinator coordinator;
class CollisionSystem : public System
{
public:
	void Update();
	CollisionSystem();
	void AABBCollision(Collider& colliderA, Collider& colliderB);
};