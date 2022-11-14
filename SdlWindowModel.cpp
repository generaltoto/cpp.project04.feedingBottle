#include "SdlWindowModel.h"
#include "Shared.h"

#include <SDL.h>
#include <iostream>

SdlWindowModel::SdlWindowModel()
{
	this->window = NULL;
	this->renderer = NULL;
	this->screenSurface = NULL;
}

SdlWindowModel::~SdlWindowModel() {}

SDL_Window* SdlWindowModel::getWindow(void) { return this->window; }

SDL_Renderer* SdlWindowModel::getRenderer(void) { return this->renderer; }

SDL_Surface* SdlWindowModel::getSurface(void) { return this->screenSurface; }

void SdlWindowModel::initSDLWindow(void)
{
	if (SDL_Init(SDL_INIT_TIMER) < 0) std::cout << "SDL could not initialize! SDL_Error: %s\n" << SDL_GetError() << std::endl;
	else
	{
		this->window = 
			SDL_CreateWindow("Feeding Bottle Manager", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (this->window == NULL) std::cout << "Window could not be created!SDL_Error: % s\n" << SDL_GetError() << std::endl;
		else
		{
			this->screenSurface = SDL_GetWindowSurface(this->window);
			SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(this->screenSurface->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(this->window);
			SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }
		}
	}
}