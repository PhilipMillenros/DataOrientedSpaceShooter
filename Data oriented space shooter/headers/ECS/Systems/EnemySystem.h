#pragma once
#include <random>
#include "ECS\Components\Transform.h"
#include "ECS\Core\Coordinator.h"
#include "ECS\Core\System.h"
#include "ECS\Components\RectangleSprite.h"
#include "ECS\Components\Enemy.h"
#include "ECS\Components\Collider.h"
extern Coordinator coordinator;
extern int screenSizeX;
extern int screenSizeY;

std::default_random_engine generator;
std::uniform_real_distribution<float> randPositionX(screenSizeX * 0.99f, screenSizeX);
std::uniform_real_distribution<float> randPositionY(0.f, screenSizeY);
std::uniform_real_distribution<float> randScale(65.0f, 75.0f);

class EnemySystem : public System
{
public:
	EnemySystem()
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

			transform.position = transform.position + enemy.movementSpeed * deltaTime;
			collider.position = transform.position;
			collider.bounds = transform.size;
			renderer.size = transform.size;
			renderer.position = transform.position;
			renderer.Draw();
		}
		spawnTimer += deltaTime;
		if (spawnTimer > enemySpawnTime)
		{
			spawnTimer = 0;
			
			std::bitset<8> enemyCollisionMask("00000101");
			float scale = randScale(generator);
			std::vector<Entity> enemies(1);
			for (auto& enemy : enemies)
			{
				enemy = coordinator.CreateEntity();
				coordinator.AddComponent(enemy, Transform{ {randPositionX(generator), randPositionY(generator)}, {30, 30} });
				coordinator.AddComponent(enemy, RectangleSprite{ {200.0f, 20.0f}, {50, 50} });
				coordinator.AddComponent(enemy, Enemy{ 1, {-145.f, 0} });
				coordinator.AddComponent(enemy, Collider{ {randPositionX(generator), randPositionY(generator)}, {75, 30}, enemy, 1, enemyCollisionMask });
			}
		}
	}
private:
	float spawnTimer = 0;
	float enemySpawnTime = 0.2f;
};