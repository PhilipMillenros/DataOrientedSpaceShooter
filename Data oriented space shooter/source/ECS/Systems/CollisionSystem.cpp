#include "ECS\Systems\CollisionSystem.h"

#include <vector>
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
	std::vector<Entity> ent(entities.size());
	int i = 0;
	for (auto const& entity : entities)
	{
		ent[i] = entity;
		i++;
		auto& collider = coordinator.GetComponent<Collider>(entity);
		std::vector<Collider*> colliders;
		quadTreeCollision.Retrieve(colliders, &collider);
		
		for (int i = 0; i < colliders.size(); i++)
		{
			AABBCollision(collider, *colliders[i]);
		}
	}
	quadTreeCollision.Clear();
	for (int i = 0; i < ent.size(); i++)
	{
		if (coordinator.GetComponent<Collider>(ent[i]).collision)
		{
			coordinator.DestroyEntity(ent[i]);
		}
	}
}
void CollisionSystem::AABBCollision(Collider& colliderA, Collider& colliderB)
{
	if (colliderA.position.x < colliderB.position.x + colliderB.bounds.x &&
		colliderA.position.x + colliderA.bounds.x > colliderB.position.x &&
		colliderA.position.y < colliderB.position.y + colliderB.bounds.y &&
		colliderA.position.y + colliderA.bounds.y > colliderB.position.y)
	{
		colliderA.Collision(colliderA, colliderB);
	}
}