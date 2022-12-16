#include "ECS\Systems\QuadTreeCollision.h"
QuadTreeCollision::QuadTreeCollision()
{
    level = 0;

}
QuadTreeCollision::QuadTreeCollision(int level, const Bounds& bounds)
{ 
    this->bounds = bounds;
    this->level = level;
    nodeFlag = false;

    for (int i = 0; i < 4; i++)
    {
        nodes[i] = nullptr;
    }
}

void QuadTreeCollision::Clear()
{
    objects.clear();

    if (nodeFlag)
    {
        for (int i = 0; i < 4; i++)
        {
            nodes[i]->Clear();
            delete nodes[i];
        }

        nodeFlag = false;
    }
}

void QuadTreeCollision::Insert(Collider* collider)
{
    if (objects.size() == maxObjects && level < maxLevels)
    {
        if (!nodeFlag)
        {
            nodes[0] = new QuadTreeCollision(level + 1, Bounds(bounds.position, bounds.bounds / 2.f));
            nodes[1] = new QuadTreeCollision(level + 1, Bounds(Vector2(bounds.position.x + bounds.bounds.x / 2, bounds.position.y), bounds.bounds / 2.f));
            nodes[2] = new QuadTreeCollision(level + 1, Bounds(Vector2(bounds.position.x, bounds.position.y + bounds.bounds.y / 2.f), bounds.bounds / 2.f));
            nodes[3] = new QuadTreeCollision(level + 1, Bounds(Vector2(bounds.position.x + bounds.bounds.x / 2.f, bounds.position.y + bounds.bounds.y / 2.f), bounds.bounds / 2.f));
            nodeFlag = true;
        }

        int index = GetIndex(collider);

        if (index == -1)
        {
            objects.push_back(collider);
        }
        else
        {
            nodes[index]->Insert(collider);
        }
    }
    else
    {
        objects.push_back(collider);
    }
}

void QuadTreeCollision::Retrieve(std::vector<Collider*>& returnVector, Collider* aabb)
{
    for (int i = 0; i < objects.size(); i++)
    {
        if (objects[i] != aabb)
        {
            returnVector.push_back(objects[i]);
        }
    }

    if (nodeFlag)
    {
        int index = GetIndex(aabb);

        if (index != -1)
        {
            nodes[index]->Retrieve(returnVector, aabb);
        }
    }
}

int QuadTreeCollision::GetIndex(Collider* collider)
{
    int index = -1;

    if (nodeFlag)
    {
        for (int i = 0; i < 4; i++)
        {
            if (nodes[i]->bounds.ColliderFits(collider))
            {
                index = i;
                break;
            }
        }
    }

    return index;
}