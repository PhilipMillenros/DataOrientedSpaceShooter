#pragma once
#include "SDL.h"
#include "Math\Vector2.h"
extern SDL_Renderer* renderer;
extern SDL_Window* window;
struct RectangleSprite
{
public:
	Vector2 position;
	Vector2 size;
	RectangleSprite()
	{

	}

	RectangleSprite(Vector2 position, Vector2 size) : position(position), size(size)
	{

	}
	void Draw()
	{
		SDL_SetRenderDrawColor(renderer, 1, 25, 0, 100);
		rect.x = position.x;
		rect.y = position.y;
		rect.w = size.x;
		rect.h = size.y;

		SDL_RenderFillRect(renderer, &rect);
	}
private:
	SDL_Rect rect;
};