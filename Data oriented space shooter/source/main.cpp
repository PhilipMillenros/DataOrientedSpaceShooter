#pragma once

#include "ECS\Core\Coordinator.h"

#include "ECS\Components\Transform.h"
#include "ECS\Components\Projectile.h"
#include "ECS\Systems\EnemySystem.h"
#include <iostream>
#include <random>
#include "Engine\Engine.h"
#include "ECS\Systems\CollisionSystem.h"
#include "ECS\Systems\ProjectileSystem.h"
#include "ECS\Components\Player.h"
#include <chrono>
#include "ECS\Systems\PlayerMovementSystem.h"
#undef main
int screenSizeX = 1920;
int screenSizeY = 1080;
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
	coordinator.RegisterComponent<Projectile>();
	
	auto enemyMovementSystem = coordinator.RegisterSystem<EnemySystem>();
	{
		Signature signature;
		signature.set(coordinator.GetComponentType<Transform>());
		signature.set(coordinator.GetComponentType<RectangleSprite>());
		signature.set(coordinator.GetComponentType<Enemy>());
		signature.set(coordinator.GetComponentType<Collider>());
		coordinator.SetSystemSignature<EnemySystem>(signature);
	}

	auto collisionSystem = coordinator.RegisterSystem<CollisionSystem>();
	{
		Signature signature;
		signature.set(coordinator.GetComponentType<Collider>());
		signature.set(coordinator.GetComponentType<RectangleSprite>());
		signature.set(coordinator.GetComponentType<Transform>());
		coordinator.SetSystemSignature<CollisionSystem>(signature);
	}

	auto playerMovementSystem = coordinator.RegisterSystem<PlayerMovementSystem>();
	{
		Signature signature;
		signature.set(coordinator.GetComponentType<Collider>());
		signature.set(coordinator.GetComponentType<RectangleSprite>());
		signature.set(coordinator.GetComponentType<Transform>());
		signature.set(coordinator.GetComponentType<Player>());
		coordinator.SetSystemSignature<PlayerMovementSystem>(signature);
	}
	auto projectileSystem = coordinator.RegisterSystem<ProjectileSystem>();
	{
		Signature signature;
		signature.set(coordinator.GetComponentType<Collider>());
		signature.set(coordinator.GetComponentType<RectangleSprite>());
		signature.set(coordinator.GetComponentType<Transform>());
		signature.set(coordinator.GetComponentType<Projectile>());
		coordinator.SetSystemSignature<ProjectileSystem>(signature);
	}
	
	

	std::bitset<8> playerCollisionMask("00000010");
	auto player = coordinator.CreateEntity();
	coordinator.AddComponent(player, Transform{ { (float)screenSizeX / 2.f, (float)screenSizeY / 2.f}, {45, 45} });
	coordinator.AddComponent(player, RectangleSprite{ {200.0f, 20.0f}, {50, 50} });
	coordinator.AddComponent(player, Player{ 3, 200.f });
	coordinator.AddComponent(player, Collider{ {25.f * 2.f * player, 0.0f}, {75, 30}, player, 0, playerCollisionMask});
	

	float deltaTime = 0.0f;
	bool quit = false;
	while (!quit)
	{
		
		quadTreeCollision.Clear();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		auto startTime = std::chrono::high_resolution_clock::now();

		enemyMovementSystem->Update(deltaTime);
		playerMovementSystem->Update(deltaTime);
		projectileSystem->Update(deltaTime);

		collisionSystem->Update();
		auto stopTime = std::chrono::high_resolution_clock::now();

		deltaTime = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();

		SDL_RenderPresent(renderer);
	}
	return 0;
}

