#include "ECS\Components\Collider.h"
#include "ECS\Components\RectangleSprite.h"
#include "ECS\Components\Transform.h"
#include "ECS\Components\Projectile.h"
#include "ECS\Systems\ProjectileSystem.h"
#include "ECS\Core\Coordinator.h"
extern Coordinator coordinator;
ProjectileSystem::ProjectileSystem()
{

}
void ProjectileSystem::Update(float deltaTime)
{
	for (auto const& entity : entities)
	{
		auto& transform = coordinator.GetComponent<Transform>(entity);
		auto& renderer = coordinator.GetComponent<RectangleSprite>(entity);
		auto& collider = coordinator.GetComponent<Collider>(entity);
		auto& projectile = coordinator.GetComponent<Projectile>(entity);
		transform.position.x += transform.position.x * projectile.shootDirection.x * deltaTime * projectile.speed / 1000.f;
		transform.position.y += transform.position.y * projectile.shootDirection.y * deltaTime * projectile.speed / 1000.f;

		collider.position = transform.position;
		collider.bounds = transform.size;
		renderer.size = transform.size;
		renderer.position = transform.position;
		renderer.Draw();
		
	}
}