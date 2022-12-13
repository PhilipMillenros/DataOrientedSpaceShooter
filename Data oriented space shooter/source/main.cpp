#pragma once
#include "ECS/Coordinator.h"
//#include "SDL.h"
#include <ECS\Components\Transform.h>
#include <ECS\Systems\EnemyMovementSystem.h>
#include <iostream>
#include <random>
#include <chrono>
Coordinator gCoordinator;

int main()
{
	gCoordinator.Init();

	gCoordinator.RegisterComponent<Transform>();

	auto enemyMovementSystem = gCoordinator.RegisterSystem<EnemyMovementSystem>();

	Signature signature;
	signature.set(gCoordinator.GetComponentType<Transform>());
	gCoordinator.SetSystemSignature<EnemyMovementSystem>(signature);

	std::vector<Entity> entities(MAX_ENTITIES);

	std::default_random_engine generator;
	std::uniform_real_distribution<float> randPosition(-100.0f, 100.0f);
	std::uniform_real_distribution<float> randRotation(0.0f, 3.0f);
	std::uniform_real_distribution<float> randScale(3.0f, 5.0f);
	std::uniform_real_distribution<float> randGravity(-10.0f, -1.0f);

	float scale = randScale(generator);

	for (auto& entity : entities)
	{
		entity = gCoordinator.CreateEntity();

		gCoordinator.AddComponent(entity, Transform{ Vector2(0.0f, 0.0f) });
	}

	float deltaTime = 0.0f;
	bool quit = false;
	while (!quit)
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		enemyMovementSystem->Update(deltaTime);

		auto stopTime = std::chrono::high_resolution_clock::now();

		deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();

		
	}
	return 0;
}

