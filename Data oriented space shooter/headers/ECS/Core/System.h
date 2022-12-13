#pragma once
#include <set>
#include <ECS\ECS.h>

class System
{
public:
	std::set<Entity> entities;
};