#pragma once
#include "SDL.h"

SDL_Window* window = SDL_CreateWindow("Space shooter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

SDL_Event event;