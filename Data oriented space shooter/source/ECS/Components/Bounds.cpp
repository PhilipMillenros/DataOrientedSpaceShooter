#include "ECS\Components\Bounds.h"

Bounds::Bounds() 
	
{

}
Bounds::Bounds(Vector2 bounds, Vector2 position) :
	bounds(bounds), position(position)
{
	
}
bool Bounds::ColliderFits(Collider* other)
{
	if (other->position.x + other->bounds.x / 2 > position.x + bounds.x)
	{
		return false;
	}
	if (other->position.y + other->bounds.y / 2 > position.y + bounds.y)
	{
		return false;
	}
	if (other->position.y - other->bounds.y / 2 < position.y)
	{
		return false;
	}
	if (other->position.x - other->bounds.x / 2 < position.x)
	{
		return false;
	}
	return true;
}