#pragma once
#include "ECS\Core\System.h"
#include "ECS\Core\Coordinator.h"
extern Coordinator coordinator;
class PlayerMovementSystem : public System
{
	PlayerMovementSystem();
	void Update(float deltaTime);
};