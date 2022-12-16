#pragma once
#include "ECS\Core\System.h"
#include "ECS\Core\Coordinator.h"
extern Coordinator coordinator;
class PlayerMovementSystem : public System
{
public:
	PlayerMovementSystem();
	void Update(float deltaTime);
};