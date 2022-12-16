#include "ECS\Components\Collider.h"
#include "ECS\Core\Coordinator.h"
extern Coordinator coordinator;
Collider::Collider() :
	position(0, 0), bounds(1, 1){ }

Collider::Collider(Vector2 position, Vector2 bounds, Entity entity, int collisionIndex, std::bitset<8> mask) :
	position(position), bounds(bounds), entity(entity), collisionIndex(collisionIndex), collisionMask(mask) 
{
}

void Collider::Collision(Collider& colliderA, Collider& colliderB)
{
	if ((colliderA.collisionMask[colliderA.collisionIndex] | colliderB.collisionMask[colliderA.collisionIndex]) == 1)
	{
		colliderA.collision = true;
	}
	
}