#pragma once
#include "ECS\Components\Collider.h"
#include "ECS\Components\Bounds.h"
#include <iostream>
#include <vector>
class QuadTreeCollision
{
public:
    QuadTreeCollision();
    QuadTreeCollision(int level, const Bounds& bounds);

    void Clear();

    void Insert(Collider* collider);

    void Retrieve(std::vector<Collider*>& returnVector, Collider* collider);

private:
    const int maxObjects = 5;
    const int maxLevels = 5;

    int level;
    std::vector<Collider*> objects;
    Bounds bounds;
    
    QuadTreeCollision* nodes[4];
    bool nodeFlag;

    int GetIndex(Collider* aabb);
};