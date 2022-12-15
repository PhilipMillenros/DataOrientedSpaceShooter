#pragma once
#include "SDL.h";
#undef main
#include "ECS\Core\Coordinator.h"

#include "ECS\Components\Transform.h"
#include "ECS\Systems\EnemyMovementSystem.h"
#include <iostream>
#include <random>
#include "Engine\Engine.h"
#include "ECS\Systems\CollisionSystem.h"
#include "ECS\Components\Player.h"
#include <chrono>

int screenSizeX;
int screenSizeY;
Coordinator coordinator;
QuadTreeCollision quadTreeCollision = QuadTreeCollision(0, Bounds({ 0, 0 }, { (float)screenSizeX, (float)screenSizeY }));

//Each system has its signature that you set by components
//Each entity has signatures that you set by adding components to it
//Entities that matches with the system signature gets inserted into the entity array

int main()
{
	coordinator.Init();

	coordinator.RegisterComponent<Transform>();
	coordinator.RegisterComponent<RectangleSprite>();
	coordinator.RegisterComponent<Enemy>();
	coordinator.RegisterComponent<Collider>();
	coordinator.RegisterComponent<Player>();


	auto enemyMovementSystem = coordinator.RegisterSystem<EnemyMovementSystem>();
	

	auto collisionSystem = coordinator.RegisterSystem<CollisionSystem>();
	Signature signature;
	signature.set(coordinator.GetComponentType<Transform>());
	signature.set(coordinator.GetComponentType<RectangleSprite>());
	signature.set(coordinator.GetComponentType<Enemy>());
	signature.set(coordinator.GetComponentType<Collider>());
	signature.set(coordinator.GetComponentType<Player>());
	coordinator.SetSystemSignature<EnemyMovementSystem>(signature);
	coordinator.SetSystemSignature<CollisionSystem>(signature);

	Entity count = 2;

	
	std::vector<Entity> entities(count);

	std::default_random_engine generator;
	std::uniform_real_distribution<float> randPosition(-100.0f, 100.0f);
	std::uniform_real_distribution<float> randRotation(0.0f, 3.0f);
	std::uniform_real_distribution<float> randScale(3.0f, 5.0f);
	std::uniform_real_distribution<float> randGravity(-10.0f, -1.0f);

	float scale = randScale(generator);
	float x = 1;
	for (auto& enemy : entities)
	{
		enemy = coordinator.CreateEntity();
		coordinator.AddComponent(enemy, Transform{ {50 * 2.f * enemy, 0.0f}, {75, 30} });
		coordinator.AddComponent(enemy, RectangleSprite{ {200.0f, 20.0f}, {50, 50} });
		coordinator.AddComponent(enemy, Enemy{ 10, {10 * x, 0} });
		coordinator.AddComponent(enemy, Collider{ {25.f * 2.f * enemy, 0.0f}, {75, 30}, enemy });
		x = -1;
	}
	auto player = coordinator.CreateEntity();
	coordinator.AddComponent(player, Transform{ {500, 0.0f}, {30, 30} });
	coordinator.AddComponent(player, RectangleSprite{ {200.0f, 20.0f}, {50, 50} });
	coordinator.AddComponent(player, Player{ 3, 10 });
	coordinator.AddComponent(player, Collider{ {25.f * 2.f * player, 0.0f}, {75, 30}, player });

	float deltaTime = 0.0f;
	bool quit = false;
	while (!quit)
	{
		quadTreeCollision.Clear();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		auto startTime = std::chrono::high_resolution_clock::now();

		enemyMovementSystem->Update(deltaTime);
		
		collisionSystem->Update();

		auto stopTime = std::chrono::high_resolution_clock::now();

		deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();

		SDL_RenderPresent(renderer);
	}
	return 0;
}

