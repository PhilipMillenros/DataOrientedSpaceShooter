#include "ECS\Systems\PlayerMovementSystem.h"
#include "ECS\Components\Player.h"
void PlayerMovementSystem::Update(float deltaTime)
{
	for (auto const& entity : entities)
	{
		auto& player = coordinator.GetComponent<Player>(entity);
		
	}
	
	
}
PlayerMovementSystem::PlayerMovementSystem()
{

}