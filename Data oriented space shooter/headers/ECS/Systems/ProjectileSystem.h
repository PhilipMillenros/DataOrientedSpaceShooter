#pragma once
#include "ECS\Core\System.h"
class ProjectileSystem : public System
{
public:
	void Update(float deltaTime);
	ProjectileSystem();
};