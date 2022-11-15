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
		this->window = SDL_CreateWindow("Feeding Bottle Manager", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
		if (!this->renderer || !this->window) std::cout << "Window could not be created!SDL_Error: % s\n" << SDL_GetError() << std::endl;
	}
	SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 255);
	SDL_RenderClear(this->renderer);
	SDL_RenderPresent(this->renderer);
}

void SdlWindowModel::drawNavbar(void)
{
	drawRectangle({ 100,100,100,255 }, 0, 0, SCREEN_WIDTH, 65);
}

void SdlWindowModel::drawRectangle(SDL_Color color, int x, int y, int width, int height)
{
	SDL_SetRenderDrawColor(this->renderer, color.r, color.g, color.b, color.a);
	SDL_Rect rect = { x, y, width, height };
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(this->renderer);
}
