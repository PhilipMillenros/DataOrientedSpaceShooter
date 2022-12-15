#pragma once
#include "ECS\Core\System.h"
#include "ECS\Components\RectangleSprite.h"
#include "ECS\Components\Enemy.h"
#include "ECS\Components\Collider.h"
extern Coordinator coordinator;
class EnemyMovementSystem : public System
{
public:
	EnemyMovementSystem()
	{
		
	}
	
	void Update(float deltaTime)
	{
		for (auto const& entity : entities)
		{
			auto& transform = coordinator.GetComponent<Transform>(entity);
			auto& renderer = coordinator.GetComponent<RectangleSprite>(entity);
			auto& enemy = coordinator.GetComponent<Enemy>(entity);
			auto& collider = coordinator.GetComponent<Collider>(entity);

			transform.position += enemy.movementSpeed * deltaTime;
			collider.position = transform.position;
			collider.bounds = transform.size;
			renderer.size = transform.size;
			renderer.position = transform.position;
			renderer.Draw();
		}
	}
private:
	
};