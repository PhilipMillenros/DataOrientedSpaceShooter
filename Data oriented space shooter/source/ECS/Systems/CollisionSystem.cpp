#include "ECS\Systems\CollisionSystem.h"
CollisionSystem::CollisionSystem()
{

}
void CollisionSystem::Update()
{
	for (auto const& entity : entities)
	{
		auto& collider = coordinator.GetComponent<Collider>(entity);
		quadTreeCollision.Insert(&collider);
	}
	for (auto const& entity : entities)
	{
		auto& collider = coordinator.GetComponent<Collider>(entity);
		std::vector<Collider*> colliders;
		quadTreeCollision.Retrieve(colliders, &collider);
		for (int i = 0; i < colliders.size(); i++)
		{
			AABBCollision(collider, *colliders[i]);
		}
	}
	quadTreeCollision.Clear();
}
void CollisionSystem::AABBCollision(Collider& colliderA, Collider& colliderB)
{
	if (colliderA.position.x < colliderB.position.x + colliderB.bounds.x &&
		colliderA.position.x + colliderA.bounds.x > colliderB.position.x &&
		colliderA.position.y < colliderB.position.y + colliderB.bounds.y &&
		colliderA.position.y + colliderA.bounds.y > colliderB.position.y)
	{
		colliderA.Collision();
		colliderB.Collision();
	}
}