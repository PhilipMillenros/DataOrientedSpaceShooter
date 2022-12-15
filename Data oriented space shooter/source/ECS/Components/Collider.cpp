#include "ECS\Components\Collider.h"

Collider::Collider() :
	position(0, 0), bounds(1, 1){ }

Collider::Collider(Vector2 position, Vector2 bounds, Entity entity) :
	position(position), bounds(bounds), entity(entity) { }

void Collider::Collision()
{
	std::cout << "Collision Invoked" << std::endl;
	
}