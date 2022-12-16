#pragma once
#include "ECS\Systems\PlayerMovementSystem.h"
#include "ECS\Components\Player.h"
#include "ECS\Components\RectangleSprite.h"
#include "ECS\Components\Transform.h"
#include "ECS\Components\Collider.h"
#include "ECS\Components\Projectile.h"
extern SDL_Event event;
void PlayerMovementSystem::Update(float deltaTime)
{
	Transform* transform = nullptr;
	Player* player = nullptr;
	
	for (auto const& entity : entities)
	{
		transform = &coordinator.GetComponent<Transform>(entity);
		auto& renderer = coordinator.GetComponent<RectangleSprite>(entity);
		player = &coordinator.GetComponent<Player>(entity);
		auto& collider = coordinator.GetComponent<Collider>(entity);
		transform->position.x += player->xVelocity * deltaTime * player->speed;
		transform->position.y += player->yVelocity * deltaTime * player->speed;
		collider.position = transform->position;
		collider.bounds = transform->size;
		renderer.size = transform->size;
		renderer.position = transform->position;
		renderer.Draw();
	}
	
	if (transform != nullptr && player != nullptr)
	{
		while (SDL_PollEvent(&event))
		{
			if (SDL_MOUSEBUTTONDOWN == event.type)
			{
				if (SDL_BUTTON_LEFT == event.button.button)
				{
					std::bitset<8> projectileCollisionMask("00000010");
					int mouseX, mouseY;
					Uint32 mouseState = SDL_GetMouseState(&mouseX, &mouseY);
					Entity entity = coordinator.CreateEntity();
					coordinator.AddComponent(entity, Transform{ { transform->position + transform->size / 2 }, {10, 10} });
					coordinator.AddComponent(entity, RectangleSprite{ {200.0f, 20.0f}, {50, 50} });
					coordinator.AddComponent(entity, Projectile{ 1, Normalize(Vector2(mouseX, mouseY) - transform->position) });
					coordinator.AddComponent(entity, Collider{ {0.f, 0.0f}, {75, 30}, entity, 2, projectileCollisionMask});
				}
			}

			switch (event.type)
			{
			
			case SDL_KEYDOWN:
				
				switch (event.key.keysym.sym)
				{
				case SDLK_a:
					player->xVelocity = -1;
					break;
				case SDLK_d:
					player->xVelocity = 1;
					break;
				case SDLK_w:
					player->yVelocity = -1;
					break;
				case SDLK_s:
					player->yVelocity = 1;
					break;
				default:
					break;
				}
				break;
			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
				case SDLK_a:
					if (player->xVelocity < 0)
						player->xVelocity = 0;
					break;
				case SDLK_d:
					if (player->xVelocity > 0)
						player->xVelocity = 0;
					break;
				case SDLK_w:
					if (player->yVelocity < 0)
						player->yVelocity = 0;
					break;
				case SDLK_s:
					if (player->yVelocity > 0)
						player->yVelocity = 0;
					break;
				default:
					break;
				}
				break;

			default:
				break;
			}
			
			
		}
	}
	
	
	
}
PlayerMovementSystem::PlayerMovementSystem()
{

}