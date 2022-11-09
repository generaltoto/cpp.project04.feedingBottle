#include "Application.h"
#include "Shared.h"

#include <SDL.h>
#include <stdio.h>

SDL_Window* Application::getWindow(void) { return this->window; }

SDL_Surface* Application::getSurface(void) { return this->screenSurface; }

void Application::initSDLWindow(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	else
	{
		this->window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (this->window == NULL) printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		else
		{
			this->screenSurface = SDL_GetWindowSurface(this->window);
			SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(this->screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(this->window);
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
		}
	}
}