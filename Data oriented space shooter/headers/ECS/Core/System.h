#pragma once
#include <set>
#include "ECS\Core\ECS.h"

class System
{
public:
	std::set<Entity> entities;
};